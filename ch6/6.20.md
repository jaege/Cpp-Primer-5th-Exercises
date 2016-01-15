If the reference parameters will not be changed inside function, then they should be reference to `const`.

If we make a parameter a plain reference, then we can not pass
  - a `const` object,
  - or a literal,
  - or an object that requires conversion
to a plain reference parameter.
