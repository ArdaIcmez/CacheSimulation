#include <iostream>
class Stats {
 public:
  size_t total;
  size_t hit;
  size_t compMiss;
  size_t confMiss;
  size_t capMiss;
 Stats(): total(0), hit(0), compMiss(0), capMiss(0){}
  void addResult(int type) {
    total++;
    switch (type) {
    case 0 :
      hit++
      break;
    case 1:
      compMiss++
      break;
    case 2:
      confMiss++;
      break;
    case 3:
      capMiss++;
      break;
    default:
      std::cerr << "Something wrong with result" << std::endl;
      break;
    }
  }
};
