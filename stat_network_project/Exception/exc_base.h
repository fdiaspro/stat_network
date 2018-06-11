/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exc_base.h
 * Author: Franco
 *
 * Created on 22 aprile 2018, 12.43
 */
#include <exception>

#ifndef EXC_BASE_H
#define EXC_BASE_H

class A{};

class card_network_exception  : public std::exception {
    
    public:
        card_network_exception() : msg(""), errCode(0x100) {};
        card_network_exception(std::string _msg) : msg(_msg), errCode(0x100)  {};
        virtual const char* what() {return   msg.c_str(); };
        virtual unsigned int getErrocCode() {return  errCode; };
    
    protected:
        std::string msg;
        unsigned short  int errCode;
};

#endif /* EXC_BASE_H */

