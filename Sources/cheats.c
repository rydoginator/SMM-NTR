#include "cheats.h"

extern char    live_level_buffer[40];
extern char    item_level_buffer[40];
extern int     g_increase_menu_index;
extern int     g_decrease_menu_index;
extern int 	   g_increase_item_index;
extern int 	   g_decrease_item_index;

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

void    set_current_item_level(u8 value)
{
    WRITEU8(0x305A4C24, value);
}

u8      get_current_item_level(void)
{
    u8      current_level;

    current_level = READU8(0x305A4C24);
    return (current_level);
}

void    update_item_entry(void)
{
    u8 current_level;

    current_level = get_current_item_level();
    xsprintf(item_level_buffer, "Current item: %d", current_level);
}

void    increase_item_level(void)
{
    u8  current_level;

    current_level = get_current_item_level();
    if (current_level < 0x64)
        current_level++;
    else
        current_level = 0;
    set_current_item_level(current_level);
    update_item_entry();
    disableCheat(g_increase_item_index);
}

void    decrease_item_level(void)
{
    u8  current_level;

    current_level = get_current_item_level();
    if (current_level > 0)
        current_level--;
    else
        current_level = 0x64;
    set_current_item_level(current_level);
    update_item_entry();
    disableCheat(g_decrease_item_index);
}

void	inst_up(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU32(0x81C9AF8, 0x00000063);
		WRITEU32(0x81C9EE8, 0x00000063);
	}
}

void	star_inf(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{	
		WRITEU16(0x317B9F0C, 0x0008);
	}
}

void	time_inf(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
	WRITEU16(0x310366B6, 0x01F3);
	}
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
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU8(0x30F90F78, 0x0);
		WRITEU8(0x317B8BE8, 0x0);
		WRITEU8(0x317B8C00, 0x0);
		WRITEU8(0x317BA148, 0x0);
		WRITEU8(0x317BA1EC, 0x0);
		WRITEU8(0x317BBE68, 0x0);
	}
}

void	bg_mario(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU8(0x30F90F78, 0x01);
		WRITEU8(0x317B8BE8, 0x01);
		WRITEU8(0x317B8C00, 0x01);
		WRITEU8(0x317BA148, 0x01);
		WRITEU8(0x317BA1EC, 0x01);
		WRITEU8(0x317BBE68, 0x01);
	}
}

void	fr_mario(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU8(0x30F90F78, 0x02);
		WRITEU8(0x317B8BE8, 0x02);
		WRITEU8(0x317B8C00, 0x02);
		WRITEU8(0x317BA148, 0x02);
		WRITEU8(0x317BA1EC, 0x02);
		WRITEU8(0x317BBE68, 0x02);
	}
}

void	tl_mario(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU8(0x30F90F78, 0x03);
		WRITEU8(0x317B8BE8, 0x03);
		WRITEU8(0x317B8C00, 0x03);
		WRITEU8(0x317BA148, 0x03);
		WRITEU8(0x317BA1EC, 0x03);
		WRITEU8(0x317BBE68, 0x03);
	}	
}

void	tn_mario(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU8(0x30F90F78, 0x04);
		WRITEU8(0x317B8BE8, 0x04);
		WRITEU8(0x317B8C00, 0x04);
		WRITEU8(0x317BA148, 0x04);
		WRITEU8(0x317BA1EC, 0x04);
		WRITEU8(0x317BBE68, 0x04);	
	}
}

void	am_mario(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU8(0x30F90F78, 0x08);
		WRITEU8(0x317B8BE8, 0x08);
		WRITEU8(0x317B8C00, 0x08);
		WRITEU8(0x317BA148, 0x08);
		WRITEU8(0x317BA1EC, 0x08);
		WRITEU8(0x317BBE68, 0x08);	
	}
}

void	lot_pts(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU32(0x81C9B00, 0x3B9AC9FF);
	}
}

void	zero_pts(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU32(0x81C9B00, 0x00000000);
	}
}

void	num_pts(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU32(0x81C9B00, 0x075BCD15);
	}
}	

void	double_speed(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
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
}

void triple_speed(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
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
}

void ten_speed(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
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
}

void	flying_mario(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
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
}

void	invincible(void)
{
	if (READU16(0x335FEB4D) == 0x0001)
	{
		WRITEU16(0x317B9EE4, 0x000C);
	}
}

void	unlock_medals(void)
{
	WRITEU32(0x5586F8, 0xE3A00001);
}

void	coordMod(void)
{
	u32 offset = 0;

	if (is_pressed(BUTTON_Y + BUTTON_DU))
	{
		if (READU32(0x704FD0) != 0x0)
		{
			offset = READU32(0x704FD0);
			offset = READU32(0x10 + offset);
			offset += 0xC8;
			ADDTOFLOAT(offset, 0.6);
		}
	}
	if(is_pressed(BUTTON_Y + BUTTON_DD))
	{
		if (READU32(0x704FD0) != 0x0)
		{
			offset = READU32(0x704FD0);
			offset = READU32(0x10 + offset);
			offset += 0xC8;
			SUBTOFLOAT(offset, 0.6);
		}
	}
	if(is_pressed(BUTTON_Y + BUTTON_DL))
	{
		if (READU32(0x704FD0) != 0x0)
		{
			offset = READU32(0x704FD0);
			offset = READU32(0x10 + offset);
			offset += 0xC4;
			SUBTOFLOAT(offset, 0.35);
		}
	}
	if(is_pressed(BUTTON_Y + BUTTON_DR))
	{
		if (READU32(0x704FD0) != 0x0)
		{
			offset = READU32(0x704FD0);
			offset = READU32(0x10 + offset);
			offset += 0xC4;
			ADDTOFLOAT(offset, 0.35);
		}
	}
	offset = 0;
}

void 	decreaseObjectLimit(void)
{
	WRITEU32(0x305AB010, 0x00000000);
	WRITEU32(0x305ABA60, 0x00000000);
	WRITEU32(0x305AC540, 0x00000000);
	WRITEU32(0x305AC548, 0x00000000);
	WRITEU32(0x305AC54C, 0x00000000);
	WRITEU32(0x305F56D0, 0x00000000);
	WRITEU32(0x305F5D78, 0x00000000);
	WRITEU32(0x317D51F0, 0x00000000);
}

void	groundPound(void)
{
	u32 offset = 0;

	offset = 0x31047900;
	WRITEU8(0x23B4 + offset, 0x06);
	WRITEU8(0x23BC + offset, 0x06);
	WRITEU8(0x23C4 + offset, 0x06);
	WRITEU8(0x23CC + offset, 0x06);
	WRITEU8(0x23D4 + offset, 0x06);
	WRITEU8(0x23E8 + offset, 0x06);
	WRITEU8(0x23F0 + offset, 0x06);
	WRITEU8(0x23F8 + offset, 0x06);
	WRITEU8(0x2400 + offset, 0x06);
	WRITEU8(0x2408 + offset, 0x06);
	WRITEU8(0x2554 + offset, 0x06);
	WRITEU8(0x255C + offset, 0x06);
	WRITEU8(0x2564 + offset, 0x06);
	WRITEU8(0x256C + offset, 0x06);
	WRITEU8(0x2574 + offset, 0x06);
	offset += 0x78700;
	WRITEU8(0x23B4+ offset, 0x06);
	WRITEU8(0x23BC+ offset, 0x06);
	WRITEU8(0x23C4+ offset, 0x06);
	WRITEU8(0x23CC+ offset, 0x06);
	WRITEU8(0x23D4+ offset, 0x06);
	WRITEU8(0x23E8+ offset, 0x06);
	WRITEU8(0x23F0+ offset, 0x06);
	WRITEU8(0x23F8+ offset, 0x06);
	WRITEU8(0x2400+ offset, 0x06);
	WRITEU8(0x2408+ offset, 0x06);
	WRITEU8(0x2554+ offset, 0x06);
	WRITEU8(0x255C+ offset, 0x06);
	WRITEU8(0x2564+ offset, 0x06);
	WRITEU8(0x256C+ offset, 0x06);
	WRITEU8(0x2574+ offset, 0x06);
}