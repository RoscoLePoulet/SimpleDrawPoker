#include "poker.hh" 

int main() {
  Deck deck;
  Hand hand(deck);

  std::cout << "\n\n\n";
  std::cout << hand;

  hand.changeCard(0,deck);
  
  std::cout << "\n\n\n";
  std::cout << hand;
  return 0;
}
