#ifndef INPUTHANDLING_H
#define INPUTHANDLING_H

class Invalid_Input {
    public:
        Invalid_Input(string) : msg_ptr (in_ptr) { }
        const string msg_ptr;
    
    private:
        Invalid_Input();
};

#endif