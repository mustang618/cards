// deck.h
//
// @brief A class that represents a deck of playing cards
//
// @details
// This class is responsible for shuffling and dealing a deck of cards. The deck should
// contain 52 cards 2 - 10, Jack,Queen, King, Ace of four suits, but no jokers.
//

#include <string>
#include <iostream>
#include "card.h"
using namespace std;

// number of cards in standard deck
static const int STANDARD_DECK_CARDS = 52;

class Deck
{
public:

  // Constructor
	Deck();

  // Destructor
	~Deck();

  // Prints N sets of M cards to std out.
	//
	// @param[in]	sets  Number of sets to deal.
  // @param[in]	cards Number of cards in each set.
	// @return void
	void deal_hand(int sets, int cards);

	// Prints deck to std out.
	//
	// @return void
	void print_deck();

	// Shuffle all 52 cards in deck using a seedable random number.
	//
  // @param[in]	seed Seedable random number.
	// @return void
	void shuffle(int seed);

	// Sorts all 52 cards in deck according to instructions: "Sorts the deck from lowest to highest by suit then by card face value. The suits are valued from highest to lowest: Spades, Hearts, Clubs, Diamonds. The cards are valued from highest to lowest: King,Queen,Jack,10,9,8,7,6,5,4,3,2,Ace."
	//
	// @return void
	void sort();

private:

  // private array of objects of class Card 
	Card m_card[STANDARD_DECK_CARDS];  
};
