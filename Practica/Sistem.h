#include <iostream>


double mod(double x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

template <class T>
class Sistem
{
	int m_n;
	T m_a[10][11];

public:
	
	Sistem(int n);
	void Citire_Coeficienti();
	void Gauss_Total();
	void Gauss_Partial();
	void Factorizare();
	void Jacobi(T x[10], double e, int itmaxT);
	void Seidel_Gauss(T x[10], double e, int itmax);

};


template <class T>
Sistem<T>::Sistem(int n) : m_n(n)
{

}

template <class T>
void Sistem<T>::Citire_Coeficienti()
{
	for (int i = 1; i <= m_n; i++)
		for (int j = 1; j <= m_n + 1; j++)
			std::cin >> m_a[i][j];
}

template<class T>
void Sistem<T>::Gauss_Total()
{
	int c[10][3];
	int npc = 0;

	for (int k = 1; k <= m_n - 1; k++)
	{
		double piv = mod(m_a[k][k]);

		int lin = k, col = k;
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
				T aux = m_a[i][k];
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
		T S(0);
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


		/*
		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return;
		}
		*/

		if (lin != k)
		{
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
		T S(0);

		for (int j = i + 1; j <= m_n; j++)
			S = S + m_a[i][j] * m_a[j][m_n + 1];

		m_a[i][m_n + 1] = (m_a[i][m_n + 1] - S) / m_a[i][i];
	}

	for (int i = 1; i <= m_n; i++)
		std::cout << "x[" << i << "] = " << m_a[i][m_n + 1] << std::endl;
}

template<class T>
void Sistem<T>::Factorizare()
{
	if (mod(m_a[1][1]) == 0)
	{
		int i = 1;
		do
			i = i + 1;
		while (mod(m_a[i][1]) == 0 && i <= m_n);

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

	}

	for (int i = 2; i <= m_n; i++)
		m_a[i][1] = m_a[i][1] / m_a[1][1];

	for (int k = 2; k <= m_n; k++)
	{
		int i = k;
		T piv(0);
		do
		{
			T S(0);
			for (int h = 1; h <= k - 1; h++)
				S = S + m_a[i][h] * m_a[h][k];
			piv = m_a[i][k] - S;
			i = i + 1;
		} while (mod(piv) == 0 && i <= m_n);

		/*
		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}*/

		if (i != k + 1)
		{
			for (int j = 1; j <= m_n + 1; j++)
			{
				T aux = m_a[k][j];
				m_a[k][j] = m_a[i - 1][j];
				m_a[i - 1][j] = aux;
			}
		}



		for (int j = k; j <= m_n; j++)
		{
			T S(0);
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
		T S(0);
		for (int j = i + 1; j <= m_n; j++)
			S = S + m_a[i][j] * m_a[j][m_n + 1];
		m_a[i][m_n + 1] = (m_a[i][m_n + 1] - S) / m_a[i][i];
	}

	for (int i = 1; i <= m_n; i++)
		std::cout << "x[" << i << "] = " << m_a[i][m_n + 1] << std::endl;
}

template<class T>
void Sistem<T>::Jacobi(T x[10], double e, int itmax)
{
	int it;
	T y[10];
	double max;

	it = 0;

	do
	{
		max = 0;

		for (int i = 1; i <= m_n; i++)
		{
			T S = 0;

			for (int j = 1; j <= m_n; j++)
				if (j != i)
					S = S + m_a[i][j] * x[j];

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

	std::cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << e << " este : ";
	for (int i = 1; i <= m_n; i++)
		std::cout << x[i] << " ";

}

template<class T>
void Sistem<T>::Seidel_Gauss(T x[10], double e, int itmax)
{
	T y[10];
	double max;

	int it = 0;

	do
	{
		max = 0;

		for (int i = 1; i <= m_n; i++)
		{
			T S = 0;

			for (int j = 1; j <= m_n; j++)
				if (j != i)
					S = S + m_a[i][j] * x[j];

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

	std::cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << e << " este : ";
	for (int i = 1; i <= m_n; i++)
		std::cout << x[i] << " ";
}