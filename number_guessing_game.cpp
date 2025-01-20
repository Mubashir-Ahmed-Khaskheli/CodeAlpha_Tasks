#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int numberToGuess = rand() % 100 + 1;
    int playerGuess = 0;
    int numberOfTries = 0;

    cout << "*********************************************" <<endl;
    cout << "*       Welcome to Number Guessing Game!     *" <<endl;
    cout << "*********************************************" <<endl;
    cout << " \nI have chosen a number between 1 and 100, can you guess it?" <<endl;



    do {
        cout << "\nEnter your guess (1-100): ";
        cin >> playerGuess;
        numberOfTries++;

        if (playerGuess > numberToGuess) {
            cout << "Too high! Try again.\n";
        } else if (playerGuess < numberToGuess) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You've guessed the number in " << numberOfTries << " tries!\n";
        }
    } while (playerGuess != numberToGuess);

    return 0;
}
