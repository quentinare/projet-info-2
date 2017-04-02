#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class Case
{
protected:
    bool m_couleur;
    bool m_remplie;

public:
    Case();
    ~Case();

    void setcouleur(bool);
    void setremplie(bool);

    bool getcouleur()const;
    bool getremplie()const;
};

#endif // CASE_H_INCLUDED
