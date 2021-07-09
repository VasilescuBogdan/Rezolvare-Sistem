#include "NumarComplex.h"
#include <math.h>

NumarComplex::NumarComplex(double parte_reala, double parte_imaginara): m_parte_reala(parte_reala), 
    m_parte_imaginara(parte_imaginara)
{

}

NumarComplex::NumarComplex(int integer): m_parte_reala(integer),m_parte_imaginara(0)
{
}

NumarComplex::NumarComplex() : m_parte_reala(0), m_parte_imaginara(0)
{

}

NumarComplex NumarComplex::operator+(const NumarComplex& z)
{
    return NumarComplex(m_parte_reala + z.m_parte_reala, m_parte_imaginara + z.m_parte_imaginara);
}

NumarComplex NumarComplex::operator-(const NumarComplex& z)
{
    return NumarComplex(m_parte_reala - z.m_parte_reala, m_parte_imaginara - z.m_parte_imaginara);
}

NumarComplex NumarComplex::operator*(const NumarComplex& z)
{
    return NumarComplex(m_parte_reala * z.m_parte_reala - z.m_parte_imaginara * m_parte_imaginara, 
        m_parte_reala * z.m_parte_imaginara + m_parte_imaginara * z.m_parte_reala);
}

double mod(NumarComplex z)
{
    return sqrt(z.m_parte_reala * z.m_parte_reala + z.m_parte_imaginara * z.m_parte_imaginara);
}

NumarComplex NumarComplex::operator/(const NumarComplex& z)
{
    return NumarComplex( (m_parte_reala * z.m_parte_reala + z.m_parte_imaginara * m_parte_imaginara)
        / pow(mod(z), 2), (m_parte_imaginara * z.m_parte_reala - m_parte_reala * z.m_parte_imaginara) 
        / pow(mod(z), 2) );
}

void NumarComplex::operator=(const NumarComplex& z)
{
    m_parte_reala = z.m_parte_reala;
    m_parte_imaginara = z.m_parte_imaginara;
}


void NumarComplex::operator=(const int& n)
{
    this->m_parte_reala = n;
    this->m_parte_imaginara = 0;
}



std::ostream& operator<<(std::ostream& out, const NumarComplex& z)
{
    if (z.m_parte_imaginara > 0)
        out << z.m_parte_reala << "+" << z.m_parte_imaginara << "i";
    else
        if (z.m_parte_imaginara < 0)
            out << z.m_parte_reala << z.m_parte_imaginara << "i";
        else out << z.m_parte_reala;
    return out;
}

std::istream& operator>>(std::istream& in, NumarComplex& z)
{
    in >> z.m_parte_reala >> z.m_parte_imaginara;
    return in;
}
