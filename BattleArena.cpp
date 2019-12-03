#include "BattleArena.h"

// Default BattleArena constructor
BattleArena::BattleArena() {
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena default constructed." << endl;
}

// BattleArena constructor
BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc) : Building('A', in_id, in_loc) {
    max_num_rivals = max_rivals;
    stamina_cost_per_fight = stamina_cost;
    dollar_cost_per_fight = dollar_cost;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena constructed." << endl;
}

// Returns number of Rivals remaining in this BattleArena
unsigned int BattleArena::GetNumRivalsRemaining() {
    return num_rivals_remaining;
}

// Returns true if this BattleArena contains at least one Rival
bool BattleArena::HasEnoughRivals() {
    if (num_rivals_remaining > 0)
        return true;
    else
        return false;
}

// Returns the cost of one battle in this BattleArena
double BattleArena::GetDollarCost() {
    return dollar_cost_per_fight;
}

// Returns the amount of stamina required for battle
unsigned int BattleArena::GetStaminaCost() {
    return stamina_cost_per_fight;
}

// Returns true if Pokemon has enough PokemonDollars and stamina to fight
bool BattleArena::IsAbleToFight(double budget, unsigned int stamina) {
    if (budget >= dollar_cost_per_fight && stamina >= stamina_cost_per_fight)
        return true;
    else
        return false;
}

// Returns false if rivals still remain within the BattleArena
bool BattleArena::Update() {
    if (num_rivals_remaining == 0 && state != NO_RIVALS_AVAILABLE) {
        state = NO_RIVALS_AVAILABLE;
        display_code = 'a';
        cout << display_code << id_num << " has no rivals available!" << endl;
        return true;
    } else {
        return false;
    }
}

// Returns true if BattleArena has been beaten
bool BattleArena::IsBeaten() {
    if (num_rivals_remaining == 0)
        return true;
    else
        return false;
}

// Prints the status of this BattleArena
void BattleArena::ShowStatus() {
    cout << "BattleArena status: " << endl;
    GameObject::ShowStatus();
    Building::ShowStatus();
    cout << "Max number of rivals: " << max_num_rivals << endl;
    cout << "Stamina cost per fight: " << stamina_cost_per_fight << endl;
    cout << "Pokemon dollar per fight: " << dollar_cost_per_fight << endl;
    cout << num_rivals_remaining << " rival(s) are remaining for this arena." << endl;
}

// Removes a rival from the BattleArena if it has fainted
void BattleArena::RemoveRival() {
    num_rivals_remaining--;
}