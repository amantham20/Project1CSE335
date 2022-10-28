/**
 * @file SpartyTracker.h
 * @author Ian Valdovinos Granados
 *
 * Concrete visitor that keeps track of the Angry Sparties
 */

#ifndef ANGRYSPARTY_SPARTYTRACKER_H
#define ANGRYSPARTY_SPARTYTRACKER_H

#include "ItemVisitor.h"
#include "Angry.h"
#include "HelmetSparty.h"
#include "GruffSparty.h"
#include "Slingshot.h"
#include "Level.h"

/**
 * Concrete visitor that keeps track of the Angry Sparties
 */
class SpartyTracker : public ItemVisitor {
private:
    /// Angry Sparty counter
    int mNumSparty = 0;

    /// All of the Angry Sparties
    std::vector<Angry*> mSparties;
public:
    /**
     * Get the number of Angry Sparties
     * @return Number of Angry Sparties
     */
    int GetNumSparties() const {return mNumSparty; }

    void VisitHelmetSparty(HelmetSparty* helmetSparty) override;

    void VisitGruffSparty(GruffSparty* gruffSparty) override;

    void ReloadSlingshot(std::shared_ptr<Slingshot> slingshot, std::shared_ptr<Level> level);

};

#endif //ANGRYSPARTY_SPARTYTRACKER_H
