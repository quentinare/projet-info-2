#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>
#include <string>

class Joueur
{
protected:
    std::string m_nom;
    int m_score;
public:

    Joueur();
    ~Joueur();

    void setnom(std::string);
    void setscore (int);

    std::string getnom() const;
    int getscore () const;
};


#endif // JOUEUR_H_INCLUDED
