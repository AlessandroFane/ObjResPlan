(define (domain fittizio)
  (:requirements :strips)
  (:predicates
    (location ?loc)
    (at ?loc)
    (path ?x ?y)
  )

  (:action walk
    :parameters (?loc-from ?loc-to)
    :precondition (and (location ?loc-from) (location ?loc-to)
                       (at ?loc-from) (path ?loc-from ?loc-to))
    :effect (and (not (at ?loc-from)) 
                 (at ?loc-to))
  )
)

