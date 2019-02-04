#include "poker.hh" 

int main() {
  std::srand(std::time(NULL));
  deck D;
  hand H = hand(D);
  H.displayHand(std::cout);
  return 0;
}
