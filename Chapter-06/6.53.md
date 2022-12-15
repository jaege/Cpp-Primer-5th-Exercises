(a)

    int calc(int&, int&);
    int calc(const int&, const int&);
    // OK, overloaded function takes reference to `const`

(b)

    int calc(char*, char*);
    int calc(const char*, const char*);
    // OK, overloaded function takes pointer to `const`

(c)

    int calc(char*, char*);
    int calc(char* const, char* const);
    // Error, redeclare the same function, top-level `const` is ignored

