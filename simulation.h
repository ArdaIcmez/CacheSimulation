#include "stats.h"
#include <vector>
#include "cache.h"
class Simulation {
 public:
  Stats instrSt;
  Stats readSt;
  Stats writeSt;
  Stats miscSt;
  std::vector<Cache> l1;
  std::vector<Cache> l2;
 Simulation() {}
  void analyseAdd(int type, int status);
  void printResult();
  void assignCaches(Cache ** c1, Cache ** c2, int type);
  void formCaches(std::vector<std::string> caches);
  void start(char *filename);
};
