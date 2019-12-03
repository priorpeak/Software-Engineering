#include "Rival.h"

// Construct a Rival
Rival::Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc) : GameObject(in_loc, id, 'R') {
    this -> name = name;
    this -> speed = speed;
    health = hp;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    defense = def;
    state = ALIVE_RIVAL;
    // BattleArena::BattleArena()
}

// Subtracts chosen attack type's damage from the Rival's health
void Rival::TakeHit(double physical_damage, double magical_damage, double defense) {
    // Randomly chooses 1 or 0
    int damageType = rand() & 1;
    double damage = 0.0;
    if (damageType == 0) {
        damage = (100.00 - defense) / 100 * physical_damage;
    } else {
        damage = (100.00 - defense) / 100 * magical_damage;
    }
    health -= damage;
}

// Get function for Rival's physical damage
double Rival::get_phys_dmg() {
    return this -> physical_damage;
}

// Get function for Rival's magic damage
double Rival::get_magic_dmg() {
    return this -> magical_damage;
}

// Get function for Rival's defense
double Rival::get_defense() {
    return this -> defense;
}

// Get function for Rival's health
double Rival::get_health() {
    return this -> health;
}

// Updates Rival's state
bool Rival::Update() {
    if (!IsAlive() && state == ALIVE_RIVAL) {
        state = FAINTED_RIVAL;
        is_in_arena = false;
        current_arena -> RemoveRival();
        return true;
    } else {
        return false;
    }
}

// Shows the status of the Rival
void Rival::ShowStatus() {
    cout << this -> name << " status: " << endl;
    GameObject::ShowStatus();
    
    cout << "Health: " << this -> health << endl;
    switch (state) {
        case ALIVE_RIVAL:
            cout << "Rival is still alive!" << endl;
            break;
        case FAINTED_RIVAL:
            cout << "Rival has fainted!" << endl;
            break;
    }
}

// Returns true if the Rival is still alive
bool Rival::IsAlive() {
    if (state == FAINTED_RIVAL)
        return false;
    else
        return true;
}

// If Rival is alive, it should be visible
bool Rival::ShouldBeVisible() {
    if (IsAlive())
        return true;
    else
        return false;
}