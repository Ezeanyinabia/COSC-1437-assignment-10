#ifndef ARCADEMANAGER_H
#define ARCADEMANAGER_H

#include <string>
#include "SlotMachine.h"
#include "NumberGuesser.h"
#include "WordScramble.h"

class ArcadeManager {
public:
    // Nested struct declared inside the public section
    struct HighScore {
        std::string playerName;
        int score;
    };

    ArcadeManager(); // constructor: increments totalSessions

    void setPlayer(std::string name, int tokens);
    void launchMenu(); // main do-while loop controller
    void printStats() const; // displays current session stats
    void awardBonus(int amount);

    // Static tracking elements
    static void printLeaderboard();

private:
    std::string playerName;
    int totalTokens;
    std::string lastGame;

    // Sub-game program controllers (private runners called by launchMenu)
    void runSlots();
    void runGuesser();
    void runScramble();

    HighScore leaderboard[10]; // fixed array of 10 high scores
    static int totalSessions; // static tracker
};

#endif
