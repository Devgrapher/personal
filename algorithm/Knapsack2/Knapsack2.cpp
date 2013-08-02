// Knapsack2.cpp : Defines the entry point for the console application.
//

/*
	������ ���� ���� �賶����
	���Կ� ������ ���� w, v�� n���� ������ �ֽ��ϴ�. �� ���ǵ�κ��� ������ ������ W�� �ʰ����� �ʵ���
	�������� ���� ���� ������ �ִ�ġ�� ���ϼ���. �� ���� ������ ������ �� ���� ���� ���� �����մϴ�.

	�Է�
	n = 3
	W = 7
	(w,v) = {(3,4),(4,5),(2,3)}
	���
	10(0�� 1��, 2�� 2���� ����)
*/


#include "stdafx.h"
#include <iostream>

int dyn[101][10001] = {0,};// ���� ���� ���� | ������� ������ �������� ����
int input[101][2] = {0,};

int _tmain(int argc, _TCHAR* argv[])
{
	int N, W = 0;
	std::wcin >> N >> W;
	for (int i = 1; i <= N; ++i)
	{
		std::wcin >> input[i][0] >> input[i][1];
	}
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			for (int k = 1; k <= N; ++k)
			{
				int m = std::max(dyn[i-1][j-1] + input[k][1], input[k][1]);
				if (j > m)
				{
					dyn[i][j] = m;
				}
				else
				{
					dyn[i][j] = dyn[i-1][j-1];
				}
			}
		}
	}

	std::cout << dyn[N][W] << std::endl;

	return 0;
}

