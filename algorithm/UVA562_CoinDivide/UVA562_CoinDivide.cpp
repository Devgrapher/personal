// UVA562_CoinDivide.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


const int MAX_SUM = 50001;

int _tmain(int argc, _TCHAR* argv[])
{
	int testCase = 0;
	std::cin >> testCase;
	for (int t = 0; t < testCase; ++t)
	{
		if (std::cin.fail() && std::cin.eof())
		{
			break;
		}

		bool dyn[MAX_SUM] = {1,0};
		int coins[100] = {0,};

		int coinCnt = 0;
		int sum = 0;
		std::cin >> coinCnt;
		for (int i = 0; i < coinCnt; ++i)
		{
			std::cin >> coins[i];
			sum += coins[i];
		}

		// �־��� �������� ���հ����� �տ� true�� �����Ѵ�.
		for (int i = 0; i < _countof(coins); ++i)
		{
			for (int j = coins[i]; j >= 0; --j)
			{
				if (dyn[j])
				{
					dyn[j + coins[i]] = true;
				}
			}
		}

		// ������ �ּҰ��� ���Ѵ�.
		int min = MAX_SUM;
		for (int i = 1; i < sum; ++i)
		{
			if (dyn[i])
			{
				int t =  abs(sum - (2* i));
				min = std::min(t, min);
			}
		}
		
		std::cout << min << std::endl;
	}


	return 0;
}

