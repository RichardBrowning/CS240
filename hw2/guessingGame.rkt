#lang racket
; this is the racket version of the CS240 hw2
; Kristopher Mensing
; Fall 2016
; Number guessing assignment "black belt" option
; IUPUI
(define maximum_value 100)
(define minimum_value 1)
(define guessed_value (random minimum_value maximum_value))
(define count empty)

(define (guess_function low high)
  (define new_guess (random low high))
  (cons 1 count)
  (write "My guess is: ")
  (write new_guess)
  (newline)
  (write "Is my guess low, high, or correct?")
  (newline)
  (define high_low_or_correct (read-line))
  (case high_low_or_correct
       [("high") (guess_function (- high low))]
       [("low") (guess_function new_guess high)]
       [("correct") (write "wohoo")]
       [else (write "incorrect input")]))

(guess_function minimum_value maximum_value)
      