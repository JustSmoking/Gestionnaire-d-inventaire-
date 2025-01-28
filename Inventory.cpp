#include "Inventory.h"
#include <iostream>
#include <fstream>
/*
 * _count pour creer chaque index et le stocker dans le tableau et s'assurer quil soit le dernier element
 * creation d'un tableau dynamique de 3 elements
 * creation d'un tampon, copie dans le tampon suppresion du tableau,
 * recreation du nouveau _invent avec une taille n + 1
 * suppression et liberation du tampon
 */
int Objet::_count = 0;
int n = 1;

Objet* Objet::_invent = new Objet[n];

Objet::Objet(): _nom("Aucun"), _prix(0), _qte(0){};

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
int Objet::getPrix() const{
    return this->_prix;
}
int Objet::getQte() const{
    return this->_qte;
}

bool Objet::printListObject(){
    if (_invent == nullptr)
    {
        std::cout << "Inventaire Vide (FreeMemory)" << std::endl;
        return false;
    }
    
   for (unsigned int i = 0; i < n; i++) {
       std::cout << " Objet "<< _invent[i].getNom() << " " <<  _invent[i].getPrix() << " " << _invent[i].getQte() << std::endl;
   }
   return true;
}

void Objet::resizeInvent(const int resizeNumber) {
    n = resizeNumber;
    Objet *tampon = new Objet[resizeNumber]{Objet()};
    if (tampon == nullptr) {
        std::cerr << "Erreur lors de l'allocation de tampon" << std::endl;
        std::abort();
    }

    for (unsigned int i = 0; i < resizeNumber; i++) {
        tampon[i]._nom = _invent[i]._nom;
        tampon[i]._prix = _invent[i]._prix;
        tampon[i]._qte = _invent[i]._qte;
    }
    delete[] _invent;
    _invent = new Objet[resizeNumber]{Objet()};
    if (_invent == nullptr) {
        std::cerr << "Erreur lors de la reallocation de ;'inventaire" << std::endl;
        delete[] tampon;
        std::abort();
    }
    for (unsigned int i = 0; i < resizeNumber; i++) {
        _invent[i]._nom =  tampon[i]._nom;
        _invent[i]._prix = tampon[i]._prix;
        _invent[i]._qte = tampon[i]._qte;
    }
    delete[] tampon;
}

bool Objet::deleteObject(std::string& name) {
    for (unsigned int i = 0; i < n; i++) {
        if (_invent[i].getNom() == name) {
            _invent[i] = Objet();
        }
    }
    Objet *temp = new Objet[n - 1]{Objet()};
    if (temp == nullptr) {
        std::cerr << "Erreur lors de l'allocation de tampon" << std::endl;
        std::abort();
    }
    for (unsigned int i = 0; i < n - 1; i++) {
        if (_invent[i].getNom() != "Aucun element") {
            temp[i]._nom = _invent[i]._nom;
            temp[i]._prix = _invent[i]._prix;
            temp[i]._qte = _invent[i]._qte;
        }
    }
    delete[] _invent;
    n = n - 1;
    _invent = new Objet[n]{Objet()};
    if (_invent == nullptr) {
        std::cerr << "Erreur lors de la reallocation invent" << std::endl;
        delete[] temp;
        std::abort();
    }
    for (unsigned int i = 0; i < n; i++) {
        _invent[i]._nom =  temp[i]._nom;
        _invent[i]._prix = temp[i]._prix;
        _invent[i]._qte = temp[i]._qte;
    }
    delete[] temp;
    return true;
}
void Objet::freeInvent() {
    delete[] _invent;
    _invent = nullptr;
    std::cout << _invent << std::endl;
}

bool Objet::addObject(const std::string& name, unsigned int qte, unsigned int prix) {
    if (_invent == nullptr)
    {
        n = 1;
        _count = 0;
        _invent = new Objet[n]{Objet()};
        Objet(name, qte, prix);
        return true;
    }
    

    Objet *temp = new Objet[n]{Objet()};
    unsigned int m = n;
    if (temp == nullptr) {
        std::cerr << "Erreur lors de l'ajout" << std::endl;
        std::abort();
    }
    for (unsigned int i = 0; i < n; i++) {
        temp[i]._nom = _invent[i]._nom;
        temp[i]._prix = _invent[i]._prix;
        temp[i]._qte = _invent[i]._qte;
    }
    delete[] _invent;
    n = n + 1;
    _invent = new Objet[n]{Objet()};
    if (_invent == nullptr) {
        std::cerr << "Erreur lors de la reallocation de temp" << std::endl;
        delete[] temp;
        std::abort();
    }
    for (unsigned int i = 0; i < m; i++) {
        _invent[i]._nom =  temp[i]._nom;
        _invent[i]._prix = temp[i]._prix;
        _invent[i]._qte = temp[i]._qte;
    }
    Objet(name, qte, prix);
    return true;
}
void Objet::modifyObject(const std::string &name, const std::string &newName, unsigned int newQte, unsigned int newPrix){
    for (unsigned int i = 0; i < n; i++) {
        if (_invent[i].getNom() == name) {
            _invent[i]._nom = newName;
            _invent[i]._qte = newQte;
            _invent[i]._prix = newPrix;
        }
    }
}
void Objet::SaveInventToFile() {
    // Chemin d'acces aux fichiers
    std::ofstream file("/Users/smoke/CLionProjects/fic");
    if (!file)
        std::cerr << "Erreur lors de l'ouverture/ecriture du fichier" << std::endl;

    file << "=========Ajout=========" << "\n";
    for (unsigned int i = 0; i < n; i++) {
        file << _invent[i]._nom << " ";
        file << _invent[i]._prix << " ";
        file << _invent[i]._qte << "\n";

    }
    file.close();
    std::cout << "Enregistrement dans le fichier !" << std::endl;
}
