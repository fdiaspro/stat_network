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

template <class T>
unsigned char logger_base<T>::LOG_LEVEL=0;
template <class T>
const unsigned char logger_base<T>::LOG_VERBOSE=1;
template <class T>
const unsigned char logger_base<T>::LOG_DEBUG=2;
template <class T>
const unsigned char logger_base<T>::LOG_INFO=3;
template <class T>
const unsigned char logger_base<T>::LOG_WARNING=4;
    

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


 
    void logger_file::logger_debug(  std::string msg)
    {
        if (LOG_LEVEL < LOG_DEBUG)
            *this << timing() <<'\t' << "000 "<<'\t' << msg << std::endl;
    }
    
    void logger_file::logger_verbose(std::string msg)
    {
        if (LOG_LEVEL < LOG_VERBOSE)
            *this << timing() <<'\t' << "000 "<<'\t' << msg << std::endl;
    }
    
    void logger_file::logger_info( std::string msg)
    {
        if (LOG_LEVEL < LOG_INFO)
            *this << timing() <<'\t' << "000 "<<'\t' << msg << std::endl;
    
    }
    
    void logger_file::logger_warning( std::string msg)
    {
        if (LOG_LEVEL < LOG_WARNING)
            *this << timing() <<'\t' << "000 "<<'\t' << msg << std::endl;
    }
    
    void logger_file::logger_error(unsigned int codeErr, std::string msg)
    {
            *this << timing() <<'\t' << codeErr <<'\t' << msg << std::endl;
    }
    
    void logger_file::logger_fatal_error(unsigned int codeErr, std::string msg)
    {
            *this << timing() <<'\t' << codeErr <<'\t' << msg << std::endl;
    }
    std::string logger_file::timing() 
    {
        return "ToBeDone";
    }
   