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

void Simulation::start() {
  // Go in a loop to read file, and call required functions
  
}
