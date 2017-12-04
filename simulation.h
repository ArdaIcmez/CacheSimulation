class Simulation {
  size_t noInstr;
  size_t noRead;
  size_t noWrite;
  size_t noMisc;
  size_t instrHit;
  size_t readHit;
  size_t writeHit;
  size_t miscHit;
 public:
 Simulation(): noInstr(0), noRead(0), noWrite(0), noMisc(0),
    instrHit(0), readHit(0), writeHit(0), miscHit(0) {}
  void analyseAdd(int type, bool status);
  void printResult();
  void start();
};
