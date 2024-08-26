begin_version
3
end_version
begin_metric
0
end_metric
4
begin_variable
var0
-1
2
Atom at(a)
Atom at(b)
end_variable
begin_variable
var1
-1
2
Atom used(aereo1)
NegatedAtom used(aereo1)
end_variable
begin_variable
var2
-1
2
Atom used(bus1)
NegatedAtom used(bus1)
end_variable
begin_variable
var3
-1
2
Atom used(treno1)
NegatedAtom used(treno1)
end_variable
1
begin_mutex_group
2
0 0
0 1
end_mutex_group
begin_state
0
1
1
1
end_state
begin_goal
1
0 1
end_goal
3
begin_operator
travel_by_bus a b bus1
0
2
0 0 0 1
0 2 -1 0
0
end_operator
begin_operator
travel_by_plane a b aereo1
0
2
0 0 0 1
0 1 -1 0
0
end_operator
begin_operator
travel_by_train a b treno1
0
2
0 0 0 1
0 3 -1 0
0
end_operator
0
