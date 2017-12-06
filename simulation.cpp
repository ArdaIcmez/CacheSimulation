#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "simulation.h"

void Simulation::analyseAdd(int type, int status) {
  //type is the type of instruction, status is the result of hit or miss
  switch (type) {
  case 0 :
    instrSt.addResult(status);
    break;
  case 1:
    readSt.addResult(status);
    break;
  case 2:
    writeSt.addResult(status);
    break;
  default:
    miscSt.addResult(status);
    break;
    }
}

void Simulation::printResult() {
  // Print that result with numbers like the one in website, calculating stuff should be straightforward
}

void Simulation::formCaches(std::vector<std::string> caches) {
  std::vector<std::string>::iterator it;
  size_t cacheSize;
  size_t lineSize;
  bool aWrite = false;
  std::stringstream ss;
  for (it = caches.begin(); it != caches.end(); ++it) {
    std::string cacheStr = *it;
    size_t sizePos = cacheStr.find("S");
    size_t linePos = cacheStr.find("L");
    ss << cacheStr.substr(sizePos+1, linePos - sizePos -1);
    ss >> cacheSize;
    ss << cacheStr.substr(linePos+1);
    ss >> lineSize;
    if (cacheStr[4] == 'W') {
      aWrite = true;
    }
    if (cacheStr[0] == '1') {
      l1.push_back(Cache(1, cacheSize, lineSize, cacheStr[2]-'0',
			   cacheStr[3], aWrite, cacheStr[1]));
    } else if(cacheStr[1] == '2') {
      l2.push_back(Cache(2, cacheSize, lineSize, cacheStr[2]-'0',
			   cacheStr[3], aWrite, cacheStr[1]));
    }
  }
  std::cout << "printing cache specs finished" << std::endl;
}

void Simulation::start(const std::string &filename) {
  // Go in a loop to read file, and call required functions
  std::ifstream ifs(filename.c_str());
  if (ifs.is_open()) {
    std::string line;
    while (ifs.good()) {
      std::getline(ifs, line);
      int type = line[0] - '0';
      line = line.substr(2);  // get the hex address
      std::cout << type << std::endl;
      //Call get caches to get the ones that are gonna be processed
      //From order, do following:
      //Get the result of checkHit of that cache
      //Call analyseAdd(type,result);
      //Go back if it's a miss
    }
  } else {
    std::cerr << "Couldn't open the test file!" << std::endl;
    exit(EXIT_FAILURE);
  }
}
