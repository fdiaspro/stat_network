/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   statistic.cpp
 * Author: Franco
 * 
 * Created on 1 maggio 2018, 20.12
 */
#include <memory>
#include "statistic.h"

statistic::statistic(container& obj) : my_container(obj) {
    
}

statistic::statistic(const statistic& orig):  my_container(orig.my_container ) {
    
}

statistic::~statistic() {
}

