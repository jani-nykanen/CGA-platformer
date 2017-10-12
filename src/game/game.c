/// Game scene (source)
/// (c) 2017 Jani Nykänen

#include "game.h"

#include "../engine/graphics.h"
#include "../engine/bitmap.h"
#include "../engine/controls.h"
#include "../engine/assets.h"
#include "../engine/tilemap.h"

#include "objcontrol.h"
#include "stage.h"
#include "hud.h"
#include "status.h"

#include "../vpad.h"

/// Init game
static int game_init()
{

    // Init object control
    init_object_control();
    // Init stage
    init_stage();
    /// Init hud
    init_hud();
    /// Init status
    init_global_status();

    // Init vpad
    // TODO: Move to somewhere else, maybe?
    vpad_init();
    vpad_add_button(0,(int)SDL_SCANCODE_Z,1);
    vpad_add_button(1,(int)SDL_SCANCODE_X,2);
    vpad_add_button(3,(int)SDL_SCANCODE_RETURN,9);
    vpad_add_button(4,(int)SDL_SCANCODE_ESCAPE,8);

    return 0;
}

/// Update game
/// tm Time multiplier
static void game_update(float tm)
{
    update_obj_control(tm);
    stage_update(tm);
    hud_update(tm);

    vpad_update();

    get_global_status()->time -= 1.0f * tm;

    // TEMP, put into another file
    // Palette swap
    if(get_key_state((int)SDL_SCANCODE_F2) == PRESSED)
    {
        FRAME* f = get_current_frame();
        frame_swap_cga_palette(f);
    }
}

/// Draw game
static void game_draw()
{
    clear_frame(0);

    set_translation(0,0);
    stage_draw();
    draw_objects();

    set_translation(0,0);
    hud_draw();
}

/// Destroy game
static void game_destroy()
{
    destroy_assets();
}

/// Get game scene
SCENE get_game_scene()
{
    // Set scene functions
    SCENE s = (SCENE){game_init,game_update,game_draw,game_destroy};

    // Set scene name
    set_scene_name(&s,"game");

    return s;
}