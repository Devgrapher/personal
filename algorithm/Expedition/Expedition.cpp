// Expedition.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// ���å 102p, �켱����ť, POJ 2431

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <queue>

int N = 0; // ���ָ����ĵ� ����
int L = 0; // �� �̵��ҰŸ�
int P = 0; // ��߽� ���� ����
int Pos[10000] = {0,}; // ���ָ����ĵ� ��ġ(������ġ������ �Ÿ�)
int Qtt[10000] = {0,}; // ��ġ���� ���������� ��.


int Process()
{
	std::priority_queue<int> que;

	int fuel = P;
	int suppCount = 0; // ���� ���� Ƚ��
	for (int i = 0; i < N; ++i)
	{
		que.push(Qtt[i]);
		fuel -= Pos[i];// �̵��ߴٴ� ����.
		while (fuel < 0 && !que.empty()) 
		{
			fuel += que.top(); // ��������
			que.pop();
			suppCount++;
		}
		if (fuel < 0)
		{
			return -1;
		}
	}

	return suppCount;
}

int main()
{
	std::cin >> N >> L >> P;
	int lastP = 0;
	for (int i = 0; i < N; ++i)
	{
		int p = 0;
		std::cin >> p >> Qtt[i];
		Pos[i] =  p - lastP; // ������ġ������ �Ÿ��� �Է�
		lastP = p;
	}

	std::cout << Process();
}
