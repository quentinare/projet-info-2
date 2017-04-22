#include <iostream>
#include <string>
#include <vector>
#include "plateau.h"
#include "case.h"
#include "joueur.h"
#include "console.h"

//using namespace std;

void monmenu();


int main()
{
    monmenu();
    return 0;
}

void monmenu()
{
    int choixMenu = 0;
    Plateau monPlateau;
    std::vector<std::vector <Case> > tableau;
    tableau = monPlateau.initialise();


    while (choixMenu != 3)
    {
        std::cout << "Bienvenue dans l'OTHELLO!" << std::endl;
        std::cout << "Veuillez choisir ce que vous souhaitez faire" << std::endl;
        std::cout << "1. JOUER " << std::endl;
        std::cout << "2. Lire les regles du jeux" << std::endl;
        std::cout << "3. Quitter" << std::endl;
        std::cin >> choixMenu;

        if (choixMenu == 1)
                monPlateau.afficherTab(tableau);

        if (choixMenu == 2)
        {
            std::cout << "Le but du jeu est d'encadrer les pions de l'autre joueur afin de les convertir" << std::endl;
            std::cout << "Utiliser les touches s d f e pour deplacer le curseur" << std::endl;
            std::cout << "Placer un pion sur une case en appuyant sur espace" << std::endl;
        }

    }



}


/*void menu()
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
   */
