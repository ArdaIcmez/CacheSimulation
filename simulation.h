#include "stats.h"
class Simulation {
 public:
  Stats instrSt;
  Stats readSt;
  Stats writeSt;
  Stats miscSt;
 Simulation() {}
  void analyseAdd(int type, bool status);
  void printResult();
  void start();
};
