#include <iostream>
#include <malloc.h>
#define N 500
using namespace std;
int m[N][N], s[N][N];
int p[N];

void matrices_multiply(int size_array)
{
	int length = 0, i, j, k, min;
	for (i = 1; i < size_array + 1; i++) m[i][i] = 0;
	for (length = 2; length < size_array + 1; length++)
	{
		for (i = 1; i <= size_array - length + 1; i++)
		{
			j = length + i - 1;//length=j-i+1
			m[i][j] = m[i][i] + m[i + 1][j] + p[i-1] * p[i] * p[j];
			s[i][j] = i;
			for (k = i + 1; k < j; k++)
			{
				min = m[i][k] + m[k + 1][j] + p[i-1] * p[k] * p[j];
				if (min < m[i][j])
				{
					m[i][j] = min;
					s[i][j] = k;
				}
			}
		}
	}
	cout << "最少需要做" << m[1][size_array] << "次乘法。" << endl;
}

void print_best_solution(int i,int j)
{
	if (i == j)
	{
		cout << "A" << i;
	}
	else
	{
		cout << "(";
		print_best_solution(i, s[i][j]);
		print_best_solution(s[i][j] + 1, j);
		cout << ")";
	}
	
}
int main()
{
	int size_array;
	cout << "输入矩阵的数量:" << endl;
	cin >> size_array;
	cout << "输入这" << size_array << "个矩阵的行列数:" << endl;
	for (int i = 0; i < size_array + 1; i++)
	{
		cin >> p[i];
	}
	matrices_multiply(size_array);
	print_best_solution(1,size_array);
	cout << endl;
	return 0;
}