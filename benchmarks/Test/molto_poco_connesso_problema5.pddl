(define (problem Test/molto_poco_connesso_problema5.pddl) (:domain navigation)
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
    (road S0 S2 bus3)
    (railway S0 S2 train1)
    (flight S0 S4 plane2)
    (railway S0 S6 train1)
    (road S0 S8 bus2)
    (road S0 S9 bus3)
    (railway S1 S3 train1)
    (road S1 S4 bus1)
    (road S2 S3 bus2)
    (road S2 S5 bus2)
    (flight S2 S7 plane2)
    (railway S3 S4 train3)
    (road S3 S8 bus1)
    (railway S4 S7 train2)
    (road S4 S9 bus1)
    (railway S4 S9 train2)
    (road S5 S8 bus3)
    (road S6 S8 bus2)
    (railway S6 S9 train1)
    (at S0)
)
(:goal (and
    (at S9)
))
)
