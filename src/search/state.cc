//////////
// TODO //
//////////
// - Fix the dump functions to not print undefined values
// - Move the old state functions into the state registry

#include "state.h"

#include "globals.h"
#include "utilities.h"
#include "state_registry.h"

#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

State::State(const PackedStateBin *buffer_, const StateRegistry &registry_,
             StateID id_)
    : buffer(buffer_),
      registry(&registry_),
      id(id_)
{
    assert(buffer);
    assert(id != StateID::no_state);
}

State::~State()
{
}

int State::operator[](int index) const
{
    return g_state_packer->get(buffer, index);
}

void State::dump_pddl() const
{
    for (int i = 0; i < g_variable_domain.size(); i++)
    {
        const string &fact_name = g_fact_names[i][(*this)[i]].stringa;
        if (fact_name != "<none of those>")
            cout << fact_name << endl;
    }
}

void State::dump_fdr() const
{
    for (size_t i = 0; i < g_variable_domain.size(); ++i)
        cout << "  #" << i << " [" << g_variable_name[i] << "] -> "
             << (*this)[i] << endl;
}


bool State::operator==(const State &other) const
{
    for (int i = 0; i < g_variable_domain.size(); i++)
    {
        const string &fact_name1 = g_fact_names[i][(*this)[i]].stringa;
        const string &fact_name2 = g_fact_names[i][(other)[i]].stringa;
        if (fact_name1 != "<none of those>" && fact_name2 != "<none of those>" && fact_name1.compare(fact_name2) != 0)
            return false;
    }
    return true;
}