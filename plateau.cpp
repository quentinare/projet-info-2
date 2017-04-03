#include <iostream>
#include "plateau.h"
#include "case.h"

Plateau :: Plateau ()
{

}

Plateau :: ~Plateau ()
{

}

void Plateau :: afficherTab()
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            std::cout <<  m_plateau[i][j]<< std::endl;
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
            // Récupère le code ASCII de la touche
            int key = pConsole->getInputKey();
            std::cout << "touche = " << key << std::endl;

            if (key == 27) // 27 = touche escape
            {
                quit = true;
            }
            if (key == e)
        }
    }

    // Libère la mémoire du pointeur !
    Console::deleteInstance();
}
