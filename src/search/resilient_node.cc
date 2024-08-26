#include "resilient_node.h"

#include <tr1/unordered_map>
using std::tr1::hash;

using namespace std;

/// @brief Constructor for ResilientNode that takes all the parameters needed to create a node
/// @param state_ Full state of the node
/// @param k_ Number of operators that can still fail
/// @param deactivated_op_ Deactivated operators
ResilientNode::ResilientNode(State state_, int k_, std::set<set<Operator> > deactivated_op_) : state(state_), k(k_), deactivated_op(deactivated_op_)
{
    string op_value;

    if (!deactivated_op.empty()) {
        for (std::set<std::set<Operator> >::iterator it_outer = deactivated_op.begin(); it_outer != deactivated_op.end(); ++it_outer) {
            for (std::set<Operator>::iterator it_inner = it_outer->begin(); it_inner != it_outer->end(); ++it_inner) {
                op_value += it_inner->get_name();
            }
        }
    }
    else
        op_value = "";

    string state_value;
    for (int i = 0; i < g_variable_domain.size(); i++)
    {
        const string &fact_name = g_fact_names[i][(state_)[i]].stringa;
        if (fact_name != "<none of those>")
            state_value += fact_name;
    }

    std::tr1::hash<string> hasher;
    int hash = hasher(op_value + state_value);
    id = hash;
}


/// @brief Dump node information to the standard output
void ResilientNode::dump() const
{
    cout << "\n----------------------------------------" << endl;
    cout << "Node: " << id << endl;
    state.dump_pddl();
    cout << "k: " << k << endl;
    cout << "deactivated_op: " << endl;
    for (std::set<std::set<Operator> >::iterator it_outer = deactivated_op.begin(); it_outer != deactivated_op.end(); ++it_outer) {
        for (std::set<Operator>::iterator it_inner = it_outer->begin(); it_inner != it_outer->end(); ++it_inner) {
            std::cout << it_inner->get_nondet_name() << std::endl;
        }
    }
    cout << "\n----------------------------------------" << endl;
}
