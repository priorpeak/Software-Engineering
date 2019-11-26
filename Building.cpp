#include "Building.h"

// Construct a Building
Building::Building() : GameObject('B') {
    this -> pokemon_count = 0;
    cout << "Building default constructed" << endl;
}

// Construct a Building
Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code) {
    this -> display_code = in_code;
    this -> id_num = in_id;
    this -> location = in_loc;
    this -> pokemon_count = 0;
    cout << "Building constructed" << endl;
}

// Increment pokemon_count by one
void Building::AddOnePokemon() {
    this -> pokemon_count++;
}

// Decrement pokemon_count by one
void Building::RemoveOnePokemon() {
    this -> pokemon_count--;
}

// Shows how many pokemon are in the Building
void Building::ShowStatus() {
    cout << this -> pokemon_count << " pokemon";
    if (this -> pokemon_count == 1)
        cout << " is ";
    else
        cout << " are ";
    cout << "in this building" << endl;
}

// Returns true when buildings are visible (Should always be true)
bool Building::ShouldBeVisible() {
    return true;
}