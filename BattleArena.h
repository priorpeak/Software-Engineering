#ifndef BATTLEARENA_H
#define BATTLEARENA_H

#include "Building.h"

enum BattleArenaStates {
    RIVALS_AVAILABLE = 0,
    NO_RIVALS_AVAILABLE = 1
};

class BattleArena : public Building {
    public:
        BattleArena();
        BattleArena(unsigned int, unsigned int, double, int, Point2D);
        unsigned int GetNumRivalsRemaining();
        bool HasEnoughRivals();
        double GetDollarCost();
        unsigned int GetStaminaCost();
        bool IsAbleToFight(double, unsigned int);
        bool Update();
        bool IsBeaten();
        void ShowStatus();
        void RemoveRival();
    private:
        unsigned int max_num_rivals;
        unsigned int num_rivals_remaining;
        double dollar_cost_per_fight;
        unsigned int stamina_cost_per_fight;
        unsigned int pokemon_count;
};

#endif