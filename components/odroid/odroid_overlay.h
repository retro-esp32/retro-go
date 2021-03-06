#include "odroid_colors.h"
#include "stdbool.h"
#include "stdint.h"

typedef enum {
    ODROID_DIALOG_INIT,
    ODROID_DIALOG_PREV,
    ODROID_DIALOG_NEXT,
    ODROID_DIALOG_ENTER,
} odroid_dialog_event_t;

typedef enum {
    ODROID_DIALOG_IGNORE,
    ODROID_DIALOG_RETURN,
} odroid_dialog_cb_return_t;

typedef enum
{
    ODROID_MENU_CLOSED,
    ODROID_MENU_PENDING,
    ODROID_MENU_OPEN,
} odroid_menu_state_t;

typedef struct odroid_dialog_choice odroid_dialog_choice_t;

struct odroid_dialog_choice {
    int  id;
    char label[32];
    char value[16];
    bool enabled;
    bool (*update_cb)(odroid_dialog_choice_t *, odroid_dialog_event_t);
};

extern odroid_menu_state_t odroid_menu_state;

void odroid_overlay_init();
void odroid_overlay_fill(uint16_t color);
void odroid_overlay_fill_rect(int x_, int y_, int width, int height, uint16_t color, int buffer_width);
void odroid_overlay_draw_chars(uint16_t x, uint16_t y, uint16_t width, char *text, uint16_t color, uint16_t color_bg);
void odroid_overlay_draw_battery(int x_, int y_, int percentage);

int odroid_overlay_dialog(char *header, odroid_dialog_choice_t *options, int options_count, int selected_initial);
int odroid_overlay_confirm(char *text, bool yes_selected);
int odroid_overlay_error(char *text);

int odroid_overlay_settings_menu(odroid_dialog_choice_t *extra_options, int extra_count);
int odroid_overlay_game_menu();

extern int ODROID_FONT_WIDTH;
extern int ODROID_FONT_HEIGHT;
