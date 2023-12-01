#include <stdlib.h>
#define SPRITE_MAP_2D 0x0
#define SPRITE_MAP_1D 0x40
#define SPRITE_ENABLE 0x1000
*display_control = MODE0 | BG0_ENABLE | SPRITE_ENABLE | SPRITE_MAP_1D;

int main {
    

}

/* setup all sprites */
void sprite_clear() {

    next_sprite_index = 0;

    for(int i = 0; i < NUM_SPRITES; i++) {
        sprites[i].attribute0 = SCREEN_HEIGHT;
        sprites[i].attribute1 = SCREEN_WIDTH;
    }
}

struct Link link;
link_init(&link);

/*scroll */
int xscroll = 0;
int yscroll = 0;

while (1) {

    link_update(&link);

    if (button_pressed(BUTTON_RIGHT)) {
        if (link_right(&link)) {
            xscroll++;
        }
    } else if (button_pressed(BUTTON_LEFT)) {
        if (link_left(&link)) {
            xscroll--;
        }

    } else if (button_pressed(BUTTON_UP)) {
       if (link_up(&link)) {
            y++;
        }
    } else if (button_pressed(BUTTON_DOWN)) {
        if (link_down(&link)) {
            y--;
        }

    } else {
        koopa_stop(&koopa);
    }    


    wait_vblank();
    *bg0_x_scroll = xscroll;
    sprite_update_all();

    /* delay some*/
    delay(300);
}

int pix_per_second = speed >> 8;

