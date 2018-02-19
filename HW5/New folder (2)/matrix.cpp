#include <iostream>
#include <string>

template<typename T>
class Matrix {
public:
	int m, n;
	T *elements;

	// we have to set the values as by default they would be random and our destructor would try to delete random memory
	Matrix() : m{ 0 }, n{ 0 }, elements{ nullptr }  // empty matrix contructor
	{}
	Matrix(int const m, int const n) : m{ m }, n{ n }, elements{ new T[m*n] } // matrix contructor
	{}
	Matrix(Matrix const &a) // matrix copy contructor
	{
		this->m = a.m;
		this->n = a.n;
		elements = new T[this->m*this->n];
		for (int i = 0; i < m*n; ++i) {
			this->elements[i] = a.elements[i];
		}
	}
	Matrix &operator=(Matrix const &a) // assigment
	{
		// ADD: check if we are assigning to ourselves
		if (this == &a)
			//			return cout << "Assigning to ourself";
			return *this;

		delete[] elements;
		m = a.m;
		n = a.n;
		elements = new T[m*n];
		for (int i = 0; i < m*n; ++i) {
			elements[i] = a[i];
		}
		return *this;
	}
	~Matrix()  // destructor
	{
		delete[] elements;
	}

	T &operator[](int const idx)  // single index element referencing
	{
		return elements[idx];
	}

	T &operator()(int const i, int const j) // duble index element referencing
	{
		return elements[i*this->n + j]; // REPLACE: here return element at row "i" and column "j"
	}

	T const &operator[](int const idx) const // single index const element referencing
	{
		return elements[idx];
	}

	T const &operator()(int const i, int const j) const // double index cosnt element referencing
	{
		return elements[i*this->n+j]; // REPLACE: here return element at row "i" and column "j"
	}

	Matrix<T> operator*(Matrix<T> const &b) // multiplication
	{
		Matrix<T> c(this->m,b.n);
		
		for (int i = 0; i < this->m; i++)
		{
			for (int j = 0; j < b.n; j++)
			{
				c(i,j) = 0;
				for (int k = 0; k < b.m; k++)
				{
					c(i,j) = c(i,j) + this->elements[i*b.m + k] * b(k,j);
				}
			}
		}

		return c; // REPLACE: here return the new matrix which is result of multiplication of "this" and "b"
	}
	

	Matrix<T> operator+(Matrix<T> const &b) // addition
	{
		Matrix<T> result(this->m,this->n);
		for (int i = 0; i < this->m; i++)
		{
			for (int j = 0; j < this->n; j++)
				result.elements[i * this->n + j] = this->elements[i*this->n + j] + b.elements[i*this->n + j];
		}
		
		return result; // REPLACE: here return the new matrix which is result of addition of "this" and "b"
	}

};

// read function
template<typename T>
std::istream &operator>>(std::istream& is, Matrix<T> &a) // read matrix
{
	int m, n;
	is >> m >> n;
	a = Matrix<T>{ m, n };

	for (int i = 0; i < m*n; ++i) {
		is >> a[i];
	}

	return is;
}

// print function
template<typename T>
std::ostream &operator<<(std::ostream& os, Matrix<T> const &a) // write matrix
{
	for (int i = 0; i < a.m; i++)
	{
		for (int j = 0; j < a.n; j++)
		{
			os << a.elements[i*a.n + j];
			if (j < a.n - 1)
				os << " ";
			
		}
		os << "\n";
	}
	return os;
}


int
main()
{
	int case_count = 0;
	std::cin >> case_count;

	for (int i = 0; i < case_count; ++i) {
		std::cout << "Case " << i << ":\n";

		std::string operation;
		std::cin >> operation;

		std::string type;
		std::cin >> type;

		if (type == "int") {
			Matrix<int> a, b;
			std::cin >> a >> b;

			if (operation == "add") {
				std::cout << a + b;
			}
			else if (operation == "multiply") {
				std::cout << a * b;
			}
		}
		else if (type == "double") {
			Matrix<double> a, b;
			std::cin >> a >> b;

			if (operation == "add") {
				std::cout << a + b;
			}
			else if (operation == "multiply") {
				std::cout << a*b;
			}
		}
	}
}
