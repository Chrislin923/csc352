
/*
Assignment: project 5
Purpose: Play the game of black jack with driver
Other files: card_driver.c, Makefile
Author: Chris Lin
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{

	//Points for each pile
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p5 = 0;

	//count of cards in each pile
	int p1_c = 0;
	int p2_c = 0;
	int p3_c = 0;
	int p4_c = 0;
	int p5_c = 0;

	//array to store cards in each pile
	int pile1[12];
	int pile2[12];
	int pile3[12];
	int pile4[12];
	int pile5[12];

	//user choice of which pile to add the card
	int user_p;

	int score = 0;

	int high_score;

	//file to write the highes score
	FILE * fp;

	// a flag checking for invalid pile
	int flag = 0;


	//read the first card from driver
	char c;
	int fd = open("/dev/cards", O_RDONLY);
	int card_d = read( fd, &c, 1 );

	//get the correct card representation
	if(card_d < 4){
		card_d = 1;
	}
	if(card_d >= 4
		&& card_d < 8){
		card_d = 2;
	}
	if(card_d >= 8
		&& card_d < 12){
		card_d = 3;
	}
	if(card_d >= 12
		&& card_d < 16){
		card_d = 4;
	}
	if(card_d >= 16
		&& card_d < 20){
		card_d = 5;
	}
	if(card_d >= 20
		&& card_d < 24){
		card_d = 6;
	}
	if(card_d >= 24
		&& card_d < 28){
		card_d = 7;
	}
	if(card_d >= 28
		&& card_d < 32){
		card_d = 8;
	}
	if(card_d >= 32
		&& card_d < 36){
		card_d = 9;
	}
	if(card_d >= 36
		&& card_d < 40){
		card_d = 10;
	}
	if(card_d >= 40
		&& card_d < 44){
		card_d = 11;
	}
	if(card_d >= 44
		&& card_d < 48){
		card_d = 12;
	}
	if(card_d >= 48
		&& card_d < 52){
		card_d = 13;
	}


	int card_count = 0; // counting for the 

	printf("Score: %d\n\n", score);
	printf("Pile (1):     = 0\n");
	printf("Pile (2):     = 0\n");
	printf("Pile (3):     = 0\n");
	printf("Pile (4):     = 0\n");
	printf("Pile (5):     = 0\n\n");


	while(1){
		//Display in character for A J Q and K
		if(card_d == 1){
			printf("Drawn Card: %c\n\n", 'A' );
		}
		else if(card_d == 11){
			printf("Drawn Card: %c\n\n", 'J' );
		}
		else if(card_d == 12){
			printf("Drawn Card: %c\n\n", 'Q' );
		}
		else if(card_d == 13){
			printf("Drawn Card: %c\n\n", 'K' );
		}
		else
			printf("Drawn Card: %d\n\n", card_d);
		if(card_d > 10){
			//when the card is over 10
			if(p1 + 10 > 21
				&& p2 + 10 > 21
				&& p3 + 10 > 21
				&& p4 + 10 > 21
				&& p5 + 10 > 21){
				//check if we still have a valid pile to add
				printf("No more place to place the card!\n");
				break;
			}
		}
		else if(p1 + card_d > 21
			&& p2 + card_d > 21
			&& p3 + card_d > 21
			&& p4 + card_d > 21
			&& p5 + card_d > 21){
			printf("No more place to place the card!\n");
			break;
		}
		card_count++;


		printf("Which pile to place the card in? ");
		scanf("%d", &user_p);

		// make sure the input pile is valid to add a card
		if(user_p == 1
			&& p1 > 21){
			flag = 1;
		}
		if(user_p == 2
			&& p2 > 21){
			flag = 1;
		}
		if(user_p == 3
			&& p3 > 21){
			flag = 1;
		}
		if(user_p == 4
			&& p4 > 21){
			flag = 1;
		}
		if(user_p == 5
			&& p5 > 21){
			flag = 1;
		}
		while(user_p > 5
			|| flag){
			// make sure the input pile is valid to add a card
			printf("Invalid Pile! Choose a different one\n\n");
			printf("Which pile to place the card in? ");
			scanf("%d", &user_p);
			if(user_p == 1
			&& p1 > 21){
				flag = 1;
			}
			if(user_p == 2
				&& p2 > 21){
				flag = 1;
			}
			if(user_p == 3
				&& p3 > 21){
				flag = 1;
			}
			if(user_p == 4
				&& p4 > 21){
				flag = 1;
			}
			if(user_p == 5
				&& p5 > 21){
				flag = 1;
			}
			else
				flag = 0;
		}
		printf("\n\n");

		if(user_p == 1){
			//if user choose to add to pile 1
			p1_c ++;
			if(card_d == 1
				&& p1 < 11){
				// if the card is A, we have to decide to add
				// 1 or 11
				p1 += 11;
			}
			else if(card_d > 10)
				p1 += 10;
			else
				p1+= card_d;

			pile1[p1_c - 1] = card_d;
			if(p1 == 21){
				if(p1_c == 2){
					// if the current pile is 21 and with only 2 cards
					printf("Natural blackjack! +35 points\n");
					score += 35;
				}
				else{
					printf("Blackjack! +21 points\n");
					score += 21;
				}
				p1 = 0;
				p1_c = 0;

			}
			if(p1_c > 5
				&& p1 < 21){
				//if there are more then 5 cards in a pile
				printf("\"Five Card Charlie\" +%d points\n", p1);
			}

		}
		if(user_p == 2){
			//if user choose to add to pile 2
			p2_c ++;
			if(card_d == 1
				&& p2 < 11){
				// if the card is A, we have to decide to add
				// 1 or 11
				p2 += 11;
			}
			else if(card_d > 10)
				p2 += 10;
			else
				p2 += card_d;

			pile2[p2_c - 1] = card_d;
			if(p2 == 21){
				if(p2_c == 2){
					// if the current pile is 21 and with only 2 cards
					printf("Natural blackjack! +35 points\n");
					score += 35;
				}
				else{
					printf("Blackjack! +21 points\n");
					score += 21;
				}
				p2 = 0;
				p2_c = 0;

			}
			if(p2_c > 5
				&& p2 < 21){
				printf("\"Five Card Charlie\" +%d points\n", p2);
			}

		}
		if(user_p == 3){
			//if user choose to add to pile 3
			p3_c ++;
			if(card_d == 1
				&& p3 < 11){
				// if the card is A, we have to decide to add
				// 1 or 11
				p3 += 11;
			}
			else if(card_d > 10)
				p3 += 10;
			else
				p3 += card_d;

			pile3[p3_c - 1] = card_d;
			if(p3 == 21){
				if(p3_c == 2){
					printf("Natural blackjack! +35 points\n");
					score += 35;
				}
				else{
					printf("Blackjack! +21 points\n");
					score += 21;
				}
				p3 = 0;
				p3_c = 0;

			}
			if(p3_c > 5
				&& p3 < 21){
				printf("\"Five Card Charlie\" +%d points\n", p3);
			}

		}

		if(user_p == 4){
			//if user choose to add to pile 4
			p4_c ++;
			if(card_d == 1
				&& p4 < 11){
				// if the card is A, we have to decide to add
				// 1 or 11
				p4 += 11;
			}
			else if(card_d > 10)
				p4 += 10;
			else
				p4 += card_d;

			pile4[p4_c - 1] = card_d;
			if(p4 == 21){
				if(p4_c == 2){
					printf("Natural blackjack! +35 points\n");
					score += 35;
				}
				else{
					printf("Blackjack! +21 points\n");
					score += 21;
				}
				p4 = 0;
				p4_c = 0;

			}
			if(p4_c > 5
				&& p4 < 21){
				printf("\"Five Card Charlie\" +%d points\n", p4);
			}

		}
		if(user_p == 5){
			//if user choose to add to pile 5
			p5_c ++;
			if(card_d == 1
				&& p5 < 11){
				// if the card is A, we have to decide to add
				// 1 or 11
				p5 += 11;
			}
			else if(card_d > 10)
				p5 += 10;
			else
				p5 += card_d;

			pile5[p5_c - 1] = card_d;
			if(p5 == 21){
				if(p5_c == 2){
					//Blackjack
					printf("Natural blackjack! +35 points\n");
					score += 35;
				}
				else{
					//natural blackjack
					printf("Blackjack! +21 points\n");
					score += 21;
				}
				p5 = 0;
				p5_c = 0;

			}
			if(p5_c > 5
				&& p5 < 21){
				printf("\"Five Card Charlie\" +%d points\n", p5);
			}

		}
		if(p1_c == 0
			&& p2_c ==0
			&& p3_c == 0
			&& p4_c == 0
			&& p5_c == 0){
			//check if we clear the board after the game starts
			printf("Cleared the board! +45 points\n");
			score += 45;
		}
		if(card_count == 52){
			//check if the deck is clear, we track it with card_count
			printf("Cleared the deck! +60 points\n");
			card_count =0;
			score += 60;
		}

		printf("Score: %d\n\n", score);

		//display each pile on screen with the cards
		printf("Pile (1):");
		if(p1_c != 0){
			for(int i = 0; i< p1_c; i++){
				//use for loop to display each card
				//inside the pile
				if(pile1[i] == 1){
					printf("%c ", 'A' );

				}
				else if(pile1[i] == 11){
					printf("%c ", 'J' );
				}
				else if(pile1[i] == 12){
					printf("%c ", 'Q' );
				}
				else if(pile1[i] == 13){
					printf("%c ", 'K' );
				}
				else
					printf("%d ", pile1[i]);
			}
			printf("    ");
		}
		else{
			printf("     ");
		}
		printf("= %d\n", p1);

		printf("Pile (2):");
		if(p2_c != 0){
			for(int i = 0; i< p2_c; i++){
				//use for loop to display each card
				//inside the pile
				if(pile2[i] == 1){
					printf("%c ", 'A' );
				}
				else if(pile2[i] == 11){
					printf("%c ", 'J' );
				}
				else if(pile2[i] == 12){
					printf("%c ", 'Q' );
				}
				else if(pile2[i] == 13){
					printf("%c ", 'K' );
				}
				else
					printf("%d ", pile2[i]);
			}
			printf("    ");
		}
		else{
			printf("     ");
		}
		printf("= %d\n", p2);

		printf("Pile (3):");
		if(p3_c != 0){
			for(int i = 0; i< p3_c; i++){
				//use for loop to display each card
				//inside the pile
				if(pile3[i] == 1){
					printf("%c ", 'A' );
				}
				else if(pile3[i] == 11){
					printf("%c ", 'J' );
				}
				else if(pile3[i] == 12){
					printf("%c ", 'Q' );
				}
				else if(pile3[i] == 13){
					printf("%c ", 'K' );
				}
				else
					printf("%d ", pile3[i]);
			}
			printf("    ");
		}
		else{
			printf("     ");
		}
		printf("= %d\n", p3);

		printf("Pile (4):");
		if(p4_c != 0){
			for(int i = 0; i< p4_c; i++){
				//use for loop to display each card
				//inside the pile
				if(pile4[i] == 1){
					printf("%c ", 'A' );
				}
				else if(pile4[i] == 11){
					printf("%c ", 'J' );
				}
				else if(pile4[i] == 12){
					printf("%c ", 'Q' );
				}
				else if(pile4[i] == 13){
					printf("%c ", 'K' );
				}
				else
					printf("%d ", pile4[i]);
			}
			printf("    ");
		}
		else{
			printf("     ");
		}
		printf("= %d\n", p4);

		printf("Pile (5):");
		if(p5_c != 0){
			for(int i = 0; i< p5_c; i++){
				//use for loop to display each card
				//inside the pile
				if(pile5[i] == 1){
					printf("%c ", 'A' );
				}
				else if(pile5[i] == 11){
					printf("%c ", 'J' );
				}
				else if(pile5[i] == 12){
					printf("%c ", 'Q' );
				}
				else if(pile5[i] == 13){
					printf("%c ", 'K' );
				}
				else
					printf("%d ", pile5[i]);
			}
			printf("    ");
		}
		else{
			printf("     ");
		}
		printf("= %d\n\n", p5);


		card_d = read( fd, &c, 1 ); // read in the card from driver

		//get the correct card representation
		if(card_d < 4){
			card_d = 1;
		}
		if(card_d >= 4
			&& card_d < 8){
			card_d = 2;
		}
		if(card_d >= 8
			&& card_d < 12){
			card_d = 3;
		}
		if(card_d >= 12
			&& card_d < 16){
			card_d = 4;
		}
		if(card_d >= 16
			&& card_d < 20){
			card_d = 5;
		}
		if(card_d >= 20
			&& card_d < 24){
			card_d = 6;
		}
		if(card_d >= 24
			&& card_d < 28){
			card_d = 7;
		}
		if(card_d >= 28
			&& card_d < 32){
			card_d = 8;
		}
		if(card_d >= 32
			&& card_d < 36){
			card_d = 9;
		}
		if(card_d >= 36
			&& card_d < 40){
			card_d = 10;
		}
		if(card_d >= 40
			&& card_d < 44){
			card_d = 11;
		}
		if(card_d >= 44
			&& card_d < 48){
			card_d = 12;
		}
		if(card_d >= 48
			&& card_d < 52){
			card_d = 13;
		}





	}
	//Write the final score to file if it is the highest score
	if (fp = fopen("highscore.dat", "w+")){
		// if the file exist
		high_score = getw(fp);
		if(score > high_score){
			//if the score this time is the highest, remove the file
			// then create a new file recording the new highest score
			remove("highscore.dat");
			fclose(fp);
			fp = fopen("highscore.dat", "w");
			putw(score, fp);
			printf("Final score: %d(New Record!)\n", score);
			fclose(fp);
		}
		else{
			printf("Final score: %d\n", score);
		}
	}
	else{
		//if the high score file does not exist, simply create a file
		fp = fopen("highscore.dat", "w");
		putw(score, fp);
		printf("Final score: %d(New Record!)\n", high_score);
		fclose(fp);
	}


	return 0;
}