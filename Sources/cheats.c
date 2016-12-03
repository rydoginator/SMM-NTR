#include "cheats.h"

extern char    live_level_buffer[40];
extern int     g_increase_menu_index;
extern int     g_decrease_menu_index;

void    set_current_live_level(u8 value)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
    	WRITEU8(0x81C9B04, value);
	}
}

u8      get_current_live_level(void)
{
    u8      current_level;

    if (READU16(0x335FEB4D) == 0x0001)
    {
    	current_level = READU8(0x81C9B04);
    	return (current_level);
    }
}

void    update_live_entry(void)
{
    u8 current_level;

    current_level = get_current_live_level();
    xsprintf(live_level_buffer, "Current live level: %d", current_level);
}

void    increase_live_level(void)
{
    u8  current_level;

    current_level = get_current_live_level();
    if (current_level < 0x64)
        current_level++;
    else
        current_level = 0;
    set_current_live_level(current_level);
    update_live_entry();
    disableCheat(g_increase_menu_index);
}

void    decrease_live_level(void)
{
    u8  current_level;

    current_level = get_current_live_level();
    if (current_level > 0)
        current_level--;
    else
        current_level = 0x64;
    set_current_live_level(current_level);
    update_live_entry();
    disableCheat(g_decrease_menu_index);
}

void	max_lives(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
    	WRITEU8(0x81C9B04, 0x64);
	}
}

void	inst_up(void)
{
	WRITEU32(0x81C9AF8, 0x00000063);
	WRITEU32(0x81C9AFC, 0x00000063);
	WRITEU32(0x81C9EE8, 00000063);
}

void	star_inf(void)
{
	WRITEU16(0x317B9F0C, 0xFFFF);
}

void	time_inf(void)
{
	WRITEU16(0x310366B6, 0x01F3);
}

void	kys(void)
{
	if(is_pressed(BUTTON_L + BUTTON_R + BUTTON_A + BUTTON_B))
	{
		WRITEU16(0x310366B6, 0x0000);
	}
}

void	sm_mario(void)
{
	WRITEU8(0x30F90F78, 0x0);
	WRITEU8(0x317B8BE8, 0x0);
	WRITEU8(0x317B8C00, 0x0);
	WRITEU8(0x317BA148, 0x0);
	WRITEU8(0x317BA1EC, 0x0);
	WRITEU8(0x317BBE68, 0x0);	
}

void	bg_mario(void)
{
	WRITEU8(0x30F90F78, 0x01);
	WRITEU8(0x317B8BE8, 0x01);
	WRITEU8(0x317B8C00, 0x01);
	WRITEU8(0x317BA148, 0x01);
	WRITEU8(0x317BA1EC, 0x01);
	WRITEU8(0x317BBE68, 0x01);	
}

void	fr_mario(void)
{
	WRITEU8(0x30F90F78, 0x02);
	WRITEU8(0x317B8BE8, 0x02);
	WRITEU8(0x317B8C00, 0x02);
	WRITEU8(0x317BA148, 0x02);
	WRITEU8(0x317BA1EC, 0x02);
	WRITEU8(0x317BBE68, 0x02);	
}

void	tl_mario(void)
{
	WRITEU8(0x30F90F78, 0x03);
	WRITEU8(0x317B8BE8, 0x03);
	WRITEU8(0x317B8C00, 0x03);
	WRITEU8(0x317BA148, 0x03);
	WRITEU8(0x317BA1EC, 0x03);
	WRITEU8(0x317BBE68, 0x03);	
}

void	tn_mario(void)
{
	WRITEU8(0x30F90F78, 0x04);
	WRITEU8(0x317B8BE8, 0x04);
	WRITEU8(0x317B8C00, 0x04);
	WRITEU8(0x317BA148, 0x04);
	WRITEU8(0x317BA1EC, 0x04);
	WRITEU8(0x317BBE68, 0x04);	
}

void	lot_pts(void)
{
	WRITEU32(0x81C9B00, 0x3B9AC9FF);
}

void	zero_pts(void)
{
	WRITEU32(0x81C9B00, 0x00000000);
}

void	num_pts(void)
{
	WRITEU32(0x81C9B00, 0x075BCD15);
}	

void	double_speed(void)
{
	if(is_pressed(BUTTON_DR))
	{
		WRITEU32(0x317B88AC, 0x40400000);
		WRITEU32(0x317B88DC, 0x40400000); //Maybe I should use WRITEFLOAT here?
		WRITEU32(0x317B8C20, 0x40400000);
	}
	if(is_pressed(BUTTON_DL))
	{
		WRITEU32(0x317B88AC, 0xC0400000);
		WRITEU32(0x317B88DC, 0xC0400000); 
		WRITEU32(0x317B8C20, 0xC0400000);		
	}
}

void triple_speed(void)
{
	if(is_pressed(BUTTON_DR))
	{
		WRITEU32(0x317B88AC, 0x40900000);
		WRITEU32(0x317B88DC, 0x40900000); 
		WRITEU32(0x317B8C20, 0x40900000);
	}
	if(is_pressed(BUTTON_DL))
	{
		WRITEU32(0x317B88AC, 0xC0900000);
		WRITEU32(0x317B88DC, 0xC0900000); 
		WRITEU32(0x317B8C20, 0xC0900000);		
	}	
}

void ten_speed(void)
{
	if(is_pressed(BUTTON_DR))
	{
		WRITEU32(0x317B88AC, 0x41700000);
		WRITEU32(0x317B88DC, 0x41700000); 
		WRITEU32(0x317B8C20, 0x41700000);
	}
	if(is_pressed(BUTTON_DL))
	{
		WRITEU32(0x317B88AC, 0xC1700000);
		WRITEU32(0x317B88DC, 0xC1700000); 
		WRITEU32(0x317B8C20, 0xC1700000);		
	}	
}

void	flying_mario(void)
{
	WRITEU32(0x66D300, 0xEDDF0A01);
	WRITEU32(0x66D304, 0xEDC40A67);
	WRITEU32(0x66D308, 0xEAF21FB6);
	WRITEU32(0x66D30C, 0x3FC00000);
	WRITEU32(0x2F51E4, 0xEDC40A67);
	if (is_pressed(BUTTON_B))
	{
		WRITEU32(0x2F51E4, 0xEA0DE045);
	}
}

void	unlock_medals(void)
{
	WRITEU32(0x5586F8, 0xE3A00001);
}

void	invincible(void)
{
	WRITEU16(0x317B9EE4, 0xFFD6);
}