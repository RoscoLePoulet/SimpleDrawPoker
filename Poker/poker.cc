#include "poker.hh"

std::ostream & operator<<(std::ostream & os, symbol const & s) {
  switch(s){
  case symbol::diamonds :
      os << "diamonds";
    break;
    
  case symbol::spades :
      os << "spades";
    break;

  case symbol::clubs :
      os << "clubs";
    break;
    
  case symbol::hearts :
      os << "hearts";
    break;
  }
  return os;
}

std::ostream & operator<<(std::ostream & os, value const & v) {
  switch(v){
    
  case value::two :
     os << "Two";
    break;
    
  case value::three :
     os << "Three";
    break;
    
  case value::four:
    os << "Four";
    break;
    
  case value::five :
     os << "Five";
    break;
    
  case value::six:
    os << "Six";
    break;
    
  case value::seven :
    os << "Seven";
    break;
    
  case value::eight :
    os << "Eight";
    break;
    
  case value::nine :
    os << "Nine";
    break;
    
  case value::ten :
    os << "Ten";
    break;
    
  case value::jack :
    os << "Jack";
    break;

  case value::queen :
    os << "Queen";
    break;

  case value::king :
    os << "King";
    break;

  case value::ace :
    os << "Ace";
    break;
  }
  return os;
}

// CARD

void card::displayCard(std::ostream & os) const {
  os << getValue() << " of " << getSymbol() << "\n";
}

// HAND

hand::hand(deck D) {
  int i = 0;
  while(i++<5)
    {
      _hand.push_back(D.draw()); //On pioche 5 cartes du haut du paquet
    }
}

void hand::displayHand(std::ostream & os) const {
  for(auto h : _hand) h.displayCard(os);
}

// DECK

deck::deck() {
  for(auto s : v_symbol){
    for(auto v : v_value){
      card tmp = card (s,v);
      _deck.push_back(tmp);
    }
  }
  std::random_shuffle(_deck.begin(),_deck.end()); // On mélange le paquet
}

card deck::draw() {
  card tmp = card(_deck.front());
  _deck.erase(_deck.begin());
  return tmp;
}


