#include <iostream>
#include <set>
#include <pair>
#include <vector>
#include "plateau.h"
#include "case.h"
#include "console.h"

Plateau :: Plateau ()
{

}

Plateau :: ~Plateau ()
{

}

void Plateau :: afficherTab(std::vector<std::vector<Case> > m_plateau)
{
    bool typea, remplia;

    for (unsigned int i=0; i<m_plateau.size(); i++)
    {
        for (unsigned int j=0; j<m_plateau.size(); j++)
        {

            typea = m_plateau[i][j].gettype();
            remplia = m_plateau [i][j].getremplie();

            if(remplia !=0)
            {
                if(typea!=0)
                {
                    std::cout << "B" << std::endl;
                }
                else
                {
                    std::cout << "N" << std::endl;
                }
            }
            else
            {
                std::cout << "*" << std::endl;
            }

        }
    }
}

void Plateau :: setTab(std::vector<std::vector<Case> > plateau)
{
    std::vector<std::vector<Case> > m_plateau;
    m_plateau = plateau;
}

std::vector<std::vector<Case> > Plateau ::  getTab() const
{
    return m_plateau;
}

void Plateau :: deplacement()
{
    bool quit = false;
    Console* pConsole = NULL;
    int i=0;
    int j=0;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(i, j);
    pConsole->setColor(COLOR_GREEN);
    pConsole->setColor(COLOR_DEFAULT);

    // Boucle événementielle
    while (!quit)
    {
        // Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            // Récupere le code ASCII de la touche
            int key = pConsole->getInputKey();
            std::cout << "touche = " << key << std::endl;

            if (key == 27) // 27 = touche escape
            {
                quit = true;
            }

            if (key == 'e')//curseur ves le haut
            {
                pConsole->gotoLigCol(i+1,j);
            }

            if (key == 'd')//curseur vers le bas
            {
                pConsole->gotoLigCol(i-1,j);
            }

            if (key == 'f')//curseur vers la droite
            {
                pConsole->gotoLigCol(i,j+1);
            }

            if (key == 's')//curseur vers la gauche
            {
                pConsole->gotoLigCol(i,j-1);
            }
        }
    }

    // Libčre la mémoire du pointeur !
    Console::deleteInstance();
}

// fonction de jeu
void Plateau :: jeu ()
{
    do
    {
        casevide(); //fonction tester s'il y a une case vide ET que l'on peut jouer

        /*while( il y a une case vide OU que l'on peut jouer)
        {

        fonction tester s'il y a une case vide

        // fonction Tour (int) que l'on appelle 2 fois

            While (getJnumero==0) // (c'est le tour du joueur 1)
            do {
            parcourir le tableau pour savoir ou on peut placer un pion + le stocker dans un tableau
            afficher le tableu + proposition de placement + "A vous de jouer J1"
            fonction de déplacement
                If( joueur appuie sur espace pour placet le pion && le curseur est sur une des cases contenue dans le tableau de proposition)
                {
                setJnumero=1;
                }
                Else
                {
                "vous avez sélectionné une mauvaise case"
                }
            }//fin du vhile do

        fonction tester s'il y a une case vide OU si l'on peut jouer

            While (getJnumero==1) // (c'est le tour du joueur 2)
            do
            {
            parcourir le tableau pour savoir ou on peut placer un pion + le stocker dans un tableau
            afficher le tableu + proposition de placement + "A vous de jouer J2"
            fonction de déplacement
                If( joueur appuie sur espace pour placet le pion && le curseur est sur une des cases contenue dans le tableau de proposition)
                {
                setJnumero=0;
                }
                Else
                {
                "vous avez sélectionné une mauvaise case"
                }
            }//fin du while do

        fonction tester s'il y a une case vide

        }//fin du while do

        }
        fction affichage du vainqueur
        */
    }while (vide==0) //while (la touche de fin n'est pas appuyée OU qu'il n'y a pas de victoire OU que l'on ne peut pas jouer) // fin du do




}//fin de la fct de jeu

//fonction case vide
bool Plateau :: casevide ()
{
    bool vide = 1;
    bool remplissage = 0;

    for (int i=0; i< m_plateau.size(); i++)
    {
        for (int j=0; i< m_plateau[i].size(); j++)
        {
            remplissage = case.getremplie ();

            if (remplissage==0)
            {
                vide = 0;
                break;// sortir de la boucle for
            }
            else (remplissage == 1)
            {
                vide = 1;
            }

        }

        if (remplissage==0) //test pour sortir de la boucle for
        {
            break;
        }
    }


    return vide;
}


//fonction pour trouver les cas possible
std::set < std::pair <int,int> > Plateau :: coups_possibles ()
{
    bool couleurtour=Joueur.getnumero();
    bool couleurcase=Case.gettype();

    for (int i=0; i< m_plateau.size(); i++)
    {
        for (int j=0; i< m_plateau[i].size(); j++)
        {
            if(couleurtour==couleurcase)
            {
                for(int a=0; i<8; i++)
                {
                    switch (a)
                    {
                    case 1: //aller à droite
                        if(couleurcase==couleurtour)
                        {
                            break;
                        }

                    }

                }
            }


        }//fin du parcours du tableau 1D

    }//fin du parcours du tableau 2D

}//fin de la fonction


