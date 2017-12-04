void Simulation::analyseAdd(int type, bool status) {
  /*
    bool here signifies whether the operation was a hit or a miss

   */
  int incr = 0;
  if (status) {
    incr++;
  }
  
  switch (type) {
  case 0 :
    noInstr++;
    instrHit += incr;
    break;
  case 1:
    noRead++;
    readHit += incr;
    break;
  case 2:
    noWrite++;
    writeHit += incr;
    break;
  default:
    noMisc++;
    miscHit += incr;
    break;
    }
}

void Simulation::printResult() {
  // Print that result with numbers like the one in website, calculating stuff should be straightforward
}

void Simulation::start() {
  // Go in a loop to read file, and call required functions
}
