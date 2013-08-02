// Knapsack.cpp : Defines the entry point for the console application.
//

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

	for (int i = N-1; i >=0; --i)// ������ N-1������ �ϳ��� ��󰣴�(�ٿ�����)
	{
		for (int j = 0; j <= W; ++j)// �� ���԰� j�϶� ������ ������ ���ذ���. �׷��� ���� ���԰� W�϶� ������ ���´�.(�κй����� �ɰ���)
		{
			if (j < input[i][0])
			{
				dyn[i][j] = dyn[i+1][j];
			}
			else
			{
				dyn[i][j] = std::max(dyn[i+1][j] , dyn[i+1][j-input[i][0]] + input[i][1]);
			}
		}
	}

	std::wcout << dyn[0][W] << std::endl;




	return 0;
}

