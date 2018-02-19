#include <iostream>
#include <string>

template<typename T>
class Matrix {
public:
        int m, n;
        T *elements;

        Matrix()  // empty matrix contructor
		{}
        Matrix(int const m, int const n)  // matrix contructor
		{}
        Matrix(Matrix const &a) // matrix copy contructor
        {
        }
        Matrix &operator=(Matrix const &a) // assigment
        {
        }
        ~Matrix()  // destructor
		{}
		
		T &operator[](int const idx)  // single index element referencing
		{}
		T &operator()(int const i, int const j) // duble index element referencing
		{}
		T const &operator[](int const idx) const // single index const element referencing
		{}
		T const &operator()(int const i, int const j) const // double index cosnt element referencing
		{}

		Matrix<T> operator*(Matrix<T> const &b) // multiplication
		{
		}

		Matrix<T> operator+(Matrix<T> const &b) // addition
		{
		}

};

template<typename T>
std::istream &operator>>(std::istream& os, Matrix<T> &a) // read matrix
{

        return os;
}

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
