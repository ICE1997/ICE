//
//  func_body.c
//  ICE
//
//  Created by mason on 2018/4/25.
//  Copyright © 2018年 mason. All rights reserved.
//

#include "stdhd.h"
#include "strt_body.h"
struct tm *get_time(void){
    time_t t;
    struct tm *now;
    time(&t);
    now=localtime(&t);
    return now;
}
grt greeting(void){
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



