#include "GameObject.h"

// Construct a GameObject
GameObject::GameObject(char in_code) {
    this -> display_code = in_code;
    this -> id_num = 1;
    this -> state = 0;

    cout << "GameObject constructed" << endl;
}

// Construct a GameObject
GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
    this -> location = in_loc;
    this -> id_num = in_id;
    this -> display_code = in_code;
    this -> state = 0;

    cout << "GameObject constructed" << endl;
}

// Returns the location of this object
Point2D GameObject::GetLocation() {
    return this -> location;
}

// Returns the ID of this object
int GameObject::GetId() {
    return this -> id_num;
}

// Returns the state of this object
bool GameObject::GetState() {
    return this -> state;
}

// Returns all information contained in class
void GameObject::ShowStatus() {
    cout << this -> display_code << this -> id_num << " at " << this -> location << endl;
}