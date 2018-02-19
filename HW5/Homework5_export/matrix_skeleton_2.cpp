#include <iostream>
#include <string>

template<typename T>
class Matrix {
public:
        int m, n;
        T *elements;

        // we have to set the values as by default they would be random and our destructor would try to delete random memory
        Matrix() : m{0}, n{0}, elements{nullptr}  // empty matrix contructor
		{}
        Matrix(int const m, int const n) : m{m}, n{n}, elements{new T[m*n]} // matrix contructor
		{}
        Matrix(Matrix const &a) // matrix copy contructor
        {
        }
        Matrix &operator=(Matrix const &a) // assigment
        {
                // ADD: check if we are assigning to ourselves

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
                        return elements[0]; // REPLACE: here return element at row "i" and column "j"
                }

		T const &operator[](int const idx) const // single index const element referencing
		{
                        return elements[idx];
                }

		T const &operator()(int const i, int const j) const // double index cosnt element referencing
		{
                        return elements[0]; // REPLACE: here return element at row "i" and column "j"
                }

		Matrix<T> operator*(Matrix<T> const &b) // multiplication
		{
                        return Matrix{}; // REPLACE: here return the new matrix which is result of multiplication of "this" and "b"
		}

		Matrix<T> operator+(Matrix<T> const &b) // addition
		{
                        return Matrix{}; // REPLACE: here return the new matrix which is result of addition of "this" and "b"
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
                        } else if (operation == "multiply") {
                                std::cout << a * b;
                        }
                } else if (type == "double") {
                        Matrix<double> a, b;
                        std::cin >> a >> b;
                        
                        if (operation == "add") {
                                std::cout << a + b;
                        } else if (operation == "multiply") {
                                std::cout << a*b;
                        }
                }
        }
}
