#include "PokemonGym.h"

// Construct a PokemonGym
PokemonGym::PokemonGym() : Building() {
    this -> display_code = 'G';
    this -> state = NOT_BEATEN;
    this -> max_number_of_training_units = 10;
    this -> num_training_units_remaining = this -> max_number_of_training_units;
    this -> stamina_cost_per_training_unit = 1;
    this -> dollar_cost_per_training_unit = 1.0;
    this -> experience_points_per_training_unit = 2;
    cout << "PokemonGym default constructed" << endl;
}

// Construct a PokemonGym
PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building() {
    display_code = 'G';
    this -> id_num = in_id;
    this -> max_number_of_training_units = max_training_units;
    num_training_units_remaining = max_number_of_training_units;
    this -> stamina_cost_per_training_unit = stamina_cost;
    this -> experience_points_per_training_unit = exp_points_per_unit;
    this -> dollar_cost_per_training_unit = dollar_cost;
    this -> location = in_loc;
    cout << "PokemonGym constructed" << endl;
}

// PokemonGym destructor
PokemonGym::~PokemonGym() {
    cout << "PokemonGym destructed." << endl;
}

// Returns the cost of purchasing "unit_qty" training units
double PokemonGym::GetDollarCost(unsigned int unit_qty) {
    return unit_qty * this -> dollar_cost_per_training_unit;
}

// Returns the amount of stamina required for "unit_qty" training units
unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty) {
    return unit_qty * this -> stamina_cost_per_training_unit;
}

// Returns the number of training units remaining in this PokemonGym
unsigned int PokemonGym::GetNumTrainingUnitsRemaining() {
    return this -> num_training_units_remaining;
}

// Returns true if a Pokemon with a given budget and stamina can request to train unit_qty training units, or false otherewise
bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina) {
    if (budget > unit_qty * stamina)
        return true;
    else
        return false;
}

// Returns number of experience points gained by completing the training units
unsigned int PokemonGym::TrainPokemon(unsigned int training_units) {
    if (num_training_units_remaining > training_units)
        return (num_training_units_remaining - training_units) * experience_points_per_training_unit;
    else {
        unsigned int experience = num_training_units_remaining * experience_points_per_training_unit;
        num_training_units_remaining = 0;
        return experience;
    }
}

// Updates status of whether gym has been beaten or not
bool PokemonGym::Update() {
    if (num_training_units_remaining == 0 && state != BEATEN) {
        state = BEATEN;
        display_code = 'g';
        cout << display_code << id_num << " has been beaten" << endl;  
        return true;  
    } else {
        return false;
    }
}

// Returns true if training units remaining is 0
bool PokemonGym::IsBeaten() {
    if (num_training_units_remaining == 0)
        return true;
    else
        return false;
}

// Prints status of this GameObject and its member variables
void PokemonGym::ShowStatus() {
    cout << "Pokemon Gym Status: " << endl;
    Building::ShowStatus();
    cout << "Max number of training units: " << max_number_of_training_units << endl;
    cout << "Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
    cout << "Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
    cout << "Experience points per training unit: " << experience_points_per_training_unit << endl;
    cout << num_training_units_remaining << " training unit(s) are remaining for this gym" << endl;
}