#include <iostream>
#include "Inventory.h"
#include <string>

void displayMenu() {
    std::cout << "\n================ MENU INVENTAIRE ================\n";
    std::cout << "1. Afficher les objets dans l'inventaire\n";
    std::cout << "2. Ajouter un objet\n";
    std::cout << "3. Modifier un objet\n";
    std::cout << "4. Supprimer un objet\n";
    std::cout << "5. Redimensionner l'inventaire\n";
    std::cout << "6. Libérer l'inventaire\n";
    std::cout << "0. Quitter\n";
    std::cout << "=================================================\n";
    std::cout << "Choisissez une option : ";
}


int main(){

    int choix;
    do {
        displayMenu();
        std::cin >> choix;

        switch (choix) {
            case 1: {
                std::cout << "\n--- Liste des objets dans l'inventaire ---\n";
                Objet::printListObject();
                break;
            }
            case 2: {
                std::string nom;
                unsigned int qte, prix;
                std::cout << "Entrez le nom de l'objet : ";
                std::cin.ignore();
                std::getline(std::cin, nom);
                std::cout << "Entrez la quantité : ";
                std::cin >> qte;
                std::cout << "Entrez le prix : ";
                std::cin >> prix;

                Objet::addObject(nom, qte, prix);
                std::cout << "Objet ajouté avec succès !\n";
                break;
            }
            case 3: {
                std::string nom, newNom;
                unsigned int newQte, newPrix;
                std::cout << "Entrez le nom de l'objet à modifier : ";
                std::getline(std::cin, nom);
                std::cout << "Entrez le nouveau nom : ";
                std::cin >> newNom;
                std::cout << "Entrez la nouvelle quantité : ";
                std::cin >> newQte;
                std::cout << "Entrez le nouveau prix : ";
                std::cin >> newPrix;

                Objet::modifyObject(nom, newNom, newQte, newPrix);
                std::cout << "Objet modifié avec succès !\n";
                break;
            }
            case 4: {
                std::string nom;
                std::cout << "Entrez le nom de l'objet à supprimer : ";
                std::cin >> nom;

                if (Objet::deleteObject(nom)) {
                    std::cout << "Objet supprimé avec succès !\n";
                } else {
                    std::cout << "Objet introuvable !\n";
                }
                break;
            }
            case 5: {
                int newSize;
                std::cout << "Entrez la nouvelle taille de l'inventaire : ";
                std::cin >> newSize;

                Objet::resizeInvent(newSize);
                std::cout << "Taille de l'inventaire redimensionnée avec succès !\n";
                break;
            }
            case 6: {
                Objet::freeInvent();
                std::cout << "Inventaire libéré !\n";
                break;
            }
            case 0: {
                std::cout << "Merci d'avoir utilisé l'inventaire ! Au revoir !\n";
                break;
            }
            default:
                std::cout << "Option invalide, veuillez réessayer.\n";
        }
    } while (choix != 0);

    return 0;
}
