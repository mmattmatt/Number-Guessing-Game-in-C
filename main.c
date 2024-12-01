#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get valid user input
int get_valid_input() {
    int guess;
    // read user input
    if (scanf_s("%d", &guess) != 1) {
        while (getchar() != '\n'); //clear the buffer if input is not an integer
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
        printf("\nSelect difficulty level:\n");
        printf("1. Easy (20 guesses)\n");
        printf("2. Medium (10 guesses)\n");
        printf("3. Hard (5 guesses)\n");
        printf("\nEnter your choice (1/2/3): ");

        // get valid choice
        while (1) {
            if (scanf_s("%d", &difficulty) != 1 || difficulty < 1 || difficulty > 3) {
                printf("Invalid choice. Please select 1, 2, or 3: ");
                while (getchar() != '\n'); // clear input buffer to prevent infinite loop on invalid input
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

        printf("\nGuess the number between 1 and 100. You have %d guesses.\n", max_tries);

        // main loop
        while (tries < max_tries) {
            printf("Enter your guess: ");
            guess = get_valid_input(); // get input

            // increment tries regardless of validity
            tries++;

            // check if the guess is within range
            if (guess < 1 || guess > 100) {
                printf("\nInvalid Number. Please enter a number between 1 and 100. Tries left: %d\n", max_tries - tries);
                continue; // skip the rest of the loop and ask for input again
            }

            if (guess < number) { // check the guess if it's too low
                printf("\nThe number you entered is too low, try another number.");
            }
            else if (guess > number) { // check the guess if it's too high
                printf("\nThe number you entered is too high, try another number.");
            }
            else { // check the guess if it's correct
                printf("Congratulations! You've guessed the number in %d tries.\n", tries);
                break;
            }

            printf("Tries left: %d\n", max_tries - tries); // shows the number of tries left
        }

        // if the user runs out of tries
        if (tries == max_tries && guess != number) {
            printf("Sorry, you've used all your guesses. The number was %d.\n", number);
        }

        // ask if the user wants to play again
        printf("\nDo you want to play again? (y/n): ");
        while (getchar() != '\n'); // clear the buffer before taking new input
        scanf_s("%c", &play_again, 1);

    } while (play_again == 'y' || play_again == 'Y'); // makes sure capitalization will not be an issue

    printf("Thanks for playing!\n");
    return 0;
}
