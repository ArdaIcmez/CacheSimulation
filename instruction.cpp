#include "instruction.h"
#include <iostream>
Instruction::Instruction(const std::string &instr, int indSize, int offSize, int typeI): index(0), offset(0), tag(0), typeInstr(-1), original(" "){
  typeInstr =typeI;
  std::stringstream ss;
  ss << typeI;
  original = ss.str();
  original += " " + instr;
  parseInstr(instr, indSize, offSize);
}

void Instruction::parseInstr(const std::string &instr, int indSize, int offSize){
  //Parse the instruction into index offset tag
  unsigned int address;
  std::stringstream ss;
  ss << std::hex << instr;
  ss >> address;
  for (int i = 0; i < offSize; i++) {
    offset += pow(2, i) * (address%2) ;
    address /= 2;
  }
  for (int i = 0; i < indSize; i++) {
    index += pow(2, i) * (address%2) ;
    address /= 2;
  }
  for (int i = 0; address > 0; i++) {
    tag += pow(2, i) * (address%2);
    address /= 2;
  }
}
