// (a) Graphical file formats (such as gif, tiff, jpeg, bmp)

// (b) Geometric primitives (such as box, circle, sphere, cone)

class Shape_base { };
class Shape2D_base : public Shape_base { };
class Shape3D_base : public Shape_base { };
class Circle : public Shape2D_base { };
class Ellipse : public Shape2D_base { };
class Square : public Shape2D_base { };
class Rectangle : public Shape2D_base { };
class Sphere : public Shape3D_base { };
class Cube : public Shape3D_base { };
class Box : public Shape3D_base { };
class Cone : public Shape3D_base { };

// (c) C++ language types (such as class, function, member function)


// Reference:
// [Circle-ellipse problem](https://en.wikipedia.org/wiki/Circle-ellipse_problem)
