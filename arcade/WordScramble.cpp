#include "WordScramble.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Default constructor: picks a random word from a bank of 10 words
WordScramble::WordScramble() {
    std::string wordBank[10] = {
        "computer", "science", "programming", "pointer", "variable",
        "compiler", "instance", "function", "database", "academic"
    };
    
    // Select a random word from the bank
    int index = std::rand() % 10;
    originalWord = wordBank[index];
    livesLeft = 5;
    won = false;
    
    scramble();
}

// Parameterized constructor
WordScramble::WordScramble(std::string word, int lives) {
    originalWord = word;
    livesLeft = (lives > 0) ? lives : 5;
    won = false;
    
    scramble();
}

// Mutator to set a new word manually
void WordScramble::setWord(std::string word) {
    originalWord = word;
    won = false;
    scramble();
}

// Private helper: Fisher-Yates shuffle engine provided in assignment instructions
void WordScramble::scramble() {
    scrambled = originalWord;
    int n = scrambled.length();
    for (int i = n - 1; i > 0; i--) {
        int j = std::rand() % (i + 1);
        std::swap(scrambled[i], scrambled[j]); // Fisher-Yates shuffle
    }
    // Retry if the shuffle accidentally results in the original word
    if (scrambled == originalWord && n > 1) {
        scramble();
    }
}

// Evaluates the player's attempt
bool WordScramble::tryGuess(std::string attempt) {
    if (attempt == originalWord) {
        won = true;
        return true;
    } else {
        livesLeft--;
        return false;
    }
}

// Safely reveals the hidden word only when the match state concludes
std::string WordScramble::reveal() const {
    if (won || livesLeft <= 0) {
        return originalWord;
    }
    return "****** (Game still in progress)";
}

// Resets game state back to default
void WordScramble::reset() {
    livesLeft = 5;
    won = false;
    scramble();
}
