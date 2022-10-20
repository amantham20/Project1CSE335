/**
 * @file Background.h
 * @author Aman Dhruva Thamminana
 *
 *
 */

#ifndef ANGRYSPARTY_BACKGROUND_H
#define ANGRYSPARTY_BACKGROUND_H

#include "Item.h"

class Background : public Item{
private:
//    std::unique_ptr<wxBitmap> mBackground;
public:
//    Background(std::unique_ptr<wxBitmap> pBackground):Item()

    Background(const std::wstring& filename) : Item(filename){};



};

#endif //ANGRYSPARTY_BACKGROUND_H
