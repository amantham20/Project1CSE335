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
    //Background(Level *level);

//    std::unique_ptr<wxBitmap> mBackground;
public:
//    Background(std::unique_ptr<wxBitmap> pBackground):Item()

    //Background(const std::wstring& filename) : Item(filename){};


    void XmlLoad(wxXmlNode *node) override;
//    Background(const std::wstring& filename) : Item(filename){};
//    Background(const std::wstring& filename, std::shared_ptr<Level> level) : Item(level, filename){};
    Background(std::shared_ptr<Level> level) :Item(level){};
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void SetLocation(double x, double y) override;
};

#endif //ANGRYSPARTY_BACKGROUND_H
