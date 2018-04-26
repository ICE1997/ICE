//
//  strt_body.h
//  ICE
//
//  Created by mason on 2018/4/25.
//  Copyright © 2018年 mason. All rights reserved.
//
typedef struct grt {
    char grt_ph[20];
}grt;

struct tm *get_time(void);
grt surf_main_menu_greeting(void);
void load_surf_main_menu(void);
void get_surf_main_menu_choi(void);
