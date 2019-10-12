#include "Cards.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void Deck::setTotalCards(const int *tCards)
{
	
	//Set the total amount of cards in the deck to the value specified in the driver
	totalCards = tCards;

	//Reserve 42 spots (number in totalCards) in the vector
	deckVector.reserve(*totalCards);

	//Initialize a dynamic array of type Card of size 42
	Card *card[42];
	int idNumber;

	//Initialize *totalCards amount of card objects
	for (int i = 0; i < *totalCards; i++)
	{
		//Create 42 card objects, and push each into the vector
		card[i] = new Card();

		//Set the card id
		card[i]->id = new int(i);
		//cout << *(card[i]->id);
		//card[i]->id = idNumber; 

		deckVector.push_back(card[i]); //Note: Will need to initalize the value of good, action for each card in assignment 2
	}
	
}

int Deck::getTotalCards()
{
	return *totalCards;
}

/* 
The deck must have a draw() method that allows a player to draw a card from the cards remaining in the deck and place it in with the cards space. 
6 cards are to be drawn at the beginning, and then 1 for each time a card is removed (bought by a player).
*/
void Deck::draw()
{

	//Draw randomly from deck
	srand(time(NULL)); //initialize the random seed
	int randIndex; 


	//Create hand object, initialize the size of the hand (6), and place in it 6 cards from the deck
	Hand *hand = new Hand();
	int *handSize = new int(6); 
	//*handSize = 5; can change size of hand later if need to

	//Allocate cost to each card in hand
	hand->cost[0] = 0;
	hand->cost[1] = 1;
	hand->cost[2] = 2;
	hand->cost[3] = 3;
	hand->cost[4] = 4;
	hand->cost[5] = 5;

	//Allocate handsize of space in the vector
	(*hand).handVector.reserve(*handSize);
	
	//Just a true value that we can make our pointer point to
	bool trueValue = true;	
	
	cout <<"Draw method (at start - draw 6 cards)" <<endl; //At the beginning we draw 6 cards, but later on only 1 card
	//Note: Need to make so that the same random card does not get picked
	for (int i = 0; i < 6; i++)
	{
		randIndex = rand() % (*totalCards); //will generates a random number between 0 and totalCards(so if totalCards is 42, then random value between 0 and 42)

		//Take out 6 cards from the deck, and make the hand vector objects point to them
		if (*(deckVector[randIndex]->outDeck) == 0) //If the card with that index is still in the deck, then put it in the hand 
		{
			(*hand).handVector.push_back(deckVector[randIndex]);
		}
		//Card is already out of deck, so take out another random card instead
		else
		{
			i--; //Decrement and go back to loop
			continue;
		}

		deckVector[randIndex]->outDeck = &trueValue; //When taking out a card from the deck, initialize member outDeck to true, meaning it got taken out of the deck. //Note: *(deckVector[randIndex]->out) gives 1 now (means true) for that particular index
		//hand->handVector[randIndex]->outHand = &trueValue; //Since card got taken out of deck, and placed in card space, initialize outHand to true

		cout << "Card: " << randIndex << " taken out of deck." <<endl;
	}

	cout <<endl<< "Draw method (during game - only draw 1 card)" << endl;
	for (int i = 0; i < 1; i++)
	{
		randIndex = rand() % (*totalCards);

		if (*(deckVector[randIndex]->outDeck) == 0)
		{
			(*hand).handVector.push_back(deckVector[randIndex]);
		}
		//Card is already out of deck, so take out another random card instead
		else
		{
			i--; //Decrement and go back to loop
			continue;
		}

		deckVector[randIndex]->outDeck = &trueValue; 

		cout << "Card: " << randIndex << " taken out of deck." << endl;

		hand->printHand(); //Print current hand space
	}

}

/*
Prints hand space
*/
void Hand::printHand()
{
	//cout <<endl << "Cards currently in the card space: " <<endl;
	//Cards currently in card space
	for (int i = 0; i < 6; ++i)
	{
		//cout << handVector[i]->id; //Need to fix this, it prints the address not the value of id

		//Print with cost of card
		//cout << " with cost: " << cost[i] <<endl;

	}

}

/*
The hand object is a collection of cards that has an exchange () method that allows the player to select the card from its position in the row 
and pay the coin cost listed at the top of the board
*/
void Hand::exchange()
{
}

int Card::getGood()
{
	return *good ;
}

int Card::getAction()
{
	return *action;
}

void Card::setGood(int *gd)
{
	good = gd;
}

void Card::setAction(int *act)
{
	action = act;
}
