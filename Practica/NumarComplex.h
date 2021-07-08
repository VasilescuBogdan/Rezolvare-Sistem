#include <iostream>

class NumarComplex
{
	double m_parte_reala;
	double m_parte_imaginara;

public:
	NumarComplex(double parte_reala, double parte_imaginara);
	NumarComplex();
	NumarComplex operator+(const NumarComplex& z);
	NumarComplex operator-(const NumarComplex& z);
	NumarComplex operator*(const NumarComplex& z);
	NumarComplex operator/(const NumarComplex& z);
	NumarComplex& operator=(const NumarComplex& z);
	friend std::ostream& operator<< (std::ostream& out, const NumarComplex& z);
	friend std::istream& operator>> (std::istream& in, NumarComplex& z);
	friend double mod(NumarComplex z);
};

