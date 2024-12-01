//
// Created by Nadrino on 01/12/2024.
//

#ifndef ADVENT_OF_CODE_UTILS_H
#define ADVENT_OF_CODE_UTILS_H

#include "GenericToolbox.Fs.h"
#include "GenericToolbox.Vector.h"
#include "GenericToolbox.Loops.h"

#include <filesystem>

#define DEBUG_VAR(var_) std::cout << "[DEBUG_VAR]: " << #var_ << " = " << var_ << std::endl;

#define THIS_DAY_DIR std::filesystem::path(__FILE__).parent_path().parent_path().string()


#endif //ADVENT_OF_CODE_UTILS_H
