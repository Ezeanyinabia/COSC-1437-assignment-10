#include "ArcadeManager.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator once for the entire runtime execution
    std::srand(std::time(0));

    std::cout << "======================================\n";
    std::cout << " WELCOME TO THE CAMPUS SYSTEM CONSOLE\n";
    std::cout << "======================================\n";

    std::string name;
    int startingTokens;

    // Get basic player profiling info
    std::cout << "Please enter your arcade player name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your starting token budget: ";
    std::cin >> startingTokens;

    // Setup and run the primary orchestrator
    ArcadeManager arcade;
    arcade.setPlayer(name, startingTokens);
    arcade.launchMenu();

    std::cout << "\nThank you for visiting the Campus Game Arcade! Press Enter to close...\n";
    return 0;
}
