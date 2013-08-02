// UVA357_CoinChange.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	int coins[5] = {1, 5, 10 ,25, 50};
	int dyn[30001] = {1,0,};

	// �� �������� ���հ����� ���� ����� ����.
	for(int i = 0; i < _countof(coins); ++i)
	{
		for(int j = 1; j <= 30000; ++j)
		{
			if (coins[i] <= j) // �����ݾ׺��� ũ�ų� ������
			{
				dyn[j] += dyn[j - coins[i]]; // ���� �հ迡�� �����ݾ��� ����ġ�� ���� ���� ���� ���ռ��� ���Ѵ�.
			}
		}
	}

	while(!std::cin.eof() && !std::cin.fail())
	{
		int sum = 0;
		std::cin >> sum;
		std::cout<< dyn[sum] << std::endl;
	}

	return 0;
}

