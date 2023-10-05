// Handel Olivier Baptiste //
#ifndef CLIENT_H
#define CLIENT_H
#include "compte.h"
#include <string>
#include <list>

class client
{
    int Numclient;
    string nom, prenom;
    
    
list<CompteBanq>List_des_CompBanq;

    public:
        client();
        client(int,string,string,list<CompteCheq*>);
        client(int,string,string,list<CompteBanq*>);
        client(int,string,string,list<ComptEpargn*>);
        client(const client&);
void afficheInfosClient();
list<CompteBanq> listComptes=List_des_CompBanq;
};

#endif // CLIENT_H
