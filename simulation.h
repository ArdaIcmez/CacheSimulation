#include "stats.h"
#include <vector>
class Simulation {
 public:
  Stats instrSt;
  Stats readSt;
  Stats writeSt;
  Stats miscSt;
 Simulation() {}
  void analyseAdd(int type, int status);
  void printResult();
  void formCaches(std::vector<std::string> caches);
  void start(const std::string &filename);
};
