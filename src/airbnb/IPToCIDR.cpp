#include "IPToCIDR.hpp"
#include<string>
#include<sstream>
#include<iostream>

unsigned toInt(string ip) {
    stringstream s(ip);
    int a,b,c,d;
    char ch;
    s>>a>>ch>>b>>ch>>c>>ch>>d;
    return (a<<24) | (b<<16) | (c<<8) | d;
}

string toIP(int ip) {
    string ips="";
    for(int i=0;i<4;i++) {
        ips=to_string((ip&255))+"."+ips;
        ip=ip>>8;
    }
    return ips.substr(0, ips.length()-1);;
}

int getTrailingZeros(unsigned i) {
    int c=0;
    while(i>0) {
        if(i&1) return c;
        c++;
        i=i>>1;
    }
    return c;
}

vector<string> IPToCIDR::ipToCIDR(string ip, int n) {
    vector<string> ans;
    unsigned i=toInt(ip);
    while(n>0) {
        int pad=getTrailingZeros(i);
        while((1<<pad)>n)pad--;
        ans.push_back(toIP(i)+"/"+to_string(32-pad));
        n-=(1<<pad);
        i+=(1<<pad);
    }
    return ans;
}