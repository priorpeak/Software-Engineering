#ifndef VIEW_H
#define VIEW_H

#include "Pokemon.h"

const int view_maxsize = 20;
int counter = 0;

class View {
    public:
        View();
        void Clear();
        void Plot(GameObject*);
        void Draw();
    private:
        int size;
        double scale;
        Point2D origin;
        char grid[view_maxsize][view_maxsize][2];
        bool GetSubscripts(int&, int&, Point2D);
        int &out_x, &out_y;
};

#endif