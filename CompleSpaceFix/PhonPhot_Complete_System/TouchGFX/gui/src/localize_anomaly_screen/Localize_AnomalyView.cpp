#include <gui/localize_anomaly_screen/Localize_AnomalyView.hpp>
#include <BitmapDatabase.hpp>

static bool toggle = false;

Localize_AnomalyView::Localize_AnomalyView()
{

}

void Localize_AnomalyView::setupScreen()
{
    Localize_AnomalyViewBase::setupScreen();
}

void Localize_AnomalyView::tearDownScreen()
{
    Localize_AnomalyViewBase::tearDownScreen();
}

void Localize_AnomalyView::update_image()
{
	if(toggle == true)
    {
	  //Directional_Vector.setBitmap(Bitmap(BITMAP_KEEPHERNAMEOUTYOURMOUTH_ID));
	  Directional_Vector.setBitmap(Bitmap(BITMAP_KEEPHERNAMEOUTYOURMOUTH_ID));
	  Directional_Vector.invalidate();
    }
	else
	{
	  //Directional_Vector.setBitmap(Bitmap(BITMAP_VECTOR_IMAGE_ID));
	  Directional_Vector.setBitmap(Bitmap(BITMAP_VECTOR_IMAGE_ID));
	  Directional_Vector.invalidate();
	}
	toggle = !toggle;

}
