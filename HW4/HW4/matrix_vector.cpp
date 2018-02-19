#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
#include<cctype>
#include<limits>


struct Vec3
{
	double vect[3];
};

struct Mat3
{
	double mat[3][3];
};

Vec3 read_vec()
{
	Vec3 v1;
	for (int i = 0; i < 3; i++)
		std::cin >> v1.vect[i];
	return v1;
}

Mat3 read_mat()
{
	Mat3 m1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cin >> m1.mat[i][j];
	}
	return m1;
}

void print(Vec3 v)
{
	std::cout << "( ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << v.vect[i];
		if (i < 2)
			std::cout << ", ";
	}
		
	std::cout << " )";
}

void print(Mat3 m)
{
	std::cout << "[ ";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << m.mat[i][j];
			if (i != 2 || j != 2)
				std::cout << ", ";
		}
			
	}
	std::cout << " ]";
}

Vec3 add(Vec3 u, Vec3 v)
{
	Vec3 res;
	for (int i = 0; i < 3; i++)
	{
		res.vect[i] = u.vect[i] + v.vect[i];
	}
	return res;
}

double dot(Vec3 u, Vec3 v)
{
	double res = 0;
	for (int i = 0; i < 3; i++)
		res = res + u.vect[i] * v.vect[i];
	return res;
}

double length(Vec3 u)
{
	double res = 0, temp = 0;
	for (int i = 0; i < 3; i++)
		temp = temp + std::pow(u.vect[i], 2);
	res = std::sqrt(temp);
	return res;
}

Mat3 transpose(Mat3 m)
{
	Mat3 res;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			res.mat[j][i] = m.mat[i][j];
	}
	return res;
}

Vec3 row(Mat3 m, int i)
{
	Vec3 res; 
	for (int j = 0; j < 3; j++)
		res.vect[j] = m.mat[i][j];
	return res;
}

Vec3 col(Mat3 m, int i)
{
	Vec3 res;
	for (int j = 0; j < 3; j++)
		res.vect[j] = m.mat[j][i];
	return res;
}

Vec3 multiply(Mat3 m, Vec3 u)
{
	Vec3 res = { 0,0,0 };
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
			{
				res.vect[j] += m.mat[j][k] * u.vect[k];
			}
		return res;
}

Mat3 multiply(Mat3 m1, Mat3 m2)
{
	Mat3 res = { 0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
			{
				res.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
			}
	return res;
}

int main()
{
	int n;
	std::string oper;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Case " << i << ":\n";
		std::cin >> oper;
		if (oper == "add")
		{
			Vec3 var1, var2, result;
			std::string type;
			std::cin >> type; 
			var1 = read_vec();
			std::cin >> type;
			var2 = read_vec();
			result = add(var1, var2);
			print(result);
			std::cout << "\n";
		}

		if (oper == "dot")
		{
			Vec3 var1, var2;
			std::string type;
			std::cin >> type;
			var1 = read_vec();
			std::cin >> type;
			var2 = read_vec();
			std::cout<<dot(var1, var2)<<"\n";
		}

		if (oper == "length")
		{
			Vec3 var1;
			std::string type;
			std::cin >> type;
			var1 = read_vec();
			std::cout << length(var1) << "\n";
		}

		if (oper == "transpose")
		{
			Mat3 var1, result;
			std::string type;
			std::cin >> type;
			var1 = read_mat();
			result = transpose(var1);
			print(result);
			std::cout << "\n";
		}

		if (oper == "row")
		{
			Mat3 var1;
			Vec3 result;
			std::string type;
			int row_n;
			std::cin >> type;
			var1 = read_mat();
			std::cin >> row_n;
			result = row(var1, row_n);
			print(result);
			std::cout << "\n";
		}
		
		if (oper == "col")
		{
			Mat3 var1;
			Vec3 result;
			std::string type;
			int col_n;
			std::cin >> type;
			var1 = read_mat();
			std::cin >> col_n;
			result = col(var1, col_n);
			print(result);
			std::cout << "\n";
		}

		if (oper == "multiply")
		{
			Mat3 var1;
			std::string type;
			std::cin >> type;
			var1 = read_mat();
			std::cin >> type;
			if (type == "V")
			{
				Vec3 var2,result;
				var2 = read_vec();
				result = multiply(var1, var2);
				print(result);
				std::cout << "\n";
			}
			if (type == "M")
			{
				Mat3 var2, result;
				var2 = read_mat();
				result = multiply(var1, var2);
				print(result);
				std::cout << "\n";
			}

		}



	}
	return 0;
}