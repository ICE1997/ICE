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
    printf("*    What game wanna play?                    *\n");
    printf("*                                             *\n");
    printf("*---------------------------------------------*\n");
    printf("*                                             *\n");
    printf("*    1>>>Game 1                               *\n");
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
    int try_time=1;
    scanf("%d",&game_menu_choi);
    while(Wrong==1){
        switch (game_menu_choi) {
            case 1:
                Wrong=-1;
                break;
            case 2:
                Wrong=-1;
                break;
            case 3:
                Wrong=-1;
                break;
            case 0:
                system("clear");
                main();
                Wrong=-1;
                break;
            default:
                try_time++;
                printf("(%d times left)TRY AGAIN:",4-try_time);
                scanf("%d",&game_menu_choi);
                if(try_time>2){
                    printf("You've tried 3 times!\n");
                    Wrong=-1;
                }
        }
    }
    
}
