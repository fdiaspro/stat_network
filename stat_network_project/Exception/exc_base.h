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

#ifndef EXC_BASE_H
#define EXC_BASE_H

#include <exception>

class card_network_exception : std::exception {

    card_network_exception() : msg("") {};
    card_network_exception(std::string _msg) : msg(_msg) {};
    virtual const char* what() {return "cannot open card: " + msg; };
    protected:
        std::string msg;
}

#endif /* EXC_BASE_H */

