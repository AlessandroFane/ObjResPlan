(define (problem test) (:domain navigation)
(:objects 
    A B C D E - location
    car1 car2 car3 - car
    train1 train2 train3 - train
    plane1 plane2 plane3 - plane
)

(:init

    (road A B car1)
    (road B C car2)
	(road C D car3)
    (railway A B train1)
    (railway C E train2)
	(railway D E train3)
    (flight B D plane1)
	(flight C E plane2)
	(flight D E plane3)

    (at A)
)

(:goal (and
    (at E)
))

)
