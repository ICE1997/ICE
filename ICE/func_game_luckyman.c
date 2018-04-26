//
//  func_game_luckyman.c
//  ICE
//
//  Created by mason on 2018/4/26.
//  Copyright © 2018年 mason. All rights reserved.
//

#include "surf_game_luckyman.h"
#include "global_func_dcl.h"
void load_surf_game_luckyman(void){
    printf("------------------LuckyMan---------------------\n");
    printf("*                                             *\n");
    printf("*    Game Description:                        *\n");
    printf("*         The robot will randomly generate    *\n");
    printf("*         1 num,and you guess what is it.     *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*              1>>>Log in                     *\n");
    printf("*                                             *\n");
    printf("*              2>>>Register                   *\n");
    printf("*                                             *\n");
    printf("*              0>>>Back                       *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("*                                             *\n");
    printf("-----------------------------------------------\n");
    printf("Please select:");
    get_surf_game_luckyman_choi();
}

void get_surf_game_luckyman_choi(void){
    int luckyman_choi=0;
    int Wrong=1;
    int try_time=0;
    scanf("%d",&luckyman_choi);
    while(Wrong==1){
        switch (luckyman_choi) {
            case 1:
                Wrong=-1;
                system("clear");
                break;
            case 2:
                Wrong=-1;
                system("clear");
                break;
            case 0:
                Wrong=-1;
                system("clear");
                surf_game_menu();
                break;
            default:
                try_time++;
                if(try_time>2){
                    printf("You've tried %d times!\n",try_time);
                    Wrong=-1;
                }else{
                    printf("(%d times left)TRY AGAIN:",3-try_time);
                    scanf("%d",&luckyman_choi);
                }
        }
    }
    
}
void surf_game_luckyman_login(void){
    
}

void surf_game_luckyman_register(void){
    printf("------------------Register---------------------\n");
    printf("Username:");
    
}
