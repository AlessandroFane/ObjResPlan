(define (problem Test/molto_poco_connesso_problema2.pddl) (:domain navigation)
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
    (railway S0 S1 train2)
    (railway S0 S3 train2)
    (road S0 S4 bus3)
    (road S0 S5 bus2)
    (railway S0 S5 train1)
    (flight S0 S8 plane3)
    (railway S1 S4 train2)
    (flight S1 S7 plane3)
    (road S1 S9 bus2)
    (railway S1 S9 train2)
    (railway S2 S4 train2)
    (road S2 S5 bus3)
    (road S2 S6 bus1)
    (railway S2 S9 train2)
    (road S3 S6 bus2)
    (flight S3 S6 plane1)
    (road S3 S9 bus1)
    (railway S4 S5 train2)
    (road S4 S7 bus1)
    (road S4 S8 bus2)
    (road S5 S6 bus3)
    (railway S5 S6 train1)
    (road S5 S7 bus2)
    (road S6 S8 bus2)
    (road S7 S8 bus1)
    (at S0)
)
(:goal (and
    (at S9)
))
)
