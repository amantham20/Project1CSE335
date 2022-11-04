/**
 * @file Slingshot.h
 * @author Milan Mihailovic, zhiqiang ni
 *
 * Base Class for the slingshot items in the game.
 */

#ifndef ANGRYSPARTY_SLINGSHOT_H
#define ANGRYSPARTY_SLINGSHOT_H

#include "PositionalItem.h"
#include "Angry.h"
#include "Picture.h"

/**
 * Base class for a slingshot
 *
 * This applies to the wooden slingshots
 * and the goalposts in the game.
 */
class Slingshot : public PositionalItem {
private:
    /// x coordinate of the loading spot in meters
    double mXLoadSpot = 0;
    /// y coordinate of the loading spot in meters
    double mYLoadSpot = 0;

    /// x coordinate of the left attachment point for the rubber band in meters
    double mXLeftAttachment = 0;
    /// y coordinate of the left attachment point for the rubber band in meters
    double mYLeftAttachment = 0;

    /// x coordinate of the right attachment point for the rubber band in meters
    double mXRightAttachment = 0;

    /// y coordinate of the right attachment point for the rubber band in meters
    double mYRightAttachment = 0;

    /// Front View of the shared pointer of picture
    std::shared_ptr<Picture> mFrontPicture;

protected:
    /// A pointer to the currently loaded angry sparty
    Angry *mLoadedSparty;

    /// A pointer to the loaded sparty
    std::shared_ptr<Item> mLoadedSpartySP;

public:

    /**
     * Initializes a front picture image for the front of the slingshot
     * @param filename
     */
    void SetFrontPicture(const std::wstring& filename) {mFrontPicture = std::make_shared<Picture>(filename);};

    Slingshot(std::shared_ptr<Level> level);

    void XmlLoad(wxXmlNode *node) override;

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics) override;

    void DrawFront(std::shared_ptr<wxGraphicsContext> graphics);

    void DrawLeftRubberBand(std::shared_ptr<wxGraphicsContext> graphics);

    void DrawRightRubberBand(std::shared_ptr<wxGraphicsContext> graphics);

    virtual void LoadAngrySparty(Angry* sparty);

    /**
     * Get Loaded Angry Sparty Object
     * @return Angry object
     */
    Angry* GetLoadedAngrySparty(){ return mLoadedSparty; }

    /**
     * Get the x position of the loading spot
     * @return x position of the loading spot
     */
    double GetXLoadSpot() {return mXLoadSpot;};

    /**
     * Get the y position of the loading spot
     * @return y position of the loading spot
     */
    double GetYLoadSpot() {return mYLoadSpot;};

    /**
    * sets the loading x spot
    * @param x loading x spot
    */
    void SetXLoadSpot(double x) {mXLoadSpot = x;};

    /**
    * sets the loading y spot
    * @param y loading y spot
    */
    void SetYLoadSpot(double y) {mYLoadSpot = y;};

    /**
     * Gets the x coordinate of the left attachment point
     * @return x coordinate of the left attachment point
     */
    double GetXLeftAttachment() {return mXLeftAttachment;};

    /**
     * Gets the y coordinate of the left attachment point
     * @return y coordinate of the left attachment point
     */
    double GetYLeftAttachment() {return mYLeftAttachment;};

    /**
     * Gets the x coordinate of the right attachment point
     * @return x coordinate of the right attachment point
     */
    double GetXRightAttachment() {return mXRightAttachment;};

    /**
     * Gets the y coordinate of the right attachment point
     * @return y coordinate of the right attachment point
     */
    double GetYRightAttachment() {return mYRightAttachment;};

    /**
     * Sets the x coordinate of the left attachment point
     * @param x new x coordinate for the left attachment point for the rubber bands
     */
    void SetXLeftAttachment(double x) {mXLeftAttachment = x;};

    /**
     * Sets the y coordinate of the left attachment point
     * @param y new y coordinate for the left attachment point for the rubber band
     */
    void SetYLeftAttachment(double y) {mYLeftAttachment = y;};

    /**
     * Sets the x coordinate of the right attachment point
     * @param x new x coordinate for the right attachment point for the rubber band
     */
    void SetXRightAttachment(double x) {mXRightAttachment = x;};

    /**
     * Sets the y coordinate of the right attachment point
     * @param y new y coordinate for the right attachment point for the rubber bands
     */
    void SetYRightAttachment(double y) {mYRightAttachment = y;};

    /**
     * Getter for Virtual Rubber band Length function.
     * @return int
     */
    virtual int GetRubberBandLength() = 0;

    void ClearLoadedAngrySparty();
};

#endif //ANGRYSPARTY_SLINGSHOT_H
