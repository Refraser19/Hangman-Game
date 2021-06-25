/* Hangman Game
	Created by: Neha Narine USI-1036859
				Renike Fraser USI-1037455*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

int main() {

	srand(time(NULL));
	
	char listOfWords[][16] = {
		"iris", 
		"rose",
		"tulip",
		"orchid",
		"sunflower",
		"daffodil",
		"daisy",
		"marigold",
	};
	
	// index for random word
	int randomPick = rand() % 8;
	
	int prevCorrect = 0;				// holds all the correct guesses so the program dont count them twice 
	int correctEntry = 0;				// the amount of correct guesses the user enters
	int livesLeft = 5;					// amount of lives the user has or the amount of times the program will loop if wrong answers are chosen

	
	int wordLength = strlen(listOfWords[randomPick]);		//when a word is chosen randomly from the list, this finds the amount of letters in the word.
	
	
	int letterInput[8] = { 0,0,0,0,0,0,0,0 };			//this is an array that uses 0s for each letter in the word, when a correct letter is typed, the 0 in the exact positionb is changed

	
	int exit = 0;										
	
	int Loop = 0;
	int alreadyPicked = 0; 
	
	char entry[16];			// this array was made to hold all letters entered by user
	char letterEntered;	
	
	printf("	WeLcOmE tO tHe HaNgMaN GaMe 		(=^__^=)");
	printf("\n\n	You have 5 lives\n");
	printf("	Every incorrect entry takes away 1 life\n");
	
	printf("\n	HINT: The list of words are all names of flowers ;) \n");

	
	

	
	while ( correctEntry < wordLength ) {			// this is where the hangman game actually begins, if the amount of correct letters is less that the total letters of the word the program will keep running 
	
		printf("\n\n	Hangman Word: ");
	
		for( Loop = 0; Loop < wordLength; Loop++) {   // lines 57 - 65 is used to print "-" in the place of each letter of the word to hide it. if the user guesses a correct letter/s it will be shown
		
			if(letterInput[Loop] == 1) {
				printf("%c",listOfWords[randomPick][Loop]);				
			} else {
				printf("-");
			}
		
		}	
		
		printf("\n");
	
		
		printf("	Enter a letter:");
		fgets(entry, 16, stdin);			// the letter entered is stored in the "entry" array
		
		if( strncmp(entry, "exit", 4) == 0) {		// if the user types "exit" at any point in the game, the hangman game ends.
			exit = 1;
			break;
		}
		system("cls");						// this clears the screen
		letterEntered = entry[0];			// this assigns whatever letter is placed in the entry array as "letterEntered"
		
		
		printf("	You entered: %c\n",letterEntered);
		
		prevCorrect = correctEntry;  		// whenever variable "correctEntry" is updated, the value of "prevEntered" is updated to that value
		
		for( Loop = 0; Loop < wordLength; Loop++) {  	// once loop is less than the amount of letters in the random word, it will increment
		
			if(letterInput[Loop] == 1) {				//lines 87 - 93 If a letter entered is correct but was already entered, this part is activated
				if(listOfWords[randomPick][Loop] == letterEntered) {
					alreadyPicked = 1; 
					break;
				} 
				continue;
			}
		
			if( letterEntered == listOfWords[randomPick][Loop] ) {		//If a letter was added and it matches a letter from the random word that haas not been previously entered, correctEntry is incremented
				letterInput[Loop] = 1;
				correctEntry++;				
			}		
			
			
		}
			
		
		if( prevCorrect == correctEntry && alreadyPicked == 0) {		// llines 104 - 107 tries to verify if a letter inserted is not correct nor new
			livesLeft--;												// if the previous line is true then the entry is incorrect and 1 life is removed from the user
			printf("	Wrong guess (·_·) \n");
			printf("	Lives left: %d", livesLeft);
			if (livesLeft == 0) {										// if the user runs out of lives then the loop ends.
				break;
			}
		} else if( alreadyPicked == 1) {								// If a letter was correct but previously entered, lines 111 - 113 notifies the user, a life is not taken in this case
			printf("\n	This has already been guessed!!\n");
			printf("	Lives left: %d", livesLeft);
		} else {														// if none of the previous cases are true then it means the user entered a correct value, the program will notify them
			printf("\n	You got it!:)\n");
			printf("	Lives left: %d", livesLeft);
		}
		if (livesLeft==4) {												// lines 118 - 144 are used for the hangman illustration, as the lives decrease, more parts are shown	
			printf("\n		________\n");
    		printf("		|      \n");
    		printf("		|      \n");
    		printf("		|      \n");
    		printf("		|      \n");
    		printf("		|      \n");
		}else{
    		printf("");
    		printf("");
    	}
		if(livesLeft==3){
    		printf("\n		________\n");
    		printf("		|      |\n");
    		printf("		|      \n");
    		printf("		|      \n");
    		printf("		|      \n");
    		printf("		|      \n");
		}else{
    		printf("");
		}
		if(livesLeft==2){
    		printf("\n		________\n");
    		printf("		|      |\n");
    		printf("		|      0\n");
    		printf("		|      \n");
    		printf("		|      \n");
    		printf("		|      \n");
		}
		if(livesLeft==1){
			printf("\n		________\n");
    		printf("		|      |\n");
    		printf("		|      0\n");
    		printf("		|     /|\\\n");
    		printf("		|      |\n");
    		printf("		|      \n");
    		
    		
		}
		
		
	
	} // while loop

	if( exit == 1 ) {											// At any point in the program, if the user types "exit" the program will end and print the message in the next line
		printf("\n	Thanks for trying, goodbye!\n");
	} 
	else if (livesLeft == 0) {									// if the user runs out of lives, the message below will be printed
		printf("\n	You died!\n");
		printf("	The word was: %s\n",
		listOfWords[randomPick]);	
	} 
	else  {														// if the user guesses all letters before the lives are depleated then they win
		printf("\n	YOU WIN!!! :)\n");
	} 
	
	if(livesLeft==0){											//lines 173 - 180 is printed at the end of the game if the user dies
			printf("		________\n");
			printf("		|      |\n");
			printf("		|      0\n");
    		printf("		|     /|\\\n");
    		printf("		|      |\n");
    		printf("		|     / \\\n");
    		printf("		|      \n");
	}

	
return 0;
}
