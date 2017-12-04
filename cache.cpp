Cache::Cache(size_t cap, size_t bs, const std::string &assoc, char mode):
  capacity(cap), blockSize(bs), associativity(assoc), mode(mode) {
  //Allocate memory for map
}

bool Cache::checkHit(Instruction instr, missType) {
  //The heart of the homework, most things will be done here depending on different types
}

void Cache::insertCache(Instruction instr) {
  //Easy, just add to map if called

}
