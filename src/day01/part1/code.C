
#include "common.h"

void code(){

	auto lines = GenericToolbox::dumpFileAsVectorString("./input.txt");

	std::vector<long> id1List; id1List.reserve(lines.size());
	std::vector<long> id2List; id2List.reserve(lines.size());

  for( auto& line : lines ){
    auto elm = GenericToolbox::splitString(line, " ", true);

    id1List.emplace_back(std::stol(elm[0]));
    id2List.emplace_back(std::stol(elm[1]));
  }

  DEBUG_VAR(id1List.size());
  DEBUG_VAR(id2List.size());

  GenericToolbox::sortVector(id1List, [](long a_, long b_){ return a_ < b_; });
  GenericToolbox::sortVector(id2List, [](long a_, long b_){ return a_ < b_; });

  long sum{0};
  for( auto [id1, id2] : GenericToolbox::Zip(id1List, id2List) ){
    long dst = std::abs(id2 - id1);
    sum += dst;
  }

  DEBUG_VAR(sum);

}
