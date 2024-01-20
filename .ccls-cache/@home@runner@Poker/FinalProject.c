#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define size 20
#define RAND_MAX 51

typedef struct card_s {
	char suit;
	int face;
	struct card_s* next;
}card;

//3 heart,4 diamond,5 club,6 spade
void print_list(card*pt) {
	int counter = 1;
	while (pt != NULL) {
		if (pt->suit == 'S') {
			if (pt->face == 1) {
				printf("A%c ",6);
			}
			else if (pt->face == 11) {
				printf("J%c ", 6);
			}
			else if (pt->face == 12) {
				printf("Q%c ", 6);
			}
			else if (pt->face == 13) {
				printf("K%c ", 6);
			}
			else {
				printf("%d%c ", pt->face, 6);
			}
		}
		if (pt->suit == 'C') {
			if (pt->face == 1) {
				printf("A%c ", 5);
			}
			else if (pt->face == 11) {
				printf("J%c ", 5);
			}
			else if (pt->face == 12) {
				printf("Q%c ", 5);
			}
			else if (pt->face == 13) {
				printf("K%c ", 5);
			}
			else {
				printf("%d%c ", pt->face, 5);
			}
		}
		if (pt->suit == 'H') {
			if (pt->face == 1) {
				printf("A%c ", 3);
			}
			else if (pt->face == 11) {
				printf("J%c ", 3);
			}
			else if (pt->face == 12) {
				printf("Q%c ", 3);
			}
			else if (pt->face == 13) {
				printf("K%c ", 3);
			}
			else {
				printf("%d%c ", pt->face, 3);
			}
		}
		if (pt->suit == 'D') {
			if (pt->face == 1) {
				printf("A%c ", 4);
			}
			else if (pt->face == 11) {
				printf("J%c ", 4);
			}
			else if (pt->face == 12) {
				printf("Q%c ", 4);
			}
			else if (pt->face == 13) {
				printf("K%c ", 4);
			}
			else {
				printf("%d%c ", pt->face,4);
			}
		}
		pt = pt->next;
		if (counter == 13) {
			printf("\n");
			counter = 0;
		}
		++counter;
	}

}
void shuffle_deck(card* pt,int cardAmount) {
	card* pt1;
	card* pt2;
	int i, j, m;
	int k;
	int faceval2,faceval1;
	char suit1, suit2;
	for (i = 0; i < 1000; i++) {//how many shuffles
		pt1 = pt;
		for (j = 0; j < cardAmount; j++) {//goes through 52 cards
			pt2 = pt;
			k = rand() % cardAmount;

			for (m = 0; m < k; m++) {//moves pt2 k times to swap
				pt2 = pt2->next;
			}
		
			faceval1 = pt1->face;//lines of code swap the values between the two cards
			faceval2 = pt2->face;
			pt2->face = faceval1;
			pt1->face = faceval2;
			
			suit1 = pt1->suit;
			suit2 = pt2->suit;
			pt2->suit = suit1;
			pt1->suit = suit2;

			pt1 = pt1->next;
		}
	}

}
void create_player(card** pt,card*pt2) {
	card* player;
	card* tail=*pt;
	player = *pt;
	int i;
	for (i = 0; i < 4; i++) {//used to make first 5 nodes of deck to become players hand
		tail = tail->next;
	}
	*pt = tail->next;
	tail->next = NULL;
}
void print_game(char*nameInput,int*coins) {
	char spade = 6;

	*coins = 100;
	printf("Enter your name:");
	scanf("%s", nameInput);
	printf("$$$$$$$$$ $$$$$$$$$ $$$$$$$$$ $$$$$$$$$ $$$$$$$$$\n");
	printf("          $$$$$$$$$ $$$$$$$$$ $$$$$$$$$\n");
	printf("%s,\n", nameInput);
	printf("Let's play Two pairs or Better\n");
	printf("          $$$$$$$$$ $$$$$$$$$ $$$$$$$$$\n");
	printf("$$$$$$$$$ $$$$$$$$$ $$$$$$$$$ $$$$$$$$$ $$$$$$$$$\n");
	printf("$$$$$$$$$    Rank of winning            $$$$$$$$$\n");
	printf("                                        Pay\n");
	printf("Royal Flush         10%c J%c Q%c K%c A%c     250*bet\n", spade, spade, spade, spade, spade);
	printf("Straight Flush      2%c 3%c 4%c 5%c 6%c      100*bet\n", 5, 5, 5, 5, 5);
	printf("Four of a Kind      9%c 9%c 9%c 9%c %c       50*bet\n", 3, 4, 5, 6, 2);
	printf("Full House          9%c 9%c 9%c 3%c 3%c      20*bet\n", 4, 3, 6, 5, 3);
	printf("Flush               %c%c %c%c %c%c %c%c %c%c      10*bet\n", 2, 5, 2, 5, 2, 5, 2, 5, 2, 5);
	printf("Straight            4%c 5%c 6%c 7%c 8%c      5*bet\n", 2, 2, 2, 2, 2);
	printf("Three of a Kind     9%c 9%c 9%c %c %c        4*bet\n", 6, 5, 4, 2, 2);
	printf("Two Pair            K%c K%c 6%c 6%c %c       2*bet\n", 6, 4, 4, 3, 2);
	printf("********** ********** ********** ********** **********\n");
	printf("********** %s, you have %d coins **********\n", nameInput, *coins);
	printf("********** ********** ********** ********** **********\n");
}
void swap(card* pt, card* player, int pos,int swapAmt) {
	int faceval2, faceval1;
	char suit1, suit2;
	int i;
	pos = pos - 1;
	swapAmt = swapAmt - 1;
	for (i = 0; i < pos; i++) {
		player = player->next;
	}
	for (i = 0; i < swapAmt; i++) {
		pt = pt->next;
	}
	faceval1 = pt->face;//swaps values of the first card in the deck and the certain card of the player hand that is being swapped
	faceval2 = player->face;
	player->face = faceval1;
	pt->face = faceval2;
	suit1 = pt->suit;
	suit2 = player->suit;
	player->suit = suit1;
	pt->suit = suit2;
}
void check_cards(card* player,char*name,int*money,int*betAmount,int*gameOver) {
	int i;
	int SNum = 0; 
	int HNum = 0;
	int DNum = 0;  
	int CNum = 0;
	int face1 = 0;
	int face2 = 0;
	int face3 = 0;
	int face4= 0;
	int face5 = 0;
	int face6 = 0;
	int face7 = 0;
	int face8 = 0;
	int face9 = 0;
	int face10 = 0;
	int face11 = 0;
	int face12 = 0;
	int face13 = 0;
	card* temp;
	temp = player;
	for (i = 0; i < 5; ++i) {
		if (temp->suit == 'S') {//counts amount of spades in hand
			++SNum;
		}
		if (temp->suit == 'D') {//counts amount of diamonds in hand
			++DNum;
		}
		if (temp->suit == 'H') {//counts amount of hearts in hand
			++HNum;
		}
		if (temp->suit == 'C') {//counts amount of clubs in hand
			++CNum;
		}
		if (temp->face == 1) {//counts amount of aces in hand
			++face1;
		}
		if (temp->face == 2) {//counts amount of 2s in hand
			++face2;
		}
		if (temp->face == 3) {//counts amount of 3s in hand
			++face3;
		}
		if (temp->face == 4) {//counts amount of 4s in hand
			++face4;
		}
		if (temp->face == 5) {//counts amount of 5s in hand
			++face5;
		}
		if (temp->face == 6) {//counts amount of 6s in hand
			++face6;
		}
		if (temp->face == 7) {//counts amount of 7s in hand
			++face7;
		}
		if (temp->face == 8) {//counts amount of 8s in hand
			++face8;
		}
		if (temp->face == 9) {//counts amount of 9s in hand
			++face9;
		}
		if (temp->face == 10) {//counts amount of 10s in hand
			++face10;
		}
		if (temp->face == 11) {//counts amount of Js in hand
			++face11;
		}
		if (temp->face == 12) {//counts amount of Qs in hand
			++face12;
		}
		if (temp->face == 13) {//counts amount of Ks in hand
			++face13;
		}
		temp = temp->next;
	}
	if (((face10 == 1) && (face11 == 1) && (face12 == 1) && (face13 == 1) && (face1 == 1) && (SNum == 5))|| ((face10 == 1) && (face11 == 1) && (face12 == 1) && (face13 == 1) && (face1 == 1) && (DNum == 5))|| ((face10 == 1) && (face11 == 1) && (face12 == 1) && (face13 == 1) && (face1 == 1) && (HNum == 5))|| ((face10 == 1) && (face11 == 1) && (face12 == 1) && (face13 == 1) && (face1 == 1) && (CNum == 5))) {
		printf("%s's hand: (Royal Flush)\n", name);//royal flush 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 250;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face1 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (SNum == 5))|| ((face6 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (SNum == 5))|| ((face6 == 1) && (face7 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (SNum == 5))|| ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face4 == 1) && (face5 == 1) && (SNum == 5))|| ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face5 == 1) && (SNum == 5))|| ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (SNum == 5))|| ((face11 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (SNum == 5))|| ((face11 == 1) && (face12 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (SNum == 5))|| ((face11 == 1) && (face12 == 1) && (face13 == 1) && (face4 == 9) && (face10 == 1) && (SNum == 5))) {
		printf("%s's hand: (Straight Flush)\n", name);//straight with spades
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 100;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount,*money);
		
	}
	else if (((face1 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (HNum == 5)) || ((face6 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (HNum == 5)) || ((face6 == 1) && (face7 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (HNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face4 == 1) && (face5 == 1) && (HNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face5 == 1) && (HNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (HNum == 5)) || ((face11 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (HNum == 5)) || ((face11 == 1) && (face12 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (HNum == 5)) || ((face11 == 1) && (face12 == 1) && (face13 == 1) && (face4 == 9) && (face10 == 1) && (HNum == 5))) {
		printf("%s's hand: (Straight Flush)\n", name);//straight with hearts
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 100;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face1 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (CNum == 5)) || ((face6 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (CNum == 5)) || ((face6 == 1) && (face7 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (CNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face4 == 1) && (face5 == 1) && (CNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face5 == 1) && (CNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (CNum == 5)) || ((face11 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (CNum == 5)) || ((face11 == 1) && (face12 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (CNum == 5)) || ((face11 == 1) && (face12 == 1) && (face13 == 1) && (face4 == 9) && (face10 == 1) && (CNum == 5))) {
		printf("%s's hand: (Straight Flush)\n", name);//straight with clubs
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 100;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face1 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (DNum == 5)) || ((face6 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (DNum == 5)) || ((face6 == 1) && (face7 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (DNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face4 == 1) && (face5 == 1) && (DNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face5 == 1) && (DNum == 5)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (DNum == 5)) || ((face11 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (DNum == 5)) || ((face11 == 1) && (face12 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (DNum == 5)) || ((face11 == 1) && (face12 == 1) && (face13 == 1) && (face4 == 9) && (face10 == 1) && (DNum == 5))) {
		printf("%s's hand: (Straight Flush)\n", name);//straight with diamonds
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 100;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if ((face1 == 4) || (face2 == 4) || (face3 == 4) || (face4 == 4) || (face5 == 4) || (face6 == 4) || (face7 == 4) || (face8 == 4) || (face9 == 4) || (face10 == 4) || (face11 == 4) || (face12 == 4) || (face13 == 4)) {
		printf("%s's hand: (Four of a Kind)\n", name);//4 of a kind
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 50;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face1 == 3) && (face2 == 2)) || ((face1 == 3) && (face3 == 2)) || ((face1 == 3) && (face4 == 2)) || ((face1 == 3) && (face5 == 2)) || ((face1 == 3) && (face6 == 2)) || ((face1 == 3) && (face7 == 2)) || ((face1 == 3) && (face8 == 2)) || ((face1 == 3) && (face9 == 2)) || ((face1 == 3) && (face10 == 2)) || ((face1 == 3) && (face11 == 2)) || ((face1 == 3) && (face12 == 2)) || ((face1 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 Aces
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face2 == 3) && (face1 == 2)) || ((face2 == 3) && (face3 == 2)) || ((face2 == 3) && (face4 == 2)) || ((face2 == 3) && (face5 == 2)) || ((face2 == 3) && (face6 == 2)) || ((face2 == 3) && (face7 == 2)) || ((face2 == 3) && (face8 == 2)) || ((face2 == 3) && (face9 == 2)) || ((face2 == 3) && (face10 == 2)) || ((face2 == 3) && (face11 == 2)) || ((face2 == 3) && (face12 == 2)) || ((face2 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 2s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face3 == 3) && (face1 == 2)) || ((face3 == 3) && (face2 == 2)) || ((face3 == 3) && (face4 == 2)) || ((face3 == 3) && (face5 == 2)) || ((face3 == 3) && (face6 == 2)) || ((face3 == 3) && (face7 == 2)) || ((face3 == 3) && (face8 == 2)) || ((face3 == 3) && (face9 == 2)) || ((face3 == 3) && (face10 == 2)) || ((face3 == 3) && (face11 == 2)) || ((face3 == 3) && (face12 == 2)) || ((face3 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 3s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face4 == 3) && (face1 == 2)) || ((face4 == 3) && (face2 == 2)) || ((face4 == 3) && (face3 == 2)) || ((face4 == 3) && (face5 == 2)) || ((face4 == 3) && (face6 == 2)) || ((face4 == 3) && (face7 == 2)) || ((face4 == 3) && (face8 == 2)) || ((face4 == 3) && (face9 == 2)) || ((face4 == 3) && (face10 == 2)) || ((face4 == 3) && (face11 == 2)) || ((face4 == 3) && (face12 == 2)) || ((face4 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 4s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face5 == 3) && (face1 == 2)) || ((face5 == 3) && (face2 == 2)) || ((face5 == 3) && (face3 == 2)) || ((face5 == 3) && (face4 == 2)) || ((face5 == 3) && (face6 == 2)) || ((face5 == 3) && (face7 == 2)) || ((face5 == 3) && (face8 == 2)) || ((face5 == 3) && (face9 == 2)) || ((face5 == 3) && (face10 == 2)) || ((face5 == 3) && (face11 == 2)) || ((face5 == 3) && (face12 == 2)) || ((face5 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 5s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face6 == 3) && (face1 == 2)) || ((face6 == 3) && (face2 == 2)) || ((face6== 3) && (face3 == 2)) || ((face6 == 3) && (face4 == 2)) || ((face6 == 3) && (face5 == 2)) || ((face6 == 3) && (face7 == 2)) || ((face6== 3) && (face8 == 2)) || ((face6 == 3) && (face9 == 2)) || ((face6 == 3) && (face10 == 2)) || ((face6 == 3) && (face11 == 2)) || ((face6 == 3) && (face12 == 2)) || ((face6 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 6s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face7 == 3) && (face1 == 2)) || ((face7 == 3) && (face2 == 2)) || ((face7 == 3) && (face3 == 2)) || ((face7 == 3) && (face4 == 2)) || ((face7 == 3) && (face5 == 2)) || ((face7 == 3) && (face6 == 2)) || ((face7 == 3) && (face8 == 2)) || ((face7 == 3) && (face9 == 2)) || ((face7 == 3) && (face10 == 2)) || ((face7 == 3) && (face11 == 2)) || ((face7 == 3) && (face12 == 2)) || ((face7 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 7s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face8 == 3) && (face1 == 2)) || ((face8 == 3) && (face2 == 2)) || ((face8 == 3) && (face3 == 2)) || ((face8 == 3) && (face4 == 2)) || ((face8 == 3) && (face5 == 2)) || ((face8 == 3) && (face6 == 2)) || ((face8 == 3) && (face7 == 2)) || ((face8 == 3) && (face9 == 2)) || ((face8 == 3) && (face10 == 2)) || ((face8 == 3) && (face11 == 2)) || ((face8 == 3) && (face12 == 2)) || ((face8 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 8s 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face9 == 3) && (face1 == 2)) || ((face9 == 3) && (face2 == 2)) || ((face9 == 3) && (face3 == 2)) || ((face9 == 3) && (face4 == 2)) || ((face9 == 3) && (face5 == 2)) || ((face9 == 3) && (face6 == 2)) || ((face9 == 3) && (face7 == 2)) || ((face9 == 3) && (face8 == 2)) || ((face9 == 3) && (face10 == 2)) || ((face9 == 3) && (face11 == 2)) || ((face9 == 3) && (face12 == 2)) || ((face9 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 9s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face10 == 3) && (face1 == 2)) || ((face10 == 3) && (face2 == 2)) || ((face10 == 3) && (face3 == 2)) || ((face10 == 3) && (face4 == 2)) || ((face10 == 3) && (face5 == 2)) || ((face10 == 3) && (face6 == 2)) || ((face10 == 3) && (face7 == 2)) || ((face10 == 3) && (face8 == 2)) || ((face10 == 3) && (face9 == 2)) || ((face10 == 3) && (face11 == 2)) || ((face10 == 3) && (face12 == 2)) || ((face10 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 10s
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face11 == 3) && (face1 == 2)) || ((face11 == 3) && (face2 == 2)) || ((face11 == 3) && (face3 == 2)) || ((face11 == 3) && (face4 == 2)) || ((face11 == 3) && (face5 == 2)) || ((face11 == 3) && (face6 == 2)) || ((face11 == 3) && (face7 == 2)) || ((face11 == 3) && (face8 == 2)) || ((face11 == 3) && (face9== 2)) || ((face11 == 3) && (face10 == 2)) || ((face11 == 3) && (face12 == 2)) || ((face11 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 Js
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face12 == 3) && (face1 == 2)) || ((face12 == 3) && (face2 == 2)) || ((face12 == 3) && (face3 == 2)) || ((face12 == 3) && (face4 == 2)) || ((face12 == 3) && (face5 == 2)) || ((face12 == 3) && (face6 == 2)) || ((face12 == 3) && (face7 == 2)) || ((face12 == 3) && (face8 == 2)) || ((face12 == 3) && (face9 == 2)) || ((face12 == 3) && (face10 == 2)) || ((face12 == 3) && (face11 == 2)) || ((face12 == 3) && (face13 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 Qs
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face13 == 3) && (face1 == 2)) || ((face13 == 3) && (face2 == 2)) || ((face13 == 3) && (face3 == 2)) || ((face13 == 3) && (face4 == 2)) || ((face13 == 3) && (face5 == 2)) || ((face13 == 3) && (face6 == 2)) || ((face13 == 3) && (face7 == 2)) || ((face13 == 3) && (face8 == 2)) || ((face13 == 3) && (face9 == 2)) || ((face13 == 3) && (face10 == 2)) || ((face13 == 3) && (face11 == 2)) || ((face13 == 3) && (face12 == 2))) {
		printf("%s's hand: (Full House)\n", name);//full house with 3 Ks
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 20;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if ((SNum == 5) || (HNum == 5) || (CNum == 5) || (DNum == 5)) {
		printf("%s's hand: (Flush)\n", name);//flush 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 10;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
		
	}
	else if (((face1 == 1) && (face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1)) || ((face2 == 1) && (face3 == 1) && (face4 == 1) && (face5 == 1) && (face6 == 1)) || ((face3 == 1) && (face4 == 1) && (face5 == 1) && (face6 == 1) && (face7 == 1)) || ((face4 == 1) && (face5 == 1) && (face6 == 1) && (face7 == 1) && (face8 == 1)) || ((face5 == 1) && (face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1)) || ((face6 == 1) && (face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1)) || ((face7 == 1) && (face8 == 1) && (face9 == 1) && (face10 == 1) && (face11 == 1)) || ((face8 == 1) && (face9 == 1) && (face10 == 1) && (face11 == 1) && (face12 == 1)) || ((face9 == 1) && (face10 == 1) && (face11 == 1) && (face12 == 1) && (face13 == 1))) {
		printf("%s's hand: (Straight)\n", name);//straight
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 5;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);

	}
	else if ((face1 == 3) || (face2 == 3) || (face3 == 3) || (face4 == 3) || (face5 == 3) || (face6 == 3) || (face7 == 3) || (face8 == 3) || (face9 == 3) || (face10 == 3) || (face11 == 3) || (face12 == 3) || (face13 == 3)) {
		printf("%s's hand: (Three of a Kind)\n", name);//3 of a kind
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 4;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	//SEARCHING FOR TWO PAIRS
	else if (((face1 == 2) && (face2 == 2)) || ((face1 == 2) && (face3 == 2)) || ((face1 == 2) && (face4 == 2)) || ((face1 == 2) && (face5 == 2)) || ((face1 == 2) && (face6 == 2)) || ((face1 == 2) && (face7 == 2)) || ((face1 == 2) && (face8 == 2)) || ((face1 == 2) && (face9 == 2)) || ((face1 == 2) && (face10 == 2)) || ((face1 == 2) && (face11 == 2)) || ((face1 == 2) && (face12 == 2)) || ((face1 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing aces to every card
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face2 == 2) && (face3 == 2)) || ((face2 == 2) && (face4 == 2)) || ((face2 == 2) && (face5 == 2)) || ((face2 == 2) && (face6 == 2)) || ((face2 == 2) && (face7== 2)) || ((face2 == 2) && (face8 == 2)) || ((face2 == 2) && (face9 == 2)) || ((face2 == 2) && (face10 == 2)) || ((face2 == 2) && (face11 == 2)) || ((face2 == 2) && (face12 == 2)) || ((face2 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 2s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face3 == 2) && (face4 == 2)) || ((face3 == 2) && (face5 == 2)) || ((face3 == 2) && (face6 == 2)) || ((face3 == 2) && (face7 == 2)) || ((face3 == 2) && (face8 == 2)) || ((face3 == 2) && (face9 == 2)) || ((face3 == 2) && (face10 == 2)) || ((face3 == 2) && (face11 == 2)) || ((face3 == 2) && (face12 == 2)) || ((face3 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 3s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face4 == 2) && (face5 == 2)) || ((face4 == 2) && (face6 == 2)) || ((face4 == 2) && (face7 == 2)) || ((face4 == 2) && (face8 == 2)) || ((face4 == 2) && (face9 == 2)) || ((face4 == 2) && (face10 == 2)) || ((face4 == 2) && (face11 == 2)) || ((face4 == 2) && (face12 == 2)) || ((face4 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 4s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face5 == 2) && (face6 == 2)) || ((face5 == 2) && (face7 == 2)) || ((face5 == 2) && (face8 == 2)) || ((face5 == 2) && (face9 == 2)) || ((face5 == 2) && (face10 == 2)) || ((face5 == 2) && (face11 == 2)) || ((face5 == 2) && (face12 == 2)) || ((face5 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 5s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face6 == 2) && (face7 == 2)) || ((face6 == 2) && (face8 == 2)) || ((face6 == 2) && (face9 == 2)) || ((face6 == 2) && (face10 == 2)) || ((face6 == 2) && (face11 == 2)) || ((face6 == 2) && (face12 == 2)) || ((face6 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 6s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face7 == 2) && (face8 == 2)) || ((face7 == 2) && (face9 == 2)) || ((face7 == 2) && (face10 == 2)) || ((face7 == 2) && (face11 == 2)) || ((face7 == 2) && (face12 == 2)) || ((face7 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 7s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face8 == 2) && (face9 == 2)) || ((face8 == 2) && (face10 == 2)) || ((face8 == 2) && (face11 == 2)) || ((face8 == 2) && (face12 == 2)) || ((face8 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 8s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face9 == 2) && (face10 == 2)) || ((face9 == 2) && (face11 == 2)) || ((face9 == 2) && (face12 == 2)) || ((face9 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 9s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face10 == 2) && (face11== 2)) || ((face10 == 2) && (face12 == 2)) || ((face10 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing 10s to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face11 == 2) && (face12 == 2)) || ((face11 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing Js to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else if (((face12 == 2) && (face13 == 2))) {
		printf("%s's hand: (Two Pair)\n", name);//pairs comparing Qs to every card 
		print_list(player);
		printf("\n");
		*betAmount = *betAmount * 2;
		*money = *money + *betAmount;
		printf("\nYou WON %d coins and you now have %d coins\n", *betAmount, *money);
	}
	else {
	printf("%s's hand: ", name);//lost result
	print_list(player);
	printf("\n");
	*money = *money - *betAmount;
	printf("\n");
	printf("You LOST and you now have %d coins\n", *money);
	if (*money == 0) {
		*gameOver = 1;
	}
}
}
int main(void) {
	srand((int)time(0));//randomizes shuffle
	char nameInput[size];//name input
	char*nameInputPtr[size];
	strcpy(nameInputPtr,&nameInput);

	char spade = 6;
	int coins = 100;//coin amount variable
	int* coinsPtr;
	coinsPtr = &coins;
	int bet;//bet amount variable
	int*betPtr;
	betPtr = &bet;
	int allowingBet = 1;//used for while loop
	int allowingCard = 1;//used for while loop
	int cardPosition;//which card is being swapped
	int changeP1 = 0; //change first card
	int changeP2 = 0; //change 2nd card
	int changeP3 = 0;//change 3rd card
	int changeP4 = 0; //change 4th card
	int changeP5=0;//change 5th card
	int swapAmount = 1;//counts amount of swaps
	int* GAMEOVER = 0;//for while loop
	char enterKey='a';//for while loop
	int enter=0;//used for loop until user presses enter key
	int keepPlaying = 0;//used to for loop to continue playing
	int continuePlaying = 0;//for while loop
	int cardCounter = 0;//for while loop
	
	card* playerHand;
	card* headp = NULL, * temp, * tail = NULL;
	FILE* inp = fopen("Cards.txt", "r");
	temp = (card*)malloc(sizeof(card));
	while (fscanf(inp, "%d %c", &temp->face, &temp->suit) != EOF) {//reads in cards from text file
		if (headp == NULL) {
			headp = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
		tail->next = NULL;
		temp = (card*)malloc(sizeof(card));
	}
	
	shuffle_deck(headp,52);//shuffles all 52 cards
	playerHand = headp;
	create_player(&headp,playerHand);//creates player hand
	print_game(&nameInput,&coinsPtr);//prints game intro
	while (keepPlaying == 0) {
		while (allowingBet == 1) {
			printf("\n");
			printf("Place your bet (1-%d) coins (-1 to quit playing):", coins);			
			scanf("%d", &bet);
			if (bet == -1) {//if bet is -1 then game ends, variables in if statement are to exit all while loops
				allowingBet = 0;
				keepPlaying = 1;
				continuePlaying = 1;
				allowingCard = 0;
			}
			else if ((bet <= coins) && (bet >= 1)) {
				printf("\nYou bet %d coins\n", bet);//displays bet amount
				allowingBet = 0;
				continuePlaying = 0;
			}
		}
		while (continuePlaying == 0) {
			printf("%s's hand:\n", nameInput);
			printf("\n");
			print_list(playerHand);//prints player hand
			printf("\n");
			
			allowingCard = 1;//updates all these variables if user played more than once
			cardCounter = 0;
			changeP1 = 0;
			changeP2 = 0;
			changeP3 = 0;
			changeP4 = 0;
			changeP5 = 0;

			while (allowingCard == 1) {
				if (cardCounter == 5) {//if user switches all 5 cards then stop asking
					break;
				}
				printf("Pick cards (between 1-5) to hold (-1 to stop):");
				scanf("%d", &cardPosition);
				if (cardPosition == -1) {
					allowingCard = 0;//updated to exit loop
				}
				if (cardPosition == 1) {//indicates card 1 should stay the same
					changeP1 = 1;
				}
				if (cardPosition == 2) {//indicates card 2 should stay the same
					changeP2 = 1;
				}
				if (cardPosition == 3) {//indicates card 3 should stay the same
					changeP3 = 1;
				}
				if (cardPosition == 4) {//indicates card 4 should stay the same
					changeP4 = 1;
				}
				if (cardPosition == 5) {//indicates card 5 should stay the same
					changeP5 = 1;
				}
				++cardCounter;
			}
			if (changeP1 == 0) {
				if (swapAmount == 27) {//indicates that there are only 20 cards left in hand and deck
					shuffle_deck(headp, 47);//reshuffles card in deck which is 47 cards
					swapAmount = 1;//reupdates swap amount to 1 so that swap will be done with first card after the shuffle
				}
				swap(headp, playerHand, 1, swapAmount);
				++swapAmount;
			}
			if (changeP2 == 0) {
				if (swapAmount == 27) {//indicates that there are only 20 cards left in hand and deck
					shuffle_deck(headp, 47);
					swapAmount = 1;
				}
				swap(headp, playerHand, 2, swapAmount);
				++swapAmount;
			}
			if (changeP3 == 0) {
				if (swapAmount == 27) {//indicates that there are only 20 cards left in hand and deck
					shuffle_deck(headp, 47);
					swapAmount = 1;
				}
				swap(headp, playerHand, 3, swapAmount);
				++swapAmount;
			}
			if (changeP4 == 0) {
				if (swapAmount == 27) {//indicates that there are only 20 cards left in hand and deck
					shuffle_deck(headp, 47);
					swapAmount = 1;
				}
				swap(headp, playerHand, 4, swapAmount);
				++swapAmount;
			}
			if (changeP5 == 0) {
				if (swapAmount == 27) {//indicates that there are only 20 cards left in hand and deck
					shuffle_deck(headp, 47);
					swapAmount = 1;
				}
				swap(headp, playerHand, 5, swapAmount);
				++swapAmount;
			}
			printf("\n");
			check_cards(playerHand, &nameInput, &coins, &bet, &GAMEOVER);//check the player's hand to see if they won or lost
			
			if (GAMEOVER == 1) {//if user lost all their coins
				printf("\n");
				printf("You lost all of your coins. Game Over!\n");
				allowingBet = 0;//updates these variables so user can exit the while loops
				keepPlaying = 1;
				continuePlaying = 1;
			}
			else {
				while (enter == 0) {//used to run until user presses enter key
					printf("Hit Enter key to continue:");
					scanf("%*c%c", &enterKey);
					if (enterKey == 10) {
						enter = 1;
					}
				}
				printf("\n");
				printf("********* ********* ********* ********* *********\n");
				printf("********* %s, you have %d coins *********\n", nameInput, coins);//displays user coins after turn
				allowingBet = 1;//updates variables so user can run through while loops again
				allowingCard = 0;
				continuePlaying = 1;
			}
			
		}
	}
	printf("\nGoodbye %s", nameInput);

	free(headp);
	free(playerHand);

	return 0;
}
