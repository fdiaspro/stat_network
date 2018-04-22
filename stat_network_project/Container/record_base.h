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

enum control_bit { SYN=0, CWR, ECE, URG, ACH, PSH, RST, FIN, SIZE_ENUM };

struct record_TCP_IP : record_base {
    unsigned long   IP_src;
    unsigned int    port_src;
    unsigned long   IP_dest;
    unsigned int    port_dest;
    struct timeval  ts;
    time_t          timestamp;
    unsigned long   ack;
    unsigned long   seq;
    unsigned char   size;
    enum control_bit c_bit;
    
    virtual unsigned long getKey() {return IP_src;};
}


#endif /* RECORD_BASE_H */

