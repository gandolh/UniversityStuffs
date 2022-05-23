// FacemCePutem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


template <typename T> class Matrice {
private:
	T** matrice;
	int n, m;
public:
	Matrice(int n, int m);
	
	template<typename B>
	friend void operator >> (std::istream&, Matrice<B>&);
	
	template<typename B>
	friend void operator << (std::ostream&, Matrice<B>&);

	Matrice<T>& operator += (Matrice<T>&);
	Matrice<T>& operator * (float);
	//template<typename B>
	//friend  Matrice<B>& operator + (Matrice<B>&, Matrice<B>&);


	~Matrice() {
		for (int i = 0; i < n; i++)
			delete[] matrice[i];
		delete matrice;
	}
	
	void afisare(std::ostream& out) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				out << matrice[i][j] << " ";
			out << std::endl;
		}
				

	}
};
template <typename T>
Matrice<T>::Matrice(int n, int m) {
	this->n = n;
	this->m = m;
	matrice = new T * [n];
	for (int i = 0; i < n; i++)
		matrice[i] = new T[m];
}
template<typename T>
void operator >> (std::istream& in, Matrice<T>& M)
{
	//std::cout << "Baga n\n";
	//in >> M.n;
	//std::cout << "Baga m\n";
	//in >> M.m;
	std::cout << "Baga matrice\n";
	for (int i = 0; i < M.n; i++)
		for (int j = 0; j < M.m; j++)
			std::cin >> M.matrice[i][j];
}

template<typename T>
void operator << (std::ostream& out, Matrice<T>& M)
{
	M.afisare(out);
}

template<typename T>
Matrice<T>& Matrice<T>::operator += (Matrice<T>& m1) {
	try
	{
		if (this->n != m1.n || this->m != m1.m) {
			throw "nu merge";
		}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					this->matrice[i][j] += m1.matrice[i][j];
			}
		}
	}
	catch (const std::exception& err)
	{
		//std::cout << "sad";
	}



		
}

template<typename T>
Matrice<T>& Matrice<T>::operator * (float m1) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			this->matrice[i][j] *= m1;
		}
	}
	return *this;
}

int main()
{
	Matrice<double> m(2,2);
	Matrice<double> n(2,2);
	std::cin >> m;
	std::cin >> n;
	m += n;
	m = m*3;
	std::cout << m;
}
