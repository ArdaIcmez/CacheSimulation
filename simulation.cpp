#include <iostream>
#include <fstream>
#include <cstdlib>
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

void Simulation::start(const std::string &filename) {
  // Go in a loop to read file, and call required functions
  std::ifstream ifs(filename);
  if (ifs.open()) {
    std::string line;
    while (ifs.good()) {
      std::getline(ifs, line);
      int type = line[0] - '0';
      line = line.substr(2);  // get the hex address
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
