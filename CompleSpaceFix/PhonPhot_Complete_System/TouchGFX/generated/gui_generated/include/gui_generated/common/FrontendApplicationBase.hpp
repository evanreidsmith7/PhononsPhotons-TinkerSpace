/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // Main
    void gotoMainScreenNoTransition();

    void gotoMainScreenWipeTransitionSouth();

    // Localize_Anomaly
    void gotoLocalize_AnomalyScreenWipeTransitionNorth();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Main
    void gotoMainScreenNoTransitionImpl();

    void gotoMainScreenWipeTransitionSouthImpl();

    // Localize_Anomaly
    void gotoLocalize_AnomalyScreenWipeTransitionNorthImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
