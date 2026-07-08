#include "lcd12864.h"
#include "typedefs.h"

u8 g_lcd12864_write_data[8][128];
u8 g_lcd12864_curr_data[8][128];

void lcd12864_init(void) {}
void lcd12864_init_lcd(void) {}
void lcd12864_delay(void) {}
void lcd12864_delay_ms(u32 ms) { (void)ms; }
void lcd12864_send_cmd(u8 dat8) { (void)dat8; }
void lcd12864_send_data(u8 dat8) { (void)dat8; }
u8 lcd12864_read_data(u8 page, u8 column) { (void)page; (void)column; return 0; }
void lcd12864_led_on(void) {}
void lcd12864_led_off(void) {}
void lcd12864_reset(void) {}
void lcd12864_set_address(u8 page, u8 column) { (void)page; (void)column; }
void lcd12864_clear_screen(void) {}
void lcd12864_clear_line(u8 page, u8 column, u8 len) { (void)page; (void)column; (void)len; }
void lcd12864_full_display(void) {}
void lcd12864_display_graphic_symbol(u8 page, u8 column, const u8 *p_data, u8 len) { (void)page; (void)column; (void)p_data; (void)len; }
void lcd12864_display_graphic_32x32(u8 page, u8 column, const u8 *dp) { (void)page; (void)column; (void)dp; }
void lcd12864_display_graphic_16x16(u8 page, u8 column, const u8 *dp) { (void)page; (void)column; (void)dp; }
void lcd12864_display_graphic_8x16(u8 page, u8 column, const u8 *dp) { (void)page; (void)column; (void)dp; }
void lcd12864_display_string_8x16(u8 page, u8 column, const u8 *text) { (void)page; (void)column; (void)text; }
void lcd12864_display_string_6x8(u8 page, u8 column, const u8 *text) { (void)page; (void)column; (void)text; }
void lcd12864_display_logo(void) {}
void lcd12864_set_auto_update(u8 is_auto) { (void)is_auto; }
void lcd12864_update_data(u8 is_update) { (void)is_update; }
void lcd12864_draw_point(u8 x, u8 y) { (void)x; (void)y; }
void lcd12864_draw_line(u8 x1, u8 y1, u8 x2, u8 y2) { (void)x1; (void)y1; (void)x2; (void)y2; }
