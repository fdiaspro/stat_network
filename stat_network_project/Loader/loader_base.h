/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   loader_base.h
 * Author: Franco
 *
 * Created on 1 maggio 2018, 21.07
 */

#ifndef LOADER_BASE_H
#define LOADER_BASE_H


class Record_Data ;
class Config_Parameter ;


class loader_base {
public:
//    loader_base();
//    loader_base(const loader_base& orig);
    virtual ~loader_base();
    virtual void config(Config_Parameter& conf);
    virtual void init()=0;
    virtual int load(Record_Data & obj);
    virtual void open()=0;
    virtual void close()=0;
    
private:

};

#endif /* LOADER_BASE_H */

