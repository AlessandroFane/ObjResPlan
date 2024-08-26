(define (domain similNavigation)
  (:requirements :strips :typing)
  (:types
    location bus train plane
  )
  (:predicates
    (at ?loc - location)
    (road ?x - location ?y - location ?bus - bus)
    (railway ?x - location ?y - location ?train - train)
    (flight ?x - location ?y - location ?plane - plane)
	(used ?bus - bus)
	(used ?train - train)
	(used ?plane - plane)
  )

  (:action TRAVEL_BY_BUS
    :parameters (?from - location ?to - location ?bus - bus)
    :precondition (and (at ?from) (road ?from ?to ?bus))
    :effect (and (not (at ?from)) (at ?to) (used ?bus))
  )

  (:action TRAVEL_BY_TRAIN
    :parameters (?from - location ?to - location ?train - train)
    :precondition (and (at ?from) (railway ?from ?to ?train))
    :effect (and (not (at ?from)) (at ?to) (used ?train))
  )

  (:action TRAVEL_BY_PLANE
    :parameters (?from - location ?to - location ?plane - plane)
    :precondition (and (at ?from) (flight ?from ?to ?plane))
    :effect (and (not (at ?from)) (at ?to) (used ?plane))
  )

)