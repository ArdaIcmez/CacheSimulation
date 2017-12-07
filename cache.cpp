#include "cache.h"
Cache::Cache(size_t lvl, size_t cap, size_t bs, int assoc, char rAlgo, bool aWrite, char cType):
  level(lvl), capacity(cap), blockSize(bs), type(assoc), replAlgo(rAlgo),
  allocWrite(aWrite),cacheType(cType) {
  offsetSize = log2(bs);
  size_t i = 1024;
  
  capacity *= i;
  if (type == 0) { // Fully Associtive
    indexSize = type;
  } else {
    indexSize = log2(capacity / (type * 32)); // n way set-associtive, DM = 1
  }
}

int Cache::checkHit(const std::string &instr, bool isWrite) {
  //The heart of the homework, most things will be done here depending on different types
  Instruction curInstr(instr, indexSize, offsetSize);
  //Check the map if it's a hit or a miss
  if (myCache.find(curInstr.tag) == myCache.end()){
    size_t replaceIndex = checkReplacement(0);
    insertCache(curInstr,replaceIndex);
    return COMP;
  }
  
  //if it's a miss, call findReplacement method
  //get the return value of findReplacement
  //call insertCache(curInst, value of find replacement) to insert into cache
  //Return HIT, COMP depending on result
  return HIT;
}

void Cache::printCache(){
  std::cout<<"level "<<level<<"\n";
  std::cout<<"capacity "<<capacity<<"\n";
  std::cout<<"blockSize "<<blockSize<<"\n";
  std::cout<<"type "<<type<<"\n";
  std::cout<<"allocWrite"<<allocWrite<<"\n";
  std::cout<<"indexSize"<<indexSize<<"\n";
  std::cout<<"offsetSize"<<offsetSize<<"\n";
  std::cout<<"\n";
}

size_t Cache::checkReplacement(size_t index) {
  // Go to that index in the map, and figure out the block to replace
  switch (replAlgo) {
  case 'L': //Least recently used alrogithm

    break;
  case 'R': //Random number algorithm
    srand((unsigned)time(0));
    if(type == 0){
      setNum = pow(2,indexSize);
      return (rand() % setNum);
    }else{
      return (rand()) % type);
    }

    break;
  case 'N': //Not most recently used algorithm

    break;
  case 'F': //Fifo algorithm
    if(fifoMap[index].empty()) {
      return 0; 
    }
    size_t way = fifoMap[index].front();
    fifoMap[index].pop();
    return way;

    break;
  default :
    std::cerr << "Something went wrong with replacement algorithms!" << std::endl;
    break;
  }
  return 0;
}

void Cache::insertCache(Instruction instr, size_t replaceIndex) {
  //Easy, just add to map if called
  //Also populate replacement algorithms data structures

}
