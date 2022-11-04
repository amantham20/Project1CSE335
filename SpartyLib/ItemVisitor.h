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

    /**
     * Visitor Pattern for Visiting Background
     * @param background
     */
    virtual void VisitBackground(Background* background) {}

    /**
     * Visitor Pattern for Visiting Slingshot
     * @param woodenSlingshot
     */
    virtual void VisitWoodenSlingshot(WoodenSlingshot* woodenSlingshot) {}

    /**
     * Visitor Pattern for Visiting GoalPost
     * @param goalpost
     */
    virtual void VisitGoalpost(Goalpost* goalpost) {}

    /**
     * Visitor Pattern for Visiting Block
     * @param block
     */
    virtual void VisitBlock(Block* block) {}

    /**
     * Visitor Pattern for Visiting Poly
     * @param poly
     */
    virtual void VisitPoly(Poly* poly) {}

    /**
     * Visitor Pattern for Visiting Foe
     * @param foe
     */
    virtual void VisitFoe(Foe* foe) {}

    /**
     * Visitor Pattern for Visiting GruffSparty
     * @param gruffSparty
     */
    virtual void VisitGruffSparty(GruffSparty* gruffSparty) {}

    /**
     * Visitor Pattern for Visiting HelmetSparty
     * @param helmetSparty
     */
    virtual void VisitHelmetSparty(HelmetSparty* helmetSparty) {}

    /**
     * Visitor Pattern for Visiting ScoreDisplay
     * @param scoreDisplay
     */
    virtual void VisitScoreDisplay(ScoreDisplay* scoreDisplay) {}

};

#endif //ANGRYSPARTY_ITEMVISITOR_H