//
//  surf_game_luckyman.h
//  ICE
//
//  Created by mason on 2018/4/26.
//  Copyright © 2018年 mason. All rights reserved.
//

#include "stdhd.h"

struct lkm_acnt{
    char username[20];
    int lucky_index;
    int rank;
};

void load_surf_game_luckyman(void);
void get_surf_game_luckyman_choi(void);
void surf_game_luckyman(void);
void surf_game_luckyman_login(void);
void surf_game_luckyman_register(void);
