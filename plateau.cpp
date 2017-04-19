#include <iostream>
#include <set>
#include <pair>
#include <vector>
#include "plateau.h"
#include "case.h"
#include "console.h"
#include "joueur.h"

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

void Plateau :: deplacement(int i=0, int j=0)
{
    bool quit = false;
    Console* pConsole = NULL;

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

    Joueur monjoueur1;
    Joueur monjoueur2;

    monjoueur1.setnumero(false);
    monjoueur2.setnumero(false);

    while (casevide()==true)
        {

            while (monjoueur1.getnumero()==false && monjoueur2.getnumero()==false)
                {

                    tour(m_plateau, monjoueur1)

            //parcourir le tableau pour savoir ou on peut placer un pion + le stocker dans un tableau
            //afficher le tableau + proposition de placement + "A vous de jouer J1"
            //fonction de déplacement

                if(kbhit == ' ')
                {
                    monjoueur1.setnumero(true);
                    monjoueur2.setnumero(true);
                }

                else
                {
                std::cout << "vous avez sélectionné une mauvaise case" << std::endl;
                }
            } // c'est le tour du joueur 1

        //fonction tester s'il y a une case vide OU si l'on peut joue

            while (monjoueur1.getnumero()==true && monjoueur2.getnumero()==true)
                {
            //parcourir le tableau pour savoir ou on peut placer un pion + le stocker dans un tableau
            //afficher le tableu + proposition de placement + "A vous de jouer J2"
            //fonction de déplacement
                //if( joueur appuie sur espace pour placet le pion && le curseur est sur une des cases contenue dans le tableau de proposition)

                if(kbhit == ' ')
                {
                setnumero=0;
                }
                else
                {
                std::cout << "vous avez sélectionné une mauvaise case"<< std::endl;
                }
            } // (c'est le tour du joueur 2) //fin du do while

        //fction affichage du vainqueur

        vainqueur(monjoueur1.getscore(), monjoueur2.getscore());

    }


}//fin de la fct de jeu

// fonction de jeu
void Plateau :: jeu ()
{
    do
    {
        bool vide=casevide(); //fonction tester s'il y a une case vide
        //ET que l'on peut jouer

        /*while( il y a une case vide OU que l'on peut jouer)
        {

        fonction tester s'il y a une case vide

        // fonction Tour (int) que l'on appelle 2 fois (1/2)
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

        // fonction Tour (int) que l'on appelle 2 fois (2/2)
            While (getJnumero==1) // (c'est le tour du joueur 2)
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
    bool remplissage = false;
        Case casetest;

    for (int i=0; i< m_plateau.size(); i++)
    {
        for (int j=0; i< m_plateau[i].size(); j++)
        {
            casetest = m_plateau[i][j];
            remplissage = casetest.getremplie ();

            if (remplissage==false)
            {
                return true;
            }
            else (remplissage == true)
            {
                return false;
            }
        }
    }
}

//fonction pour trouver les cas possible
std::set < std::pair <int,int> > Plateau :: coups_possibles ()
{
    bool couleurtour=Joueur.getnumero();
    bool couleurcase=Case.gettype();
    int x,y;

    for (int i=0; i<= m_plateau.size(); i++)
    {
        x=j;
        for (int j=0; i<= m_plateau[i].size(); j++)
        {
            y=i
            if(couleurtour==couleurcase)
            {
                for(int a=0; a<8; a++)
                {
                    switch (a)
                    {
                    case 1: //Droite
                        m_plateau[x][y+1];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x][y+1];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur
                        }

                    case 2: //Gauche
                        m_plateau[x][y-1];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x][y-1];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur
                        }

                    case 3: //Haut
                        m_plateau[x+1][y];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x+1][y];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur
                        }

                    case 4: //Bas
                        m_plateau[x-1][y];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x-1][y];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur + besoin d'un setter?
                        }

                    case 5: //Haut Droit
                        m_plateau[x+1][y+1];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x+1][y+1];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur
                        }

                    case 6: //Haut Gauche
                        m_plateau[x+1][y-1];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x+1][y-1];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur
                        }

                    case 7: //Bas Droit
                        m_plateau[x-1][y+1];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x-1][y+1];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur
                        }

                    case 8: //Bas Gauche
                        m_plateau[x-1][y-1];
                        bool couleurcase=Case.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                            m_plateau[x-1][y-1];
                            bool couleurcase=Case.gettype();
                            }while(couleurcase!=couleurtour)

                            m_stockage_cas.insert(<x,y>);//pas sure de l'insertion dans le conteneur
                        }


                    } //fin du switch

                }//fin de la boucle for
            }


        }//fin du parcours du tableau 1D

    }//fin du parcours du tableau 2D

}//fin de la fonction

void Plateau :: vainqueur(int score1, int score2)
{

    if (score1 > score2)
    {
        std::cout << "le joueur 1 a gagne" << std::endl;
    }
    else
    {
      std::cout << "le joueur 2 a gagne" << std::endl;
    }
}



