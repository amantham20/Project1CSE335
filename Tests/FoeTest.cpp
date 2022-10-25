/**
 * @file FoeTest.cpp
 * @author Milan Mihailovic
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Foe.h>
#include <Level.h>

TEST(FoeTest, FoeTest){
    std::shared_ptr<Level> level;
    Foe testFoe(level);
}
