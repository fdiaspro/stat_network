/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   logger_base.cpp
 * Author: Franco
 * 
 * Created on 20 aprile 2018, 22.29
 */

#include "logger_base.h"
template <class T>
logger_base<T>* logger_base<T>::instance=NULL;


logger_base<std::string>* logger_file::getLogger(unsigned int _LOG_LEVEL)
{
    logger_base<std::string>* lb;

    if ( (lb=this->getLogger()) == 0)
    {
        this->setLogger( new logger_file(_LOG_LEVEL) );
    }
    
    return lb;
}

logger_file::logger_file(unsigned int _LOG_LEVEL)
{
    this->LOG_LEVEL = _LOG_LEVEL;
    
    this->open("logger_file.log", ios_base::out|ios_base::app);    
}

logger_file::logger_file( std::string& orig, unsigned int _LOG_LEVEL)
{
    this->LOG_LEVEL = _LOG_LEVEL;
    
    this->open(orig, ios_base::out|ios_base::app);        
}
