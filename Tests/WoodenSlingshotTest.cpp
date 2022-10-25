/**
 * @file SlingshotTest.cpp
 * @author Milan Mihailovic
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <WoodenSlingshot.h>
#include <Level.h>

TEST(WoodenSlingshotTest, WoodenSlingshotTest){
    std::shared_ptr<Level> level;
    WoodenSlingshot testWoodenSlingshot(level);
}
