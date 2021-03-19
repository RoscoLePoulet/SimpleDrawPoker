#include "poker.hh"

std::ostream& operator<<(std::ostream& os, const symbol& s) {
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

std::ostream& operator<<(std::ostream& os, const value& v) {
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

std::ostream& operator<<(std::ostream& os, const Card& card){
  return os << card._value << " of " << card._symbol;
}

bool operator==(const Card& a, const Card& b){
  return ((a._value==b._value)&&(a._symbol==b._symbol));
}


// DECK

std::ostream& operator<<(std::ostream& os, const Deck& deck){
  for(Card card : deck._deck){
    os << card << "\n";
  }
  return os;
}

Deck::Deck(){
  for(int i=0; i<4; i++){      //Symbol
    for(int j=0; j<13; j++){     //Value
      _deck.push_back(Card(t_symbol[i],t_value[j]));
    }
  }
}

Card Deck::draw(){
  Card tmp = _deck.back();
  _deck.pop_back();
  return tmp;
}

// HAND

std::ostream& operator<<(std::ostream& os, const Hand& hand){
  for(Card card : hand._hand){
    os << card << "\n";
  }
  return os;
}

Hand::Hand(Deck& deck){
  for(int i=0; i<5; i++){
    _hand.push_back(deck.draw());
  }
}

void Hand::changeCard(const int &i, Deck& deck){
  _hand.erase(_hand.begin()+i);
  _hand.push_back(deck.draw());
}
  
