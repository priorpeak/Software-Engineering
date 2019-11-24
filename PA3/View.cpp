#include "View.h"

// Sets default parameters for grid
View::View() {
    size = 11;
    scale = 2;
    origin = Point2D(0, 0);
}

// Resets all grid cells to background pattern
void View::Clear() {
    // Rows
    for (int i = 0; i < size; i++) {
        // Columns
        for (int j = 0; j < size; j++) {
            if (counter % 2)
                grid[i][j][0] = '.';
            else
                grid[i][j][0] = ' ';
        }
    }
}

// Plots objects on the grid
void View::Plot(GameObject* ptr) {
    if (GetSubscripts(out_x, out_y, ptr -> GetLocation())) {
        ptr -> DrawSelf(grid);
    }
}

// Outputs the grid to the display
void View::Draw() {
    
}

// Calculates column and row subscripts of the grid array
bool View::GetSubscripts(int &out_x, int &out_y, Point2D location) {
    out_x = (location.x - origin.x) / scale;
    out_y = (location.y - origin.y) / scale;

    if (out_x <= view_maxsize && out_y <= view_maxsize)
        return true;
    else {
        cout << "An object is outside the display." << endl;
        return false;
    }
}