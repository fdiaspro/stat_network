/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   virtual_sniffer.h
 * Author: Franco
 *
 * Created on 10 aprile 2018, 23.08
 */

#ifndef VIRTUAL_SNIFFER_H
#define VIRTUAL_SNIFFER_H
#include <string>
#include <memory>

#include "Container/container.h"


 class virtual_sniffer {
public:
    virtual ~virtual_sniffer(){};
    virtual void openCard(std::string card)=0;
    virtual void setFilter(std::string sFilter)=0;
    virtual void startSniffing(container&)=0;
    virtual container& getContainer(container&)=0;
};

#endif /* VIRTUAL_SNIFFER_H */

