class Instruction {
  void parseInstr(const std::string &instr);
 public:
  Instruction(const std::string &instr);
  size_t index;
  size_t offset;
  size_t tag;
};
