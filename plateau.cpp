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
    bool typea, remplia;

    for (int i=0; i<m_plateau.size(); i++)
    {
        for (int j=0; j<m_plateau.size(); j++)
        {

            typea = m_plateau[i][j].gettype();
            remplia = m_plateau [i][j].getremplie();
            std::cout << "" << std::endl;
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
