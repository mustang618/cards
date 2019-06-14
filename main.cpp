// main.cpp
//
// @brief This program simulates the shuffling, sorting and dealing of a set of cards.
//
// @details
// 
//
#include <iostream>
#include "deck.h"

using namespace std;

int main()
{
  Deck deck;

  cout << "\n=== Original Deck ==============================\n";
  deck.print_deck();

  cout << "\n=== Shuffle Deck ==============================\n";
  deck.shuffle(15);  // use a seed value of 15
  deck.print_deck();

  cout << "\n=== Sorted Deck ==============================\n";
  deck.sort();
  deck.print_deck();

  cout << "\n=== Shuffled Again ==============================\n";
  deck.shuffle(34);  // use a seed value of 34
  deck.print_deck();

  cout << "\n=== Deal 3 sets of 5 cards ==============================\n";
  deck.deal_hand(3,5);

  cout << "\n=== Deal again ==============================\n";
  deck.deal_hand(3,5);
  // the second deal above will output the same hands as  the first deal as per instructed...
  // from instructions: "Also, two consecutive 'deals' should produce the same result. The deck must be shuffled in order to produce a different 'deal'."

  cout << "\n=== Suffle and deal again ==============================\n";
  deck.shuffle(99);  // use a seed value of 99
  deck.deal_hand(3,5);

  cout << "\n";
} 
