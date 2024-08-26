(define (problem Test/poco_connesso_problema5.pddl) (:domain navigation)
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
    (road S0 S2 bus1)
    (road S0 S4 bus2)
    (road S0 S5 bus2)
    (flight S0 S5 plane1)
    (road S0 S7 bus1)
    (road S1 S2 bus1)
    (railway S1 S3 train1)
    (road S1 S4 bus3)
    (flight S1 S4 plane1)
    (flight S1 S5 plane2)
    (road S1 S6 bus2)
    (road S1 S7 bus3)
    (road S1 S9 bus1)
    (road S2 S4 bus2)
    (railway S2 S4 train1)
    (railway S2 S5 train1)
    (railway S3 S4 train1)
    (road S3 S5 bus2)
    (road S3 S6 bus1)
    (flight S3 S9 plane1)
    (road S4 S5 bus2)
    (road S4 S6 bus2)
    (road S4 S7 bus2)
    (railway S4 S7 train1)
    (flight S4 S9 plane2)
    (railway S5 S7 train2)
    (railway S5 S9 train3)
    (road S6 S9 bus1)
    (at S0)
)
(:goal (and
    (at S9)
))
)
