#include <iostream>
#include <vector>
#include "Humain.h"
#include "joueur.h"
#include "plateau.h"
#include "case.h"

Humain :: Humain()
{

}
Humain :: ~Humain()
{

}

/*void Humain :: choix_coup(std::vector<std::vector<Case> > monplateau,std::set < std::pair <int,int> > m_stockage_cas)
{
    Plateau montableau;
    bool a = false;
    Case macase;

    monplateau = montableau.possibilite_placement(monplateau);

    for ( unsigned int i = 0; i<8; i++)
    {
        for ( unsigned int j = 0; j<8; j++)
        {

            macase = stockagecas[i][j];
            a = macase.getremplie();
            if (a == true)
            {
                monplateau[i][j] = stockagecas[i][j];
            }
        }
    }
    montableau.afficherTab(monplateau);

}*/

void Humain :: affichage_coup(std::vector<std::vector<Case> > monplateau)
{
}
