#include "GameObject.h"

using namespace std;

int main() {
    Point2D point1;
    cout << point1 << endl;

    Point2D point2(2, 4);
    cout << point2 << endl;

    double distance = GetDistanceBetween(point1, point2);
    cout << distance << endl;

    Vector2D vec1;
    cout << vec1 << endl;

    Vector2D vec2(4, 8);
    cout << vec2 << endl;

    double d = 2;

    cout << point2 + vec2 << endl;

    cout << point2 - vec2 << endl;

    Vector2D vec3(8, 12);

    cout << vec3 * d << endl;
    cout << vec3 / d << endl;

    GameObject obj1('B');
    obj1.ShowStatus();
    cout << obj1.GetState() << endl;

    return 0;
}