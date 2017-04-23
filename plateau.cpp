#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>
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

void Plateau :: setTab(std::vector<std::vector<Case> > plateau)
{
    m_plateau = plateau;
}

std::vector<std::vector<Case> > Plateau::getTab() const
{
    return m_plateau;
}

std::vector<std::vector<Case> > Plateau::initialise()
{
    //création du plateau de jeu
    std::vector<std::vector<Case> > plateau;
    int x,y;
    Case c;
    Plateau LePlateau;
    plateau=std::vector<std::vector<Case> >(8, std::vector<Case>(8));

    std::cout<<"coucou2"<<std::endl;// wtf

    // boucle d'initialisation
	for (int i=0; i<8; i++)
    {
        x=i;
        for (int j=0; j<8; j++)
        {
            y=j;

            if(i==3 && j==3)
            {
                c.setremplie(true);
                c.settype(true);
                plateau[x][y]=c;//rempli
                plateau[x][y]=c; //blanc
            }
            if(i==3 && j==4)
            {
                c.setremplie(true);
                c.settype(false);
                plateau[x][y]=c; //rempli
                plateau[x][y]=c; //blanc
            }
            if(i==4 && j==4)
            {
                c.setremplie(true);
                c.settype(true);
                plateau[x][y]=c; //rempli
                plateau[x][y]=c; //blanc
            }
            if(i==4 && j==3)
            {
                c.setremplie(true);
                c.settype(false);
                plateau[x][y]=c; //rempli
                plateau[x][y]=c; //blanc
            }
            else
            {
                c.setremplie(false);
            }

        }//fin boucle 1D
    }//fin boucle 2D
    LePlateau.setTab(plateau);
    return plateau;
}//fin de la fonction

void Plateau :: afficherTab(std::vector<std::vector<Case> > plateau)
{
    bool typea, remplia;
    Case c;

    //std::cout<<"coucou2"<<std::endl;

    for (unsigned int i=0; i<plateau.size(); i++)
    {
        for (unsigned int j=0; j<plateau.size(); j++)
        {

            //std::cout<<"coucou3"<<std::endl;
            c = plateau[i][j];
            //std::cout<<"coucou4"<<std::endl;

            typea = c.gettype();

            remplia = c.getremplie();

            if(remplia == true)
            {
                if(typea == false)
                {
                    std::cout << "N ";
                }
                else
                {
                    std::cout << "B ";
                }
            }
            else
            {
                std::cout << "* ";
            }

        }
        std::cout<<std::endl;
    }
}

void Plateau :: deplacement(int i, int j)
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
            //std::cout << "touche = " << key << std::endl;

            if (key == 27) // 27 = touche escape
            {
                quit = true;
            }

            if (key == 'd')//curseur ves le haut
            {
                i=i+1;
                pConsole->gotoLigCol(i,j);
            }

            if (key == 'e')//curseur vers le bas
            {
                i=i-1;
                pConsole->gotoLigCol(i,j);
            }

            if (key == 'f')//curseur vers la droite (touche f)
            {
                j=j+2;
                pConsole->gotoLigCol(i,j);
            }

            if (key == 's')//curseur vers la gauche
            {
                j=j-2;
                pConsole->gotoLigCol(i,j);
            }
        }
    }

    // Libčre la mémoire du pointeur !
    Console::deleteInstance();
}

void Regle ()
{
    int i;


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

        std::cin >> i;



        while (i!=1)
        {
            std::cout <<"veuillez recommencer"<<std::endl;
            std::cin >> i;
        }

    }

    //fonction pour trouver les cas possible
std::set < std::pair <int,int> > Plateau :: coups_possibles (Joueur monjoueur)
{
    bool couleurtour;
    bool couleurcase;
    Case c;
    int x,y;

    couleurtour = monjoueur.getnumero();

    for (int i=0; i< m_plateau.size(); i++)
    {
        x=i;
        for (int j=0; i< m_plateau[i].size(); j++)
        {
            y=j;
            if(couleurtour==couleurcase)
            {
                for(int a=0; a<8; a++)
                {
                    switch (a)
                    {
                    case 1: //Droite
                        c = m_plateau[x][y+1];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                            if(couleurcase!=couleurtour)
                        {
                            do{
                                c = m_plateau[x][y+1];
                                couleurcase=c.gettype();
                                y=y+1;

                            } while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int> (x,y));
                            break;
                        }

                    case 2: //Gauche
                        c = m_plateau[x][y-1];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                            if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x][y-1];
                                couleurcase=c.gettype();
                                y=y-1;

                            }while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int> (x,y));
                            break;
                        }

                    case 3: //Haut
                        c = m_plateau[x+1][y];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                            if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x+1][y];
                                couleurcase=c.gettype();
                                x=x+1;

                            }while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int> (x,y));
                            break;
                        }

                    case 4: //Bas
                        c = m_plateau[x-1][y];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                            if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x-1][y];
                                couleurcase=c.gettype();
                                x=x-1;

                            }while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int> (x,y));
                            break;
                        }

                    case 5: //Haut Droit
                        c = m_plateau[x+1][y+1];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }


                            if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x+1][y+1];
                                couleurcase=c.gettype();
                                x=x+1;
                                y=y+1;

                            }while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int> (x,y));
                            break;
                        }

                    case 6: //Haut Gauche
                        c = m_plateau[x+1][y-1];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                            if(couleurcase!=couleurtour)
                        {

                            do
                            {

                                c = m_plateau[x+1][y-1];
                                couleurcase=c.gettype();
                                x=x+1;
                                y=y-1;

                            }while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int> (x,y));
                            break;
                        }

                    case 7: //Bas Droit
                        c = m_plateau[x-1][y+1];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                            if(couleurcase!=couleurtour)
                        {
                            do
                            {

                                c = m_plateau[x-1][y+1];
                                couleurcase=c.gettype();
                                x=x-1;
                                y=y+1;

                            }while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int>(x,y));
                            break;
                        }

                    case 8: //Bas Gauche
                        c = m_plateau[x-1][y-1];
                        couleurcase=c.gettype();

                            if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                            if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x-1][y-1];
                                couleurcase=c.gettype();
                                x=x-1;
                                y=y-1;

                            }while(couleurcase!=couleurtour || c.getremplie()!=true);

                            m_stockage_cas.insert(std::pair <int,int>(x,y));
                            break;
                        }


                    } //fin du switch

                }//fin de la boucle for
            }


        }//fin du parcours du tableau 1D

    }//fin du parcours du tableau 2D

}//fin de la fonction

//fonction de jeu traduction Valentin
void Plateau :: jeu ()
{
/*
    Joueur monjoueur1;
    Joueur monjoueur2;

    monjoueur1.setnumero(false);
    monjoueur2.setnumero(true);


    while (casevide()==true)
        {

            while (monjoueur1.getnumero()==false && monjoueur2.getnumero()==false)
                {

                    tour(m_plateau, monjoueur1);

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

*/
}//fin de la fct de jeu


// fonction de jeu
/*void Plateau :: jeu ()
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

    }while (vide==0) //while (la touche de fin n'est pas appuyée OU qu'il n'y a pas de victoire OU que l'on ne peut pas jouer) // fin du do

}//fin de la fct de jeu
*/


//fonction case vide
/*bool Plateau :: casevide ()
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
            else (remplissage==true)
            {
                return false;
            }
        }
    }
}*/

/*void Plateau :: encadrement(int x, int y, Joueur monjoueur)
{
    bool couleurtour;
    bool couleurcase;
    Case c;
    int x,y;
    int compteur = 0;

    couleurtour = monjoueur.getnumero();

            if(couleurtour==couleurcase)
            {
                for(int a=0; a<8; a++)
                {
                    switch (a)
                    {
                    case 1: //Droite
                        c = m_plateau[x][y+1];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y || c.getremplie()!=true) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x][y+1];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x][y-1];
                                        c.settype(couleurtour);
                                        y = y-1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            y = y +1;
                            break;
                        }

                    case 2: //Gauche
                        c = m_plateau[x][y-1];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x][y-1];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x][y+1];
                                        c.settype(couleurtour);
                                        y = y+1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            y = y-1;
                            break;
                        }

                    case 3: //Haut
                        c = m_plateau[x+1][y];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x+1][y];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x-1][y];
                                        c.settype(couleurtour);
                                        x = x-1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            x = x+1;
                            break;
                        }

                    case 4: //Bas
                        c = m_plateau[x-1][y];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x-1][y];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x+1][y];
                                        c.settype(couleurtour);
                                        x = x+1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            x = x-1;
                            break;
                        }

                    case 5: //Haut Droit
                        c = m_plateau[x+1][y+1];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x+1][y+1];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x-1][y-1];
                                        c.settype(couleurtour);
                                        x = x-1;
                                        y = y-1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            x = x+1;
                            y = y+1;
                            break;
                        }

                    case 6: //Haut Gauche
                        c = m_plateau[x+1][y-1];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x+1][y-1];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x-1][y+1];
                                        c.settype(couleurtour);
                                        x = x-1;
                                        y = y+1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            x = x+1;
                            y = y-1;
                            break;
                        }

                    case 7: //Bas Droit
                        c = m_plateau[x-1][y+1];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x-1][y+1];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x+1][y-1];
                                        c.settype(couleurtour);
                                        x = x+1;
                                        y = y-1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            x = x-1;
                            y = y+1;
                            break;
                        }

                    case 8: //Bas Gauche
                        c = m_plateau[x-1][y-1];
                        couleurcase=c.gettype();
                        if(couleurcase==couleurtour || 0<x || x>8 || 0<y || x>y) // couleur pion = couleur du jeur OU sortie du tableau
                        {
                            break;
                        }

                        if(couleurcase!=couleurtour)
                        {
                            do
                            {
                                c = m_plateau[x-1][y-1];
                                if (couleurcase==couleurtour)
                                {
                                    for(unsigned int i = 0; i<compteur; i++)
                                    {
                                        c = m_plateau[x+1][y+1];
                                        c.settype(couleurtour);
                                        x = x+1;
                                        y = y+1;
                                    }
                                }
                                compteur++;

                            }while(0<x || x>8 || 0<y || x>y || c.getremplie()!=true)
                            x = x-1;
                            y = y-1;
                            break;
                        }


                    } //fin du switch

                }//fin de la boucle for
            }


        }//fin du parcours du tableau 1D
        */


/*void Plateau :: vainqueur(int score1, int score2)
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
*/


