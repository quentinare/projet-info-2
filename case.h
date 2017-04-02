#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

class Case
{
protected:
    bool m_type;
    bool m_remplie;

public:
    Case();
    ~Case();

    void settype(bool);
    void setremplie(bool);

    bool gettype()const;
    bool getremplie()const;
};

#endif // CASE_H_INCLUDED
