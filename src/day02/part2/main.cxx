
#include "common.h"

enum Slope{
  Unset,
  Increasing,
  Decreasing,
  Cst
};


int main(int argc, char** argv){

  auto lines = GenericToolbox::dumpFileAsVectorString(THIS_DAY_DIR + "/input.txt");


  long nSafe{0};

  std::vector<std::vector<long>> unsafeLines{};
  unsafeLines.reserve(lines.size());

  auto getUnsafeCount = [](const std::vector<std::string>& levelList_){
    int unsafeCount{0};
    long lastLevel = -1;
    Slope lineSlope{Unset};
    for( auto& level : levelList_ ){

      long thisLevel = std::stol(level);

      // can't infer on the first one
      if( lastLevel == -1 ){ lastLevel = thisLevel; continue; }

      long step = thisLevel - lastLevel;
      if( std::abs(step) > 3 ){ unsafeCount++; continue; } // unsafe

      Slope thisSlope{Unset};
      if     ( step == 0 ){ thisSlope = Cst; }
      else if( step >  0 ){ thisSlope = Increasing; }
      else if( step <  0 ){ thisSlope = Decreasing; }

      if( lineSlope == Unset ){ lineSlope = thisSlope; }
      else if( thisSlope != lineSlope ){ unsafeCount++; continue; } // unsafe

      // updating only if safe
      lastLevel = thisLevel;

    }

    return unsafeCount;
  };

  for( auto& line : lines ){
    auto levelList = GenericToolbox::splitString(line, " ", true);

    if( getUnsafeCount(levelList) < 2 ){ nSafe++; }
    else{
      // check with removing the first one
      levelList.erase( levelList.begin() );
      // this time, no error is permitted
      if( getUnsafeCount(levelList) == 0 ){ nSafe++; }
    }

  }

  DEBUG_VAR(nSafe);

}
