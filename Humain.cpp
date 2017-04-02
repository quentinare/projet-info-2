#include <iostream>
#include "Humain.h"
#include "joueur.h"
#include "plateau.h"

Humain :: Humain()
{

}
Humain :: ~Humain()
{

}

void Humain :: choix_coup(std::vector<std::vector<Case> > monplateau, std::vector<std::vector<Case> > stockagecas)
{
    Plateau montableau;

    monplateau = montableau.possibilite_placement(monplateau);

    for ( unsigned int i = 0; i<8; i++)
    {
        for ( unsigned int j = 0; j<8; j++)
        {
            if (stockagecas[i][j].getremplie == true)
            {
                monplateau[i][j] = stockagecas[i][j];
            }
        }
    }


    montableau.affichertab(monplateau);
}

void Huamin :: affichage_coup()
{

}
