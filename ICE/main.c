//
//  main.c
//  ICE
//
//  Created by mason on 2018/4/25.
//  Copyright © 2018年 mason. All rights reserved.
//
#include "stdhd.h"
#include "func_dcl.h"
int main(int argc, const char * argv[]) {
    struct tm *now_time;
    int menu_choi=0;
    int Wrong=1;
    int try_time=1;
    grt grts=greeting();
    now_time=get_time();
    printf("--------------------Welcome--------------------\n");
    printf("*    Hello!%20s               *\n",grts.grt_ph);
    printf("*                                             *\n");
    printf("*    Date:  %4d %2d.%2d                        *\n",
           1900+now_time->tm_year,1+now_time->tm_mon,now_time->tm_mday);
    printf("*    Time:  %2d:%2d:%2d                          *\n",
           now_time->tm_hour,now_time->tm_min,now_time->tm_sec);
    printf("***********************************************\n");
    printf("*                                             *\n");
    printf("*    1>>>Game                                 *\n");
    printf("*                                             *\n");
    printf("*    2>>>function2                            *\n");
    printf("*                                             *\n");
    printf("*    3>>>function3                            *\n");
    printf("*                                             *\n");
    printf("*    0>>>Exit                                 *\n");
    printf("*                                             *\n");
    printf("-----------------------------------------------\n");
    printf("Please select:");
    scanf("%d",&menu_choi);
    while(Wrong==1){
        switch (menu_choi) {
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
                printf("Bye!Thank you for your using!\n");
                exit(1);
                break;
            default:
                try_time++;
                printf("(%d times left)TRY AGAIN:",4-try_time);
                scanf("%d",&menu_choi);
                if(try_time>2){
                    printf("You've tried 3 times!\n");
                    Wrong=-1;
                }
        }
    }

    return 0;
}
