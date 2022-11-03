/**
 * @file BlockTest.cpp
 * @author Ian Valdovinos Granados
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Block.h>
#include <Level.h>

TEST(BlockTest, Construct){
   std::shared_ptr<Level> level;
   Block testBlock(level);
}