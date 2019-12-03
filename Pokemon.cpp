#include "Pokemon.h"

// Construct a Pokemon
Pokemon::Pokemon() : GameObject('P') {
    speed = 5;
    stamina = 20;
    state = STOPPED;
    current_center = 0;
    current_gym = 0;
    pokemon_dollars = 0;
    experience_points = 0;

    health = 20;
    store_health = 20;
    physical_damage = 5;
    magical_damage = 4;
    defense = 15;
    current_arena = 0;
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
    pokemon_dollars = 0;
    experience_points = 0;

    health = 20;
    store_health = 20;
    physical_damage = 5;
    magical_damage = 4;
    defense = 15;
    current_arena = 0;
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
    pokemon_dollars = 0;
    experience_points = 0;

    health = 20;
    store_health = 20;
    physical_damage = 5;
    magical_damage = 4;
    defense = 15;
    current_arena = 0;
    cout << "Pokemon constructed." << endl;
}

// Construct a pokemon
Pokemon::Pokemon(string in_name, double speed, double hp, double phys_damage, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc) : GameObject(in_loc, in_id, in_code) {
    this -> speed = speed;
    name = in_name;
    stamina = 20;
    state = STOPPED;
    current_center = 0;
    current_gym = 0;
    pokemon_dollars = 0;
    experience_points = 0;

    health = hp;
    store_health = 20;
    physical_damage = phys_damage;
    magical_damage = magic_dmg;
    defense = def;
    current_arena = 0;
    cout << "Pokemon constructed." << endl;
}

// Pokemon destructor function
Pokemon::~Pokemon() {
    cout << "Pokemon destructed." << endl;
}

// Tells the Pokemon to start moving
void Pokemon::StartMoving(Point2D dest) {
    if (location == destination) {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
        state = STOPPED;
    }
    else if (IsExhausted())
        cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
    else {
        cout << display_code << id_num << ": On my way." << endl;
        SetupDestination(dest);
        state = MOVING;
    }
}

// Tells the Pokemon to start moving to a PokemonCenter
void Pokemon::StartMovingToCenter(PokemonCenter* center) {
    if (this -> IsExhausted())
        cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina..." << endl;
    else if (location == destination)
        cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
    else {
        cout << display_code << id_num << ": On my way to center " << center -> GetId() << endl;
        SetupDestination(center -> GetLocation());
        current_center = center;
        state = MOVING_TO_CENTER;
    }
}

// Tells the Pokemon to start moving to a PokemonGym
void Pokemon::StartMovingToGym(PokemonGym* gym) {
    if (this -> IsExhausted())
        cout << display_code << id_num << ": I am exhausted so I shouldn't be going ot the gym..." << endl;
    else if (location == destination)
        cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
    else {
        cout << display_code << id_num << ": On my way to gym " << gym -> GetId() << endl;
        SetupDestination(gym -> GetLocation());
        current_gym = gym;
        state = MOVING_TO_GYM;
    }
}

// Tells the Pokemon to start training
void Pokemon::StartTraining(unsigned int num_training_units) {
    if (!is_in_gym)
        cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;
    else {
        if (this -> IsExhausted())
            cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl;
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
}

// Tells the Pokemon to start recovering at a PokemonCenter
void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points) {
    if (!is_in_center)
        cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
    else {
        if (!current_center -> CanAffordStaminaPoints(num_stamina_points, pokemon_dollars))
            cout << display_code << id_num << ": Not enough money to recover stamina." << endl;
        else if (!current_center -> HasStaminaPoints())
            cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center." << endl;
        else {
            state = RECOVERING_STAMINA;
            cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " << current_center -> GetId() << endl;
            stamina_points_to_buy = min(num_stamina_points, current_center -> GetNumStaminaPointsRemaining());
        }
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
    if (!this -> IsExhausted())
        return true;
    else
        return false;
}

// Prints state specific status information
void Pokemon::ShowStatus() {
    cout << this -> name << " status: " << endl;
    GameObject::ShowStatus();
    
    cout << "Stamina: " << this -> stamina << endl;
    cout << "Pokemon Dollars: " << this -> pokemon_dollars << endl;
    cout << "Experience Points: " << this -> experience_points << endl;

    switch (state) {
        case STOPPED:
            cout << " stopped" << endl;
            break;
        case MOVING:
            cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << endl;
            break;
        case MOVING_TO_CENTER:
            cout << " heading to Pokemon Center " << current_center -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case MOVING_TO_GYM:
            cout << " heading to Pokemon Gym " << current_gym -> GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
            break;
        case IN_CENTER:
            cout << " inside Pokemon Center " << current_center -> GetId() << endl;
            break;
        case IN_GYM:
            cout << " inside Pokemon Gym " << current_gym -> GetId() << endl;
            break;
        case TRAINING_IN_GYM:
            cout << " training in Pokemon Gym " << current_gym -> GetId() << endl;
            break;
        case RECOVERING_STAMINA:
            cout << " recovering stamina in Pokemon Center " << current_center -> GetId() << endl;
            break;
        default:
            break;
    }
}

// Generally returns true whenever the state is changed and false if it stays in the same state
bool Pokemon::Update() {
    switch (state) {
        case STOPPED:
            this -> ShowStatus();
            return false;
            break;
        case MOVING:
            if (this -> IsExhausted()) {
                cout << "This Pokemon is too exhausted to move." << endl;
                Stop();
                ShowStatus();
                return false;
            } else if (is_in_gym) {
                is_in_gym = false;
                current_gym -> RemoveOnePokemon();
            } else if (is_in_center) {
                is_in_center = false;
                current_center -> RemoveOnePokemon();
            } else
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                ShowStatus();
                return this -> UpdateLocation();
            break;
        case MOVING_TO_CENTER:
            if (this -> IsExhausted()) {
                cout << "This Pokemon is too exhausted to move." << endl;
                Stop();
                ShowStatus();
                return false;
            } else if (is_in_gym) {
                is_in_gym = false;
                current_gym -> RemoveOnePokemon();
                return false;
            } else
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                ShowStatus();
                if (UpdateLocation()) {
                    state = IN_CENTER;
                    is_in_center = true;
                    current_center -> AddOnePokemon();
                    return true;
                } else {
                    return false;
                }
            break;
        case MOVING_TO_GYM:
            if (this -> IsExhausted()) {
                cout << "This Pokemon is too exhausted to move." << endl;
                Stop();
                ShowStatus();
                return false;
            } else if (is_in_center) {
                is_in_center = false;
                current_center -> RemoveOnePokemon();
                return false;
            } else if (is_in_arena) {
                is_in_arena = false;
                current_arena -> RemoveOnePokemon();
                return false;
            } else
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                ShowStatus();
                if (UpdateLocation()) {
                    state = IN_GYM;
                    is_in_gym = true;
                    current_gym -> AddOnePokemon();
                    return true;
                } else {
                    return false;
                }
            break;
        case IN_CENTER:
            ShowStatus();
            return false;
            break;
        case IN_GYM:
            ShowStatus();
            return false;
            break;
        case TRAINING_IN_GYM:
            ShowStatus();
            stamina -= current_gym -> GetStaminaCost(stamina_points_to_buy);
            pokemon_dollars -= current_gym -> GetDollarCost(training_units_to_buy);
            experience_points += current_gym -> TrainPokemon(training_units_to_buy);
            cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)! **" << endl;
            cout << "** " << name << " gained " << current_gym -> TrainPokemon(training_units_to_buy) << " experience point(s)! **" << endl;
            state = IN_GYM;
            return true;
            break;
        case RECOVERING_STAMINA:
            ShowStatus();
            stamina += current_center -> DistributeStamina(stamina_points_to_buy);
            pokemon_dollars -= current_center -> GetDollarCost(stamina_points_to_buy);
            cout << "** " << name << " recovered " << current_center -> DistributeStamina(stamina_points_to_buy) << " stamina point(s)! **" << endl;
            state = IN_CENTER;
            return true;
            break;
        case FAINTED:
            ShowStatus();
            return false;
            break;
        case MOVING_TO_ARENA:
            if (this -> IsExhausted()) {
                cout << "This Pokemon is too exhausted to move." << endl;
                Stop();
                ShowStatus();
                return false;
            } else if (is_in_center) {
                is_in_center = false;
                current_center -> RemoveOnePokemon();
                return false;
            } else if (is_in_gym) {
                is_in_gym = false;
                current_gym -> RemoveOnePokemon();
                return false;
            } else
                stamina--;
                pokemon_dollars += GetRandomAmountOfPokemonDollars();
                ShowStatus();
                if (UpdateLocation()) {
                    state = IN_ARENA;
                    is_in_arena = true;
                    current_arena -> AddOnePokemon();
                    return true;
                } else {
                    return false;
                }
            break;
        case BATTLE:
            stamina -= current_arena -> GetStaminaCost();
            pokemon_dollars -= current_arena -> GetDollarCost();
            StartBattle();
            if (this -> health > 0) {
                this -> health = store_health;
                state = IN_ARENA;
                target -> IsAlive();
            } else {
                state = FAINTED;
                target -> IsAlive();
            }
        default:
            state = STOPPED;
            return false;
            break;
    }
}

// Get function for the Pokemon's name
string Pokemon::GetName() {
    return this -> name;
}

// Updates the object's location while it is moving
bool Pokemon::UpdateLocation() {
    if ((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y))) {
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
    double f = (double)rand() / RAND_MAX;
    return 0 + f * (2 - 0);
}

// Returns true if state is not 'FAINTED'
bool Pokemon::IsAlive() {
    if (state == 'FAINTED')
        return false;
    else
        return true;
}

// Subtracts chosen attack type's damage from the Pokemon's health
void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense) {
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

// if the pokemon is in an arena and the arena is not beaten, set the state to 'BATTLE'
void Pokemon::ReadyBattle(Rival *in_target) {
    if (state == 'IN_ARENA' && current_arena -> IsAbleToFight() && !current_arena -> IsBeaten() && in_target -> IsAlive()) {
        target = in_target;
        state = 'BATTLE';
    } else {
        state = 'IN_ARENA';
    }
}

// Calls TakeHit() until the Pokemon or its Rival faint
bool Pokemon::StartBattle() {
    // While the Pokemon and Rival both have health greater than zero, allow them to attack (Rival hits first)
    do {
        this -> TakeHit(target -> get_phys_dmg(), target -> get_magic_dmg(), target -> get_defense());
        // If the Pokemon faints first, break the loop
        if (this -> health <= 0) {
            return false;
        }
        target -> TakeHit(this -> physical_damage, this -> magical_damage, this -> defense);
    } while (target -> get_health() > 0);

    return true;
}