#include "Model.h"

// Model constructor
Model::Model() {
    time = 0;

    // Initialize the 8 game objects
    Pokemon* P1 = new Pokemon("Pikachu", 2, 20, 5, 4, 15, 'P', 1, Point2D(5, 1));
    Pokemon* P2 = new Pokemon("Bulbasaur", 3, 20, 5, 4, 20, 'P', 2, Point2D(10, 1));
    PokemonCenter* C1 = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    PokemonCenter* C2 = new PokemonCenter(2, 2, 200, Point2D(10, 20));
    PokemonGym* G1 = new PokemonGym(10, 1, 2, 3, 1, Point2D(0, 0));
    PokemonGym* G2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5, 5));
    Rival* R1 = new Rival("Jonathan", 5, 10, 3, 4, 10, 1, Point2D(10, 10));
    Rival* R2 = new Rival("Ib", 5, 12, 4, 3, 12, 2, Point2D(15, 15));

    // Assign Pokemon to their array
    pokemon_ptrs[0] = P1;
    pokemon_ptrs[1] = P2;

    // Assign Pokemon Centers to their array
    center_ptrs[0] = C1;
    center_ptrs[1] = C2;

    // Assign Pokemon Gyms to their array
    gym_ptrs[0] = G1;
    gym_ptrs[1] = G2;

    // Assign Rivals to their array
    rival_ptrs[0] = R1;
    rival_ptrs[1] = R2;

    // Assign all GameObjects to their array
    object_ptrs[0] = P1;
    object_ptrs[1] = P2;
    object_ptrs[2] = C1;
    object_ptrs[3] = C2;
    object_ptrs[4] = G1;
    object_ptrs[5] = G2;
    object_ptrs[6] = R1;
    object_ptrs[7] = R2;

    num_objects = 8;
    num_pokemon = 2;
    num_centers = 2;
    num_gyms = 2;
    num_rivals = 2;

    cout << "Model default constructed." << endl;
}

// Copy constructor
Model::Model(const Model& cpy) {
    time = cpy.time;
    num_objects = cpy.num_objects;
    num_pokemon = cpy.num_pokemon;
    num_centers = cpy.num_centers;
    num_gyms = cpy.num_gyms;

    for (int i = 0; i < num_objects; i++) {
        object_ptrs[i] = cpy.object_ptrs[i];
        pokemon_ptrs[i] = cpy.pokemon_ptrs[i];
        center_ptrs[i] = cpy.center_ptrs[i];
        gym_ptrs[i] = cpy.gym_ptrs[i];
    }
}

// Model destructor
Model::~Model() {
    for (int i = 0; i < num_objects; i++)
        delete object_ptrs[i];

    cout << "Model destructed." << endl;
}

// Lookup/Validation for Pokemon objects
Pokemon* Model::GetPokemonPtr(int id) {
    for (int i = 0; i < num_pokemon; i++) {
        if (pokemon_ptrs[i] -> GetId() == id)
            return pokemon_ptrs[i];
    }
    return 0;
}

// Lookup/Validation for PokemonCenter objects
PokemonCenter* Model::GetPokemonCenterPtr(int id) {
    for (int i = 0; i < num_centers; i++) {
        if (center_ptrs[i] -> GetId() == id)
            return center_ptrs[i];
    }
    return 0;
}

// Lookup/Validation for PokemonGym objects
PokemonGym* Model::GetPokemonGymPtr(int id) {
    for (int i = 0; i < num_gyms; i++) {
        if (gym_ptrs[i] -> GetId() == id)
            return gym_ptrs[i];
    }
    return 0;
}

// Increments time, iterates thru object_ptrs array and calls Update() for each object
bool Model::Update() {
    time++;

    for (int i = 0; i < num_gyms; i++) {
        if (gym_ptrs[i] -> IsBeaten()) {
            cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < num_pokemon; i++) {
        if (pokemon_ptrs[i] -> IsExhausted()) {
            cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < num_objects; i++)
        object_ptrs[i] -> Update();

    for (int i = 0; i < num_objects; i++) {   
        if (object_ptrs[i] -> Update())
            return true;
        else
            return false;
    }
}

// Outputs time and generates the view display for all GameObjects
void Model::Display(View& view) {
    cout << "Time: " << time << endl;
    view.Clear();

    for (int i = 0; i < num_objects; i++) {
        view.Plot(object_ptrs[i]);
    }

    view.Draw();
}

// Outputs the status of all GameObjects by calling their ShowStatus() function
void Model::ShowStatus() {
    for (int i = 0; i < num_objects; i++)
        object_ptrs[i] -> ShowStatus();
}

// Lookup/Validation for Rival objects
Rival* Model::GetRivalPtr(int id) {
    for (int i = 0; i < num_rivals; i++) {
        if (rival_ptrs[i] -> GetId() == id)
            return rival_ptrs[i];
    }
    return 0;
}