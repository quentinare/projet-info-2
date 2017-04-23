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
    std::set < std::pair <int,int> > m_stockage_cas;

public:
    Plateau();
    ~Plateau();

    void setTab(std::vector<std::vector<Case> > plateau);
    std::vector<std::vector<Case> > getTab() const;
    std::set < std::pair <int,int> > getstockage_cas ();

    //std::vector<std::vector<Case> > possibilite_placement (std::vector<std::vector<Case> > plateau);
    void calcul_encadrement(std::vector<std::vector<Case> > m_plateau);
    void afficherTab(std::vector<std::vector<Case> > m_plateau);
    void savegare_partie();
    //void navigation_choix();
    void deplacement(int,int);
    void jeu ();
    std::vector<std::vector<Case> > initialise();
    bool casevide ();
    std::set < std::pair <int,int> > coups_possibles (Joueur monjoueur);
    void vainqueur();
    bool play();
    void tour(std::vector<std::vector<Case> >, Joueur);
    void changement_couleur();
    void Regle ();
    void blindageposH (int x, int y, std::set(std::pair <int,int>) coups_possible);

};

#endif // PLATEAU_H_INCLUDED
