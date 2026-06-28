#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <iostream>
#include <string>

class SlotMachine {
public:
    SlotMachine(); // default constructor: sets coins to 100, prints welcome banner
    SlotMachine(int startCoins); // param constructor: validates startCoins > 0
    ~SlotMachine(); // destructor: prints farewell message with remaining coins

    void setCoins(int c); // mutator
    bool spin(int bet); // mutator -- core game logic
    void printResult() const; // accessor (const!)
    void resetMachine(); // mutator

    // Inline accessor functions -- defined here in the header
    int getCoins() const { return coins; }
    int getTotalSpins() const { return totalSpins; }

private:
    int coins;
    std::string reel[3];
    int totalSpins;
    std::string randomSymbol(); // private helper function
};

#endif
