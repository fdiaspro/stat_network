/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sniffer_tcp.cpp
 * Author: Franco
 * 
 * Created on 19 aprile 2018, 22.50
 */

#include "Sniffer/sniffer_tcp.h"

sniffer_tcp::sniffer_tcp() {
}

sniffer_tcp::sniffer_tcp(const sniffer_tcp& orig) {
}

sniffer_tcp::~sniffer_tcp()   {
    this->~virtual_sniffer();
}

