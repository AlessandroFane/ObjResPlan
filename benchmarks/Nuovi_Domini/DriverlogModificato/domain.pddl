(define (domain driverlog)
  (:requirements :strips)
  (:predicates
    (VEHICLE ?v)
    (LOCATION ?loc)
    (DRIVER ?d)
    (at ?d ?loc)
    (path ?x ?y ?v)
	(used ?v)
  )
  
    (:action MOVE
    :parameters (?driver ?loc-from ?loc-to ?vehicle)
    :precondition (and (DRIVER ?driver) (LOCATION ?loc-from) (LOCATION ?loc-to) (VEHICLE ?vehicle)
      (at ?driver ?loc-from) (path ?loc-from ?loc-to ?vehicle))
    :effect (and (not (at ?driver ?loc-from)) (at ?driver ?loc-to) (used ?vehicle))
  )

)