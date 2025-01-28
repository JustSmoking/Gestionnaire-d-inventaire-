#ifndef __INVENTORY__H__
#define __INVENTORY__H__
#include <string>

/*
 * DeleteObject == > supprimer un objet dans le le tableau dynamique *_invent;
 * printListObject() == > afficher la liste des objets presents
 * addObject() == > ajouter un objet
 * modifyoObject == > Modifier un objet
 * resizeInvent() == > donner une taille predefinie a l'inventaire
 * freeInvent() == > Liberer la memoire allouee
 * _invent ==> Tableau dynamique d'objet accesible et modifiable par tous les instances de la classe
 */

class Objet {
public:
    Objet();
    Objet(const std::string&, unsigned int, unsigned int);
    static bool printListObject();
    static bool addObject(const std::string&, unsigned int, unsigned int);
    static bool deleteObject(std::string&);
    void modifyObject();
    static void resizeInvent(const int);
    std::string getNom() const;
    int getQte() const;
    int getPrix() const;
    static void freeInvent();
    static void modifyObject(const std::string&, const std::string&, unsigned int, unsigned int);
    static void SaveInventToFile();
private:
    std::string _nom;
    unsigned int _qte;
    unsigned int _prix;
    static Objet *_invent;
    static int _count;

};


#endif
