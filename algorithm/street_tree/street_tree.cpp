// street_tree.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// http://211.228.163.31/pool/street_tree/street_tree.php?pname=street_tree

#include "stdafx.h"
#include <iostream>

int N = 0;
int arr[100000] = {0,};
int diff[100000] = {0,};


int GCD(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}

	return a;
}

int main()
{
	std::cin >> N;
	std::cin >> arr[0];
	int gcd = 0;
	for (int i = 1; i < N; ++i)
	{
		std::cin >> arr[i];
		diff[i] = arr[i] - arr[i-1];
		if (i > 1)
		{
			gcd = GCD(diff[i], gcd);
		}
		else
		{
			gcd = diff[1];
		}
	}

	int sum = 0;
	for (int i = 1; i < N; ++i)
	{
		sum += (diff[i] / gcd) - 1;
	}

	std::cout << sum;

	return 0;
}

// ����ȭ ���� �ڵ�.
/*
int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}

	for (int i = 1; i < N; ++i)
	{
		diff[i] = arr[i] - arr[i-1];
	}

	int gcd = diff[1];
	for (int i = 2; i < N; ++i)
	{
		gcd = GCD(diff[i], gcd);
	}

	int sum = 0;
	for (int i = 1; i < N; ++i)
	{
		sum += (diff[i] / gcd) - 1;
	}

	std::cout << sum;

	return 0;
}

*/