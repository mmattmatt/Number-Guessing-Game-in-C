#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// function to get valid user input
int get_valid_input() {
    int guess;
    // read user input
    if (scanf_s("%d", &guess) != 1) {
        // clear the buffer if input is not an integer
        while (getchar() != '\n');
        return -1; // indicate invalid input
    }
    return guess; // return the valid guess
}

// main method
int main() {
    char play_again;
    do {
        // variable declaration
        int number, guess, tries = 0, difficulty;

        // random number generator
        srand(time(NULL));

        // generate a random number between 1 and 100
        number = rand() % 100 + 1;

        // ask the user for difficulty level
        printf("\n==================================================================================================");
        printf("\nSelect difficulty level:\n");
        printf("1. Easy (20 guesses)\n");
        printf("2. Medium (10 guesses)\n");
        printf("3. Hard (5 guesses)\n");
        printf("==================================================================================================");
        printf("\nEnter your choice (1/2/3): ");

        // get valid choice
        while (1) {
            if (scanf_s("%d", &difficulty) != 1 || difficulty < 1 || difficulty > 3) {
                printf("==================================================================================================");
                printf("\nInvalid choice. Please select 1, 2, or 3: ");
                // clear input buffer to prevent infinite loop on invalid input
                while (getchar() != '\n');
            }
            else {
                break;
            }
        }

        // set the maximum number of tries based on difficulty
        int max_tries;
        if (difficulty == 1) max_tries = 20;
        else if (difficulty == 2) max_tries = 10;
        else max_tries = 5;

        printf("\n==================================================================================================");
        printf("\nGuess the number between 1 and 100. You have %d guesses.\n", max_tries);
        printf("==================================================================================================");

        // main loop, until the player run out of tries
        while (tries < max_tries) {
            printf("\nEnter your guess:");
            printf(" ");

            guess = get_valid_input(); // get input

            // increment tries regardless of validity
            tries++;

            // check if the guess is valid
            if (guess < 1 || guess > 100) {
                printf("\n==================================================================================================");
                printf("\nInvalid Input. Please enter a number between 1 and 100. Tries left: %d\n", max_tries - tries);
                printf("==================================================================================================");
                continue; // skip the rest of the loop and ask for input again
            }

            if (guess < number) { // check the guess if it's too low
                printf("\n==================================================================================================");
                printf("\nThe number you entered is too low, try another number. Tries left: %d\n", max_tries - tries);
                printf("==================================================================================================");
            }
            else if (guess > number) { // check the guess if it's too high
                printf("\n==================================================================================================");
                printf("\nThe number you entered is too high, try another number. Tries left: %d\n", max_tries - tries);
                printf("==================================================================================================");
            }
            else { // guess is correct
                printf("\n==================================================================================================");
                printf("\nCongratulations! You've guessed the number in %d tries.\n", tries);
                printf("==================================================================================================");
                break;
            }
        }

        // ask if the user wants to play again
        do {
            printf("\nDo you want to play again? (y/n): ");
            scanf_s(" %c", &play_again, 1); 
            play_again = tolower(play_again); // convert input to lowercase for easier comparison

            if (play_again != 'y' && play_again != 'n') {
                printf("\n==================================================================================================\n");
                printf("Invalid input. Please use y/n.");          // prompt if input is invalid
                printf("\n==================================================================================================\n");
            }
        } while (play_again != 'n' && play_again != 'y'); 
    } while (play_again != 'n');

    printf("\nThanks for playing!\n");
    printf("\nFOC Project of Group #1 \nAustria, Leandro Gabriele A.\nAvendano, Bon Federique B.\nDe Robles, Leonicos Chael C.\nDetalo, Andrew G.\nFrancisco, Neil Joshua L.\nMarcelino, Mask G.\nNicolas, James Hancel R.\nRobles, Brylle G.\n");

    return 0;
}
