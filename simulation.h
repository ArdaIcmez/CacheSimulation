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
  void formCaches(std::vector<std::string> caches);
  void start(const std::string &filename);
};
