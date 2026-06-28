#include "ArcadeManager.h"
#include <iostream>

// Initialize static member tracking variable
int ArcadeManager::totalSessions = 0;

// Constructor
ArcadeManager::ArcadeManager() {
    playerName = "Player 1";
    totalTokens = 100;
    lastGame = "None";
    totalSessions++;

    // Initialize leaderboard array with dummy template placeholders
    for (int i = 0; i < 10; i++) {
        leaderboard[i].playerName = "Empty";
        leaderboard[i].score = 0;
    }
}

// Configures current player state
void ArcadeManager::setPlayer(std::string name, int tokens) {
    playerName = name;
    if (tokens > 0) {
        totalTokens = tokens;
    }
}

// Gives bonus credits
void ArcadeManager::awardBonus(int amount) {
    if (amount > 0) {
        totalTokens += amount;
        std::cout << "\n[Bonus]: Awarded " << amount << " tokens to " << playerName << "!\n";
    }
}

// Tracks and loops the primary console interface
void ArcadeManager::launchMenu() {
    int choice = 0;
    do {
        std::cout << "\n--- CAMPUS GAME ARCADE MAIN MENU ---\n";
        std::cout << "Player: " << playerName << " | Balance: " << totalTokens << " tokens\n";
        std::cout << "Last Game Played: " << lastGame << "\n";
        std::cout << "1. Play Slot Machine\n";
        std::cout << "2. Play Number Guesser\n";
        std::cout << "3. Play Word Scramble\n";
        std::cout << "4. View Session Statistics\n";
        std::cout << "5. Exit Arcade\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                runSlots();
                break;
            case 2:
                runGuesser();
                break;
            case 3:
                runScramble();
                break;
            case 4:
                printStats();
                break;
            case 5:
                std::cout << "\nExiting Arcade Manager. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice! Please select an option between 1 and 5.\n";
        }
    } while (choice != 5);
}

// Private sub-runner for executing Slot Machine
void ArcadeManager::runSlots() {
    lastGame = "Slot Machine";
    SlotMachine slots(totalTokens); // Instantiate game passing current tokens
    
    int bet;
    std::cout << "\nEnter token amount to bet: ";
    std::cin >> bet;
    
    slots.spin(bet);
    totalTokens = slots.getCoins(); // Sync remaining balance back to manager
}

// Private sub-runner for executing Number Guesser
void ArcadeManager::runGuesser() {
    lastGame = "Number Guesser";
    NumberGuesser guesser(1, 100);
    int playerGuess;
    
    std::cout << "\n--- Number Guesser (Range 1-100) ---\n";
    while (!guesser.isSolved() && guesser.getGuessCount() < 7) {
        std::cout << "Guess #" << (guesser.getGuessCount() + 1) << ": ";
        std::cin >> playerGuess;
        
        std::string result = guesser.guess(playerGuess);
        std::cout << "Result: " << result << "\n";
    }
    
    if (guesser.isSolved()) {
        std::cout << "Congratulations! You found it in " << guesser.getGuessCount() << " tries.\n";
        awardBonus(20); // Award token prize
    } else {
        std::cout << "Out of guesses! Better luck next time.\n";
    }
}

// Private sub-runner for executing Word Scramble
void ArcadeManager::runScramble() {
    lastGame = "Word Scramble";
    WordScramble game; // Uses default 10-word bank selection
    std::string userAttempt;
    
    std::cout << "\n--- Word Scramble --- \n";
    while (!game.isWon() && game.getLivesLeft() > 0) {
        std::cout << "Scrambled Word: " << game.getScrambled() << "\n";
        std::cout << "Lives Remaining: " << game.getLivesLeft() << "\n";
        std::cout << "Your Guess: ";
        std::cin >> userAttempt;
        
        if (game.tryGuess(userAttempt)) {
            std::cout << "Spot on! Correct word!\n";
            awardBonus(30);
        } else {
            std::cout << "Incorrect guess!\n";
        }
    }
    
    if (!game.isWon()) {
        std::cout << "Game Over! The word was: " << game.reveal() << "\n";
    }
}

// Prints diagnostic performance data
void ArcadeManager::printStats() const {
    std::cout << "\n===============================\n";
    std::cout << " CURRENT SESSION STATS \n";
    std::cout << "===============================\n";
    std::cout << "Active Profile: " << playerName << "\n";
    std::cout << "Current Token Bank: " << totalTokens << "\n";
    std::cout << "Last Played Module: " << lastGame << "\n";
    std::cout << "Total Active Global Managers: " << totalSessions << "\n";
    std::cout << "===============================\n";
}

// Static leaderboard implementation placeholder matching the class diagram requirements
void ArcadeManager::printLeaderboard() {
    std::cout << "\n--- Arcade Leaderboard Top Scores ---\n";
    std::cout << "Rank\tName\t\tScore\n";
    for (int i = 0; i < 3; i++) {
        std::cout << (i + 1) << "\tGuest\t\t100\n";
    }
}
