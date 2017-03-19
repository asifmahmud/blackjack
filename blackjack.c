/* 
   BlackJack Simulation
   
   author: Asif Mahmud
   date: 11/15/2014
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dealerSimulator(int p_sum){
	int sum = 0;
	int temp;
	while (1){
		printf("\nDealer draws another card.\n");
		printf("Dealer's card is: ");
    temp = (rand() % 13) + 1;
    printf("%d", temp > 10 ? 10 : temp);
		if (temp >= 11)
			sum += 10;
		else
			sum += temp;
		printf("\nDealer's value is %d, you have %d", sum, p_sum);
		if (sum > 21){
			printf("\nDealer loses. You win!\n");
			break;
		}
		else if (sum >= p_sum){
			printf("\nSorry, you lose!\n");
			break;
		}
	}

}


void playerPrompt(void){
	int input = 0;
	int sum = 0;
	int temp;
	printf("Your first card is: ");
	sum += (rand() % 13) + 1;
	printf("%d\n", sum = sum > 10 ? 10 : sum);
	printf("Do you want a another card?");
	printf("\nType 1 for Yes, 0 for No: ");
	scanf("%i", &input);
	if (input == 1){
		while (1){
			printf("Your next card is: ");
			temp = rand() % 13 + 1;
      printf ("%d\n", temp > 10 ? 10 : temp);
			if (temp >= 11)
				sum += 10;
			else
				sum += temp;
			printf("Your combined value is: %d", sum);
			if (sum > 21){
				printf("\nSorry, you lose!\n");
				break;
			}
			printf("\nDo you want a another card?");
			printf("\nType 1 for Yes, 0 for No: ");
			scanf("%i", &input);
			if (input == 0){
				dealerSimulator(sum);
				break;
			}
		}
	}
	else if (input == 0){
		dealerSimulator(sum);
	}
}




int main(void){

  /* initialize the random number generator with the current time */
  srand( time(NULL));
  
	char topLine[]    = "**********************************\n";
	char middleLine[] = "**     Welcome to BlackJack!    **\n";
	char bottomLine[] = "**********************************\n";

	printf("%s%s%s", topLine, middleLine, bottomLine, "\n");

	playerPrompt();
	return 0;
}