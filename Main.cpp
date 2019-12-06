#include "Pokemon.h"
#include "GameCommand.h"
#include "View.h"
#include "Input_Handling.h"

int main() {
    char command; // char to store user input

    char type; // char to store type for new object creation

    bool loop = true; // boolean to keep user input switch case looping

    int id, id1, id2, x, y; // parameters for GameCommands
    unsigned int stamina_amount, unit_amount;

    Model mainModel = Model(); // Initialize the Model
    View mainView = View(); // Initialize the View

    cout << endl << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 4" << endl << endl;

    mainModel.ShowStatus(); // Print the status of all GameObjects created in the Model

    do {
        cout << endl << "Please enter a command character: ";
        cin >> command;

        try {
            switch (command) {
                case 'm':
                    cout << "Input move paramters <Pokemon ID> <X Coordinate> <Y Coordinate>: ";
                    cin >> id >> x >> y;
                    // if (!(cin >> id >> x >> y)) {
                    //     cin.ignore();
                    //     cin.clear();
                    //     throw Invalid_Input("Was expecting three integers.");
                    //     break;
                    // }
                    DoMoveCommand(mainModel, id, Point2D(x, y));                
                    break;
                case 'g':
                    cout << "Input move to Pokemon Gym parameters <Pokemon ID> <Gym ID>: ";
                    cin >> id1 >> id2;
                    // if (!(cin >> id1 >> id2)) {
                    //     throw Invalid_Input("Was expecting two integers.");
                    //     break;
                    // }
                    DoMoveToGymCommand(mainModel, id1, id2);
                    break;
                case 'c':
                    cout << "Input move to Pokemon Center parameters <Pokemon ID> <Center ID>: ";
                    cin >> id1 >> id2;
                    // if (!(cin >> id1 >> id2)) {
                    //     throw Invalid_Input("Was expecting two integers.");
                    //     break;
                    // }
                    DoMoveToCenterCommand(mainModel, id1, id2);
                    break;
                case 's':
                    cout << "Input a Pokemon's ID to stop it: ";
                    cin >> id;
                    // if (!(cin >> id)) {
                    //     throw Invalid_Input("Was expecting an integer.");
                    //     break;
                    // }
                    DoStopCommand(mainModel, id);
                    break;
                case 'r':
                    cout << "Input recover at Pokemon Center parameters <Pokemon ID> <stamina_amount>: ";
                    cin >> id1 >> stamina_amount;
                    // if (!(cin >> id1 >> stamina_amount)) {
                    //     throw Invalid_Input("Was expecting two integers.");
                    //     break;
                    // }
                    DoRecoverInCenterCommand(mainModel, id1, stamina_amount);
                    break;
                case 't':
                    cout << "Input training at Pokemon Gym parameters <Pokemon ID> <unit_amount>: ";
                    cin >> id >> unit_amount;
                    // if (!(cin >> id >> unit_amount)) {
                    //     throw Invalid_Input("Was expecting two integers.");
                    //     break;
                    // }
                    DoTrainInGymCommand(mainModel, id, unit_amount);
                    break;
                case 'v':
                    DoGoCommand(mainModel, mainView);
                    mainModel.Display(mainView);
                    break;
                case 'x':
                    DoRunCommand(mainModel, mainView);
                    break;
                case 'b':
                    cout << "Input battle parameters <Pokemon ID> <Rival ID>: ";
                    cin >> id1 >> id2;
                    // if (!(cin >> id1 >> id2)) {
                    //     throw Invalid_Input("Was expecting two integers");
                    //     break;
                    // }
                    DoStartBattle(mainModel, id1, id2);
                    break;
                case 'n':
                    cout << "Create a new object by specifying: <TYPE> <ID> <X_COORD> <Y_COORD>: ";
                    cin >> type >> id >> x >> y;
                    tolower(type);

                    // if (!(cin >> type >> id >> x >> y)) {
                    //     throw Invalid_Input("Was expecting a character followed by three integers");
                    //     break;
                    // }

                    mainModel.NewCommand(type, id, x, y);
                    break;
                default:
                    break;
            }
        } catch (Invalid_Input& except) {
            cout << "Invalid input - " << except.msg_ptr << endl;
        }

        mainModel.Display(mainView);

    } while (command != 'q');
    cout << "Exiting program." << endl;
    mainModel.~Model();
    exit(0);

    return 0;
}