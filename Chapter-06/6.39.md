(a)

    int calc(int, int);
    int calc(const int, const int);  // Same with first line, top-level `const` are ignored

(b)

    int get();
    double get();  // Error, differ only on return types

(c)

    int *reset(int *);
    double *reset(double *);  // OK, define an overloaded function

