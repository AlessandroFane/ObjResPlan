(define (problem BW-rand-10)
  (:domain blocksworld)
  (:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 a1 a2)
  (:init
    (on b2 b1)
    (on-table b1)
	(on-table b3)
    (clear b2)
	(clear b3)
  )
  (:goal
(on b2 b3)
)
)



