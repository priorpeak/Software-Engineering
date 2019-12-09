#ifndef RIVAL_H
#define RIVAL_H

#include "BattleArena.h"

enum RivalStates {
    ALIVE_RIVAL = 0,
    FAINTED_RIVAL = 1
};

class Rival : public GameObject {
    public:
        Rival(string, double, double, double, double, double, int, Point2D, BattleArena*);
        void TakeHit(double, double, double);
        double get_phys_dmg();
        double get_magic_dmg();
        double get_defense();
        double get_health();
        bool Update();
        void ShowStatus();
        bool IsAlive();
        bool ShouldBeVisible();

    protected:
        double health;
        double physical_damage;
        double magical_damage;
        double defense;
        bool is_in_arena;
        BattleArena* current_arena;
        string name;
        double speed;
        BattleArena* battle_arena_pointer;
};

#endif