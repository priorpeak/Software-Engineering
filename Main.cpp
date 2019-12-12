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
    cout << "Programming Assignment 4" << endl;
    cout << "Alex Prior" << endl << endl;

    mainModel.ShowStatus(); // Print the status of all GameObjects created in the Model
    mainModel.Display(mainView); // Display the plot at the beginning of the game

    do {
        try {
        cout << endl << "Please enter a command character: ";
        if (!(cin >> command)) {
            cin.ignore(100, '\n');
            cin.clear();
            throw Invalid_Input("Invalid command.");
        }

            switch (command) {
                case 'm':
                    cout << "Input move paramters <Pokemon ID> <X Coordinate> <Y Coordinate>: ";
                    if (!(cin >> id >> x >> y)) {
                        cin.ignore(100, '\n');
                        cin.clear(); 
                        throw Invalid_Input("Expected three integers");
                        cout << endl;
                        break;
                    }
                    DoMoveCommand(mainModel, id, Point2D(x, y));                
                    break;
                case 'g':
                    cout << "Input move to Pokemon Gym parameters <Pokemon ID> <Gym ID>: ";
                    if (!(cin >> id1 >> id2)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected two integers");
                        cout << endl;
                        break;
                    }
                    DoMoveToGymCommand(mainModel, id1, id2);
                    break;
                case 'c':
                    cout << "Input move to Pokemon Center parameters <Pokemon ID> <Center ID>: ";
                    if (!(cin >> id1 >> id2)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected two integers");
                        cout << endl;
                        break;
                    }
                    DoMoveToCenterCommand(mainModel, id1, id2);
                    break;
                case 's':
                    cout << "Input a Pokemon's ID to stop it: ";
                    if (!(cin >> id)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected an integer");
                        cout << endl;
                        break;
                    }
                    DoStopCommand(mainModel, id);
                    break;
                case 'r':
                    cout << "Input recover at Pokemon Center parameters <Pokemon ID> <stamina_amount>: ";
                    if (!(cin >> id1 >> stamina_amount)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected two integers");
                        cout << endl;
                        break;
                    }
                    DoRecoverInCenterCommand(mainModel, id1, stamina_amount);
                    break;
                case 't':
                    cout << "Input training at Pokemon Gym parameters <Pokemon ID> <unit_amount>: ";
                    if (!(cin >> id >> unit_amount)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected two integers");
                        cout << endl;
                        break;
                    }
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
                    if (!(cin >> id1 >> id2)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected two integers");
                        cout << endl;
                        break;
                    }
                    DoStartBattle(mainModel, id1, id2);
                    break;
                case 'n':
                    cout << "Create a new object by specifying: <TYPE> <ID> <X_COORD> <Y_COORD>: ";
                    if (!(cin >> type >> id >> x >> y)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected a char and three integers");
                        cout << endl;
                        break;
                    }
                    tolower(type);

                    mainModel.NewCommand(type, id, x, y);
                    break;
                // A new command character for moving to a battle arena
                case 'a':
                    cout << "Input move to Battle Arena parameters <Pokemon ID> <Arena ID>: ";
                    if (!(cin >> id1 >> id2)) {
                        cin.ignore(100, '\n');
                        cin.clear();
                        throw Invalid_Input("Expected two integers");
                        cout << endl;
                        break;
                    }
                    DoMoveToArenaCommand(mainModel, id1, id2);
                    break;
                default:
                    cout << endl << "That command character does not exist, please try again." << endl << endl;
                    break;
            }
        } catch (Invalid_Input& except) {
            cout << "Invalid input - " << except.msg_ptr << endl;
        }
        if (mainModel.Update()) {
            mainModel.ShowStatus();
        }
        mainModel.Display(mainView);

    } while (command != 'q');
    cout << "Exiting program." << endl;

    return 0;
}