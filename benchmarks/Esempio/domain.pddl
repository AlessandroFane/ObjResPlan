(define (domain navigation)
  (:requirements :strips :typing)
  (:types
    fermata bicicletta metro auto
  )
  (:predicates
    (at ?loc - fermata)
    (ciclabile ?x - fermata ?y - fermata ?bicicletta - bicicletta)
    (linea_metro ?x - fermata ?y - fermata ?metro - metro)
    (strada ?x - fermata ?y - fermata ?auto - auto)
	(used ?bicicletta - bicicletta)
	(used ?metro - metro)
	(used ?auto - auto)
  )

  (:action TRAVEL_BY_bicicletta
    :parameters (?from - fermata ?to - fermata ?bicicletta - bicicletta)
    :precondition (and (at ?from) (ciclabile ?from ?to ?bicicletta))
    :effect (and (not (at ?from)) (at ?to) (used ?bicicletta))
  )

  (:action TRAVEL_BY_metro
    :parameters (?from - fermata ?to - fermata ?metro - metro)
    :precondition (and (at ?from) (linea_metro ?from ?to ?metro))
    :effect (and (not (at ?from)) (at ?to) (used ?metro))
  )

  (:action TRAVEL_BY_auto
    :parameters (?from - fermata ?to - fermata ?auto - auto)
    :precondition (and (at ?from) (strada ?from ?to ?auto))
    :effect (and (not (at ?from)) (at ?to) (used ?auto))
  )

)
