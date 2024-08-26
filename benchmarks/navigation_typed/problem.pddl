(define (problem test) (:domain navigation)
(:objects 
    A B C - location
    car1 - car
    train1 train2 - train
    plane1 - plane
)

(:init

    (road A B car1)
    (road B C car1)

    (railway A B train1)
    (railway B C train2)

    (flight B C plane1)

    (at A)
)

(:goal (and
    (at C)
))

)
