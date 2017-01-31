(print "Hello")

(define count
  (let ((c 0))
    (lambda ()
      (inc! c)
      c)))
