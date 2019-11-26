#include "GameObject.h"

// Construct a GameObject
GameObject::GameObject(char in_code) {
    this -> display_code = in_code;
    this -> id_num = 1;
    this -> state = 0;

    cout << "GameObject constructed." << endl;
}

// Construct a GameObject
GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
    this -> location = in_loc;
    this -> id_num = in_id;
    this -> display_code = in_code;
    this -> state = 0;

    cout << "GameObject constructed." << endl;
}

// GameObject destructor
GameObject::~GameObject() {
    cout << "GameObject destructed." << endl;
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
char GameObject::GetState() {
    return this -> state;
}

// Returns all information contained in class
void GameObject::ShowStatus() {
    cout << this -> display_code << this -> id_num << " at " << this -> location << endl;
}

// Get function for display_code
char GameObject::GetDisplayCode() {
    return this -> display_code;
}

// Adds display_code and id_num to char pointer
void GameObject::DrawSelf(char* char_ptr) {
    *char_ptr = this -> GetDisplayCode();
    *(char_ptr + 1) = '0' + this -> GetId();
}