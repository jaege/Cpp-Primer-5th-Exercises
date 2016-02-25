The dynamic type of an expression that is either a reference or a pointer could be different from that expression's static type.

    class Base { /* ... */ };
    class Derived : public Base { /* ... */ };
    Derived d;
    Base *bp = &d;
    Base &br = d;
    Derived *dp = &d;
    Base *bp2 = dp;

`bp2`, `bp` and `br` have different static type and dynamic type.
