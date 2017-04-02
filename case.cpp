#include <iostream>
#include "case.h"
Case::Case()
{
    m_type = -1;
    m_remplie = -1;
}

Case::~Case()
{

}

void Case :: settype(bool type)
{
    m_type = type;
}
void setremplie(bool remplie)
{
    m_remplie = remplie;
}

bool Case::gettype()const
{
    return m_type;
}

bool getremplie()const
{
    return m_remplie;
}
