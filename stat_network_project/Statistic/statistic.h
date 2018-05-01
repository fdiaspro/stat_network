/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   statistic.h
 * Author: Franco
 *
 * Created on 1 maggio 2018, 20.12
 */

#ifndef STATISTIC_H
#define STATISTIC_H

#include <map>
#include <memory>
#include "Container/container.h"
#include "Loader/loader_base.h"
class statistic {
public:
     statistic( container& );
     statistic(const statistic& orig);
    virtual ~statistic();
    virtual int compute()=0;
    virtual void save(std::shared_ptr<loader_base> lb)=0;
private:
    container& my_container;
};

struct map_shuf_red_info {
    unsigned long msg;
    unsigned long size;
};

class map_shuffle_reduce : public statistic, 
                           public std::map<unsigned long, map_shuf_red_info>
{
public:
     map_shuffle_reduce( container& );
     map_shuffle_reduce(const map_shuffle_reduce& orig);
    virtual ~map_shuffle_reduce();
    virtual int compute();
    virtual void save(std::shared_ptr<loader_base> lb);
private:
    container& my_container;
};

#endif /* STATISTIC_H */

