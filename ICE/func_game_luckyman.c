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
                surf_game_luckyman_register();
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
    FILE* F_plyer_r,*F_plyer_w;
    lkm_acnt player;
    P_lkm_anct P_player_head,P_player_tail,P_player_ele;
    int TRUE=1;
    int EXSIT=0;
    int try_time=0;
    printf("------------------Register---------------------\n");
    if((F_plyer_r=fopen("/Users/mason/Desktop/ICE/ICE/ICE/plyerinfo","r"))==NULL){
        printf("Fail to open the player file.\n");
    }else{
        if((P_player_head=(P_lkm_anct)malloc(sizeof(lkm_acnt)))==NULL){
            printf("OverFlow!\n");
            exit(0);
        }else{
            P_player_tail=P_player_head;
            printf("Succeed in loading the player file.\n");
            while (!feof(F_plyer_r)) {
                if((P_player_ele=(P_lkm_anct)malloc(sizeof(lkm_acnt)))==NULL){
                    printf("OverFlow!\n");
                    exit(0);
                }
                fscanf(F_plyer_r, "%s %d %d\n",P_player_ele->username,&P_player_ele->lucky_index,&P_player_ele->rank);
                P_player_ele->next=NULL;
                P_player_tail->next=P_player_ele;
                P_player_tail=P_player_ele;
            }
            while(TRUE){
                printf("Username:");
                scanf("%s",player.username);
                for(P_player_ele=P_player_head->next;
                    P_player_ele!=NULL;
                    P_player_ele=P_player_ele->next){
                    if((strcmp(player.username, P_player_ele->username))==0){
                        EXSIT=1;
                    }
                }
                if(EXSIT){
                    try_time++;
                    printf("(%d times left)User exist!\n",3-try_time);
                    if(try_time>2){
                        printf("You've tried %d times!\n",try_time);
                        printf("Backing to Luckyman surface.\n");
                        usleep(20000);
                        system("clear");
                        surf_game_luckyman();
                    }
                }else{
                    TRUE=0;
                }
            }
        }
    }
    
}
