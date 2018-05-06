//
//  surf_game_luckyman.h
//  ICE
//
//  Created by mason on 2018/4/26.
//  Copyright © 2018年 mason. All rights reserved.
//

#include "stdhd.h"

#ifndef LKM_ACNT
#define LKM_ACNT

typedef struct lkm_acnt{
    char username[20];
    char password[20];
    struct lkm_acnt* next;
}lkm_acnt;
typedef lkm_acnt* P_lkm_anct;

#endif

#ifndef LKM_PLAYER_INFO
#define LKM_PLAYER_INFO
typedef struct lkm_player_info{
    char username[20];
    double lucky_index;
    int rank;
    struct lkm_player_info* next;
}lkm_player_info;
typedef lkm_player_info* P_lkm_player_info;
#endif

#define TM 2000000
#define TI 500000

void load_surf_game_luckyman(void);
void get_surf_game_luckyman_choi(void);
void surf_game_luckyman(void);
void surf_game_luckyman_login(void);
void surf_game_luckyman_register(void);
void func_game_luckyman_dstynode(P_lkm_anct H_tobedel);
void surf_game_luckyman_playing(char *player_name);
lkm_player_info func_game_luckyman_playing(char *player_name,int range_up);
int func_generate_randomly_num(int range_up);
void surf_game_luckyman_rank(void);
void func_game_luckyman_sort(P_lkm_player_info head);
void func_game_luckyman_pyifo_prt(P_lkm_player_info head);
