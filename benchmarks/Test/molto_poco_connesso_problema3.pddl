(define (problem Test/molto_poco_connesso_problema3.pddl) (:domain navigation)
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
    (road S0 S3 bus2)
    (road S0 S5 bus2)
    (road S1 S4 bus1)
    (road S1 S8 bus3)
    (flight S2 S5 plane3)
    (road S2 S6 bus2)
    (flight S2 S6 plane1)
    (road S2 S7 bus1)
    (railway S3 S5 train3)
    (flight S3 S6 plane3)
    (railway S3 S9 train3)
    (road S4 S7 bus3)
    (road S4 S9 bus1)
    (railway S5 S9 train3)
    (flight S6 S7 plane1)
    (railway S6 S8 train1)
    (road S7 S9 bus3)
    (at S0)
)
(:goal (and
    (at S9)
))
)
