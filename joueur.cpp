#include <iostream>
#include <string>
#include <vector>

#include "joueur.h"

Joueur::Joueur()
{

}
Joueur::~Joueur()
{

}

void Joueur::setnumero (int numero)
{
    m_numero = numero;
}

void Joueur::setnom(std::string nom)
{
    m_nom = nom;
}
void Joueur::setscore (int score)
{
    m_score = score;
}

std::string Joueur::getnom() const
{
    return m_nom;
}

int Joueur::getscore () const
{
    return m_score;
}

int Joueur::getnumero () const
{
    return m_numero;
}
