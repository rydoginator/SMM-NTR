#include "cheats.h"
#include "notes.h"
#include <string.h>

char	*builder_name = "RyDog";

char    live_level_buffer[40] = "First init";
int     g_increase_menu_index = 0;
int     g_decrease_menu_index = 0;

void	my_menus(void)
{
	//int index;
	int i;
	
	new_unselectable_entry("Mario Maker NTR Cheats Ver 1.0.2");
	update_live_entry();
	new_spoiler("Lives Codes");
        new_unselectable_entry(live_level_buffer);
        g_increase_menu_index = new_entry("Add one life", increase_live_level);
        g_decrease_menu_index = new_entry("Lose one life", decrease_live_level);
        new_entry("Max Lives", max_lives);
        new_entry("Instant 1 Up", inst_up);
    exit_spoiler();
    new_spoiler("Conditions");
    	new_entry("Star Invincibility", star_inf);
        new_entry("Invincibility without Star", invincible);
    	new_spoiler("Mario State Modifer (Beta)");
    		new_radio_entry("Small Mario (Stable)", sm_mario);
    		new_radio_entry("Big Mario (Stable)", bg_mario);
    		new_radio_entry("Fire Mario", fr_mario);
    		new_radio_entry("Tall Mario", tl_mario);
    		new_radio_entry("Tanooki Mario", tn_mario);
    	exit_spoiler();
    exit_spoiler();
    new_spoiler("Points Modifier");
    	new_radio_entry("0 Points", zero_pts);
    	new_radio_entry("999999999 Points", lot_pts);
    	new_radio_entry("123456789 Points", num_pts);
    exit_spoiler();
    new_spoiler("Miscellaneous Codes");
        new_entry("Hold B to fly", flying_mario);
        new_entry("Get all medals After Level Completion", unlock_medals);
    	new_entry("Unlimited Time", time_inf);
    	new_entry("Press L+R+A+B To Kill Yourself", kys);
    	new_spoiler("Current Speed Modifier(Use D Pad)");
    		new_radio_entry("2x", double_speed);
    		new_radio_entry("3x", triple_speed);
    		new_radio_entry("10x", ten_speed);
    	exit_spoiler();
    exit_spoiler();



	//for (i = 2; i <= index; i++)
	//	set_note(notes[i - 2], i);
}