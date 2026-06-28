#include "SlotMachine.h"
#include <cstdlib>
#include <ctime>

// Default constructor
SlotMachine::SlotMachine() {
    coins = 100;
    totalSpins = 0;
    std::cout << "\n======================================\n";
    std::cout << " WELCOME TO THE CAMPUS SLOT MACHINE \n";
    std::cout << "======================================\n";
}

// Parameterized constructor
SlotMachine::SlotMachine(int startCoins) {
    if (startCoins > 0) {
        coins = startCoins;
    } else {
        coins = 100; // Fallback default if validation fails
    }
    totalSpins = 0;
}

// Destructor
SlotMachine::~SlotMachine() {
    std::cout << "\nThanks for playing! You leave with [" << coins << "] coins.\n";
}

// Mutator to set coins manually if needed
void SlotMachine::setCoins(int c) {
    if (c >= 0) {
        coins = c;
    }
}

// Private helper to get a random reel symbol
std::string SlotMachine::randomSymbol() {
    std::string symbols[] = {"Cherry", "Bell", "Bar", "7", "Lemon"};
    int index = std::rand() % 5;
    return symbols[index];
}

// Core spin mechanics
bool SlotMachine::spin(int bet) {
    // 1. Validate the bet
    if (bet <= 0 || bet > coins) {
        std::cout << "\n[Error]: Invalid bet amount! You have " << coins << " coins.\n";
        return false;
    }

    // 2. Generate random symbols for the three reels
    reel[0] = randomSymbol();
    reel[1] = randomSymbol();
    reel[2] = randomSymbol();
    
    totalSpins++;

    // 3. Apply win/lose logic
    if (reel[0] == reel[1] && reel[1] == reel[2]) {
        // All three match (3x match pays 5x the bet)
        int winnings = bet * 5;
        coins += (winnings - bet); // Add net winnings
        printResult();
        std::cout << "!!! JACKPOT !!! 3 matching symbols! You won " << winnings << " coins!\n";
        return true;
    } 
    else if (reel[0] == reel[1] || reel[1] == reel[2] || reel[0] == reel[2]) {
        // Two match (2x match pays 2x the bet)
        int winnings = bet * 2;
        coins += (winnings - bet); // Add net winnings
        printResult();
        std::cout << "Nice! 2 matching symbols! You won " << winnings << " coins.\n";
        return true;
    } 
    else {
        // No match
        coins -= bet;
        printResult();
        std::cout << "No match. You lost " << bet << " coins.\n";
        return false;
    }
}

// Accessor to display outcome
void SlotMachine::printResult() const {
    std::cout << "\n[ " << reel[0] << " | " << reel[1] << " | " << reel[2] << " ]\n";
}

// Reset machine state
void SlotMachine::resetMachine() {
    coins = 100;
    totalSpins = 0;
}
