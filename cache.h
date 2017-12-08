#include <iostream>
#include <map>
#include <cmath>
#include "instruction.h"
#include <queue>
#include <vector>
#include <list>
#include <set>
#define HIT 0
#define COMP 1
#define CONF 2
#define CAP 3

class Cache {
  typedef std::map<int,std::vector<std::pair<std::pair<size_t,bool>,std::string> > > Map_t;
  size_t level;
  size_t capacity;
  size_t blockSize;
  int type; //Direct-Mapped, Set-Associative, FA
  char replAlgo; // LRU, NMRU, RND, FIFO
  bool allocWrite; // read miss, write miss, no write miss
  char cacheType; // Unified, Data, Instruction
  size_t indexSize;
  size_t offsetSize;
  Instruction curInstr;
  //Data structures for replacement algorithms
  Map_t myCache;
  std::map<size_t, std::queue<size_t> > fifoMap;
  std::set<size_t> tags;
  std::map<size_t, std::list<size_t> > lruMap;//front is LRU, back is MRU 
 public:
  bool isDirty;
  std::string dirtyAddress;
  Cache(size_t lvl, size_t cap, size_t bs, int assoc, char rAlgo, bool aWrite, char cType);
 int checkHit(const std::string &instr, int typeI);
 size_t checkReplacement(size_t index);
 void insertCache(const Instruction &instr, size_t replaceIndex, bool isReplace);
 void printCache();
 void addUsedList(size_t setIndex, size_t index);
};
