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

sniffer_tcp::sniffer_tcp() {
}

sniffer_tcp::sniffer_tcp(const sniffer_tcp& orig) {
}

sniffer_tcp::~sniffer_tcp()   {
    this->~virtual_sniffer();
}

void sniffer_tcp::openCard(std::string card)
{
     pcap_t *handle;		/* Session handle */
	 char dev[] = "rl0";		/* Device to sniff on */
	 char errbuf[PCAP_ERRBUF_SIZE];	/* Error string */
	 struct bpf_program fp;		/* The compiled filter expression */
	 char filter_exp[] = "port 23";	/* The filter expression */
	 bpf_u_int32 mask;		/* The netmask of our sniffing device */
	 bpf_u_int32 net;		/* The IP of our sniffing device */

	 if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
		 fprintf(stderr, "Can't get netmask for device %s\n", dev);
		 net = 0;
		 mask = 0;
	 }
	 handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
	 if (handle == NULL) {
		 fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
		 return;
	 }
	 if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
		 fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
		 return;
	 }
	 if (pcap_setfilter(handle, &fp) == -1) {
		 fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
		 return;
	 }
}
void sniffer_tcp::setFilter(std::string sFilter)
{
}
void sniffer_tcp::startSniffing(container&)
{
}
container& sniffer_tcp::getContainer(container&){
    
}
