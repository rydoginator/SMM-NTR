#include "cheats.h"
#include "notes.h"
#include <string.h>

char	*builder_name = "RyDog";

    static const char * const live_note = "Sets your lives!";
    static const char * const inst_note = "Collect coins to instatnly level up!";
    static const char * const star_note = "Ever lasting star!";
    static const char * const inv_note = "Invincibility without star!";
    static const char * const medal_note = "Finish the course to acquire all the medals!";
    static const char * const cm_note = "Press Y + D Pad to move in the direction that you want!";
    static const char * const speed_note = "Use the D Pad";
    static const char * const grd_note = "Animation doesn't play";
    static const char * const obj_note = "Going over the object limit may cause you to crash.";


void with_note_common(const char *name, const char *note, void (*cheatfunction)(void), int type)
{
    int     index;

    if (type == 0)
        index = new_entry((char *)name, cheatfunction);
    else if (type == 1)
        index = new_radio_entry((char *)name, cheatfunction);
    else if (type == 2)
        index = new_spoiler((char *)name);
    else return;
    set_note(note, index);
}

inline void new_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 0);
}

inline void new_radio_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 1);
}

inline void new_spoiler_with_note(const char *name, const char *note)
{
    with_note_common(name, note, NULL, 2);
}

char    live_level_buffer[40] = "First init";
char    item_level_buffer[40] = "First init";
int     g_increase_menu_index = 0;
int     g_decrease_menu_index = 0;
int     g_increase_item_index = 0;
int     g_decrease_item_index = 0;

void	my_menus(void)
{
	//int index;
	int i;
	
	new_unselectable_entry("Mario Maker NTR Cheats Ver 1.1");
	update_live_entry();
    update_item_entry();
	new_spoiler_with_note("Lives Codes", live_note);
        new_unselectable_entry(live_level_buffer);
        g_increase_menu_index = new_entry("Add one life", increase_live_level);
        g_decrease_menu_index = new_entry("Lose one life", decrease_live_level);
        new_entry("Max Lives", max_lives);
        new_entry_with_note("Instant 1 Up", inst_note, inst_up);
    exit_spoiler();
    new_spoiler("Conditions");
    	new_entry_with_note("Star Invincibility", star_note, star_inf);
        new_entry_with_note("Invincibility without Star", inv_note, invincible);
    	new_spoiler("Mario State Modifer");
    		new_radio_entry("Small Mario", sm_mario);
    		new_radio_entry("Big Mario ", bg_mario);
    		new_radio_entry("Fire Mario", fr_mario);
    		new_radio_entry("Tall Mario", tl_mario);
    		new_radio_entry("Tanooki Mario", tn_mario);
            new_radio_entry("Mega Amiibo Mario", am_mario);
    	exit_spoiler();
    exit_spoiler();
    new_spoiler("Item Modifier");
        new_unselectable_entry(item_level_buffer);
        g_increase_item_index = new_entry("Go up", increase_item_level);
        g_decrease_item_index = new_entry("Go down", decrease_item_level);
    new_spoiler("Points Modifier");
    	new_radio_entry("0 Points", zero_pts);
    	new_radio_entry("999999999 Points", lot_pts);
    	new_radio_entry("123456789 Points", num_pts);
    exit_spoiler();
    new_spoiler_with_note("Current Speed Modifier", speed_note);
        new_radio_entry("2x", double_speed);
        new_radio_entry("3x", triple_speed);
        new_radio_entry("10x", ten_speed);
    exit_spoiler();
    new_spoiler("Miscellaneous Codes");
        new_entry_with_note("Use Ground Pound in SMB2", grd_note, groundPound);
        new_entry_with_note("Coordinates Modifier", cm_note, coordMod);
        //new_entry("Hold B to fly", flying_mario);
        new_entry_with_note("Get medals", medal_note, get_medals);
    	new_entry("Unlimited Time", time_inf);
    	new_entry("Press L+R+A+B To Kill Yourself", kys);
        new_entry_with_note("Decrease Object Limit", obj_note, decreaseObjectLimit);
    exit_spoiler();

    



	//for (i = 2; i <= index; i++)
	//	set_note(notes[i - 2], i);
}