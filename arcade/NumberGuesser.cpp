#include "NumberGuesser.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Initialize the static variable outside the class
int NumberGuesser::gamesPlayed = 0;

// Constructor matching assignment template
NumberGuesser::NumberGuesser(int lo, int hi) {
    // Seed random sequence if it hasn't been seeded yet
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
    
    setRange(lo, hi);
    maxGuesses = 7;
    guessCount = 0;
    solved = false;
    
    gamesPlayed++; // Increment shared global static game tracker
}

// Sets or changes the target play range
void NumberGuesser::setRange(int lo, int hi) {
    if (lo > hi) { // Quick safety swap if ranges are inverted
        int temp = lo;
        lo = hi;
        hi = temp;
    }
    secretNumber = std::rand() % (hi - lo + 1) + lo;
}

// Core guessing evaluation function
std::string NumberGuesser::guess(int n) {
    guessCount++;
    
    if (n > secretNumber) {
        return "Too High";
    } else if (n < secretNumber) {
        return "Too Low";
    } else {
        solved = true;
        return "Correct!";
    }
}

// Reset implementation
void NumberGuesser::reset() {
    guessCount = 0;
    solved = false;
    // Reset range between default 1 and 100 for replay safety
    setRange(1, 100); 
    gamesPlayed++;
}

// Static function implementation
void NumberGuesser::printGamesPlayed() {
    std::cout << "\n[Global Arcade Stats] Number Guesser has been initiated " 
              << gamesPlayed << " times across all sessions.\n";
}
