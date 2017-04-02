#ifndef HUMAIN_H_INCLUDED
#define HUMAIN_H_INCLUDED
#include "joueur.h"
#include "case.h"

class Humain : Joueur
{
public:
    Humain();
    ~Humain();

    void choix_coup(std::vector<std::vector<Case> > monplateau, std::vector<Case> stockagecas);
    void affichage_coup(std::vector<std::vector<Case> > monplateau);

};
#endif // HUMAIN_H_INCLUDED
