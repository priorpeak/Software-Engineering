#ifndef POKEMON_H
#define POKEMON_H

#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Rival.h"

#include <stdlib.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>

enum PokemonStates {
    STOPPED = 0,
    MOVING = 1,
    EXHAUSTED = 2,
    IN_GYM = 3,
    IN_CENTER = 4,
    MOVING_TO_GYM = 5,
    MOVING_TO_CENTER = 6,
    TRAINING_IN_GYM = 7,
    RECOVERING_STAMINA = 8,
    IN_ARENA = 9,
    MOVING_TO_ARENA = 10,
    BATTLE = 11,
    FAINTED = 12
};

class Pokemon : public GameObject {
    public:
        Pokemon();
        Pokemon(char);
        Pokemon(string, int, char, unsigned int, Point2D);
        ~Pokemon();
        void StartMoving(Point2D);
        void StartMovingToCenter(PokemonCenter*);
        void StartMovingToGym(PokemonGym*);
        void StartTraining(unsigned int);
        void StartRecoveringStamina(unsigned int);
        void Stop();
        bool IsExhausted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetName();

        Pokemon(string, double, double, double, double, double, int, char, Point2D);
        bool IsAlive();
        void TakeHit(double, double, double);
        void ReadyBattle(Rival*);
        bool StartBattle();

    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D);

        double health;
        double store_health;
        double physical_damage;
        double magical_damage;
        double defense;
        Rival* target;
        bool is_in_arena = false;
        BattleArena* current_arena;

    private:
        double speed;
        bool is_in_gym = false;
        bool is_in_center = false;
        unsigned int stamina;
        unsigned int experience_points;
        double pokemon_dollars;
        unsigned int training_units_to_buy;
        unsigned int stamina_points_to_buy;
        string name;
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2D destination;
        Vector2D delta;
};

static double GetRandomAmountOfPokemonDollars();

#endif