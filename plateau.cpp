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
