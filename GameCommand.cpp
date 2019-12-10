#include "GameCommand.h"

// Starts moving a pokemon
void DoMoveCommand(Model& model, int pokemon_id, Point2D p1) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        cout << "Moving " << poke1 -> GetName() << " to " << p1 << endl;
        poke1 -> StartMoving(p1);
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// Starts moving a pokemon to a Pokemon Center
void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        cout << "Moving " << poke1 -> GetName() << " to center " << center_id << endl;
        poke1 -> StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// Starts moving a pokemon to a Arena
void DoMoveToArenaCommand(Model& model, int pokemon_id, int arena_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        cout << "Moving " << poke1 -> GetName() << " to arena " << arena_id << endl;
        poke1 -> StartMovingToArena(model.GetBattleArenaPtr(arena_id));
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// Starts moving a pokemon to a Pokemon Gym
void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        cout << "Moving " << poke1 -> GetName() << " to gym " << gym_id << endl;
        poke1 -> StartMovingToGym(model.GetPokemonGymPtr(gym_id));
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// Stops the pokemon
void DoStopCommand(Model& model, int pokemon_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        cout << "Stopping " << poke1 -> GetName() << endl;
        poke1 -> Stop();
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// Starts training a pokemon in a gym
void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        cout << "Training " << poke1 -> GetName() << endl;
        poke1 -> StartTraining(training_units);
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// Starts recovering a pokemon in a Pokemon Center
void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        cout << "Recovering " << poke1 -> GetName() << "'s stamina" << endl;
        poke1 -> StartRecoveringStamina(stamina_points);
    } else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// Advances one tick
void DoGoCommand(Model& model, View& view) {
    cout << "Advancing one tick." << endl;
    model.Update();
}

// Advances one tick
void DoRunCommand(Model& model, View& view) {
    cout << "Advancing to next event." << endl;
    int counter = 0;
    while (!model.Update() && counter < 6)
        counter++;
}

// Starts a battle in the arena
void DoStartBattle(Model& model, int pokemon_id, int rival_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetRivalPtr(rival_id) != 0) {
        Pokemon* poke1 = model.GetPokemonPtr(pokemon_id);
        Rival* rival1 = model.GetRivalPtr(rival_id);
        cout << "Preparing to fight!" << endl;
        poke1 -> ReadyBattle(rival1);
    } else {
        cout << "Invalid pokemon and/or rival IDs." << endl;
    }
}