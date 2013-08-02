// koi_routing.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// http://211.228.163.31/pool/koi_routing/koi_routing.php?pname=koi_routing

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

int N = 0;
int table[1001][1001] = {0,};
int dp[3][1002][1002] = {0,};// 3�� ��, ����, ������ �� �ش��ϴ� ������ ���̺��� ����� ����
const int MAXINT = 1000000;

int Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			dp[0][i][j] = std::max(dp[2][i-1][j], std::max(dp[0][i-1][j], dp[1][i-1][j])) + table[i][j]; // ���� ���� ������ ��� ó��
			dp[1][i][j] = std::max(dp[0][i][j-1], dp[1][i][j-1]) + table[i][j]; // ���ʿ��� �°�� ó��(�̰�� "������", "���ʿ���"���� �°�츸 ���
		}

		if (i > 1)
		{
			for (int j = N; j > 0; --j)
			{
				dp[2][i][j] = std::max(dp[0][i][j+1], dp[2][i][j+1]) + table[i][j]; // �����ʿ��� �°�� ó��(�̰�� "��������", "�����ʿ�����"���� �°�츸 ���
			}
		}
	}

	return std::max(dp[2][N][N], std::max(dp[0][N][N], dp[1][N][N]));
}
/*
int Solve()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + table[i][j];
		}
		if (i >= 2)
		{
			int dp2[1002] = {0,};
			for (int j = N; j > 0; --j)
			{
				dp2[j] = std::max(dp[i-1][j], dp2[j+1]) + table[i][j];
				dp[i][j] = std::max(dp[i][j], dp2[j]);
			}
		}
	}

	return dp[N][N];
}
*/

int main()
{	
	std::cin >> N;
	std::cin.ignore(256,'\n');
	for (int i = 1; i <= N; ++i)
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream in(line);

		for (int j = 1; j <= N; ++j)
		{
			in >> table[i][j];
		}
	}

	std::cout << Solve() << std::endl;

	return 0;
}
