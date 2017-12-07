#include <iostream>
#include <map>
#include <cmath>
#include "instruction.h"
#include <queue>
#include <vector>
#include <set>
#define HIT 0
#define COMP 1
#define CONF 2
#define CAP 3

class Cache {
  typedef std::map<int,std::vector<size_t> > Map_t;
  size_t level;
  size_t capacity;
  size_t blockSize;
  int type; //Direct-Mapped, Set-Associative, FA
  char replAlgo;
  bool allocWrite; // read miss, write miss, no write miss
  char cacheType;
  size_t indexSize;
  size_t offsetSize;
//Need to add different stuff for replacement algorithm
Map_t myCache;
 std::map<size_t, std::queue<size_t> > fifoMap;
 //std::map<size_t, std::list<size_t> > lruMap; 

 std::set<size_t> tags;

 public:
 Cache(size_t lvl, size_t cap, size_t bs, int assoc, char rAlgo, bool aWrite, char cType);
 int checkHit(const std::string &instr, bool isWrite);
 size_t checkReplacement(size_t index);
 void insertCache(Instruction instr, size_t replaceIndex, bool isReplace);
 void printCache();
};
