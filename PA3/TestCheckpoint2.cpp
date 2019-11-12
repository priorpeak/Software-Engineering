#include "PokemonCenter.h"
#include "PokemonGym.h"

void printBanner(const char*);

int main ()
{
    // points to use as locations for testing objects
    Point2D p1(1.79, 5.62);
    Point2D p2;

    // checkpoint 2
    // printBanner("skyline.txt");

    cout << endl << "Center Examples: " << endl;
    
    PokemonCenter C1; // default pokemon center
    C1.ShowStatus();

    cout << endl << "*****" << endl << endl;

    PokemonCenter C2(2, p1); // non default
    C2.ShowStatus();

    cout << endl << "*****" << endl << endl;

    C2.DistributeStamina(C2.GetNumStaminaPointsRemaining()); // empty all stamina
    C2.Update();
    C2.ShowStatus();

    cout << endl << "Gym Examples: " << endl;
    PokemonGym G1;
    PokemonGym G2(100, 2, 4, 3, 2, Point2D(1.34, 6.57));

    cout << endl << "G2 Status:" << endl;
    G2.ShowStatus();

    cout << endl << "Remove all G2 training capacity..." <<endl;
    G2.TrainPokemon(G2.GetNumTrainingUnitsRemaining());

    if (G2.IsBeaten()) {
        G2.Update();
    }
    cout << endl << "After training to max capacity:" << endl;
    G2.ShowStatus();

    cout << "*******" << endl;
    G2.AddOnePokemon();
    G2.AddOnePokemon();
    G2.AddOnePokemon();
    G2.ShowStatus();
    
    return 0;
}

// void printBanner(const char* fileName)
// {
//     // prints ascii file based on string file name input
//     ifstream readFile;
//     readFile.open(fileName);

//     string line;
//     while (getline(readFile, line)) {
//         cout << line << endl;
//     }

// }
