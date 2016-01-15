The function prototype is the same as `void print(const int *ia)`, which means we can pass any pointer to int to the function, not only an array of ten `int`s. This will lead to an error. We can change the parameter to a reference to array:

    void print(const int (&ia)[10]) { /* ... */ }

