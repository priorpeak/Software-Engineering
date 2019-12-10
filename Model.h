#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <iterator>
#include <vector>

#include "Pokemon.h"
#include "View.h"
#include "Input_Handling.h"

class Model {
    public:
        Model();
        ~Model();
        Pokemon* GetPokemonPtr(int);
        PokemonCenter* GetPokemonCenterPtr(int);
        BattleArena* GetBattleArenaPtr(int);
        PokemonGym* GetPokemonGymPtr(int);
        bool Update();
        void Display(View& view);
        void ShowStatus();
        // Model(const Model&);

        Rival* GetRivalPtr(int);
        void NewCommand(char, int, int, int);

    private:
        double time;
        list <GameObject*> object_ptrs;
        list <GameObject*> active_ptrs;
        list <Pokemon*> pokemon_ptrs;
        list <PokemonCenter*> center_ptrs;
        list <PokemonGym*> gym_ptrs;
        list <Rival*> rival_ptrs;
        list <BattleArena*> arena_ptrs;
};

#endif