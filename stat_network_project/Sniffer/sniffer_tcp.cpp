/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sniffer_tcp.cpp
 * Author: Franco
 * 
 * Created on 19 aprile 2018, 22.50
 */
#include <pcap.h>

#include "Sniffer/sniffer_tcp.h"
#include "Exception/exc_base.h"

sniffer_tcp::sniffer_tcp() {

}

sniffer_tcp::sniffer_tcp(const sniffer_tcp& orig) {

}

sniffer_tcp::~sniffer_tcp()   {
    this->~virtual_sniffer();
}

void sniffer_tcp::openCard(std::string card/* Device to sniff on */)
{
         char errbuf[1000];
	 if (pcap_lookupnet( card.c_str(), &net, &mask, errbuf) == -1) {
		 std::string err("");
                 err= "Can't get netmask for device " + card;
		 net = 0;
		 mask = 0;
                 card_network_exception my_err(err);
                 
                 my_logger->logger_error(my_err.getErrocCode(), my_err.what() );
                 throw (err);
	 }
	 handle = pcap_open_live(card.c_str(), sizeof(errbuf), 1, 1000, errbuf);
	 if (handle == NULL) {
		 std::string err("");
                 err= "Couldn't open device %s: %s\n" + card+ std::string(errbuf);
		 return;
	 }
	 
}
void sniffer_tcp::setFilter(std::string sFilter /* The filter expression */)
{
    struct bpf_program fp;		/* The compiled filter expression */
     ;	
	
    if (pcap_compile(handle, &fp, sFilter.c_str(), 0, net) == -1) {
		std::string err("");
                err= "Couldn't parse filter %s: %s\n" + sFilter +  std::string(pcap_geterr(handle));
		return;
    }
    
     if (pcap_setfilter(handle, &fp) == -1) {
		std::string err("");
                err= "Couldn't install filter %s: %s\n" + sFilter +  std::string(pcap_geterr(handle));
		return;
    }
}
void sniffer_tcp::startSniffing(container&)
{
}
container& sniffer_tcp::getContainer(container&){
    
}
