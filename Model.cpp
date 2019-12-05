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

    // pokemon_ptrs list
    pokemon_ptrs.push_back(P1);
    pokemon_ptrs.push_back(P2);

    // center_ptrs list
    center_ptrs.push_back(C1);
    center_ptrs.push_back(C2);

    // gym_ptrs list
    gym_ptrs.push_back(G1);
    gym_ptrs.push_back(G2);

    // rival_ptrs list
    rival_ptrs.push_back(R1);
    rival_ptrs.push_back(R2);

    // object_ptrs list
    object_ptrs.push_back(P1);
    object_ptrs.push_back(P2);
    object_ptrs.push_back(C1);
    object_ptrs.push_back(C2);
    object_ptrs.push_back(G1);
    object_ptrs.push_back(G2);
    object_ptrs.push_back(R1);
    object_ptrs.push_back(R2);

    // active_ptrs list
    active_ptrs.push_back(P1);
    active_ptrs.push_back(P2);
    active_ptrs.push_back(C1);
    active_ptrs.push_back(C2);
    active_ptrs.push_back(G1);
    active_ptrs.push_back(G2);
    active_ptrs.push_back(R1);
    active_ptrs.push_back(R2);

    cout << "Model default constructed." << endl;
}

// Copy constructor
// Model::Model(const Model& cpy) {
//     time = cpy.time;
//     num_objects = cpy.num_objects;
//     num_pokemon = cpy.num_pokemon;
//     num_centers = cpy.num_centers;
//     num_gyms = cpy.num_gyms;

//     for (int i = 0; i < num_objects; i++) {
//         object_ptrs[i] = cpy.object_ptrs[i];
//         pokemon_ptrs[i] = cpy.pokemon_ptrs[i];
//         center_ptrs[i] = cpy.center_ptrs[i];
//         gym_ptrs[i] = cpy.gym_ptrs[i];
//     }
// }

// Model destructor
Model::~Model() {
    for (list <GameObject*>::iterator obj_it = object_ptrs.begin(); obj_it != object_ptrs.end(); obj_it++) {
        object_ptrs.erase(obj_it);
    }

    cout << "Model destructed." << endl;
}

// Lookup/Validation for Pokemon objects
Pokemon* Model::GetPokemonPtr(int id) {
    for (list <Pokemon*>::iterator obj_it = pokemon_ptrs.begin(); obj_it != pokemon_ptrs.end(); obj_it++) {
        if ((*obj_it) -> GetId() == id)
            return (*obj_it);
    }
    return 0;
}

// Lookup/Validation for PokemonCenter objects
PokemonCenter* Model::GetPokemonCenterPtr(int id) {
    for (list <PokemonCenter*>::iterator obj_it = center_ptrs.begin(); obj_it != center_ptrs.end(); obj_it++) {
        if ((*obj_it) -> GetId() == id)
            return (*obj_it);
    }
    return 0;
}

// Lookup/Validation for PokemonGym objects
PokemonGym* Model::GetPokemonGymPtr(int id) {
    for (list <PokemonGym*>::iterator obj_it = gym_ptrs.begin(); obj_it != gym_ptrs.end(); obj_it++) {
        if ((*obj_it) -> GetId() == id)
            return (*obj_it);
    }
    return 0;
}

// Increments time, iterates thru object_ptrs array and calls Update() for each object
bool Model::Update() {
    time++;

    for (list <PokemonGym*>::iterator obj_it = gym_ptrs.begin(); obj_it != gym_ptrs.end(); obj_it++) {
        if ((*obj_it) -> IsBeaten()) {
            cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
            exit(0);
        }
    }

    for (list <Pokemon*>::iterator obj_it = pokemon_ptrs.begin(); obj_it != pokemon_ptrs.end(); obj_it++) {
        if ((*obj_it) -> IsExhausted()) {
            cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
            exit(0);
        }
    }

    // Update all GameObjects
    for (list <GameObject*>::iterator obj_it = active_ptrs.begin(); obj_it != active_ptrs.end(); obj_it++) {
        (*obj_it) -> Update();
    }

    // Find dead objects in the active_ptrs list
    vector <GameObject*> tempRemove;
    for (list <GameObject*>::iterator obj_it = active_ptrs.begin(); obj_it != active_ptrs.end(); obj_it++) {
        if (!(*obj_it) -> ShouldBeVisible()) {
            tempRemove.push_back(*obj_it);
            cout << "Dead object removed" << endl;
        }
    }

    // Remove dead objects from the active_ptrs list
    for (int i = 0; i < tempRemove.size(); i++) {
        active_ptrs.remove(tempRemove[i]);
    }

    // Return true if a GameObject gets updated
    for (list <GameObject*>::iterator obj_it = active_ptrs.begin(); obj_it != active_ptrs.end(); obj_it++) {
        if ((*obj_it) -> Update()) {
            return true;
        } else {
            return false;
        }
    }

    // for (int i = 0; i < num_objects; i++) {   
    //     if (object_ptrs[i] -> Update())
    //         return true;
    //     else
    //         return false;
    // }
}

// Outputs time and generates the view display for all GameObjects
void Model::Display(View& view) {
    cout << "Time: " << time << endl;
    view.Clear();

    for (list <GameObject*>::iterator obj_it = active_ptrs.begin(); obj_it != active_ptrs.end(); obj_it++) {
        view.Plot(*obj_it);
    }

    view.Draw();
}

// Outputs the status of all GameObjects by calling their ShowStatus() function
void Model::ShowStatus() {
    for (list <GameObject*>::iterator obj_it = object_ptrs.begin(); obj_it != object_ptrs.end(); obj_it++) {
        (*obj_it) -> ShowStatus();
    }
}

// Lookup/Validation for Rival objects
Rival* Model::GetRivalPtr(int id) {
    for (list <Rival*>::iterator obj_it = rival_ptrs.begin(); obj_it != rival_ptrs.end(); obj_it++) {
        if ((*obj_it) -> GetId() == id)
            return (*obj_it);
    }
    return 0;
}

// Creates new object from user input
void Model::NewCommand(char type, int id, int x, int y) {
    if (type == 'g' || type == 'c' || type == 'p' || type == 'r') {
        switch (type) {
            case 'g':
                for (list <PokemonGym*>::iterator obj_it = gym_ptrs.begin(); obj_it != gym_ptrs.end(); obj_it++) {
                    if ((*obj_it) -> GetId() == id) {
                        Invalid_Input("A Pokemon Gym with that ID already exists!");
                        return;
                    } else if (id > 9) {
                        Invalid_Input("ID values greater than 9 cannot be displayed on the grid. Please choose a single-digit ID");
                        return;
                    } else {
                        PokemonGym* id = new PokemonGym();
                        gym_ptrs.push_back(id);
                    }
                }
            case 'c':
                for (list <PokemonCenter*>::iterator obj_it = center_ptrs.begin(); obj_it != center_ptrs.end(); obj_it++) {
                    if ((*obj_it) -> GetId() == id)
                }
        }
    } else {
            throw Invalid_Input("Accepted parameters are: 'g', 'c', 'p', or 'r'.");
            return;
    }   
}