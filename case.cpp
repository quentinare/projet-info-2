#include <iostream>
#include "case.h"
Case::Case()
{
    m_couleur = 1;
    m_remplie = 0;
}

Case::~Case()
{

}

void Case :: setcouleur(bool couleur)
{
    m_couleur = couleur;
}
void Case :: setremplie(bool remplie)
{
    m_remplie = remplie;
}

bool Case :: getcouleur()const
{
    return m_couleur;
}

bool Case :: getremplie()const
{
    return m_remplie;
}
