// koi_order.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// http://211.228.163.31/pool/koi_order/koi_order.php?pname=koi_order

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <list>

int N = 0;

struct E
{
	int h; // Ű
	int c; // �տ����� ������ ����
};

E arr[100000] = {0,};
std::list<int> order;


void Process()
{
	for (int i = 0; i < N; ++i)
	{
		int cnt = 0;
		std::list<int>::iterator it;
		for (it = order.begin(); it != order.end(); ++it)
		{
			if (cnt == arr[i].c)
			{
				break;
			}
			if (arr[i].h > *it)
			{
				++cnt;
			}
		}
		order.insert(it, arr[i].h);
	}
}

int Pred(E& l, E&r)
{
	return l.c < r.c;
}

int main()
{
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i].h;
	}

	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i].c;
	}

	std::sort(arr, arr + N, Pred);

	Process();
}
