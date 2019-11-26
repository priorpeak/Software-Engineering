#ifndef MODEL_H
#define MODEL_H

#include "Pokemon.h"
#include "View.h"

class Model {
    public:
        Model();
        ~Model();
        Pokemon* GetPokemonPtr(int);
        PokemonCenter* GetPokemonCenterPtr(int);
        PokemonGym* GetPokemonGymPtr(int);
        bool Update();
        void Display(View& view);
        void ShowStatus();
        Model(const Model&);

    private:
        double time;
        GameObject* object_ptrs[10];
        int num_objects;
        Pokemon* pokemon_ptrs[10];
        int num_pokemon;
        PokemonCenter* center_ptrs[10];
        int num_centers;
        PokemonGym* gym_ptrs[10];
        int num_gyms;
};

#endif