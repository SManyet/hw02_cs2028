#ifndef PLAYER_H
#define PLAYER_H

#include "Wheel.h"

class Player {
    private:
        double wallet;
        Wheel wheel;

    public:
        Player();
        Player(double);
        Player(double, int);

        void bet(double);
        void win(double);
        double getWallet();
        Wheel getWheel();
};
#endif
