Abstract Data Type (ADT) Definition for SlotMachine
​Type Name: SlotMachine
​Domain: > * An integer representing current coins (>= 0).
​An integer representing total lifetime totalSpins (>= 0).
​A fixed collection of 3 strings (reel) containing values chosen from {"Cherry", "Bell", "Bar", "7", "Lemon"}.

Operations:
​SlotMachine(): Initializes coins to 100 and totalSpins to 0. Prints a system welcome banner.
​SlotMachine(startCoins): Validates that input is > 0 and initializes the machine with that amount.
​~SlotMachine(): Destructs the object instance and prints a termination summary displaying final currency values.
​setCoins(c): Mutates and updates the internal coin balances.
​spin(bet): Checks if the user has enough coins for the bet. Selects three random symbols, evaluates matching conditions (3x, 2x, or none), mutates currency values based on payouts, increments totalSpins, and returns a success flag.
​printResult(): Read-only operation that formats and outputs the active strings stored on the reel array.
​resetMachine(): Reinitializes properties back to standard fresh session baselines.

Design Justification Paragraph

​All data member fields across the four arcade classes—such as coins and reel in SlotMachine, secretNumber and solved in NumberGuesser, and originalWord in WordScramble—were explicitly declared inside the private access scope.
This practice enforces information hiding and encapsulation, ensuring that the state of an active game cannot be corrupted, bypassed, or directly modified by external driver programs or unexpected client actions.
Access to these properties is strictly controlled through carefully authenticated public mutator interfaces and const-correct accessor methods, preventing invalid states (such as a negative bet or cheating by manually viewing the scrambled word) and ensuring the integrity of the arcade program.

