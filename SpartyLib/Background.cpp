/**
 * @file Background.cpp
 * @author Aman Dhruva Thamminana
 */

#include "Background.h"

const std::wstring background = L"images/background1.png";
Background::Background(std::shared_ptr<wxGraphicsContext> graphics) : Item(graphics, background){

}
