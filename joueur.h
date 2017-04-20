#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include <iostream>
#include <string>

class Joueur
{
protected:
    std::string m_nom;
    int m_score;
    bool m_numero;
    bool m_tour;

public:

    Joueur();
    ~Joueur();

    void setnom(std::string);
    void setscore (int);
    void setnumero (bool);
    void settour (bool);

    std::string getnom() const;
    int getscore () const;
    bool getnumero () const;
    bool gettour () const;


    void jeu();// fonction qui permet d'alterner les joueur jusqu'à la fin du jeu
};


#endif // JOUEUR_H_INCLUDED
