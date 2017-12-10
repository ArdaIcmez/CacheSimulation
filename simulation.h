#include "stats.h"
#include <vector>
#include "cache.h"
class Simulation {
 public:
  Stats instrSt[4];
  Stats readSt[4];
  Stats writeSt[4];
  Stats miscSt[4];
  std::vector<Cache> l1;
  std::vector<Cache> l2;
  std::vector<Cache> faL1;
  std::vector<Cache> faL2;
  bool classifyMisses;
 Simulation() : classifyMisses(false) {}
 void analyseAdd(int type, int status, int level);
  void printResult();
  void assignCaches(Cache ** c1, Cache ** c2, int type);
  void assignFACaches(Cache ** c1, Cache ** c2, int type);
  void formCaches(std::vector<std::string> caches);
  void start(char *filename);
};
