#include "cache.h"
Cache::Cache(size_t cap, size_t bs, int type, bool aWrite):
  capacity(cap), blockSize(bs), type(type), allocWrite(aWrite) {
  offsetSize = log2(bs);
  if (type == 0) { // Fully Associtive
    indexSize = type;
  } else {
    indexSize = log2(cap / type); // n way set-associtive, DM = 1
  }
}

int Cache::checkHit(const std::string &instr) {
  //The heart of the homework, most things will be done here depending on different types
  Instruction curInstr(instr, indexSize, offsetSize);
  //Check the map if it's a hit or a miss
  //if it's a miss, call findReplacement method
  //get the return value of findReplacement
  //call insertCache(curInst, value of find replacement) to insert into cache
  //Return HIT, COMP depending on result
  return HIT;
}

void Cache::insertCache(Instruction instr, size_t replaceIndex) {
  //Easy, just add to map if called

}
