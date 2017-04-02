#ifndef HUMAIN_H_INCLUDED
#define HUMAIN_H_INCLUDED
#include "joueur.h"

class Humain : Joueur
{
public:
    void choix_coup();
    void affichage_coup();
};
#endif // HUMAIN_H_INCLUDED
