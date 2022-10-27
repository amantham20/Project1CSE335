/**
 * @file ItemVisitor.h
 * @author Ian Valdovinos Granados
 *
 * Item visitor base class
 */

#ifndef ANGRYSPARTY_ITEMVISITOR_H
#define ANGRYSPARTY_ITEMVISITOR_H

// Forward references to all item types
class Background;
class Goalpost;
class WoodenSlingshot;
class Block;
class Poly;
class Foe;
class GruffSparty;
class HelmetSparty;
class ScoreDisplay;

/**
 * Item visitor base class
 */
class ItemVisitor
{
protected:
    /**
     * Constructor
     * Ensures this is an abstract class
     */
    ItemVisitor() {}

public:

    virtual ~ItemVisitor() {}

    virtual void VisitBackground(Background* background) {}

    virtual void VisitWoodenSlingshot(WoodenSlingshot* woodenSlingshot) {}

    virtual void VisitGoalpost(Goalpost* goalpost) {}

    virtual void VisitBlock(Block* block) {}

    virtual void VisitPoly(Poly* poly) {}

    virtual void VisitFoe(Foe* foe) {}

    virtual void VisitGruffSparty(GruffSparty* gruffSparty) {}

    virtual void VisitHelmetSparty(HelmetSparty* helmetSparty) {}

    virtual void VisitScoreDisplay(ScoreDisplay* scoreDisplay) {}

};

#endif //ANGRYSPARTY_ITEMVISITOR_H