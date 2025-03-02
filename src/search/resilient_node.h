#ifndef RESILIENT_NODE_H
#define RESILIENT_NODE_H

#include "operator.h"
#include <set>

using namespace std;

class ResilientNode
{
    State state;
    int k;
    std::set<std::set<Operator> > deactivated_op;
    unsigned long int id;
    ResilientNode();

public:
    ResilientNode(State state_, int k_, std::set<std::set<Operator> > deactivated_op_);

    void dump() const;

    State get_state() const
    {
        return state;
    }

    int get_k() const
    {
        return k;
    }

    int get_id() const
    {
        return id;
    }

    std::set<set<Operator> > get_deactivated_op() const
    {
        return deactivated_op;
    }

    bool operator==(const ResilientNode &other) const
    {
        return this->id == other.id;
    }
    bool operator<(const ResilientNode &other) const
    {
        return this->id < other.id;
    }
    bool operator!=(const ResilientNode &other) const
    {
        return this->id != other.id;
    }
};

#endif
