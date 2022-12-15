The order of evaluation is undefined for the operator `*`, thus the expression `return factorial(val--) * val` make equal to either of the following expressions:

    // Version 1
    auto tmp = factorial(val) * val;  // evaluate second operand first
    --val;
    return tmp;

    // Version 2
    auto tmp = factorial(val);
    --val;
    return tmp * val;  // evaluate first operand first

