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

Part 3 – Reflection Answers

​Q1: Accessors vs. Mutators in SlotMachine:
An accessor function is a read-only tool used to look at or return an internal class variable without changing it, while a mutator function is designed to actively change or update class data.
 In our SlotMachine class, the getCoins() function acts as an accessor because it simply returns the player's current coin balance. This function must use the const keyword because its only job is to read data, and const guarantees that it will not accidentally modify anything.
  On the other hand, the spin() function is a mutator that cannot be const because it must be allowed to change the machine's variables by deducting your bet, picking new random symbols, and updating your total coins.
  
​Q2: Information Hiding & Direct Access Restriction: 
​ Information hiding means keeping the variables inside a class safe and hidden from the outside parts of the program. For example, a programmer cannot write a line of code like game.originalWord = "secret" from the main menu because originalWord is hidden in the private section of the WordScramble class.
Instead, if an external function wants to change the hidden word, it is forced to use the public mutator function called setWord(). This rule is helpful because it allows the class to safely manage its own data, such as automatically running the scramble logic whenever a new word is given. By blocking direct access to variables, we stop accidental bugs, prevent players from cheating, and make it easy to update our class code later without breaking the rest of the project.

​Q3: Static Variables vs. Instance Variables Memory Lifecycle:
​ A static variable like gamesPlayed belongs to the entire class itself and stays alive in memory for the whole duration of the program, while instance variables like guessCount are created fresh every time you make a new game object. If you create two separate NumberGuesser objects in your code, the computer sets aside completely unique memory boxes for each object's private target numbers and guess counters. 
 However, the computer does not create a new memory space for gamesPlayed when these objects are made. This is because a static variable lives in a single shared memory location that is set up just once when the program starts. Both game objects look at and share this exact same single counter behind the scenes. Therefore, whenever either object finishes a game and updates the count, the change is instantly seen by the other object.
SHARED STATIC MEMORY
┌──────────────────────────────────────┐
│ NumberGuesser::gamesPlayed = 2 │ ◄──┐ (Both objects share this counter)
└──────────────────────────────────────┘ │
                                            │
UNIQUE OBJECT MEMORY │
┌──────────────────────────────────────┐ │
│ Object 1: guesserA │ │
│ - guessCount = 3 │ ───┤
│ - secretNumber = 42 │ │
└──────────────────────────────────────┘ │
┌──────────────────────────────────────┐ │
│ Object 2: guesserB │ │
│ - guessCount = 0 │ ───┘
│ - secretNumber = 87 │
└──────────────────────────────────────┘

Q4: Default vs. Parameterized Constructors & Object Arrays:
 ​A default constructor takes no arguments and sets up an object with standard starting values, while a parameterized constructor lets you pass custom data into an object right when you create it. A developer will use a default constructor when they just want a standard game setup, but they will choose a parameterized constructor if they want to specify a custom word and a custom number of lives.
 If you write a parameterized constructor but forget to include a default constructor, trying to create an array like WordScramble games[10]; will break your code completely. This compilation error happens because creating an array of objects requires the computer to automatically build each slot using a parameterless default constructor. Without a default constructor written in your class file, the compiler does not know how to initialize the array slots and will stop your program from running.

 ​Q5: Private Helper Functions vs. Free Functions:
  ​A private helper function is a special routine that can only be called by other functions inside the exact same class. The scramble() function must be private because it is a hidden background task that the main menu loop should never be allowed to call out of order. If we made scramble() a free function outside of the class instead, it would lose direct access to private class variables like originalWord because of standard C++ scope security rules.
  To fix that issue, we would be forced to create extra public functions to pass the secret data back and forth, which completely ruins our data security. Keeping the helper function private balances our tradeoffs perfectly because it keeps our code tidy, protects our data, and hides the messy shuffling logic away from the rest of the program.

​Q6: Classes vs. Structs for HighScore Storage:
 ​In C++, the only actual difference between a struct and a class is that struct members are public by default, while class members are private by default. We used a nested struct for our HighScore item because it is a simple, lightweight container meant to hold a name string and a score integer together without needing any complex logic or functions.
 A programmer would change this decision and convert the struct into a class if they suddenly needed to protect the data with strict rules. For example, if you wanted to block users from entering a negative score or a blank name, you would turn it into a class and use private variables combined with public functions to validate the data safely.

 ​Q7: Static Member Function Restrictions:
  ​Static member functions belong directly to the class rather than an individual object instance, which means they do not have a hidden this pointer to track individual object data. Because of this, a static function is restricted and can only interact with static variables or other static functions inside the class.
  If you try to use a normal instance variable like playerName or totalTokens inside our static printLeaderboard() function, your code will fail to compile immediately. This error occurs because instance variables require a specific player object to exist in memory, but a static function can be called by the system even when no player objects have been created yet.
