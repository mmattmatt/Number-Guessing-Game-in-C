#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess;
    int guess_limit;
    int guesses = 0;
    int answer;
    char choice;
    int difficulty;
    int MAX;

    srand(time(0));

    printf("Please select difficulty level\n");
    printf("[1] Easy (1-30)\n[2] Normal (1-50)\n[3] Hard (1-100)\n");
    scanf("%d", &difficulty);

    switch (difficulty) {
        case 1:
            answer = (rand() % 30) + 1;
            MAX = 30;
            guess_limit = 10;
            break;
        case 2:
            answer = (rand() % 50) + 1;
            MAX = 50;
            guess_limit = 6;
            break;
        case 3:
            answer = (rand() % 100) + 1;
            MAX = 100;
            guess_limit = 3;
            break;
        default:
            printf("Invalid difficulty level. Defaulting to normal mode.\n");
            answer = (rand() % 50) + 1;
            MAX = 30;
            guess_limit = 6;
            break;
    }
    do {
        guesses = 0;

        do {
            printf("Enter your guess (1-%d):\n", MAX);
            if (scanf("%d", &guess) != 1 || guess < 1 || guess > MAX) {
                printf("Invalid input. Please enter a positive integer between 1 and %d.\n", MAX);
                while ((getchar()) != '\n');
                continue;
            }

            if (guess > answer) {
                printf("Your guess is too high. Remaining guesses: %d\n", guess_limit - guesses - 1);
            } else if (guess < answer) {
                printf("Your guess is too low. Remaining guesses: %d\n", guess_limit - guesses - 1);
            } else {
                printf("Correct! The answer is %d.\n", answer);
            }
            guesses++;
        } while (guess != answer && guesses < guess_limit);

        if (guesses >= guess_limit) {
            printf("You've reached the guess limit. The answer was %d.\n", answer);
        }

        printf("Do you want to play again? (y/n):\n");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
