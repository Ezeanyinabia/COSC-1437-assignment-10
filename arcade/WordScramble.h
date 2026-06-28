#ifndef WORDSCRAMBLE_H
#define WORDSCRAMBLE_H

#include <string>

class WordScramble {
public:
    WordScramble(); // default constructor: picks random word from bank, lives = 5
    WordScramble(std::string word, int lives); // param constructor: custom word and lives

    void setWord(std::string word); // mutator: updates word and runs scramble()
    bool tryGuess(std::string attempt); // returns true if correct, decrements livesLeft if wrong
    void reset(); // resets game state

    // Const-correct accessors
    std::string getScrambled() const { return scrambled; }
    int getLivesLeft() const { return livesLeft; }
    bool isWon() const { return won; }
    std::string reveal() const; // only exposes originalWord after game ends

private:
    std::string originalWord;
    std::string scrambled;
    int livesLeft;
    bool won;

    void scramble(); // private helper: executes Fisher-Yates shuffle
};

#endif
