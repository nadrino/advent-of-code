
#include "common.h"

int main(int argc, char** argv){

  auto lines = GenericToolbox::dumpFileAsVectorString(THIS_DAY_DIR + "/input.txt");

  std::vector<long> id1List; id1List.reserve(lines.size());
  std::vector<long> id2List; id2List.reserve(lines.size());

  for( auto& line : lines ){
    auto elm = GenericToolbox::splitString(line, " ", true);

    id1List.emplace_back(std::stol(elm[0]));
    id2List.emplace_back(std::stol(elm[1]));
  }

  DEBUG_VAR(id1List.size());
  DEBUG_VAR(id2List.size());

  long sum{0};
  for( auto id1 : id1List ){
    long nbAppears = std::count(id2List.begin(), id2List.end(), id1);
    long score = nbAppears * id1;
    sum += score;
  }

  DEBUG_VAR(sum);

}
