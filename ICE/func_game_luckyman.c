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
    printf("*              3>>>Rank                       *\n");
    printf("*                                             *\n");
    printf("*              0>>>Back                       *\n");
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
    getchar();
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
            case 3:
                Wrong=0;
                system("clear");
                surf_game_luckyman_rank();
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
    char player_name[20];
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
                        strcpy(player_name, P_player_ele->username);
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
            usleep(TM);
            surf_game_luckyman_playing(player_name);
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
                        usrpswd_Loop_YES=1;
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

void surf_game_luckyman_playing(char *player_name){
    int range_up;
    lkm_player_info player_info;
    FILE* player_luck = NULL;
    printf("------------------LuckyMan---------------------\n");
    printf("*                                             *\n");
    printf("-----------------------------------------------\n");
    printf("           Hello!  %s                          \n",player_name);
    printf("-----------------------------------------------\n");
    printf("Please enter the biggest number(as the range):");
    scanf("%d",&range_up);
    printf("I'm generating a number between 1 and %d.\n",range_up);
    usleep(TI);
    printf("P");
    usleep(TI-500);
    printf("l");
    usleep(TI-2000);
    printf("e");
    usleep(TI-4000);
    printf("a");
    usleep(TI-8000);
    printf("s");
    usleep(TI-16000);
    printf("e");
    usleep(TI-32000);
    printf(" ");
    usleep(TI-64000);
    printf("w");
    usleep(TI-128000);
    printf("a");
    usleep(TI-256000);
    printf("i");
    usleep(TI-256000);
    printf("t");
    usleep(TI-256000);
    printf(".");
    usleep(TI);
    printf(".");
    usleep(TI);
    printf(".");
    usleep(TI);
    printf(".");
    usleep(TI);
    printf(".");
    usleep(TI);
    printf(".\n");
    usleep(TI*2);
    player_info=func_game_luckyman_playing(player_name,range_up);
    player_luck=fopen("/Users/mason/Desktop/ICE/ICE/ICE/player_luck","a+");
    fprintf(player_luck, "%20s %8.2lf\n",player_info.username,player_info.lucky_index);
    printf("%s %.2lf%%\n",player_info.username,player_info.lucky_index);
    
    
}

lkm_player_info func_game_luckyman_playing(char *player_name,int range_up){
    lkm_player_info player_info;
    strcpy(player_info.username, "-1");
    player_info.lucky_index=-1;
    int guess_LOOP_YES=1;
    int guesstimes=0;
    int generated_num;
    char guess_choi;
    int my_num=0;
    double lucky_index;
    generated_num=func_generate_randomly_num(range_up);
    printf("Done!\n");
    while (guess_LOOP_YES) {
        guesstimes++;
        printf("Please guess what the number is:");
        scanf("%d",&my_num);
        if(my_num>generated_num){
            printf("The number you entered is bigger than mine.\n");
            guess_LOOP_YES=1;
            if(guesstimes%10==0){
                printf("You've tried %d time(s).\n",guesstimes);
                printf("Do you wanna give up(Y/N):");
                getchar();
                scanf("%c",&guess_choi);
                if(guess_choi=='N'||guess_choi=='n'){
                    printf("It's so sorry that you cant get the number.\n");
                    guess_LOOP_YES=0;
                    printf("Backing to last suface!\n");
                    usleep(TM);
                    system("clear");
                    surf_game_luckyman_playing(player_name);
                }
                if(guess_choi=='Y'||guess_choi=='y'){
                    printf("Try hard!You will get it!\n");
                    guess_LOOP_YES=1;
                }
            }
        }else if(my_num<generated_num){
            printf("The number you entered is smaller than mine.\n");
            guess_LOOP_YES=1;
            if(guesstimes%10==0){
                printf("You've tried %d time(s).\n",guesstimes);
                printf("Do you wanna give up(Y/N):");
                getchar();
                scanf("%c",&guess_choi);
                if(guess_choi=='Y'||guess_choi=='y'){
                    printf("It's so sorry that you cant get the number.\n");
                    guess_LOOP_YES=0;
                    printf("Backing to last suface!\n");
                    usleep(TM);
                    system("clear");
                    surf_game_luckyman_playing(player_name);
                }
                if(guess_choi=='N'||guess_choi=='n'){
                    printf("Try hard!You will get it!\n");
                    guess_LOOP_YES=1;
                }
            }
        }else{
            printf("After %d time(s).You got the number!\n",guesstimes);
            guess_LOOP_YES=0;
            if(range_up>=guesstimes){
                lucky_index=100.0*(range_up-guesstimes)/range_up;
            }else{
                lucky_index=0;
            }
            strcpy(player_info.username, player_name);
            player_info.lucky_index=lucky_index;
        }
    }
    return player_info;
}

int func_generate_randomly_num(int range_up){
    int generated_num;
    srand((unsigned)time(NULL));
    generated_num=rand()%range_up+1;
    return generated_num;
}

void surf_game_luckyman_rank(void){
    FILE* player_luck;
    player_luck=fopen("/Users/mason/Desktop/ICE/ICE/ICE/player_luck","r");
    P_lkm_player_info player_info_head=NULL;
    player_info_head=(P_lkm_player_info)malloc(sizeof(lkm_player_info));//To be enhanced.
    player_info_head->lucky_index=-1;
    player_info_head->rank=-1;
    strcpy(player_info_head->username,"-1");
    player_info_head->next=NULL;
    P_lkm_player_info player_info_p = player_info_head;
    P_lkm_player_info player_info_new=NULL;
    while(!feof(player_luck)){
        player_info_new=(P_lkm_player_info)malloc(sizeof(lkm_player_info));
        fscanf(player_luck,"%20s %8lf\n",player_info_new->username,&player_info_new->lucky_index);
        player_info_new->next=NULL;
        player_info_p->next=player_info_new;
        player_info_p=player_info_new;
    }
    func_game_luckyman_sort(player_info_head);
    printf("--------------------Rank-----------------------\n");
    func_game_luckyman_pyifo_prt(player_info_head);
}

void func_game_luckyman_sort(P_lkm_player_info head){
    P_lkm_player_info p1,p2;
    P_lkm_player_info p_temp=NULL;
    lkm_player_info temp;
    for(p1=head->next;p1->next;p1=p1->next){
        p_temp=p1;
        for(p2=p1->next;p2;p2=p2->next){
            if(p2->lucky_index>p_temp->lucky_index){
                p_temp=p2;
            }
        }
        if(p_temp!=p1){
            strcpy(temp.username,p_temp->username);
            temp.lucky_index=p_temp->lucky_index;
            strcpy(p_temp->username, p1->username);
            p_temp->lucky_index=p1->lucky_index;
            strcpy(p1->username, temp.username);
            p1->lucky_index=temp.lucky_index;
        }
    }
}

void func_game_luckyman_pyifo_prt(P_lkm_player_info head){
    int i=1;
    for(head=head->next;head;head=head->next,i++){
        printf("%4d%10s%8.2lf%%\n",i,head->username,head->lucky_index);
    }
}
