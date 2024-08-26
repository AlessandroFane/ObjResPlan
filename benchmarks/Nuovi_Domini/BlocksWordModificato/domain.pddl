(define (domain blocksworld)
(:requirements :strips)
(:predicates (clear ?x)
             (on-table ?x)
             (on ?x ?y)
			 (used ?a))

(:action move-b-to-b
  :parameters (?bm ?bf ?bt ?a)
  :precondition (and (clear ?bm) (clear ?bt) (on ?bm ?bf))
  :effect (and (not (clear ?bt)) (not (on ?bm ?bf))
               (on ?bm ?bt) (clear ?bf) (used ?a)))

(:action move-b-to-t
  :parameters (?bm ?bf ?a)
  :precondition (and (clear ?bm) (on ?bm ?bf))
  :effect (and (not (on ?bm ?bf))
               (on-table ?bm) (clear ?bf) (used ?a)))

(:action move-t-to-b
  :parameters (?bm ?bt ?a)
  :precondition (and (clear ?bm) (clear ?bt) (on-table ?bm))
  :effect (and (not (clear ?bt)) (not (on-table ?bm))
               (on ?bm ?bt) (used ?a))))

