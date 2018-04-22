/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   container.h
 * Author: Franco
 *
 * Created on 19 aprile 2018, 23.11
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include "record_base.h"

 class container  {

public:
    virtual ~container()=0;
    virtual void add(record_base R)=0;
    virtual void add( unsigned long k, record_base value)=0;
    virtual void deleteRecord( unsigned long k)=0;
    virtual void deleteRecord( record_base k)=0;
    virtual record_base& getRecord( unsigned long k)=0;     
    virtual record_base& getRecord( record_base k)=0;
    virtual void clean (time_t)=0; 
};

#endif /* CONTAINER_H */

