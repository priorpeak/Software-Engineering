#include "Pokemon.h"

// Construct a Pokemon
Pokemon::Pokemon() : GameObject('P') {
    speed = 5;
    cout << "Pokemon default constructed." << endl;
}

// Construct a Pokemon
Pokemon::Pokemon(char in_code) : GameObject('P') {
    speed = 5;
    display_code = in_code;
    state = STOPPED;
    cout << "Pokemon constructed." << endl;
}

// Construct a pokemon
Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code) {
    speed = in_speed;
    name = in_name;
    cout << "Pokemon constructed." << endl;
}

// Tells the Pokemon to start moving
void Pokemon::StartMoving(Point2D dest) {
    if (UpdateLocation())
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
    else {
        cout << display_code << id_num << ": On my way." << endl;
        SetupDestination(dest);
        state = MOVING;
    }
}

// Tells the Pokemon to start moving to a PokemonCenter
void Pokemon::StartMovingToCenter(PokemonCenter* center) {
    if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina..." << endl;
    else if (UpdateLocation())
        cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
    else {
        cout << display_code << id_num << ": On my way to center " << center -> id_num << endl;
        SetupDestination(center -> GetLocation());
        state = MOVING_TO_CENTER;
    }
}

// Tells the Pokemon to start moving to a PokemonGym
void Pokemon::StartMovingToGym(PokemonGym* gym) {
    if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I shouldn't be going ot the gym..." << endl;
    else if (UpdateLocation())
        cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
    else {
        cout << display_code << id_num << ": On my way to gym " << gym -> GetId() << endl;
        SetupDestination(gym -> GetLocation());
        state = MOVING_TO_GYM;
    }
}

// Tells the Pokemon to start training
void Pokemon::StartTraining(unsigned int num_training_units) {
    if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl;
    else if (!is_in_gym)
        cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;
    else if (stamina == 0 || pokemon_dollars == 0)
        cout << display_code << id_num << ": Not enough stamina and/or money for training." << endl;
    else if (current_gym -> IsBeaten())
        cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already beaten!" << endl;
    else {
        cout << display_code << id_num << ": Started to train at Pokemon Gym " << current_gym -> GetId() << " with " << current_gym -> GetNumTrainingUnitsRemaining << " training units." << endl;
        state = TRAINING_IN_GYM;
        training_units_to_buy = min(num_training_units, current_gym -> GetNumTrainingUnitsRemaining());
    }
}

// Tells the Pokemon to start recovering at a PokemonCenter
