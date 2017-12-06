#include "cache.h"
Cache::Cache(size_t lvl, size_t cap, size_t bs, int assoc, char rAlgo, bool aWrite, char cType):
  level(lvl), capacity(cap), blockSize(bs), type(assoc), replAlgo(rAlgo),
  allocWrite(aWrite),cacheType(cType) {
  offsetSize = log2(bs);
  if (type == 0) { // Fully Associtive
    indexSize = type;
  } else {
    indexSize = log2(cap / type); // n way set-associtive, DM = 1
  }
}

int Cache::checkHit(const std::string &instr, bool isWrite) {
  //The heart of the homework, most things will be done here depending on different types
  Instruction curInstr(instr, indexSize, offsetSize);
  //Check the map if it's a hit or a miss
  //if it's a miss, call findReplacement method
  //get the return value of findReplacement
  //call insertCache(curInst, value of find replacement) to insert into cache
  //Return HIT, COMP depending on result
  return HIT;
}

size_t Cache::checkReplacement(size_t index) {
  // Go to that index in the map, and figure out the block to replace
  return 0;
}

void Cache::insertCache(Instruction instr, size_t replaceIndex) {
  //Easy, just add to map if called

}
