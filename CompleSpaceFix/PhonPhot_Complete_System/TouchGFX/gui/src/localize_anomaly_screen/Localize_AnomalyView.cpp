#include <gui/localize_anomaly_screen/Localize_AnomalyView.hpp>
#include <BitmapDatabase.hpp>
#include "ipc_interface.h"

int8_t curr_region,prev_region = 0;

enum regions{

	REGION_1 = 1,
	REGION_2,
	REGION_3,
	REGION_4,
	REGION_5,
	REGION_6,
	REGION_7,
	REGION_8,
	REGION_9,
	REGION_10,
	REGION_11,
	REGION_12,
	};

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

// Gets value from IPC, if changed, re-draw image on localize_anomaly_screen
void Localize_AnomalyView::update_image()
{
	prev_region = curr_region;
	curr_region = IPCGetPredictedRegion();

	if(curr_region != prev_region)
	{

		switch(curr_region)
		{

			case REGION_1:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR1_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_2:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR2_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_3:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR3_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_4:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR4_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_5:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR5_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_6:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR6_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_7:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR7_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_8:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR8_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_9:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR9_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_10:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR10_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_11:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR11_ID));
				  Directional_Vector.invalidate();
				  break;
			case REGION_12:
				  Directional_Vector.setBitmap(Bitmap(BITMAP_RR12_ID));
				  Directional_Vector.invalidate();
				  break;
			default: break;
		}
	}
}
