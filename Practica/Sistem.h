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


template <class T>
Sistem<T>::Sistem(unsigned int n) : m_n(n)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; i <= n + 1; j++)
			m_a[i][j] = 0;
}

template <class T>
void Sistem<T>::Citire_Coeficienti()
{
	for (int i = 1; i <= m_n; i++)
		for (int j = 1; i <= m_n + 1; j++)
			std::cin >> m_a[i][j];
}

template<class T>
void Sistem<T>::Gauss_Total()
{
	T c[10, 3];
	unsigned int npc = 0;

	for (int k = 1; k <= m_n - 1; k++)
	{
		T piv = mod(m_a[k][k]);

		unsigned int lin = k, col = k;
		for (int i = k; i <= m_n; i++)
			for (int j = k; j <= m_n; j++)
				if (piv < mod(m_a[i][j]))
				{
					piv = mod(m_a[i][j]);
					lin = i;
					col = j;
				}

		/*
		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}
		*/
		if (lin != k)
			for (int j = k; j <= m_n + 1; j++)
			{
				T aux = m_a[k][j];
				m_a[k][j] = m_a[lin][j];
				m_a[lin][j] = aux;
			}

		if (col != k)
		{
			npc = npc + 1;
			c[npc][1] = k;
			c[npc][2] = col;
			for (int i = 1; i <= m_n; i++)
			{
				int aux = m_a[i][k];
				m_a[i][k] = m_a[i][col];
				m_a[i][col] = aux;
			}
		}

		for (int i = k + 1; i <= m_n; i++)
		{
			m_a[i][k] = m_a[i][k] / m_a[k][k];
			for (int j = k + 1; j <= m_n + 1; j++)
				m_a[i][j] = m_a[i][j] - m_a[i][k] * m_a[k][j];
		}
	}

	/*if (mod(m_a[m_n][m_n]) == 0)
	{
		std::cout << "Sistemul nu are solutie unica";
		return 0;
	}*/

	m_a[m_n][m_n + 1] = m_a[m_n][m_n + 1] / m_a[m_n][m_n];

	for (int i = m_n - 1; i >= 1; i--)
	{
		T S = 0;
		for (int j = i + 1; j <= m_n; j++)
			S = S + m_a[i][j] * m_a[j][m_n + 1];
		m_a[i][m_n + 1] = (m_a[i][m_n + 1] - S) / m_a[i][i];
	}

	if (npc != 0)
		for (int i = npc; i >= 1; i--)
		{
			T aux = m_a[c[i][1]][m_n + 1];
			m_a[c[i][1]][m_n + 1] = m_a[c[i][2]][m_n + 1];
			m_a[c[i][2]][m_n + 1] = aux;
		}

	for (int i = 1; i <= m_n; i++)
		std::cout << "x[" << i << "] = " << m_a[i][m_n + 1] << std::endl;
}

template<class T>
void Sistem<T>::Gauss_Partial()
{
	unsigned int nrp = 0;

	for (int k = 1; k < m_n; k++)
	{
		T piv = m_a[k][k];
		int lin = k;

		for (int i = k + 1; i <= m_n; i++)
			if (mod(piv) < mod(m_a[i][k]))
			{
				piv = m_a[i][k];
				lin = i;
			}

		std::cout << "pivotul la pasul " << k << " este " << piv << std::endl;
		std::cout << "acesta se afla pe pozitia " << lin << " cu " << k << std::endl;

		/*
		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return;
		}
		*/

		if (lin != k)
		{
			std::cout << "au fost permutate liniile " << k << " si " << lin << std::endl;
			nrp++;
			for (int j = k; j <= m_n + 1; j++)
			{


				T aux = m_a[k][j];
				m_a[k][j] = m_a[lin][j];
				m_a[lin][j] = aux;
			}
		}

		for (int i = k + 1; i <= m_n + 1; i++)
		{
			m_a[i][k] = m_a[i][k] / m_a[k][k];

			for (int j = k + 1; j <= m_n + 1; j++)
				m_a[i][j] = m_a[i][j] - m_a[i][k] * m_a[k][j];
		}
	}

	/*if (m_a[m_n][m_n] == 0)
	{
		std::cout << "Sistemul nu are solutie unica";
		return;
	}*/

	m_a[m_n][m_n + 1] = m_a[m_n][m_n + 1] / m_a[m_n][m_n];

	for (int i = m_n - 1; i >= 1; i--)
	{
		T S = 0;

		for (int j = i + 1; j <= m_n; j++)
			S = S + m_a[i][j] * m_a[j][m_n + 1];

		m_a[i][m_n + 1] = (m_a[i][m_n + 1] - S) / m_a[i][i];
	}

	for (int i = 1; i <= m_n; i++)
		std::cout << "x[" << i << "] = " << m_a[i][m_n + 1] << std::endl;

	std::cout << "au fost facute " << nrp << " permutari";
}

template<class T>
void Sistem<T>::Factorizare()
{
	if (m_a[1][1] == 0)
	{
		int i = 1;
		do
			i = i + 1;
		while (m_a[i][1] == 0 && i <= m_n);

		/*if (i > m_n)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}*/

		for (int j = 1; j <= m_n + 1; j++)
		{
			T aux = m_a[1][j];
			m_a[1][j] = m_a[i][j];
			m_a[i][j] = aux;
		}
		std::cout << "Se permuta linia 1 cu linia" << i << std::endl;
	}

	for (int i = 2; i <= m_n; i++)
		m_a[i][1] = m_a[i][1] / m_a[1][1];

	for (int k = 2; k <= m_n; k++)
	{
		int i = k;
		T piv = 0;
		do
		{
			T S = 0;
			for (int h = 1; h <= k - 1; h++)
				S = S + m_a[i][h] * m_a[h][k];
			piv = m_a[i][k] - S;
			i = i + 1;
		} while (piv == 0 && i <= m_n);

		/*
		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}*/

		if (i != k + 1)
		{
			std::cout << "Se permuta linia " << i - 1 << " cu linia " << k << std::endl;
			for (int j = 1; j <= m_n + 1; j++)
			{
				T aux = m_a[k][j];
				m_a[k][j] = m_a[i - 1][j];
				m_a[i - 1][j] = aux;
			}
		}



		for (int j = k; j <= m_n; j++)
		{
			T S = 0;
			for (int h = 1; h <= k - 1; h++)
				S = S + m_a[k][h] * m_a[h][j];
			m_a[k][j] = m_a[k][j] - S;
		}

		for (int i = k + 1; i <= m_n; i++)
		{
			T S = 0;
			for (int h = 1; h <= k - 1; h++)
				S = S + m_a[i][h] * m_a[h][k];
			m_a[i][k] = (m_a[i][k] - S) / m_a[k][k];
		}
	}

	std::cout << "L = " << std::endl;
	for (int i = 1; i <= m_n; i++)
	{
		for (int j = 1; j <= m_n; j++)
			if (i == j)
				std::cout << "1 ";
			else if (i < j)
				std::cout << "0 ";
			else
				std::cout << m_a[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << "R = " << std::endl;
	for (int i = 1; i <= m_n; i++)
	{
		for (int j = 1; j <= m_n; j++)
			if (i > j)
				std::cout << "0 ";
			else
				std::cout << m_a[i][j] << " ";
		std::cout << std::endl;
	}

	for (int i = 2; i <= m_n; i++)
	{
		T S = 0;
		for (int k = 1; k <= i - 1; k++)
			S = S + m_a[i][k] * m_a[k][m_n + 1];
		m_a[i][m_n + 1] = m_a[i][m_n + 1] - S;
	}

	m_a[m_n][m_n + 1] = m_a[m_n][m_n + 1] / m_a[m_n][m_n];

	for (int i = m_n - 1; i >= 1; i--)
	{
		T S = 0;
		for (int j = i + 1; j <= m_n; j++)
			S = S + m_a[i][j] * m_a[j][m_n + 1];
		m_a[i][m_n + 1] = (m_a[i][m_n + 1] - S) / m_a[i][i];
	}

	for (int i = 1; i <= m_n; i++)
		std::cout << "x[" << i << "] = " << m_a[i][m_n + 1] << std::endl;
}

template<class T>
void Sistem<T>::Jacobi(T x[10], T e, unsigned int itmax)
{
	unsigned int it;
	T y[10], max;

	it = 0;

	do
	{
		max = 0;

		for (int i = 1; i <= m_n; i++)
		{
			T S = 0;

			for (int j = 1; j <= m_n; j++)
				if (j != i)
					S += m_a[i][j] * x[j];

			y[i] = (m_a[i][m_n + 1] - S) / m_a[i][i];

			if (max < mod(y[i] - x[i]))
				max = mod(y[i] - x[i]);
		}

		for (int i = 1; i <= m_n; i++)
			x[i] = y[i];

		it++;
	} while (max > e && it <= itmax);

	/*
	if (it > itmax)
	{
		std::cout << "nu se poate obtine solutia in " << itmax << " iteratii cu precizia " << e;
		return 0;
	}
	*/

	std::cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << e << " este :";
	for (int i = 1; i <= m_n; i++)
		std::cout << x[i] << " ";

}

template<class T>
void Sistem<T>::Seidel_Gauss(T x[10], T e, unsigned int itmax)
{
	T y[10], max;

	unsigned int it = 0;

	do
	{
		max = 0;

		for (int i = 1; i <= m_n; i++)
		{
			T S = 0;

			for (int j = 1; j <= m_n; j++)
				if (j != i)
					S += m_a[i][j] * x[j];

			y[i] = (m_a[i][m_n + 1] - S) / m_a[i][i];

			if (max < mod(y[i] - x[i]))
				max = mod(y[i] - x[i]);

			x[i] = y[i];
		}

		it++;
	} while (max > e && it <= itmax);

	/*if (it > itmax)
	{
		std::cout << "nu se poate obtine solutia in " << itmax << " iteratii cu precizia " << e;
		return 0;
	}
	*/

	std::cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << e << " este :";
	for (int i = 1; i <= m_n; i++)
		std::cout << x[i] << " ";
}