#include <queue>

int main (void) {

  std::map<size_t, std::queue<size_t> > fifoMap;
  size_t index;
  if(fifoMap[index].empty()) {
    return 0;
  }
  size_t way = fifoMap[index].front();
  fifoMap[index].pop();
  return way;


  return 0;
}
