(define (problem Test/molto_poco_connesso_problema1.pddl) (:domain navigation)
(:objects
    S0 - location
    S1 - location
    S2 - location
    S3 - location
    S4 - location
    S5 - location
    S6 - location
    S7 - location
    S8 - location
    S9 - location
    bus1 bus2 bus3 - bus
    treno1 treno2 treno3 - train
    aereo1 aereo2 aereo3 - plane
)
(:init
    (road S0 S1 bus2)
    (road S0 S3 bus2)
    (railway S0 S5 train1)
    (flight S0 S7 plane2)
    (railway S0 S8 train2)
    (road S0 S9 bus2)
    (road S1 S5 bus1)
    (flight S1 S5 plane2)
    (railway S1 S6 train3)
    (railway S1 S7 train3)
    (flight S1 S8 plane2)
    (railway S1 S9 train2)
    (railway S3 S4 train1)
    (road S3 S8 bus1)
    (road S4 S5 bus1)
    (flight S4 S5 plane2)
    (road S5 S7 bus1)
    (road S6 S7 bus2)
    (at S0)
)
(:goal (and
    (at S9)
))
)
