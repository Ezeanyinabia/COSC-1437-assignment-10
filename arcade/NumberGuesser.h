#ifndef NUMBERGUESSER_H
#define NUMBERGUESSER_H

#include <string>

class NumberGuesser {
public:
    NumberGuesser(int lo, int hi); // constructor: uses rand() for secret #, increments gamesPlayed
    
    void setRange(int lo, int hi);
    std::string guess(int n); // returns "Too High", "Too Low", or "Correct!"
    void reset(); // generates new secret number, clears counts, increments gamesPlayed
    
    // Inline accessors
    int getGuessCount() const { return guessCount; }
    bool isSolved() const { return solved; }

    // Static member function to print shared stats
    static void printGamesPlayed();

private:
    int secretNumber;
    int maxGuesses;
    int guessCount;
    bool solved;

    static int gamesPlayed; // shared static tracking variable
};

#endif
