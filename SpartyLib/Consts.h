/**
 * @file Consts.h
 * @author Aman Dhruva Thamminana, Ian Valdovinos Granados
 *
 * Some basic handy constants
 */

#ifndef ANGRYSPARTY_CONSTS_H
#define ANGRYSPARTY_CONSTS_H

/**
 * Some basic handy constants
 */
class Consts {
public:
    /// Conversion of meters to centimeter display dimensions
    static constexpr double MtoCM = 100.0;

    /// Conversion of degrees to radians
    static constexpr double DtoR = 0.0174532925199;

    /// Convert of radians to degrees
    static constexpr double RtoD = 57.2957795131;

    static constexpr double Pi = 3.14159265358979323846;

    /// Convert of seconds to milliseconds
    static constexpr int SecToMillisec = 1000;

    /// Convert of milliseconds to seconds
    static constexpr double MillisecToSec = 0.001;

    // Slingshot constants:

    /// Base filename for the slingshot image
    const std::wstring WoodSlingshotBaseName = L"slingshot";

    /// Size of the slingshot image in meters
    const b2Vec2 WoodSlingshotSize = b2Vec2(0.5, 1.446);

    /// Back band attachment point
    const b2Vec2 WoodSlingshotBandAttachBack = b2Vec2(-0.15f, 1.12f);

    /// Front band attachment point
    const b2Vec2 WoodSlingshotBandAttachFront = b2Vec2(0.15f, 1.2f);

    /// Maximum amount the slingshot can be pulled in meters
    const double WoodSlingshotMaximumPull = 1;

    /// Pull angles from -pi to this value are allowed
    const double SlingshotMaximumNegativePullAngle = -1.7;

    /// Pull angles from +pi to this value are allowed
    const double SlingshotMinimumPositivePullAngle = 2.42;

    /// Width of the slingshot band in centimeters
    const int SlingshotBandWidth = 15;

    /// The slingshot band colour
    const wxColour SlingshotBandColor = wxColour(55, 18, 1);

    /// Initial Slingshot X location
    constexpr static const double InitialX = -5.5;

    /// Initial Slingshot Y location
    constexpr static const double InitialY = 0.25;

};

#endif //ANGRYSPARTY_CONSTS_H
