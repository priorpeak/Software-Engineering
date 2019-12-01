#include "Vector2D.h"

// Construct a Vector2D object
Vector2D::Vector2D() {
    x = 0.0;
    y = 0.0;
}

// Construct a Vector2D object
Vector2D::Vector2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

// Overloaded multiplication operator
Vector2D operator*(const Vector2D v_in, const double d) {
    Vector2D v_out;

    v_out.x = v_in.x * d;
    v_out.y = v_in.y * d;

    return v_out;
}

// Overloaded division operator
Vector2D operator/(const Vector2D v_in, const double d) {
    Vector2D v_out;

    v_out.x = v_in.x / d;
    v_out.y = v_in.y / d;

    return v_out;
}

// Overloaded output stream operator
ostream& operator<<(ostream& out, const Vector2D v_in) {
    out << "<" << v_in.x << "," << " " << v_in.y << ">";
    return out;
}