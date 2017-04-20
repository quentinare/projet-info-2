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

void Joueur::setnumero (bool numero)
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

void Joueur::settour (bool tour)
{
    m_tour = tour;
}

std::string Joueur::getnom() const
{
    return m_nom;
}

int Joueur::getscore () const
{
    return m_score;
}

bool Joueur::getnumero () const
{
    return m_numero;
}

bool Joueur::gettour () const
{
    return m_tour;
}
