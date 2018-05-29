/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sniffer_tcp.h
 * Author: Franco
 *
 * Created on 19 aprile 2018, 22.50
 */

#ifndef SNIFFER_TCP_H
#define SNIFFER_TCP_H
#include <memory>
#include "virtual_sniffer.h"
#include "Log/logger_base.h"

class sniffer_tcp : virtual_sniffer {
    private:
        pcap_t *handle;		/* Session handle */
	logger_file* appLog;
        bpf_u_int32 mask;		/* The netmask of our sniffing device */
	bpf_u_int32 net;		/* The IP of our sniffing device */
        
    public:
    sniffer_tcp();
    sniffer_tcp(std::shared_ptr <logger_base<std::string> > logger):my_logger(logger){};
    sniffer_tcp(const sniffer_tcp& orig);
    virtual ~sniffer_tcp();
    virtual void set_logger(std::shared_ptr <logger_base<std::string> > logger){my_logger=(logger);};
     virtual void openCard(std::string card);
    virtual void setFilter(std::string sFilter);
    virtual void startSniffing(container&);
    virtual container& getContainer(container&);
private:
    std::shared_ptr<logger_base<std::string> > my_logger;
};

#endif /* SNIFFER_TCP_H */

