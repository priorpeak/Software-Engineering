#include "Pokemon.h"

// Construct a Pokemon
Pokemon::Pokemon() : GameObject('P') {
    speed = 5;
    stamina = 20;
    state = STOPPED;
    current_center = 0;
    current_gym = 0;
    cout << "Pokemon default constructed." << endl;
}

// Construct a Pokemon
Pokemon::Pokemon(char in_code) : GameObject('P') {
    speed = 5;
    stamina = 20;
    display_code = in_code;
    state = STOPPED;
    current_center = 0;
    current_gym = 0;
    cout << "Pokemon constructed." << endl;
}

// Construct a pokemon
Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code) {
    speed = in_speed;
    name = in_name;
    stamina = 20;
    state = STOPPED;
    current_center = 0;
    current_gym = 0;
    cout << "Pokemon constructed." << endl;
}

// Pokemon destructor function
Pokemon::~Pokemon() {
    cout << "Pokemon destructed." << endl;
}

// Tells the Pokemon to start moving
void Pokemon::StartMoving(Point2D dest) {
    if (location == destination)
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
    else if (location == destination)
        cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
    else {
        cout << display_code << id_num << ": On my way to center " << center -> GetId() << endl;
        SetupDestination(center -> GetLocation());
        state = MOVING_TO_CENTER;
    }
}

// Tells the Pokemon to start moving to a PokemonGym
void Pokemon::StartMovingToGym(PokemonGym* gym) {
    if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I shouldn't be going ot the gym..." << endl;
    else if (location == destination)
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
    else if (!current_gym -> IsAbleToTrain(num_training_units, pokemon_dollars, stamina))
        cout << display_code << id_num << ": Not enough stamina and/or money for training." << endl;
    else if (current_gym -> IsBeaten())
        cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already beaten!" << endl;
    else {
        cout << display_code << id_num << ": Started to train at Pokemon Gym " << current_gym -> GetId() << " with " << training_units_to_buy << " training units." << endl;
        state = TRAINING_IN_GYM;
        training_units_to_buy = min(num_training_units, current_gym -> GetNumTrainingUnitsRemaining());
    }
}

// Tells the Pokemon to start recovering at a PokemonCenter
void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points) {
    if (!current_center -> CanAffordStaminaPoints(num_stamina_points, pokemon_dollars))
        cout << display_code << id_num << ": Not enough money to recover stamina." << endl;
    else if (!current_center -> HasStaminaPoints())
        cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center." << endl;
    else if (!is_in_center)
        cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
    else {
        state = RECOVERING_STAMINA;
        cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " << current_center -> GetId() << endl;
        stamina_points_to_buy = min(num_stamina_points, current_center -> GetNumStaminaPointsRemaining());
    }
}

// Tells the Pokemon to stop doing whatever it was doing
void Pokemon::Stop() {
    state = STOPPED;
    cout << display_code << id_num << "Stopping..." << endl;
}

// Returns true if stamina is 0
bool Pokemon::IsExhausted() {
    if (stamina == 0) {
        state = EXHAUSTED;
        return true;
    }
    else
        return false;
}

// Returns true if this pokemon is NOT exhausted
bool Pokemon::ShouldBeVisible() {
    if (state != EXHAUSTED)
        return true;
    else
        return false;
}

// Prints state specific status information
void Pokemon::ShowStatus() {
    cout << name << " status: " << endl;
    GameObject::ShowStatus();
    
    cout << "Stamina: " << stamina << endl;
    cout << "Pokemon Dollars: " << pokemon_dollars << endl;
    cout << "Experience Points: " << experience_points << endl;

    switch (state) {
        case STOPPED:
            cout << " stopped" << endl;
            break;
        case MOVING:
            cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
            cout << "Stamina: " << stamina << endl;
            cout << "Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "Experience Points: " << experience_points << endl;
            break;
        case MOVING_TO_CENTER:
            cout << " heading to Pokemon Center " << current_center -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Stamina: " << stamina << endl;
            cout << "Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "Experience Points: " << experience_points << endl;
            break;
        case MOVING_TO_GYM:
            cout << " heading to Pokemon Gym " << current_gym -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            cout << "Stamina: " << stamina << endl;
            cout << "Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "Experience Points: " << experience_points << endl;
            break;
        case IN_CENTER:
            cout << " inside Pokemon Center " << current_center -> GetId() << endl;
            cout << "Stamina: " << stamina << endl;
            cout << "Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "Experience Points: " << experience_points << endl;
            break;
        case IN_GYM:
            cout << " inside Pokemon Gym " << current_gym -> GetId() << endl;
            cout << "Stamina: " << stamina << endl;
            cout << "Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "Experience Points: " << experience_points << endl;
            break;
        case TRAINING_IN_GYM:
            cout << " training in Pokemon Gym " << current_gym -> GetId() << endl;
            cout << "Stamina: " << stamina << endl;
            cout << "Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "Experience Points: " << experience_points << endl;
            break;
        case RECOVERING_STAMINA:
            cout << " recovering stamina in Pokemon Center " << current_center -> GetId() << endl;
            cout << "Stamina: " << stamina << endl;
            cout << "Pokemon Dollars: " << pokemon_dollars << endl;
            cout << "Experience Points: " << experience_points << endl;
            break;
        default:
            break;
    }
}

// Generally returns true whenever the state is changed and false if it stays in the same state
bool Pokemon::Update() {
    switch (state) {
        case STOPPED:
            return false;
            break;
        case MOVING:
            pokemon_dollars += GetRandomAmountOfPokemonDollars();
            stamina--;
            
            if (stamina == 0) {
                Stop();
                state = EXHAUSTED;
                return true;
            }

            if (is_in_gym) {
                is_in_gym = false;
                return false;
            } else if (is_in_center) {
                is_in_center = false;
                return false;
            }

            if (UpdateLocation()) {
                Stop();
                return true;
            } else
                return false;
            break;
        case MOVING_TO_CENTER:
            pokemon_dollars += GetRandomAmountOfPokemonDollars();
            stamina--;

            if (stamina == 0) {
                Stop();
                state = EXHAUSTED;
                return true;
            }

            if (is_in_gym) {
                is_in_gym = false;
                return false;
            }

            if (UpdateLocation()) {
                state = IN_CENTER;
                is_in_center = true;
                return true;
            } else
                return false;
            break;
        case MOVING_TO_GYM:
            pokemon_dollars += GetRandomAmountOfPokemonDollars();
            stamina--;

            if (stamina == 0) {
                Stop();
                state = EXHAUSTED;
                return true;
            }

            if (is_in_center) {
                is_in_center = false;
                return false;
            } 

            if (UpdateLocation()) {
                state = IN_GYM;
                is_in_gym = true;
                return true;
            } else
                return false;
            break;
        case IN_CENTER:
            is_in_center = true;
            return false;
            break;
        case IN_GYM:
            is_in_gym = true;
            return false;
            break;
        case TRAINING_IN_GYM:
            stamina -= current_gym -> GetStaminaCost(stamina_points_to_buy);
            pokemon_dollars -= current_gym -> GetDollarCost(training_units_to_buy);
            experience_points += current_gym -> TrainPokemon(training_units_to_buy);
            cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)! **" << endl;
            cout << "** " << name << " gained " << current_gym -> TrainPokemon(training_units_to_buy) << " experience point(s)! **" << endl;
            state = IN_GYM;
            return true;
            break;
        case RECOVERING_STAMINA:
            stamina += current_center -> DistributeStamina(stamina_points_to_buy);
            pokemon_dollars -= current_center -> GetDollarCost(stamina_points_to_buy);
            cout << "** " << name << " recovered " << current_center -> DistributeStamina(stamina_points_to_buy) << " stamina point(s)! **" << endl;
            state = IN_CENTER;
            return true;
            break;
        default:
            break;
    }
}

// Updates the object's location while it is moving
bool Pokemon::UpdateLocation() {
    if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)) {
        location = destination;
        cout << display_code << id_num << ": Has arrived at its destination!" << endl;
        return true;
    } else {
        location = location + delta;
        cout << display_code << id_num << ": Has moved!" << endl;
        return false;
    }
}

// Sets up the object to start moving to dest.
void Pokemon::SetupDestination(Point2D dest) {
    destination = dest;
    Vector2D prod1 = (destination - location);
    double prod2 = (speed / GetDistanceBetween(destination, location));
    delta = prod1 * prod2;
}

// Returns a random number between 0.0 and 2.0 inclusive
static double GetRandomAmountOfPokemonDollars() {
    srand (time(NULL));
    double f = (double)rand() / 2;
    return 2 * f;
}