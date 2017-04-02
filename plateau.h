#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include <iostream>
#include <vector>
#include "case.h"

class Plateau
{
private:
    std::vector<std::vector<Case> > m_plateau;

public:
    Plateau();
    ~Plateau();
    void afficherTab();
    void setTab(std::vector<std::vector<Case> > plateau);
    std::vector<std::vector<Case> > getTab() const;

};

#endif // PLATEAU_H_INCLUDED
