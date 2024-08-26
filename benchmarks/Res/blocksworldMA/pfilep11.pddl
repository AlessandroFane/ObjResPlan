(define (problem BLOCKS-4-0) (:domain blocks)
(:objects
	a - block
	c - block
	b - block
	e - block
	d - block
	g - block
	f - block
	i - block
	h - block
	a1 - agent
	a3 - agent
	a2 - agent
)
(:init
	(handempty a1)
	(clear a)
	(clear b)
	(clear c)
	(ontable a)
	(ontable b)
	(ontable c)
)
(:goal
	(and
	(ontable a)
	(not (clear a))
	)
)
)