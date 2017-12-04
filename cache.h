#include <iostream>
#include <map>
#include "instruction.h"

class Cache {
  typedef std::map<int, std::string> Map_t
  size_t capacity;
  size_t blockSize;
  std::string associativity; //Direct-Mapped, Set-Associative, FA
  char mode; //None | Split | Unified
  Map_t myCache *;
public:
  Cache(size_t cap, size_t bs, const std::string &assoc, char mode);
  bool checkHit(Instruction instr, std::string &missType);
  void insertCache(Instruction instr);
};
