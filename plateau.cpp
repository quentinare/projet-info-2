#include <iostream>
#include "plateau.h"
#include "case.h"

Plateau :: Plateau ()
{

}

Plateau :: ~Plateau ()
{

}

void afficherTab(std::vector<std::vector<Case> > m_plateau)
{
    bool typea, remplia;

    for (int i=0; i<m_plateau.size(); i++)
    {
        for (int j=0; j<m_plateau.size(); j++)
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

void setTab(std::vector<std::vector<Case> > plateau)
{
    m_plateau = plateau;
}

std::vector<std::vector<Case> > getTab() const
{
    return m_plateau;
}

void Plateau :: deplacement()
{
    bool quit = false;
    Console* pConsole = NULL;

    // Alloue la mémoire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(5, 10);
    pConsole->setColor(COLOR_GREEN);
    pConsole->setColor(COLOR_DEFAULT);

    // Boucle événementielle
    while (!quit)
    {
        // Si on a appuyé sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            // Récupčre le code ASCII de la touche
            int key = pConsole->getInputKey();
            std::cout << "touche = " << key << std::endl;

            if (key == 27) // 27 = touche escape
            {
                quit = true;
            }

            if (key == e)//curseur ves le haut
            {
                gotoLigCol(i+1,j);
            }

            if (key == d)//curseur vers le bas
            {
                gotoLigCol(i-1,j);
            }

            if (key == f)//curseur vers la droite
            {
                gotoLigCol(i,j+1);
            }

            if (key == s)//curseur vers la gauche
            {
                gotoLigCol(i,j-1);
            }
        }
    }

    // Libčre la mémoire du pointeur !
    Console::deleteInstance();
}
