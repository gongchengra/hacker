sicp notes

(define (abs x)
(cond ((> x 0) x)
((= x 0) 0)
((< x 0) (- x))))

(define (abs x)
(cond ((< x 0) (- x))
(else x)))

(define (abs x)
(if (< x 0)
(- x)
x))

(and ⟨e1⟩ . . . ⟨en⟩)

(or ⟨e1⟩ . . . ⟨en⟩)

(not ⟨e⟩)

(and (> x 5) (< x 10))

(define (>= x y) (or (> x y) (= x y)))

(define (>= x y) (not (< x y)))

(define a 3)
(define b (+ a 1))
(if (and (> b a) (< b (* a b))) b a)
(cond ((= a 4) 6)((= b 4)(+ 6 7 a))(else 25))
(+ 2 (if (> b a) b a))
(* (cond ((> a b) a)((< a b) b)(else -1))(+ a 1))

(define (p) (p))
(define (test x y)
(if (= x 0) 0 y))

(define (sqrt-iter guess x)
(if (good-enough? guess x)
guess
(sqrt-iter (improve guess x) x)))

(define (improve guess x)
(average guess (/ x guess)))

(define (average x y)
(/ (+ x y) 2))

(define (good-enough? guess x)
(< (abs (- (square guess) x)) 0.001))

(define (sqrt x)
(sqrt-iter 1.0 x))

(define (sqrt x)
	(define (good-enough? guess x)
	(< (abs (- (square guess) x)) 0.001))
	(define (improve guess x) (average guess (/ x guess)))
	(define (sqrt-iter guess x)
	(if (good-enough? guess x)
	guess
	(sqrt-iter (improve guess x) x)))
(sqrt-iter 1.0 x))

(define (factorial n)
	(if (= n 1)
	1
	(* n (factorial (- n 1)))))

(define (factorial n)
(define (iter product counter)
(if (> counter n)
product
(iter (* counter product)
(+ counter 1))))
(iter 1 1))

(define (fib n)
(cond ((= n 0) 0)
((= n 1) 1)
(else (+ (fib (- n 1))
(fib (- n 2))))))

(define (fib n)
(fib-iter 1 0 n))
(define (fib-iter a b count)
(if (= count 0)
b
(fib-iter (+ a b) a (- count 1))))

(define (fib n)
	(define (fib-iter a b count)
(if (= count 0)
b
(fib-iter (+ a b) a (- count 1))))
	(fib-iter 1 0 n)
	)

(define cube (lambda (x) (* x x x)))
(define (cube x) (* x x x))
(define average (lambda (x y) (/ (+ x y) 2)))
(define (average x y) (/ (+ x y) 2))

(define (sum term a next b)
	(if (> a b)
		0
		(+ (term a)
			(sum term 
				(next a)
				next
				b))))

(define (sum-int a b)
	(define (id x) x)
	(sum id a 1+ b))

(define (sum-sq a b)
	(sum square a 1+ b))

(define (pi-sum a b)
	(sum (lambda (i) (/ i (* i (+ i 2))))
		a
		(lambda (i) (+ i 4))
		b))
