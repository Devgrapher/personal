// bridging.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
// http://211.228.163.31/30stair/bridging/bridging.php?pname=bridging

#include "stdafx.h"
#include <iostream>
#include <algorithm>

int P = 0; // ���� ��
int M = 1;
struct Node
{
	int v; // ��
	int idx; // �ε���
};

Node in[140001] = {0,};
int DP[140001] = {0,};
int BIT[180001] = {0,}; // Binary Indexed Tree;

int operator<(const Node& l, const Node& r)
{
	return l.v < r.v;
}

int IndexTree(int l, int r, int lev, int tx, int ty)
{
	if(l==tx && r==ty){return BIT[lev];} // If range correct, return value

	int m=(l+r)/2;

	if(ty<=m)
	{
		return IndexTree(l,m,lev*2,tx,ty); // Only Left
	}
	else if(tx>=m+1)
	{
		return IndexTree(m+1,r,lev*2+1,tx,ty); // Only Right
	}
	else
	{ // Include Both Left and Right
		int r1,r2;
		r1=IndexTree(l,m,lev*2,tx,m); // Cutting Left
		r2=IndexTree(m+1,r,lev*2+1,m+1,ty); // Cutting Right
		if(r1<r2){return r2;}
		return r1;
	}
}

void Refresh(int idx, int v)
{
	int i = M+idx - 1;
	BIT[i] = v;
	while (i != 1)
	{
		i = i / 2;
		BIT[i] = std::max(BIT[i*2], BIT[i*2+1]);
	}
}

int main()
{
	std::cin >> P;
	for (int i = 1; i <= P; ++i)
	{
		std::cin >> in[i].v;
		in[i].idx = i;
	}

	while (M < P)
	{
		M = M * 2;	
	}

	std::sort(in + 1, in + P + 1);

	int max = 0;
	for (int i = 1; i <= P; ++i)
	{
		int val = IndexTree(1, M, 1, 1, in[i].idx);
		DP[in[i].idx] = val + 1;
		max = std::max(max, DP[in[i].idx]);
		Refresh(in[i].idx, val + 1); // Ʈ���� ���� �ش� �������� �ִ� ���Ӽ��ڰ����� �ǹ��Ѵ�.
	}

	std::cout << max;
}
