/**
 * @file PositionalItem.cpp
 * @author Rajmeet Singh Chandok, zhiqiang ni, Milan Mihailovic
 */

#include "pch.h"
#include "PositionalItem.h"
#include "Level.h"
#include "Consts.h"

/**
 * PositionalItem constructor
 * @param world
 */
PositionalItem::PositionalItem(std::shared_ptr<Level> level) : Item(level)
{

}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void PositionalItem::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"x", L"0").ToDouble(&mX);
    node->GetAttribute(L"y", L"0").ToDouble(&mY);
    Item::XmlLoad(node);
}

void PositionalItem::SetLocation(double x, double y)
{
    mX = x;
    mY = y;
}

/**
 * Function that checks if this item has been clicked on
 * @param x x coordinate to test
 * @param y y coordinate to test
 * @return True if the item has been clicked on. False otherwise.
 */
bool PositionalItem::HitTest(int x, int y)
{
    // Get the item's bitmap and image
    auto itemBitmap = Item::GetBitMap();
    auto itemImage = Item::GetImage();

    // Get bitmaps width and height
    double itemBitmapWidth = itemBitmap->GetWidth()*0.5;
    double itemBitmapHeight = itemBitmap->GetHeight()*0.5;

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner

    // Get the item's level and scale factor centimeters pixel
    std::shared_ptr<Level> level = Item::GetLevel();
    double scale = level->GetGameScale();

    // Get item's position in pixels
    double screenX = (GetX() * Consts::MtoCM + level->GetGameXOffset()) * scale;
    double screenY = (GetY() * Consts::MtoCM + level->GetGameYOffset()) * -scale;

    // Get position to test
    double testX = x - screenX + itemBitmapWidth / 2;
    double testY = y - screenY + itemBitmapHeight / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= itemBitmapWidth || testY >= itemBitmapHeight)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !itemImage->IsTransparent((int)testX, (int)testY);
}
