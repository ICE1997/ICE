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
    int lucky_index;
    int rank;
    struct lkm_acnt* next;
}lkm_acnt;
typedef lkm_acnt* P_lkm_anct;
#endif
void load_surf_game_luckyman(void);
void get_surf_game_luckyman_choi(void);
void surf_game_luckyman(void);
void surf_game_luckyman_login(void);
void surf_game_luckyman_register(void);
