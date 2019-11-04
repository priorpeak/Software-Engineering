#include "PokemonCenter.h"

// Construct a PokemonCenter
PokemonCenter::PokemonCenter() : Building() {
    this -> display_code = 'C';
    this -> stamina_capacity = 100;
    this -> num_stamina_points_remaining = stamina_capacity;
    this -> dollar_cost_per_stamina_point = 5;
    this -> state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

// Construct a PokemonCenter
PokemonCenter::PokemonCenter(int in_id, Point2D in_loc) : Building('C', in_id, in_loc) {
    this -> stamina_capacity = 100;
    this -> num_stamina_points_remaining = stamina_capacity;
    this -> dollar_cost_per_stamina_point = 5;
    this -> state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
}

// Returns true if PokemonCenter has at least one stamina point
bool PokemonCenter::HasStaminaPoints() {
    if (this -> num_stamina_points_remaining > 0)
        return true;
    else
        return false;
}

// Returns the number of stamina points remaining in the PokemonCenter
unsigned int PokemonCenter::GetNumStaminaPointsRemaining() {
    return num_stamina_points_remaining;
}

// Returns true if this Pokemon can afford to purchase stamina_points with the given budget
bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget) {
    
}