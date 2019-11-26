#include "View.h"

// Sets default parameters for grid
View::View() {
    this -> size = 11;
    this -> scale = 2;
    this -> origin = Point2D();
}

// Resets all grid cells to background pattern
void View::Clear() {
    // Rows
    for (int i = 0; i < size; i++) {
        // Columns
        for (int j = 0; j < size; j++) {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

// Plots objects on the grid

// Could not get this to work, commented out in Main.cpp so that code would compile :(

void View::Plot(GameObject* ptr) {
    int x, y;
    char comp1 = '.';
    char comp2 = ' ';
    // cout << "out variable just declared" << endl;

    if (GetSubscripts(x, y, ptr -> GetLocation())) {
        // cout << "Get subscripts passed" << endl;
        if (grid[x][y][0] == comp1) {
            // cout << "In if statement" << endl;
            char* draw;
            ptr -> DrawSelf(draw);
            // cout << "This is draw: " << *draw << *(draw + 1) << endl;
            grid[x][y][0] = *draw;
            grid[x][y][1] = *(draw + 1);
        } else {
            grid[x][y][0] = '*';
            grid[x][y][1] = ' ';
        }
    }
}

// Outputs the grid to the display
void View::Draw() {
    // Loop from top to bottom
    for (int j = size - 1; j >= 0; j--) {
        // Loop thru row
        for (int i = -1; i < size; i++) {
            if (i == -1) {
                // Even numbered line so print axis value
                if (j % 2 == 0) {
                    if (j * scale < 10) {
                        // Single digit number so print whitespace after
                        cout << j * scale << " ";
                    } else {
                        // Double digit number so no whitespace
                        cout << j * scale;
                    }
                } else {
                    // No axis value so print two whitespaces
                    cout << "  ";
                }
            } else {
                // Print grid values
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        // Next row
        cout << endl;
    }
    // Whitespace
    cout << " ";
    for (int i = -1; i < size; i++) {
        // Even numbered line so print axis value
        if (i % 2 == 0) {
            // Single digit so add whitespace
            if (i * scale < 10) {
                cout << i * scale << " ";
            } else {
                // Double digit so no whitespace
                cout << i * scale;
            }
        } else {
            // No axis value so print two whitespaces
            cout << "  ";
        }
    }
}

// Calculates column and row subscripts of the grid array
bool View::GetSubscripts(int &out_x, int &out_y, Point2D location) {
    // cout << "In GetSubscripts" << endl;

    out_x = int((location.x - origin.x) / scale);
    out_y = int((location.y - origin.y) / scale);

    // cout << "out vars created" << out_x << out_y << endl;

    if (out_x < size * scale && out_y < size * scale)
        return true;
    else {
        cout << "An object is outside the display." << endl;
        return false;
    }
}