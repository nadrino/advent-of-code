
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

  for( auto& line : lines ){
    auto levelList = GenericToolbox::splitString(line, " ", true);

    bool isSafe{true};

    long lastLevel = -1;
    long lastStep = 0;
    Slope lineSlope{Unset};
    for( auto& level : levelList ){

      long thisLevel = std::stol(level);
      if( lastLevel == -1 ){
        lastLevel = thisLevel;
        continue;
      }

      lastStep = thisLevel - lastLevel;
      if( std::abs(lastStep) > 3 ){ isSafe = false; break; } // unsafe

      lastLevel = thisLevel;

      Slope thisSlope{Unset};
      if     ( lastStep == 0 ){ thisSlope = Cst; }
      else if( lastStep >  0 ){ thisSlope = Increasing; }
      else if( lastStep <  0 ){ thisSlope = Decreasing; }

      if( lineSlope == Unset ){ lineSlope = thisSlope; }
      else if( thisSlope != lineSlope ){ isSafe = false; break; } // unsafe

    }

    if( isSafe ){ nSafe++; }

  }

  DEBUG_VAR(nSafe);

}
