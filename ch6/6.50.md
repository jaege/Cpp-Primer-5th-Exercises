(a) `f(2.56, 42)` is illegal. The call is ambiguous, because either `f(int, int)` or `f(double, double)` is a better match than the other on one of the arguments to the call.

(b) `f(42)` has a best match function `f(int)`.
(c) `f(42, 0)` has a best match function `f(int, int)`.
(d) `f(2.56, 3.14)` has a best match function `f(double, double)`.
