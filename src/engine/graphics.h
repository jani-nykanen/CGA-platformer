/// Graphics (header)
/// (c) 2017 Jani Nykänen

#ifndef __GRAPHICS__
#define __GRAPHICS__

#include "stdbool.h"

#include "bitmap.h"
#include "frame.h"

/// Flipping enumerations
enum
{
    FLIP_NONE = 0,
    FLIP_HORIZONTAL = 1,
    FLIP_VERTICAL = 2,
    FLIP_BOTH = 3,
};

/// Set the global renderer
/// < rend Renderer
void set_global_renderer(SDL_Renderer* rend);

/// Returns the global renderer
SDL_Renderer* get_global_renderer();

/// Clear screen
/// < r Red
/// < g Green
/// < b Blue
void clear(unsigned char r, unsigned char g, unsigned char b);

/// Set window dimensions
/// < w Width
/// < h Height
void set_dimensions(int w, int h);

/// Returns window dimensions
/// > Window dimensions
SDL_Point get_dimensions();

/// Bind frame so it can be used globally
/// < fr Frame to bind
void bind_frame(FRAME* fr);

/// Return currently used frame
/// > Frame
FRAME* get_current_frame();

/// Clear frame
/// < index Palette index
void clear_frame(Uint8 index);

/// Draw a non-scaled bitmap
/// < b Bitmap to be drawn
/// < dx X coordinate
/// < dy Y coordinate
/// < flip Flip
void draw_bitmap(BITMAP* b, int dx, int dy, int flip);

/// Draw a bitmap region
/// < b Bitmap to be drawn
/// < sx Source X
/// < sy Source Y
/// < sw Source W
/// < sh Source H
/// < dx X coordinate
/// < dy Y coordinate
/// < flip Flip
void draw_bitmap_region(BITMAP* b, int sx, int sy, int sw, int sh, int dx, int dy, int flip);

/// Draw text using a bitmap font
/// < b Bitmap font
/// < text Text
/// < len Text length
/// < dx Destination x
/// < dy Destination y
/// < xoff X offset
/// < yoff Y offset
/// < center Center text
void draw_text(BITMAP* b, Uint8* text, int len, int dx, int dy, int xoff, int yoff, bool center);

/// Fill rectangle
/// < x X coordinate
/// < y Y coordinate
/// < w Width
/// < h Height
/// < index Color index
void fill_rect(int x, int y, int w, int h, Uint8 index);

/// Set translation
/// < x Horizontal
/// < y Vertical
void set_translation(int x, int y);

#endif // __GRAPHICS__