#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <iostream>
#include <vector>
#include <set>
#include "case.h"
#include "joueur.h"

class Plateau
{
private:
    std::vector<std::vector<Case> > m_plateau;
    std::vector<Case> m_stockage_cas;

public:
    Plateau();
    ~Plateau();

    void setTab(std::vector<std::vector<Case> > plateau);
    std::vector<std::vector<Case> > getTab() const;

    std::vector<std::vector<Case> > possibilite_placement (std::vector<std::vector<Case> > plateau);
    void calcul_encadrement(std::vector<std::vector<Case> > plateau);
    void afficherTab(std::vector<std::vector<Case> > m_plateau);
    void savegare_partie();
    void navigation_choix();
    void deplacement(int,int);
    void jeu ();
    bool casevide ();
    std::set < std::pair <int,int> > coups_possibles ();
    void vainqueur();
    bool play();
    void tour(std::vector<std::vector<Case> >, Joueur)

};

#endif // PLATEAU_H_INCLUDED
