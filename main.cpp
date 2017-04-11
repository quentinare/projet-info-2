#include <iostream>
#include <string>
#include <vector>
#include "plateau.h"
#include "case.h"
#include "joueur.h"
#include "console.h"

//using namespace std;

int main()
{
    void menu()
   {
       int choixMenu;
       
       do 
       {
           std::cout << "Bienvenue dans le jeu d'Othello!" << std::endl;
           std::cout << "Entrez le chiffres correspondants à votre choix:" << std::endl;
           std::cout << "1.Jouer" << std::endl;
           std::cout << "2.Règles" << std::endl;
           std::cout << "3.Quitter" << std::endl;
           
           std::cin >> choixMenu;
           
           while (choixMenu != 1 && choixMenu != 2 && choixMenu != 3)
           do
           {
               std::cout << "choix invalide, veuillez réessayer" << std::endl;
               std::cin >> choixMenu;
           }
     
           switch (choixMenu)
           {
               case 1:
                   
                   break;
               case 2:
                   break;
               case 3:
                   break;
               
   } 
    return 0;
}
