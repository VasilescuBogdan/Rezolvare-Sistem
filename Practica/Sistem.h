#include <iostream>

double mod(double x);

template <class T>
class Sistem
{
	unsigned int m_n;
	T m_a[10][11];

public:
	
	Sistem(unsigned int n);
	void Citire_Coeficienti();
	void Gauss_Total();
	void Gauss_Partial();
	void Factorizare();
	void Jacobi(T x[10], T e, unsigned int itmaxT);
	void Seidel_Gauss(T x[10], T e, unsigned int itmax);

};
