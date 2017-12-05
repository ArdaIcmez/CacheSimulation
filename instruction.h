#include <sstream>

class Instruction {
  void parseInstr(const std::string &instr, int indSize, int offSize);
 public:
  Instruction(const std::string &instr, int indSize, int offSize);
  size_t index;
  size_t offset;
  size_t tag;
};
