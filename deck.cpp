#include <string>
#include <iostream>
#include <random>
#include "deck.h"

// constructor
Deck::Deck()
{
  // initialize standard deck to 
  // could specify standard deck in naother constructor
  // e.g. Deck(boolean jokers = 0)

  int c = 0; // deck card array counter

  for( int i=0; i<=sizeof(Card::Suit)-1; i++ ) // all four suits
  {
    for( int j=Card::ACE; j<=Card::KING; j++ ) // aces through kings
    {
      m_card[c].set_value(j, i); // could have this as a constructor?
      //card[c].print();
      c++;
    }
  }
}

// destructor
Deck::~Deck()
{
  // delete []m_card;
}

//
// Deck::deal_hand
//
void Deck::deal_hand(int sets, int cards)
{
  int c = 0; // deck card array counter

  for (int i=0; i<sets; i++)
  {
    for (int j=0; j<cards; j++)
    {
      m_card[c].print();
      c++;
    }
    cout << endl;
  }
}
  
//
// Deck::print_deck
//
void Deck::print_deck()
{
  static const int columns = 13;
  for (int i=0; i<STANDARD_DECK_CARDS; i++)
  {
    m_card[i].print();
    
    // could have below code optional...
    // e.g. print_deck(int mode = 0)
    // e.g. if (mode != 0) ...
    if ((i+1) % columns == 0)
    {
      cout << endl;
    }
  }
}

//
// Deck::shuffle
//
void Deck::shuffle(int seed)
{
  srand(seed);
  
  // shuffle array as std::shuffle_shuffle and std::random not working on this compiler ???
  // randomize or "shuffle" m_card array with 52 elements

  // shuffle elements in m_card array
  for (int i=0; i<STANDARD_DECK_CARDS; i++)
  {
    //using std::swap;
    int r = std::rand();
    
    swap(m_card[i], m_card[r % (i+1)]);
    //swap(m_card[i], m_card[r % STANDARD_DECK]);
  }
}

//
// Deck::sort
//
void Deck::sort()
{
  // Diamonds < Clubs < Hearts < Spades
  // A < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 10 < J < Q < K

  // go through m_card array and determine a numerical value to each card then assign a temp array element to that numerical value
  int foo[STANDARD_DECK_CARDS]; // temp array

  for (int i=0; i<STANDARD_DECK_CARDS; i++)
  {
    switch(m_card[i].get_suit())
    {
      case Card::DIAMONDS:
        foo[i] = 0;
        break;
      case Card::CLUBS:
        foo[i] = 1;
        break;
      case Card::HEARTS:
        foo[i] = 2;
        break;
      case Card::SPADES:
        foo[i] = 3;
        break;
    }

    // formula for numerical value for each card
    // assign temp array element to the numerical value
    foo[i] = foo[i] * 13 + m_card[i].get_value();
    //cout << foo[i];
  }
  //cout << endl;
  // Note: Instead of using a temp array, one can have a "numerical value order" property of the Card class. Then sort the deck based on the card's numerical_value(). 

  // bubble sort
  // sort through temp array and when swapping temp array elements also swap m_card array
  // this will result in the m_card array being sorted
  int flag = 1;
  for (int i=0; (i<STANDARD_DECK_CARDS-1) && flag; i++)
  {
    flag = 0;
    for (int j=0; j<STANDARD_DECK_CARDS-i-1; j++)
    {  
      if (foo[j] > foo[j+1])
      {
        swap(foo[j], foo[j+1]);
        swap(m_card[j], m_card[j+1]);
        flag = 1;
      }
    }
  }
}
