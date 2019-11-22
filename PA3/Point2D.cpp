#include "Point2D.h"

// Construct a Point2D object
Point2D::Point2D() {
    x = 0.0;
    y = 0.0;
}

// Construct a Point2D object
Point2D::Point2D(double in_x, double in_y) {
    x = in_x;
    y = in_y;
}

// Returns ordinary distance between p1 and p2
double GetDistanceBetween(Point2D p1, Point2D p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

// Overloaded output stream operator
ostream& operator<<(ostream& out, const Point2D p_in) {
    out << "(" << p_in.x << ", " << p_in.y << ")";
    return out;
}

// Overloaded addition operator
Point2D operator+(const Point2D p_in, const Vector2D v_in) {
    Point2D p_out;

    p_out.x = p_in.x + v_in.x;
    p_out.y = p_in.y + v_in.y;

    return p_out;
}

// Overloaded subtraction operator
Vector2D operator-(const Point2D p_in1, const Point2D p_in2) {
    Vector2D v_out;

    v_out.x = p_in1.x - p_in2.x;
    v_out.y = p_in1.y - p_in2.y;

    return v_out;
}

// Overloaded comparison operator
bool operator==(const Point2D p_in1, const Point2D p_in2) {
    if (p_in1.x == p_in2.x && p_in1.y == p_in2.y)
        return true;
    else
        return false;
}