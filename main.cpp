#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include "plateau.h"
#include "case.h"
#include "joueur.h"
#include "console.h"

//using namespace std;

void monmenu();
void Regle();


int main()
{
    monmenu();
    return 0;
}
/*
void monmenu()
{
    int choixMenu = 0;
    int i=0, j=0;
    Plateau monPlateau;
    std::vector<std::vector <Case> > tableau;
    tableau = monPlateau.initialise();


    do
    {
        std::cout << "Bienvenue dans l'OTHELLO!" << std::endl;
        std::cout << "Veuillez choisir ce que vous souhaitez faire" << std::endl;
        std::cout << "1. JOUER " << std::endl;
        std::cout << "2. Lire les regles du jeux" << std::endl;
        std::cout << "3. Quitter" << std::endl;
        std::cin >> choixMenu;

    }
    while (choixMenu != 1 || choixMenu != 2 || choixMenu != 3 );

    if (choixMenu == 1)
    {
        system("cls");
        do {
        monPlateau.afficherTab(tableau);
        monPlateau.deplacement(i, j);
       }
       while (choixMenu != 1 || choixMenu != 2 || choixMenu != 3);
    }

    if (choixMenu == 2)
    {
        do
        {
        std::cout << "\t OTHELLO GAME !!" << std::endl;

        std::cout << "Objectif" << std::endl;
        std::cout << std::endl;
        std::cout << "Le but du jeu est d'encadrer les pions de l'autre " << std::endl;
        std::cout << "joueur afin de les convertir" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Regles du jeu" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "1) Utiliser les touches s d f e pour deplacer le curseur" << std::endl;
        std::cout << std::endl;
        std::cout << "2) Placer un pion sur une case en appuyant sur espace" << std::endl;
        std::cout << std::endl;
        std::cout << "3) Vous ne pouvez placer un pion que a proximite" << std::endl;
        std::cout << std::endl;
        std::cout << "   d'un pion de votre adversaire" << std::endl;
        std::cout << std::endl;
        std::cout << "4) Votre score est le comptage du nombre de vos pions" << std::endl;
        std::cout << std::endl;
        std::cout << "   sur le plateau" << std::endl;
        std::cout << std::endl;
        std::cout << "5) La partie se termine lorsqu'un joueur ne peut plus placer" << std::endl;
        std::cout << "   de pion" << std::endl;
        std::cout << std::endl;
        std::cout << "6) Le joueur ayant le plus grand score remporte la partie" << std::endl;
        std::cout << std::endl;

        std::cout << "TAPER 1 POUR RETOURNER AU MENU" << std::endl;

        std::cin >> choixMenu;
        } while (choixMenu != 1);


        if (choixMenu == 1)
        {
            system("cls");
            choixMenu = 0;

            do
            {
                std::cout << "Bienvenue dans l'OTHELLO!" << std::endl;
                std::cout << "Veuillez choisir ce que vous souhaitez faire" << std::endl;
                std::cout << "1. JOUER " << std::endl;
                std::cout << "2. Lire les regles du jeux" << std::endl;
                std::cout << "3. Quitter" << std::endl;
                std::cin >> choixMenu;

            }
            while (choixMenu == 0);

        }
    }

}*/


void monmenu()
   {
       int choixMenu = 0;
       int i=0, j=0;
       Plateau monPlateau;
       std::vector<std::vector <Case> > tableau;
       tableau = monPlateau.initialise();

       {
           std::cout << "Bienvenue dans le jeu d'Othello!" << std::endl;
           std::cout << "Entrez le chiffres correspondants à votre choix:" << std::endl;
           std::cout << "1.Jouer" << std::endl;
           std::cout << "2.Regles" << std::endl;
           std::cout << "3.Quitter" << std::endl;

           std::cin >> choixMenu;

           switch (choixMenu)
           {
               case 1:
                   //Mygame.afficherTab();
                   monPlateau.afficherTab(tableau);
                   monPlateau.deplacement(i, j);
                   break;
               case 2:
                   Regle();
                   break;
               case 3:
                   break;
               default:
                   std::cout << "choix invalide, veuillez réessayer" << std::endl;
           }

        }while (choixMenu != 1 || choixMenu != 3);

        }


