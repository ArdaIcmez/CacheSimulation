#include <sstream>
#include <cmath>
class Instruction {
  void parseInstr(const std::string &instr, int indSize, int offSize);
 public:
 Instruction(const std::string &instr, int indSize, int offSize, int typeI);
  size_t index;
  size_t offset;
  size_t tag;
  int typeInstr;
  std::string original;
 Instruction():index(0),offset(0),tag(0),typeInstr(0),original("init"){};
    Instruction(const Instruction &rhs): index(rhs.index), offset(rhs.offset), tag(rhs.tag), typeInstr(rhs.typeInstr) {}
  /*Instruction& operator=(const Instruction &rhs) {
    if (this != &rhs) {
      index = rhs.index;
      offset = rhs.offset;
      tag = rhs.tag;
      typeInstr = rhs.typeInstr;
    }
    return *this;
  }*/
};
