#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "simulation.h"

void Simulation::analyseAdd(int type, int status, int level) {
  //type is the type of instruction, status is the result of hit or miss
  switch (type) {
  case 0 :
    instrSt[level].addResult(status);
    break;
  case 1:
    readSt[level].addResult(status);
    break;
  case 2:
    writeSt[level].addResult(status);
    break;
  default:
    miscSt[level].addResult(status);
    break;
    }
}

void Simulation::printResult() {
  // Print that result with numbers like the one in website, calculating stuff should be straightforward
}

void Simulation::assignCaches(Cache ** c1, Cache ** c2, int type) {
  /*
    First cache is always instruction, second cache is always data
*/
  *c2 = NULL;
  if (type == 2) {
    *c1 = &(l1[0]);
    if (l2.size() > 0) {
      *c2 = &(l2[0]);
    }
  } else {
    if (l1.size() > 1) {
      *c1 = (&l1[1]);
    } else {
      *c1 = (&l1[0]);
    }
    if (l2.size() > 1) {
      *c2 = (&l2[1]);
    } else if (l2.size() > 0) {
      *c2 = (&l2[0]);
    }
  }
}
  
void Simulation::formCaches(std::vector<std::string> caches) {
  std::vector<std::string>::iterator it;
  size_t cacheSize = 0;
  size_t lineSize = 0;
  bool aWrite = false;
  for (it = caches.begin(); it != caches.end(); ++it) {
    std::stringstream ss;
    std::string cacheStr = *it;
    size_t sizePos = cacheStr.find("S");
    size_t linePos = cacheStr.find("P");
    ss << cacheStr.substr(sizePos+1, linePos - sizePos -1);
    ss << " ";
    ss << cacheStr.substr(linePos+1);
    ss >> cacheSize;
    ss >> lineSize;
    if (cacheStr[4] == 'W') {
      aWrite = true;
    }
    if (cacheStr[0] == '1') {
      Cache c(1, cacheSize, lineSize, cacheStr[2]-'0',cacheStr[3], aWrite, cacheStr[1]);
      l1.push_back(c);
    } else if(cacheStr[0] == '2') {
      Cache c(2, cacheSize, lineSize, cacheStr[2]-'0',cacheStr[3], aWrite, cacheStr[1]);
      l2.push_back(c);
    }
  }
}

void Simulation::start(char *filename) {
  // Go in a loop to read file, and call required functions
  std::ifstream ifs(filename);
  if (ifs.is_open()) {
    std::string line;
    Cache *c1;
    Cache *c2;
    while (ifs.good()) {
      std::getline(ifs, line);
      int type = line[0] - '0';
      line = line.substr(2);  // get the hex address
      //Call get caches to get the ones that are gonna be processed
      assignCaches(&c1,&c2,type);
      c1->printCache();
      if (c2 != NULL) {
	c2->printCache();
      }
      //Get the result of checkHit of that cache
      int result = c1->checkHit(line,type);
      if (c1->isDirty) {
	std::stringstream ss ;
	ss << (c1->dirtyAddress).substr(0,2);
	c1->dirtyAddress = (c1->dirtyAddress).substr(2);
	int dType;
	ss >> dType;
	analyseAdd(dType,c2->checkHit(c1->dirtyAddress,dType),2);
	c1->isDirty = false;
      }
      if (result != HIT && c2 != NULL) {
	analyseAdd(type,c2->checkHit(line,type),2);
      }
      analyseAdd(type,result,1);
    }
  } else {
    std::cerr << "Couldn't open the test file!" << std::endl;
    exit(EXIT_FAILURE);
  }
}
