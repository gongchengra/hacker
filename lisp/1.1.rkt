#lang racket
;exe 1.1
(+ 5 3 4)
(- 9 1)
(/ 6 2)
(+ (* 2 4) (- 4 6))
(define a 3)
(define b (+ a 1))
(+ a b (* a b))
(= a b)
(if (and (> b a) (< b (* a b)))
    b
    a)
(cond ((= a 4) 6)
      ((= b 4) (+ 6 7 a))
      (else 25))
(+ 2 (if (> b a) b a))
(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1))

;exe 1.2
(/ (+ 5 
       4 
       (- 2 (- 3 (+ 6 (/ 4 5))))) 
    (* 3 
       (- 6 2) 
       (- 2 7))) 

;exe 1.3
;method 1:
(define (square x) (* x x)) 
(define (sum-of-squares x y) (+ (square x) (square y))) 
(define (sum-max2-sqr1 x y z) 
         (cond ((= (min x y z) x) (sum-of-squares y z)) 
               ((= (min x y z) y) (sum-of-squares x z)) 
               ((= (min x y z) z) (sum-of-squares x y)))) 

;method 2: 
(define (sum-max2-sqr2 x y z) 
   (if (>= x y) 
       (sum-of-squares x (if (>= y z) y z)) 
       (sum-of-squares y (if (>= x z) x z))))

;method 3:
(define (smallest-two-of-three a b c) 
   (if (< a b)  
     (if (< a c) a c) 
     (if (< b c) b c))) 
(define (sum-max2-sqr3 a b c)  
   (+ (square a) (square b) (square c) (- (square (smallest-two-of-three a b c)))))

;method 4:
(define (sum-max2-sqr4 a b c) 
   (cond ((and (<= a b) (<= a c)) (sum-of-squares b c)) 
         ((<= a b) (sum-of-squares a b)) 
         (else (sum-of-squares a c)))) 

;method 5:
(define (sum-max2-sqr5 a b c) 
   (cond ((and (<= a b) (<= a c)) (sum-of-squares b c)) 
         ((<= a b) (sum-of-squares a b)) 
         (else (sum-of-squares a c)))) 

;method 6:
(define (sum-max2-sqr6 a b c) 
   (- (+ (square a) (square b) (square c)) (square (min a b c)))) 

;method 7:
(define (sum-max2-sqr7 a b c) 
   (define (>= x y) 
     (or (> x y) (= x y))) 
   (define (square x) 
     (* x x)) 
   (cond ((and (>= a b) (>= b c)) (+ (square a) (square b))) ; a >= b >= c 
         ((and (>= b a) (>= c b)) (+ (square b) (square c))) ; a <= b <= c 
         (else (sum-max2-sqr7 b c a)))) 

;method 8:
(define (sum-max2-sqr8 a b c) 
   (+ (if (or (> a b) (> a c)) 
          (* a a ) 
          0) 
      (if (or (> b a) (> b c)) 
          (* b b ) 
          0) 
      (if (or (> c a) (> c b)) 
          (* c c ) 
          0))) 

;method 9:
(define (sum-max2-sqr9 x y z) 
         (cond 
                 ((and (>= x z) (>= y z)) (+ (* x x) (* y y))) 
                 ((and (>= x y) (>= z y)) (+ (* x x) (* z z))) 
                 ((and (>= y x) (>= z x)) (+ (* y y) (* z z))))) 

;method 10:
(define 
  (sum-max2-sqr10 a b c)   
  (cond 
    ((and (not (> c a)) (not (> c b)))  (+ (* a a) (* b b)))         
    ((and (not (> b a)) (not (> b c)))  (+ (* a a) (* c c)))         
    ((and (not (> a b)) (not (> a c)))  (+ (* b b) (* c c)))
    )
  )

;exe 1.4
(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

;calculate sqrt1
(define (sqrt1 x)
  (define (good-enough? guess x)
    (< (abs (- (square guess) x)) 0.001))
  (define (improve guess x)
    (average guess (/ x guess)))
  (define (average x y)
    (/ (+ x y) 2))
  (define (sqrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x) x)))
  (sqrt-iter 1.0 x))

;calculate sqrt2
(define (sqrt2 x)
  (define (sqrt-iter guess oldguess x) 
   (if (good-enough? guess oldguess x) 
       guess 
       (sqrt-iter (improve guess x) guess 
                  x))) 
  (define (improve guess x)
    (average guess (/ x guess)))
  (define (average x y)
    (/ (+ x y) 2))
  (define (good-enough? guess oldguess x) 
    (< (abs (- guess oldguess)) 
      (* guess 0.001)))  
   (sqrt-iter 1.0 2.0 x)) 

;calculate sqrt3
(define (sqrt3 x)
  (define (good-enough? guess)
    (< (abs (- (square guess) x)) 0.001))
  (define (improve guess)
    (average guess (/ x guess)))
  (define (average x y)
    (/ (+ x y) 2))
  (define (sqrt-iter guess)
    (if (good-enough? guess)
        guess
        (sqrt-iter (improve guess))))
  (sqrt-iter 1.0))

