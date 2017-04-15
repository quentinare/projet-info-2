#include <iostream>
#include <string>
#include <vector>
#include "plateau.h"
#include "case.h"
#include "joueur.h"
#include "console.h"

//using namespace std;

void menu();

int main()
{
    menu();

    return 0;
}

void menu()
   {
       int choixMenu;
       int n = 0;
       Plateau Mygame;

       while(n=0)
       {
           std::cout << "Bienvenue dans le jeu d'Othello!" << std::endl;
           std::cout << "Entrez le chiffres correspondants à votre choix:" << std::endl;
           std::cout << "1.Jouer" << std::endl;
           std::cout << "2.Règles" << std::endl;
           std::cout << "3.Quitter" << std::endl;

           std::cin >> choixMenu;

           while (choixMenu != 1 && choixMenu != 2 && choixMenu != 3)
           {
               std::cout << "choix invalide, veuillez réessayer" << std::endl;
               std::cin >> choixMenu;
           }

           switch (choixMenu)
           {
               case 1:
                   Mygame.afficherTab();
                   break;
               case 2:
                   break;
               case 3:
                   break;
           }
        }
   }
