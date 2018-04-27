//
//  func_main_menu.c
//  ICE
//
//  Created by mason on 2018/4/25.
//  Copyright © 2018年 mason. All rights reserved.
//
#include "stdhd.h"
#include "surf_main_menu.h"
#include "surf_game_menu.h"

struct tm *get_time(void){
    time_t t;
    struct tm *now;
    time(&t);
    now=localtime(&t);
    return now;
}

grt surf_main_menu_greeting(void){
    struct tm *przt;
    int now_hour;
    grt grts;
    przt=get_time();
    now_hour=przt->tm_hour;
    if(4<=now_hour&&now_hour<12){
        strcpy(grts.grt_ph,"Good morning!");
    }else if(12<=now_hour&&now_hour<16){
        strcpy(grts.grt_ph,"Good afternoon!");
    }else{
        strcpy(grts.grt_ph,"Good evenning!");
    }
    return grts;
}

void load_surf_main_menu(void){
    struct tm *now_time;
    grt grts=surf_main_menu_greeting();
    now_time=get_time();
    printf("--------------------Welcome--------------------\n");
    printf("*    Hello! Mason! %20s       *\n",grts.grt_ph);
    printf("*                                             *\n");
    printf("*    Date:  %4d.%02d.%2d                        *\n",
           1900+now_time->tm_year,1+now_time->tm_mon,now_time->tm_mday);
    printf("*    Time:  %02d:%02d:%02d                          *\n",
           now_time->tm_hour,now_time->tm_min,now_time->tm_sec);
    printf("***********************************************\n");
    printf("*                                             *\n");
    printf("*    What you wanna do?                       *\n");
    printf("*                                             *\n");
    printf("*---------------------------------------------*\n");
    printf("*                                             *\n");
    printf("*    1>>>Play Game                            *\n");
    printf("*                                             *\n");
    printf("*    2>>>Use Tool                             *\n");
    printf("*                                             *\n");
    printf("*    3>>>Boring funcs                         *\n");
    printf("*                                             *\n");
    printf("*    0>>>Exit                                 *\n");
    printf("*                                             *\n");
    printf("-----------------------------------------------\n");
    printf("Please select:");
    get_surf_main_menu_choi();
}

void get_surf_main_menu_choi(void){
    int menu_choi=0;
    int Wrong=1;
    int try_time=0;
    scanf("%d",&menu_choi);
    while(Wrong==1){
        switch (menu_choi) {
            case 1:
                Wrong=-1;
                system("clear");
                surf_game_menu();
                break;
            case 2:
                Wrong=-1;
                break;
            case 3:
                Wrong=-1;
                break;
            case 0:
                system("clear");
                printf("Bye!Thank you for your using!\n");
                exit(1);
                break;
            default:
                try_time++;
                if(try_time>2){
                    printf("You've tried %d times!\n",try_time);
                    Wrong=-1;
                }else{
                    printf("(%d times left)TRY AGAIN:",3-try_time);
                    scanf("%d",&menu_choi);
                }
        }
    }

}

