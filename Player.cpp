#include "Player.h"
#include "Wheel.h"

Player::Player() {
    wallet = 200.0;
    wheel = Wheel();
}

Player::Player(double w) {
    wallet = w;
    wheel = Wheel(); 
}

Player::Player(double w, int mV) {
    wallet = w;
    wheel = Wheel(mV);
}

void Player::bet(double b) {
    wallet -= b;
}

void Player::win(double w) {
    wallet += w;
}

double Player::getWallet() {
    return wallet;
}

Wheel Player::getWheel() {
    return wheel;
}
