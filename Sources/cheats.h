#ifndef CHEATS_H
#define CHEATS_H

#include "../Includes/plugin.h"
#include <string.h>
#include <stdlib.h>

#define   add_search_replace(find, replace) g_find[g_i] = find; g_replace[g_i] = replace; g_i++
#define   reset_search()                    memset(g_find, 0, sizeof(g_find)); memset(g_replace, 0, sizeof(g_replace)); g_i = 0
#define   add_to_address(addr, value)       *(u32 *)addr += value
#define   sub_to_address(addr, value)       *(u32 *)addr -= value
#define     ADDTOFLOAT(addr, add_value)         *(float *)addr += (float)add_value
#define     SUBTOFLOAT(addr, sub_value)         *(float *)addr -= (float)sub_value

/*
** Helpers
*/

void	find_and_replace_multiple(void *start_addr, u32 length);
void    disableCheat(int index);
void    update_live_entry(void);
void    increase_live_level(void);
void    decrease_live_level(void);

void    update_item_entry(void);
void    increase_item_level(void);
void    decrease_item_level(void);


void	inst_up(void);
void	zero_pts(void);
void	lot_pts(void);
void	num_pts(void);
void	time_inf(void);
void	kys(void);
void	double_speed(void);
void	triple_speed(void);
void	ten_speed(void);
void	flying_mario(void);
void	invincible(void);
void	unlock_medals(void);
void	coordMod(void);
void	item_mod(void);
void 	decreaseObjectLimit(void);
void	groundPound(void);

/*
** State Mod Codes
*/

void	star_inf(void);
void	max_lives(void);
void	sm_mario(void);
void	bg_mario(void);
void	fr_mario(void);
void	tl_mario(void);
void	tn_mario(void);
void	am_mario(void);



#endif
