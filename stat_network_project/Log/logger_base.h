/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   logger_base.h
 * Author: Franco
 *
 * Created on 20 aprile 2018, 22.29
 */

#ifndef LOGGER_BASE_H
#define LOGGER_BASE_H
#include <fstream>

 template<class T> class logger_base {
    static logger_base* instance;

protected:
    logger_base(){LOG_LEVEL=0;};
    logger_base(unsigned int _LOG_LEVEL){LOG_LEVEL=_LOG_LEVEL;};
    
    static unsigned char LOG_LEVEL;
    virtual logger_base* getLogger(){ return instance;};
    virtual logger_base* setLogger(logger_base* _instance){ instance=_instance;};
    
        
public:
    virtual void logger_debug( T)=0;
    virtual void logger_verbose( T)=0;
    virtual void logger_info( T)=0;
    virtual void logger_warning( T)=0;
    virtual void logger_error(unsigned int codeErr,T)=0;
    virtual void logger_fatal_error(unsigned int codeErr,T)=0;
    virtual ~logger_base(){}; 
    virtual int getLogLevel(){return LOG_LEVEL;};
};

 class logger_file  : std::ofstream, logger_base<std::string>   {
    logger_file(unsigned int _LOG_LEVEL=0);
    logger_file( std::string& orig, unsigned int _LOG_LEVEL=0);
    
 public:
    virtual void logger_debug(  std::string){};
    virtual void logger_verbose(std::string){};
    virtual void logger_info( std::string){};
    virtual void logger_warning( std::string){};
    virtual void logger_error(unsigned int codeErr, std::string){};
    virtual void logger_fatal_error(unsigned int codeErr, std::string){};
    virtual logger_base<std::string>  * getLogger(unsigned int _LOG_LEVEL=0);
    
    virtual ~logger_file(){}; 
    
private:

};

#endif /* LOGGER_BASE_H */

