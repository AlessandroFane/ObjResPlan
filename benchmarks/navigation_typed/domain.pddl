(define (domain navigation)
  (:requirements :strips :typing)
  (:types
    location car train plane
  )
  (:predicates
    (at ?loc - location)
    (road ?x - location ?y - location ?car - car)
    (railway ?x - location ?y - location ?train - train)
    (flight ?x - location ?y - location ?plane - plane)
	(used ?car - car)
	(used ?train - train)
	(used ?plane - plane)
  )

  (:action TRAVEL_BY_CAR
    :parameters (?from - location ?to - location ?car - car)
    :precondition (and (at ?from) (road ?from ?to ?car))
    :effect (and (not (at ?from)) (at ?to) (used ?car))
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
