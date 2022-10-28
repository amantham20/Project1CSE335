/**
 * @file PlayingArea.cpp
 * @author Rajmeet Singh Chandok
 */

#include "PlayingArea.h"

PlayingArea::PlayingArea(std::vector<std::shared_ptr<Item>> items) : mItems(items)
{
}

void PlayingArea::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto item : mItems)
    {
        item->OnDraw(graphics);
    }
}