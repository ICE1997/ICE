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
    while(Wrong){
        switch (luckyman_choi) {
            case 1:
                Wrong=0;
                system("clear");
                surf_game_luckyman_login();
                break;
            case 2:
                Wrong=0;
                system("clear");
                surf_game_luckyman_register();
                break;
            case 0:
                Wrong=0;
                system("clear");
                surf_game_menu();
                break;
            default:
                try_time++;
                if(try_time>2){
                    printf("You've tried %d times!\n",try_time);
                    Wrong=0;
                }else{
                    printf("(%d times left)TRY AGAIN:",3-try_time);
                    scanf("%d",&luckyman_choi);
                }
        }
    }
    
}
void surf_game_luckyman_login(void){
    FILE* F_player_r;
    lkm_acnt player,player_temp;
    int usrname_Loop_YES=1;
    int usrname_EXSIT_NO=0;
    int usrpswd_MATCH_NO=0;
    int usrpswd_Loop_YES=1;
    int usrname_TRY_TIME=0;
    int usrpswd_TRY_TIME=0;
    P_lkm_anct P_player_head,P_player_tail,P_player_ele;
    if((F_player_r=fopen("/Users/mason/Desktop/ICE/ICE/ICE/player_acnt","r"))==NULL){
        printf("Fail to open the player account file.\n");
    }else{
        if((P_player_head=(P_lkm_anct)malloc(sizeof(lkm_acnt)))==NULL){
            printf("OverFlow!\n");
            exit(0);
        }else{
            P_player_tail=P_player_head;
            printf("Succeed in loading the player account file.\n");
            while (!feof(F_player_r)) {
                if((P_player_ele=(P_lkm_anct)malloc(sizeof(lkm_acnt)))==NULL){
                    printf("OverFlow!\n");
                    exit(0);
                }
                fscanf(F_player_r, "%s %s\n",P_player_ele->username,P_player_ele->password);
                P_player_ele->next=NULL;
                P_player_tail->next=P_player_ele;
                P_player_tail=P_player_ele;
            }
            fclose(F_player_r);
            while(usrname_Loop_YES){
                system("clear");
                printf("-------------------Login-----------------------\n");
                printf("Username:");
                scanf("%s",player.username);
                for(P_player_ele=P_player_head->next;
                    P_player_ele!=NULL;
                    P_player_ele=P_player_ele->next){
                    if((strcmp(player.username, P_player_ele->username))==0){
                        strcpy(player_temp.username, P_player_ele->username);
                        strcpy(player_temp.password,P_player_ele->password);
                        usrname_EXSIT_NO=0;
                        break;
                    }else{
                        usrname_EXSIT_NO=1;
                    }
                }
                if(usrname_EXSIT_NO){
                    usrname_TRY_TIME++;
                    printf("(%d times left)User not exist!\n",3-usrname_TRY_TIME);
                    if(usrname_TRY_TIME>2){
                        printf("You've tried %d times!\n",usrname_TRY_TIME);
                        printf("Backing to Luckyman surface.\n");
                        usleep(TM);
                        system("clear");
                        surf_game_luckyman();
                    }
                }else{
                    usrname_Loop_YES=0;
                }
            }
            while(usrpswd_Loop_YES){
                printf("Password:");
                scanf("%s",player.password);
                if((strcmp(player_temp.password, player.password))!=0){
                    usrpswd_MATCH_NO=1;
                }else{
                    usrpswd_MATCH_NO=0;
                }
                if(usrpswd_MATCH_NO){
                    usrpswd_TRY_TIME++;
                    printf("(%d times left)Password incorrect!\n",3-usrpswd_TRY_TIME);
                    if(usrpswd_TRY_TIME>2){
                        func_game_luckyman_dstynode(P_player_head);
                        printf("You've tried %d times!\n",usrpswd_TRY_TIME);
                        printf("Backing to Luckyman surface.\n");
                        usleep(TM);
                        system("clear");
                        surf_game_luckyman();
                    }
                }else{
                    func_game_luckyman_dstynode(P_player_head);
                    usrpswd_Loop_YES=0;
                }
            }
            printf("Successful!Enjoy yourself!\n");
            system("clear");
        }
    }
    
}

void surf_game_luckyman_register(void){
    FILE* F_player_r,*F_player_w;
    lkm_acnt player,player_temp;
    P_lkm_anct P_player_head,P_player_tail,P_player_ele;
    int usrname_Loop_YES=1;
    int usrname_EXSIT_YES=0;
    int usrpswd_MATCH_NO=0;
    int usrpswd_Loop_YES=1;
    int usrname_TRY_TIME=0;
    int usrpswd_TRY_TIME=0;
    if((F_player_r=fopen("/Users/mason/Desktop/ICE/ICE/ICE/player_acnt","r"))==NULL){
        printf("Fail to open the player account file.\n");
    }else{
        if((P_player_head=(P_lkm_anct)malloc(sizeof(lkm_acnt)))==NULL){
            printf("OverFlow!\n");
            exit(0);
        }else{
            P_player_tail=P_player_head;
            printf("Succeed in loading the player account file.\n");
            while (!feof(F_player_r)) {
                if((P_player_ele=(P_lkm_anct)malloc(sizeof(lkm_acnt)))==NULL){
                    printf("OverFlow!\n");
                    exit(0);
                }
                fscanf(F_player_r, "%s %s\n",P_player_ele->username,P_player_ele->password);
                P_player_ele->next=NULL;
                P_player_tail->next=P_player_ele;
                P_player_tail=P_player_ele;
            }
            fclose(F_player_r);
            while(usrname_Loop_YES){
                system("clear");
                printf("------------------Register---------------------\n");
                printf("Username:");
                scanf("%s",player.username);
                for(P_player_ele=P_player_head->next;
                    P_player_ele!=NULL;
                    P_player_ele=P_player_ele->next){
                    if((strcmp(player.username, P_player_ele->username))==0){
                        usrname_EXSIT_YES=1;
                    }else{
                        usrname_EXSIT_YES=0;
                    }
                }
                if(usrname_EXSIT_YES){
                    usrname_TRY_TIME++;
                    printf("(%d times left)User exist!\n",3-usrname_TRY_TIME);
                    if(usrname_TRY_TIME>2){
                        printf("You've tried %d times!\n",usrname_TRY_TIME);
                        printf("Backing to Luckyman surface.\n");
                        usleep(TM);
                        system("clear");
                        func_game_luckyman_dstynode(P_player_head);
                        surf_game_luckyman();
                    }
                }else{
                    func_game_luckyman_dstynode(P_player_head);
                    usrname_Loop_YES=0;
                }
            }
            printf("Password:");
            scanf("%s",player.password);
            while(usrpswd_Loop_YES){
                printf("Confirm:");
                scanf("%s",player_temp.password);
                if((strcmp(player_temp.password, player.password)!=0)){
                    usrpswd_MATCH_NO=1;
                }else{
                    usrpswd_MATCH_NO=0;
                }
                if(usrpswd_MATCH_NO){
                    usrpswd_TRY_TIME++;
                    printf("(%d times left)Mismatch!\n",3-usrpswd_TRY_TIME);
                    if(usrpswd_TRY_TIME>2){
                        printf("You've tried %d times!\n",usrpswd_TRY_TIME);
                        printf("Backing to Luckyman surface.\n");
                        usleep(TM);
                        system("clear");
                        surf_game_luckyman();
                    }
                }else{
                    usrpswd_Loop_YES=0;
                }
            }
            if((F_player_w=fopen("/Users/mason/Desktop/ICE/ICE/ICE/player_acnt","a"))==NULL){
                printf("Can't open the acount file!\n");
            }else{
                if((fprintf(F_player_w,"%s %s\n",player.username,player.password))<0){
                    printf("Can't save your acount!\n");
                }else{
                    fclose(F_player_w);
                    printf("Succeed in creating the new account!\n");
                    printf("Going to the login surface!\n");
                    usleep(TM);
                    system("clear");
                    surf_game_luckyman_login();
                }
            }
            
        }
    }
    
}

void func_game_luckyman_dstynode(P_lkm_anct H_tobedel){
    P_lkm_anct temp=H_tobedel;
    while(temp){
        temp=temp->next;
        free(temp);
    }
    free(H_tobedel);
}
