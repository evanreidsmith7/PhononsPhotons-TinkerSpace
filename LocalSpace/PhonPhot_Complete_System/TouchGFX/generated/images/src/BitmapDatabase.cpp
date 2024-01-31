// 4.22.1 0x67c855f5
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_background_1[]; // BITMAP_BACKGROUND_1_ID = 0, Size: 480x272 pixels
extern const unsigned char image_pressed_button[]; // BITMAP_PRESSED_BUTTON_ID = 1, Size: 30x30 pixels
extern const unsigned char image_rect_button_pressed[]; // BITMAP_RECT_BUTTON_PRESSED_ID = 2, Size: 80x32 pixels
extern const unsigned char image_rect_button_unpressed[]; // BITMAP_RECT_BUTTON_UNPRESSED_ID = 3, Size: 80x32 pixels
extern const unsigned char image_slider_dark[]; // BITMAP_SLIDER_DARK_ID = 4, Size: 335x8 pixels
extern const unsigned char image_slider_light[]; // BITMAP_SLIDER_LIGHT_ID = 5, Size: 335x8 pixels
extern const unsigned char image_toggle_button_base[]; // BITMAP_TOGGLE_BUTTON_BASE_ID = 6, Size: 70x30 pixels
extern const unsigned char image_toggle_button_off[]; // BITMAP_TOGGLE_BUTTON_OFF_ID = 7, Size: 70x30 pixels
extern const unsigned char image_toggle_button_off2[]; // BITMAP_TOGGLE_BUTTON_OFF2_ID = 8, Size: 70x30 pixels
extern const unsigned char image_toggle_button_on[]; // BITMAP_TOGGLE_BUTTON_ON_ID = 9, Size: 70x30 pixels
extern const unsigned char image_toggle_button_on2[]; // BITMAP_TOGGLE_BUTTON_ON2_ID = 10, Size: 70x30 pixels
extern const unsigned char image_unpressed_button[]; // BITMAP_UNPRESSED_BUTTON_ID = 11, Size: 30x30 pixels
extern const unsigned char image_vector_image[]; // BITMAP_VECTOR_IMAGE_ID = 12, Size: 256x160 pixels
extern const unsigned char image_volume_background2[]; // BITMAP_VOLUME_BACKGROUND2_ID = 13, Size: 64x10 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_background_1, 0, 480, 272, 0, 0, 480, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 272, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_pressed_button, 0, 30, 30, 4, 4, 22, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 22, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_rect_button_pressed, 0, 80, 32, 0, 0, 80, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 32, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_rect_button_unpressed, 0, 80, 32, 0, 0, 80, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 32, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_slider_dark, 0, 335, 8, 3, 1, 329, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 5, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_slider_light, 0, 335, 8, 4, 0, 327, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 7, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_toggle_button_base, 0, 70, 30, 10, 2, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 26, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_toggle_button_off, 0, 70, 30, 10, 2, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 26, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_toggle_button_off2, 0, 70, 30, 10, 2, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 26, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_toggle_button_on, 0, 70, 30, 10, 2, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 26, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_toggle_button_on2, 0, 70, 30, 10, 2, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 26, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_unpressed_button, 0, 30, 30, 5, 5, 20, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 21, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_vector_image, 0, 256, 160, 0, 0, 256, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 160, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 },
    { image_volume_background2, 0, 64, 10, 0, 0, 64, ((uint8_t)touchgfx::Bitmap::RGB565) >> 3, 10, ((uint8_t)touchgfx::Bitmap::RGB565) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
