#include <iostream>
#include <vector>
#include "case.h"


Case::Case()
{

}

Case::~Case()
{

}

void Case::settype(bool type)
{
    m_type = type;
}
void Case::setremplie(bool remplie)
{
    m_remplie = remplie;
}

bool Case::gettype()const
{
    return m_type;
}

bool Case::getremplie()const
{
    return m_remplie;
}
