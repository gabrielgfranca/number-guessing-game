#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gameFunctionality(void);
void gameInit(void);

int main(void) 
{
  gameInit();
  return 0;
}

void gameFunctionality(void)
{
  // Generate a random number between 1 and 100
  srand(time(NULL));
  int randomNumber = (rand() % 100) + 1;

  int userNum;
  char answer;

  // Keep playing until the user decides to quit
  while (1) {
    do {
      printf("Write a number between 1 and 100: \n");

      // Check if the input is a valid integer
      if (scanf("%i", &userNum) != 1 || userNum < 1 || userNum > 100) {
        printf("Invalid input! Please enter a number between 1 and 100.\n");

        // Clear the input buffer
        while (getchar() != '\n'); 
        continue;
      }

      // Check if the guess is correct
      if (userNum == randomNumber) { 
        printf("You got it right!\n");
        
        // Ask the user if they want to play again
        printf("Would you like to play again? (y/n)\n");
        scanf(" %c", &answer);
        answer = tolower(answer);

        if (answer == 'y') {
          randomNumber = (rand() % 100) + 1; // Generate a new number
          printf("New game started!\n");
        }
        else { printf("Thanks for playing.\n"); return; }
      }
      else { printf("You are wrong! Try again.\n"); }
    } while (userNum != randomNumber);
  }
}
void gameInit(void) {
  // Display game instructions and how to play
  printf("Welcome to the Number Guessing Game!\n\n"
    "How it works:\n"
    "    1. The computer will generate a random number between 1 and 100.\n"
    "    2. You must try to guess what the number is.\n"
    "    3. If you get it right, you win the game, but if you lose, you can try again.\n\n"
    "To start the game, type 'start'; if you want to exit, press 'Ctrl + C'.\n");

  // Main game loop, waits for the user to enter "start"
  char input[10];
  while (1) {
    printf("Type Here: ");
    scanf("%9s", input);

    // Convert input to lowercase to make it case-insensitive
    for (int i = 0; input[i]; i++) { input[i] = tolower(input[i]); }

    // Check if the user typed "start", then launch the game
    if (strcmp(input, "start") == 0) {
      gameFunctionality();
    } else {
      printf("Invalid input! Type 'start' to begin.\n");
    }
  }
}
