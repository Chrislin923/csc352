#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h>

int main(){
	int user_score = 0;
	int	com_score = 0;
	srand((unsigned int)time(NULL));
	int value = rand() % (3 - 1 + 1) + 1;
	char yorn[5];
	char user_choice[10];
	char com_choice[10];
	printf("Welcome to Rock, Paper, Scissors\n");
	printf("\n");
	while (user_score < 3 && com_score < 3){
		printf("Would you like to play? ");
		scanf("%s", yorn);
		printf("\n");
		if(strcmp(yorn, "no") == 0 ){
			break;
		}
		printf("What is your choice? ");
		scanf("%s", user_choice);
		if(value == 1){
			strcpy(com_choice, "rock");
		}
		if(value == 2){
			strcpy(com_choice, "paper");
		}
		if(value == 3){
			 strcpy(com_choice, "scissors");
		}
		if(strcmp(user_choice, "rock") == 0){
			if (strcmp(com_choice, "rock") == 0){
				printf("The computer chooses rock. Game is tie!\n");
			}
			if (strcmp(com_choice, "scissors") == 0){
				printf("The computer chooses scissors. You win the game!\n");
				user_score ++;
			}
			else{
				printf("The computer chooses paper. You lose the game!\n");
				com_score ++;
			}
		}
		if(strcmp(user_choice, "paper") == 0){
			if (strcmp(com_choice, "paper") == 0){
				printf("The computer chooses paper. Game is tie!\n");
			}
			if (strcmp(com_choice, "rock") == 0){
				printf("The computer chooses rock. You win the game!\n");
				user_score ++;
			}
			else{
				printf("The computer chooses scissors. You lose the game!\n");
				com_score ++;
			}
		}
		if(strcmp(user_choice, "scissors") == 0){
			if (strcmp(com_choice, "scissors") == 0){
				printf("The computer chooses scissors. Game is tie!\n");
			}
			if (strcmp(com_choice, "paper") == 0){
				printf("The computer chooses paper. You win the game!\n");
				user_score ++;
			}
			else{
				printf("The computer chooses rock. You lose the game!\n");
				com_score ++;
			}
		}
		printf("\n");
		printf("The score is now you: %d computer: %d\n", user_score, com_score);
	}
	return 0;

}