#include "Inventory.h"
#include <iostream>

int Objet::_count = 0;
int n = 3;

Objet* Objet::_invent = new Objet[n]{Objet()};

Objet::Objet(): _nom("Rien"), _prix(0), _qte(0){};

Objet::Objet(const std::string &nom, unsigned int qte, unsigned int prix) {
    if (_invent == nullptr)
        std::cerr << "Erreur lors de l'allocation du tableau" << std::endl;

    this->_nom = nom;
    this->_prix = prix;
    this->_qte = qte;
    this->_invent[_count]._nom = nom;
    this->_invent[_count]._prix = prix;
    this->_invent[_count]._qte = qte;
    this->_count++;
}
std::string Objet::getNom() const {
    return this->_nom;
}

void Objet::printListObject(){
   for (unsigned int i = 0; i < n; i++) {
       std::cout << " Objet No "  << i + 1 << " "<< _invent[i].getNom() << " " <<  _invent[i].getPrix() << " " << _invent[i].getQte() << std::endl;
   }
}

