/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sniffer_tcp.h
 * Author: Franco
 *
 * Created on 19 aprile 2018, 22.50
 */

#ifndef SNIFFER_TCP_H
#define SNIFFER_TCP_H
#include "virtual_sniffer.h"

class sniffer_tcp : virtual_sniffer {
public:
    sniffer_tcp();
    sniffer_tcp(const sniffer_tcp& orig);
    virtual ~sniffer_tcp();
    
private:

};

#endif /* SNIFFER_TCP_H */

