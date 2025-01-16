#ifndef __INVENTORY__H__
#define __INVENTORY__H__
#include <string>


class Objet {
public:
    Objet();
    Objet(const std::string&, unsigned int, unsigned int);
    static void printListObject();
    std::string getNom() const;
    int getQte() const;
    int getPrix() const;
private:
    std::string _nom;
    unsigned int _qte;
    unsigned int _prix;
    static Objet *_invent;
    static int _count;

};



#endif
