//
//  fun_game_menu.c
//  ICE
//
//  Created by mason on 2018/4/26.
//  Copyright © 2018年 mason. All rights reserved.
//

#include "surf_game_menu.h"
#include "global_func_dcl.h"

void load_surf_game_menu(void){
    printf("--------------------Game-----------------------\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*---------------------------------------------*\n");
    printf("*                                             *\n");
    printf("*    What game you wanna play?                *\n");
    printf("*                                             *\n");
    printf("*---------------------------------------------*\n");
    printf("*                                             *\n");
    printf("*    1>>>Lucky man                            *\n");
    printf("*                                             *\n");
    printf("*    2>>>Game 2                               *\n");
    printf("*                                             *\n");
    printf("*    3>>>Game 3                               *\n");
    printf("*                                             *\n");
    printf("*    0>>>Back                                 *\n");
    printf("*                                             *\n");
    printf("-----------------------------------------------\n");
    printf("Please select:");
    get_surf_game_menu_choi();
}

void get_surf_game_menu_choi(void){
    int game_menu_choi=0;
    int Wrong=1;
    int try_time=0;
    scanf("%d",&game_menu_choi);
    while(Wrong){
        switch (game_menu_choi) {
            case 1:
                system("clear");
                surf_game_luckyman();
                Wrong=0;
                break;
            case 2:
                system("clear");
                Wrong=0;
                break;
            case 3:
                system("clear");
                Wrong=0;
                break;
            case 0:
                system("clear");
                main();
                Wrong=0;
                break;
            default:
                try_time++;
                if(try_time>2){
                    printf("You've tried %d times!\n",try_time);
                    Wrong=0;
                }else{
                    printf("(%d times left)TRY AGAIN:",3-try_time);
                    scanf("%d",&game_menu_choi);
                }
        }
    }
    
}
