#include "console.h"
#include <conio.h>
#include <windows.h>

Console* Console::m_instance = NULL;

Console::Console()
{
    m_instance = NULL;
}

Console::~Console()
{

}

void Console::deleteInstance()
{
    delete m_instance;
    m_instance = NULL;
}

Console* Console::getInstance()
{
    if (!Console::m_instance)
    {
        m_instance = new Console();
    }

    return m_instance;
}

void Console::gotoLigCol(int lig, int col)
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

int Console::getInputKey()
{
    return getch();
}

bool Console::isKeyboardPressed()
{
    return kbhit();
}

/*
0: noir
1: bleu foncé
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc
*/
void Console::_setColor(int back, int front)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,front*16+back);
}

void Console::setColor(Color col)
{
    switch (col)
    {
        case COLOR_WHITE:
            this->_setColor(15, 0);
            break;
        case COLOR_BLACK:
            this->_setColor(0, 0);
            break;
        case COLOR_RED:
            this->_setColor(12, 0);
            break;
        case COLOR_GREEN:
            this->_setColor(10, 0);
            break;
        case COLOR_BLUE:
            this->_setColor(9, 0);
            break;
        case COLOR_YELLOW:
            this->_setColor(14, 0);
            break;
        case COLOR_PURPLE:
            this->_setColor(5, 0);
            break;
        default:
            this->_setColor(7, 0);
    }
}

void menu()
{
    int choixMenu=0;

    do
    {
        std::cout << "Bienvenue dans l'OTHELLO!" << std::endl;
        std::cout << "Veuillez choisir ce que vous souhaitez faire" << std::endl;
        std::cout << "1. JOUER " << std::endl;
        std::cout << "2. Lire les régles du jeux" << std::endl;
        std::cout << "3.Quitter" << std::endl;

    } while (choixMenu != 1 || choixMenu != 2 || choixMenu != 3);

}

/* fonction de jeu
void jeu()
{
    do
    {
    fonction tester s'il y a une case vide.
        
        while( il y a une case vide)
        { 
        
        fonction tester s'il y a une case vide
        
            While (getJnumero==0) // (c'est le tour du joueur 1)
            do {
            parcourir le tableau pour savoir ou on peut placer un pion + le stocker dans un tableau
            afficher le tableu + proposition de placement + "A vous de jouer J1"
            fonction de déplacement
                If( joueur appuie sur espace pour placet le pion && le curseur est sur une des cases contenue dans le tableau de proposition)
                {
                setJnumero==1;
                }
                Else
                {
                "vous avez sélectionné une mauvaise case"
                }
            }//fin du vhile do
            
        fonction tester s'il y a une case vide
        
            While (getJnumero==1) // (c'est le tour du joueur 2)
            do 
            {
            parcourir le tableau pour savoir ou on peut placer un pion + le stocker dans un tableau
            afficher le tableu + proposition de placement + "A vous de jouer J2"
            fonction de déplacement
                If( joueur appuie sur espace pour placet le pion && le curseur est sur une des cases contenue dans le tableau de proposition)
                {
                setJnumero==0;
                }
                Else
                {
                "vous avez sélectionné une mauvaise case"
                }
            }//fin du while do
            
        fonction tester s'il y a une case vide
       
        }//fin du while do
       
    } // fin du do
   */
