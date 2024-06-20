#include <iostream>
using namespace std;
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Random number between 1 and 100
    int targetNumber = rand() % 100 + 1;
    int guess;
    bool correctGuess = false;

    cout << "Welcome to the Guessing Game!" << std::endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it!" << std::endl;

    while (!correctGuess) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > targetNumber) {
            cout << "Your guess is too high. Try again." << std::endl;
        } else if (guess < targetNumber) {
            cout << "Your guess is too low. Try again." << std::endl;
        } else {
            cout << "Congratulations! You've guessed the correct number." << std::endl;
            correctGuess = true;
        }
    }

    return 0;
}
