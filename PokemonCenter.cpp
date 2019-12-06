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
PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc) : Building('C', in_id, in_loc) {
    this -> stamina_capacity = stamina_cap;
    this -> num_stamina_points_remaining = stamina_capacity;
    this -> dollar_cost_per_stamina_point = stamina_cost;
    this -> state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
}

// PokemonCenter destructor
PokemonCenter::~PokemonCenter() {
    cout << "PokemonCenter destructed." << endl;
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
    return this -> num_stamina_points_remaining;
}

// Returns true if this Pokemon can afford to purchase stamina_points with the given budget
bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget) {
    if (this -> num_stamina_points_remaining * dollar_cost_per_stamina_point < budget)
        return true;
    else
        return false;
}

// Returns the Pokemon dollar cost for the specified number of stamina points
double PokemonCenter::GetDollarCost(unsigned int stamina_points) {
    return stamina_points * dollar_cost_per_stamina_point;
}

// Checks amount of stamina points remaining in PokemonCenter and distributes as needed
unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed) {
    if (this -> num_stamina_points_remaining >= points_needed) {
        this -> num_stamina_points_remaining -= points_needed;
        return points_needed;
    } else {
        unsigned int num_stamina_points_remaining_temp = this -> num_stamina_points_remaining;
        this -> num_stamina_points_remaining = 0;
        return num_stamina_points_remaining_temp;
    }
}

// Checks how many stamina points are available in the PokemonCenter
bool PokemonCenter::Update() {
    if (num_stamina_points_remaining == 0 && state != NO_STAMINA_POINTS_AVAILABLE) {
        this -> state = NO_STAMINA_POINTS_AVAILABLE;
        this -> display_code = 'c';
        cout << "PokemonCenter " << id_num << " has run out of stamina points." << endl;
        return true;
    } else {
        return false;
    }
}

// Prints the status of the object
void PokemonCenter::ShowStatus() {
    cout << "Pokemon Center Status: " << endl;
    Building::ShowStatus();
    cout << this -> display_code << this -> id_num << " located at " << this -> location << endl;
    cout << "Pokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
    cout << "Has " << num_stamina_points_remaining << " stamina point(s) remaining." << endl << endl;
}