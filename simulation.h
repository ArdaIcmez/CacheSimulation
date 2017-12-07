#include "stats.h"
#include <vector>
#include "cache.h"
class Simulation {
 public:
  Stats instrSt[2];
  Stats readSt[2];
  Stats writeSt[2];
  Stats miscSt[2];
  std::vector<Cache> l1;
  std::vector<Cache> l2;
 Simulation() {}
 void analyseAdd(int type, int status, int level);
  void printResult();
  void assignCaches(Cache ** c1, Cache ** c2, int type);
  void formCaches(std::vector<std::string> caches);
  void start(char *filename);
};
