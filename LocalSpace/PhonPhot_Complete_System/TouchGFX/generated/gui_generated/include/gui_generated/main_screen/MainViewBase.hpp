/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINVIEWBASE_HPP
#define MAINVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/progress_indicators/TextProgress.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Button.hpp>

class MainViewBase : public touchgfx::View<MainPresenter>
{
public:
    MainViewBase();
    virtual ~MainViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

    /*
     * Virtual Action Handlers
     */
    virtual void set_volume_slider(int value)
    {
        // Override and implement this function in Main
    }
    virtual void update_anomaly_alert()
    {
        // Override and implement this function in Main
    }
    virtual void toggle_voice()
    {
        // Override and implement this function in Main
    }
    virtual void alert_mute_pressed()
    {
        // Override and implement this function in Main
    }
    virtual void set_volume_encoder()
    {
        // Override and implement this function in Main
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image Main_Background;
    touchgfx::Container Button_Panel;
    touchgfx::BoxWithBorder Button_Panel_Background;
    touchgfx::Container Voice_Comm_Panel;
    touchgfx::BoxWithBorder Voice_Comm_Background;
    touchgfx::Container Voicecomm_Textbox;
    touchgfx::BoxWithBorder Voicecomm_Border;
    touchgfx::TextArea Voicecomm_Text;
    touchgfx::Container Volume_Textbox;
    touchgfx::BoxWithBorder Volume_Text_Border;
    touchgfx::TextProgress textProgress1;
    touchgfx::Container Toggle_Textbox;
    touchgfx::BoxWithBorder Toggle_Text_Border;
    touchgfx::TextArea Toggle_Text;
    touchgfx::Slider Volume_Slider;
    touchgfx::ToggleButton Voice_Toggle_Button;
    touchgfx::Container Anomaly_Detection_Panel;
    touchgfx::BoxWithBorder Anomaly_Detection_Background;
    touchgfx::Container Message_panel;
    touchgfx::BoxWithBorder Button_Panel_Background_1;
    touchgfx::Container Message_Board_Panel_1;
    touchgfx::BoxWithBorder MessageBoard_Background_1;
    touchgfx::Container Message_Board_Textbox_1;
    touchgfx::BoxWithBorder MessageBoard_Border_1_1;
    touchgfx::TextArea MessageBoard_Text_1;
    touchgfx::Container VoiceComm_Textbox_1;
    touchgfx::BoxWithBorder VoiceCommMess_Background;
    touchgfx::BoxWithBorder VoiceCommMess_Background2;
    touchgfx::TextArea VoiceCommMess_Text_On;
    touchgfx::TextArea VoiceCommMess_Text_Off;
    touchgfx::Container AnomalyWarning_Textbox_1_1;
    touchgfx::BoxWithBorder MessageBoard_Border_1_1_1_2;
    touchgfx::BoxWithBorder MessageBoard_Border_1_1_1_1_1;
    touchgfx::TextArea MessageBoard_Message_1;
    touchgfx::TextArea MessageBoard_Message_Muted;
    touchgfx::Container Alarm_Mute_Indicator_Textbox_1_1;
    touchgfx::BoxWithBorder AnomalyDetection_Border_1_1_1;
    touchgfx::TextArea AnomalyDetection_Text_1_1;
    touchgfx::Image Disabled_Button2;
    touchgfx::Image Disabled_Button1;
    touchgfx::Button Alert_Mute_Button;
    touchgfx::Button Localize_Button;
    touchgfx::Container Alarm_Mute_Indicator_Textbox_1_1_1;
    touchgfx::BoxWithBorder AnomalyDetection_Border_1_1_1_1;
    touchgfx::TextArea AnomalyDetection_Text_1_1_1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MainViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;
    touchgfx::Callback<MainViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MAINVIEWBASE_HPP
