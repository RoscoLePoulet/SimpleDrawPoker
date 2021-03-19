#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <string>

enum class symbol {diamonds, clubs, hearts, spades};
enum class value {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

const std::array<symbol, 4> t_symbol {symbol::clubs, symbol::diamonds, symbol::hearts, symbol::spades};

const std::array<value, 13> t_value {value::two, value::three, value::four, value::five, value::six, value::seven, value::eight, value::nine, value::ten, value::jack, value::queen, value::king, value::ace};
class Card {
private:
  symbol _symbol;
  value _value;
  friend std::ostream& operator<<(std::ostream& os, const Card& c);
  friend bool operator==(const Card& a, const Card& b);
public:
  Card(const symbol& s, const value& v):_symbol(s),_value(v){}
  Card(const Card& c) = default;
  symbol getSymbol() const {return _symbol;}
  value getValue() const {return _value;}
};

class Deck{
private:
  std::vector<Card> _deck;
  friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
public:
  Deck();
  Card draw(); //Pulls out a card, and deletes it from the deck.
};

class Hand{
private:
  std::vector<Card> _hand;
  friend std::ostream& operator<<(std::ostream& os, const Hand& hand);
public:
  Hand(Deck& deck);
  void changeCard(const int& i, Deck& deck); //Deletes the selected card and draws a new one from the deck.
};
