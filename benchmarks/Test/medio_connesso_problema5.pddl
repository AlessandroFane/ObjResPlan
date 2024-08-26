(define (problem Test/medio_connesso_problema5.pddl) (:domain navigation)
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
    (railway S0 S1 train1)
    (road S0 S2 bus2)
    (flight S0 S2 plane1)
    (road S0 S5 bus1)
    (railway S0 S5 train3)
    (road S0 S6 bus3)
    (railway S0 S7 train2)
    (road S0 S8 bus1)
    (road S0 S9 bus3)
    (road S1 S2 bus2)
    (road S1 S3 bus1)
    (railway S1 S3 train3)
    (road S1 S4 bus1)
    (railway S1 S4 train2)
    (road S1 S5 bus1)
    (road S1 S7 bus2)
    (road S1 S8 bus1)
    (road S2 S4 bus1)
    (railway S2 S4 train1)
    (railway S2 S5 train2)
    (road S2 S7 bus1)
    (railway S2 S7 train1)
    (flight S2 S7 plane2)
    (road S2 S8 bus3)
    (road S3 S5 bus3)
    (railway S3 S6 train1)
    (road S3 S7 bus2)
    (road S3 S8 bus3)
    (flight S3 S8 plane3)
    (railway S3 S9 train3)
    (road S4 S5 bus3)
    (railway S4 S5 train2)
    (railway S4 S7 train1)
    (flight S4 S7 plane1)
    (road S4 S8 bus2)
    (road S4 S9 bus2)
    (railway S4 S9 train2)
    (flight S4 S9 plane2)
    (road S5 S6 bus1)
    (railway S5 S6 train3)
    (railway S5 S7 train3)
    (road S5 S8 bus2)
    (flight S5 S9 plane3)
    (road S6 S7 bus1)
    (railway S6 S7 train3)
    (road S7 S8 bus2)
    (railway S7 S8 train2)
    (road S7 S9 bus3)
    (road S8 S9 bus3)
    (at S0)
)
(:goal (and
    (at S9)
))
)
