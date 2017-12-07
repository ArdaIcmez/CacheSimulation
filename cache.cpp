#include "cache.h"
#include <algorithm>
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
  int result = COMP;
  //Check the map if it's a hit or a miss
  if (myCache.find(curInstr.tag) == myCache.end()){
    insertCache(curInstr,0,false); // COMP
  } else {
    if (std::find((myCache[curInstr.index]).begin(),
		  (myCache[curInstr.index]).end(),
		  curInstr.tag) != myCache[curInstr.index].end()) {
      result = HIT; //HIT
    } else { //Miss
      if ((myCache[curInstr.index]).size() < pow(2, indexSize)) { //Have space
	insertCache(curInstr,0,false); // COMP
      } else { // Replacement
	if (tags.find(curInstr.tag) == tags.end()) { // First time for tag
	  tags.insert(curInstr.tag); //COMP
	} else {
	  result = ((type == 0) ? CAP : CONF);
	}
	insertCache(curInstr, checkReplacement(curInstr.index), true);
      }
      //Add to pqueue data structure!
      
    }
  }
  return result;
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
  size_t result = 0;
  switch (replAlgo) {
  case 'L': //Least recently used alrogithm
   /*
   if (lruMap[index].empty()) {
	for(size_t i = 0; i<type; i++) {
          lruMap[index].push_back(i); 
       } 
   }
   size_t way = lruMap[index].front();
   lruMap[index].pop_front(); 
   lruMap[index].push_back(way); 
   return way; 
  //NOTE NEED TO DO FOLLOWING FOR EVERY HIT:
  //lruMap[index].remove(way); 
  //lruMap[index].push_back(way);   
   */
    break;
  case 'R': //Random number algorithm
    srand((unsigned)time(0));
    if(type == 0) {
      result = (rand() % (int)(pow(2, indexSize)));
    } else {
      result = (rand() % type);
    }
    break;
  case 'N': //Not most recently used algorithm

    break;
  case 'F': //Fifo algorithm
    if (fifoMap[index].empty()) {
      return 0; 
    }
    result = fifoMap[index].front();
    fifoMap[index].pop();
    break;
  default :
    std::cerr << "Something went wrong with replacement algorithms!" << std::endl;
    break;
  }
  return result;
}

void Cache::insertCache(Instruction instr, size_t replaceIndex, bool isReplace) {
  fifoMap[instr.index].push(instr.tag); //Add to our fifo map
  if (isReplace) {
    (myCache[instr.index]).at(replaceIndex) = instr.tag;
  } else {
    myCache[instr.index].push_back(instr.tag);
  }
}
