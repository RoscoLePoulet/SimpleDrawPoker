#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <map> 

enum class symbol {diamonds, clubs, hearts, spades};
enum class value {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

//On utilise des vecteurs pour parcourir simplement les enums

const std::vector<symbol> v_symbol {symbol::clubs, symbol::diamonds, symbol::hearts, symbol::spades};

const std::vector<value> v_value {value::two, value::three, value::four, value::five, 
                          value::six, value::seven, value::eight, value::nine, value::ten, value::jack, 
                          value::queen, value::king, value::ace};
class card {
private:
  symbol _symbol;
  value _value;
public:
  card(const symbol &s, const value &v):_symbol(s),_value(v){}
  card(const card & c) = default;
  symbol getSymbol() const {return _symbol;}
  value getValue() const {return _value;}
  void setSymbol(const symbol &s) {_symbol = s;}
  void setValue(const value &v) {_value = v;}
  void displayCard(std::ostream & os) const;
};

class deck {
private:
  std::vector<card> _deck;
public:
  deck(); // On met les 52 cartes
  card draw();
};

class hand {
private:
  std::vector<card> _hand;
  std::map<std::string, value> _combination;
public:
  hand(deck D); //On pioche 5 cartes du deck
  void displayHand(std::ostream & os) const;
  void swapCard(card c); // Echange une carte de la main contre celle du haut du paquet, puis met l'ancienne carte en début du paquet.
  void displayCombination (std::ostream & os) const;
  void setCombination(); // Cherche la meilleure combinaison de cartes du jeu, et la met dans _combination.
};
