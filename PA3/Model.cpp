#include "Model.h"

// Model constructor
Model::Model() {
    time = 0;

    object_ptrs[0], pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 2, Point2D(5, 1));
    object_ptrs[1], pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 1, Point2D(10, 1));
    object_ptrs[2], center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    object_ptrs[3], center_ptrs[1] = new PokemonCenter(2, 2, 200, Point2D(10, 20));
    object_ptrs[4], gym_ptrs[0] = new PokemonGym(10, 1, 2, 3, 1, Point2D(0, 0));
    object_ptrs[5], gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5, 5));

    num_objects = 6;
    num_pokemon = 2;
    num_centers = 2;
    num_gyms = 2;

    cout << "Model default constructed." << endl;
}

// Copy constructor
Model::Model(const Model& cpy) {
    time = cpy.time;
    num_objects = cpy.num_objects;
    num_pokemon = cpy.num_pokemon;
    num_centers = cpy.num_centers;
    num_gyms = cpy.num_gyms;

    for (int i = 0; i < 10; i++) {
        object_ptrs[i] = cpy.object_ptrs[i];
        pokemon_ptrs[i] = cpy.pokemon_ptrs[i];
        center_ptrs[i] = cpy.center_ptrs[i];
        gym_ptrs[i] = cpy.gym_ptrs[i];
    }
}

// Model destructor
Model::~Model() {
    for (int i = 0; i < 6; i++)
        delete object_ptrs[i];

    cout << "Model destructed." << endl;
}

// Lookup/Validation for Pokemon objects
Pokemon* Model::GetPokemonPtr(int id) {
    for (int i = 0; i < num_pokemon; i++) {
        if (pokemon_ptrs[i] -> GetId() == id)
            return pokemon_ptrs[i];
        else
            return 0;
    }
}

// Lookup/Validation for PokemonCenter objects
PokemonCenter* Model::GetPokemonCenterPtr(int id) {
    for (int i = 0; i < num_centers; i++) {
        if (center_ptrs[i] -> GetId() == id)
            return center_ptrs[i];
        else
            return 0;
    }
}

// Lookup/Validation for PokemonGym objects
PokemonGym* Model::GetPokemonGymPtr(int id) {
    for (int i = 0; i < num_gyms; i++) {
        if (gym_ptrs[i] -> GetId() == id)
            return gym_ptrs[i];
        else
            return 0;
    }
}

// Increments time, iterates thru object_ptrs array and calls Update() for each object
bool Model::Update() {
    time++;

    for (int i = 0; i < 10; i++) {
        if (gym_ptrs[i] -> IsBeaten()) {
            cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (pokemon_ptrs[i] -> IsExhausted()) {
            cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < 10; i++)
        object_ptrs[i] -> Update();

    for (int i = 0; i < 10; i++) {   
        if (object_ptrs[i] -> Update())
            return true;
        else
            return false;
    }
}

// Outputs time and generates the view display for all GameObjects
// void Model::Display(View& view) {
//     // PLACEHOLDER
// }

// Outputs the status of all GameObjects by calling their ShowStatus() function
void Model::ShowStatus() {
    for (int i = 0; i < 10; i++)
        object_ptrs[i] -> ShowStatus();
}