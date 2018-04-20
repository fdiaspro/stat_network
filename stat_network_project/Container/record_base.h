/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   record_base.h
 * Author: Franco
 *
 * Created on 20 aprile 2018, 21.51
 */

#ifndef RECORD_BASE_H
#define RECORD_BASE_H

#include "time.h"
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

struct record_base{
    virtual unsigned long getKey()=0;    
};

struct record_TCP_IP: record_base {
    unsigned long   IP_src;
    unsigned long   IP_dest;
    struct timeval  ts;
    unsigned long   ack;
    unsigned long   seq;
    unsigned char   size;
    virtual unsigned long getKey() {return IP_src;};
}


#endif /* RECORD_BASE_H */

