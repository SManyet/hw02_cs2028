#include <iostream>
#include "Player.h"
#include "Wheel.h"

using namespace std;

Player makePlayer() {
    while (true) {
        cout << "would you like default wallet and wheel (1)" << endl;
        cout << "or custom wallet and default wheel (2)" << endl;
        cout << "or custome wallet and wheel (3)?" << endl;
        int choice;
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore();
            cout << "invalid input, must be int, 1-3" << endl;
            continue;
        }

        if (choice == 1) {
            return Player();
        } else {
            cout << "player wallet: " << endl;
            double w;
            cin >> w;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "invlid input must be double" << endl;
                continue;
            }
            if (choice == 2){
                return Player(w);
            } else if (choice == 3) {
                cout << "wheel range (min 6, max 20): " << endl;
                int r;
                cin >> r;
                if (cin.fail() || r < 6 || r > 20) {
                    cin.clear();
                    cin.ignore();
                    cout << "invalid input, must be int, 6-20" << endl;
                    continue;
                }
                return Player(w, r);
            }
        }
    }
}


int main() {

    bool running = true;
    double pot = 0;
    double minBet = 20.0;
    double currBet = 0;

    cout << "======================================" << endl;
    cout << "welcome to modified roulette" << endl;
    Player user = makePlayer();
    Wheel wheel = user.getWheel();

    cout << "$ in wallet: $" << user.getWallet() << endl;
    while (running) {
        bool betCheck = false;
        while (!betCheck) {
            cout << "bet ammount, min $20?" << endl;
            cin >> currBet;
            if (cin.fail() || currBet < minBet || currBet > user.getWallet()) {
                cin.clear();
                cin.ignore();
                cout << "invalid bet" << endl;
                continue;
            } else {
                pot += currBet;
                betCheck = true;
            }
        }        
        int userSpin = wheel.spin();
        cout << "your ball landed on " << userSpin << endl;

        bool turnCheck = false;
        while (!turnCheck) {
            cout << "would you like to double (1), half (2), or do nothing(3)" << endl;
            int choice;
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 3) {
                cin.clear();
                cin.ignore();
                cout << "invalid input, must be int, 1-3" << endl;
            }
            int houseSpin = wheel.spin();
            cout << "house spun " << houseSpin << endl;
            if (houseSpin < userSpin) {
                cout << "house lost spin 1" << endl;
                if (choice != 1) {
                    user.win(currBet);
                    cout << "user won " << currBet << endl;
                    turnCheck = true;
                    continue;
                }
                houseSpin = wheel.spin();
                cout << "house spun a " << houseSpin << endl;
                if (houseSpin < userSpin) {
                    cout << "house lost spin 2" << endl;
                    if (choice == 1) {
                        user.win(2 * currBet);
                        cout << "user won " <<2*currBet << endl;
                        turnCheck = true;
                    }
                }
            } else {
                cout << "house won spin 1" << endl;
                houseSpin = wheel.spin();
                cout << "house spun a " << houseSpin << endl;
                if (choice == 1) {
                    user.bet(2*currBet);
                    cout << "user lost " << 2*currBet << endl;
                    turnCheck = true;
                }

                if (choice == 3) {
                    user.bet(currBet);
                    cout << "user lost " << currBet << endl;
                    turnCheck = true;

                }
                if (houseSpin < userSpin) {
                    cout << "house lost spin 2" << endl;
                    if (choice == 1) {
                        user.win(currBet * 2 );
                        cout << "user won " <<2*currBet << endl;
                        turnCheck = true;
                    }
                    if (choice == 2) {
                        user.win(currBet);
                        cout << "user won " << currBet << endl;
                        turnCheck = true;
                    }
                } else {
                    cout << "house won spin 2" << endl;
                    if (choice == 2) {
                        user.bet(currBet);
                        cout << "user lost " << currBet << endl;
                        turnCheck = true;
                    }

                }

            }
        }
        int input;
        bool check = true;
        while (check) {
            if (user.getWallet() <= 0) {
                cout << "out of money! quitting" << endl;
                running = false;
                break;
            }
            cout << "$ in wallet: $" << user.getWallet() << endl;
            cout << "quit (1) or continue (2)" << endl;
            cin >> input;
            if (cin.fail() || input > 2 || input < 1) {
                cin.clear();
                cin.ignore();
                cout << "invalid input" << endl;
            } else {
                check = false;
            }
        }
        if (input == 1) {
            running = false;
            cout << "quitting" << endl;
        }
    }
    return 0;
}
