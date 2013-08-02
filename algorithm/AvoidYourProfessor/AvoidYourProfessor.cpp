// AvoidYourProfessor.cpp : Defines the entry point for the console application.
// http://www.algospot.com/judge/problem/read/AVOID
// ���ͽ�Ʈ�� ���� : http://www.unf.edu/~wkloster/foundations/DijkstraApplet/DijkstraApplet.htm

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <queue>


void dijkstra(int (*a)[101], int n, int (*visit)[101])
{
	// a �� �Ÿ����� ��� ������ �迭
	int w = 0;
	int start = 1;
	int di[101] = {0,}; // di �� �ش� �������� �ּҰ��� ������Ʈ�� ���� 1���� �ӽ� �迭
	for (int i = 1; i <= n; ++i)
	{
		di[i] = 10000; // ���� �ƹ��͵� �������� �ʾ����Ƿ� �ִ밪���� ����
	}
	int chk[101] = {0,}; // �ּ� �Ÿ��� Ȯ���� ���

	di[start] = 0;// �������� �Ÿ� 0���� �����Ѵ�. �׷��� break�� �Ⱥ��������Ŵ�.
	for(int i = 1; i <= n; i++)
	{
		int min = 10000;
		for(int j = 1; j <= n; j++)
		{
			if(min > di[j] && chk[j] == 0)
			{
				min=di[j];				// ������� ���� ������ �ּҰ��� ���Ѵ�.
				w=j; 
			}
		}

		if(min == 10000) break;
		chk[w]=1;	// ������� ���� �Ÿ��� ���� ª�� ���̹Ƿ� Ȯ���Ѵ�.

		for(int j = 1; j <= n; j++)
		{
			if(a[w][j] != 0) // �ٸ� ������ w �� �̸��� ���� �ִٸ�
			{
				int t = a[w][j] + di[w];
				if (di[j] > t) // �� ���� �׵��� w���� �� �Ÿ�(di[w])�� �� ���ο� ��(a[w][j])�� ���Ѱź��� ũ�ٸ�(��, ������ ���� �ּҰŸ����)
				{
					di[j] = a[w][j] + di[w]; // �װ��� �̸��� �ּҰŸ��� ������Ʈ�Ѵ�.
					
					std::fill(visit[j], visit[j] + n + 1, 0);// ���� �湮��� ����
					visit[j][w]++;			// j�� w���� �湮�ؿ�
				}
				else if (di[j] == t)
				{
					visit[j][w]++;			// j�� w���� �湮�ؿ�(���⼱ �ʱ�ȭ �������Ƿ� ������ΰ� �ߺ��� ��)
				}				
			}
		}
	}
}

 int Gcd(int u, int v)
 {
	 int shift;
	 if (u == 0 || v == 0)
	   return u | v;
 
	 for (shift = 0; ((u | v) & 1) == 0; ++shift) {
		 u >>= 1;
		 v >>= 1;
	 }
 
	 while ((u & 1) == 0)
	   u >>= 1;
 
	 do {
		 while ((v & 1) == 0) 
		   v >>= 1;
 
	  if (u > v) {
		 int t = v; v = u; u = t;}  
	  v = v - u;                
	 } while (v != 0);
 
	 return u << shift;
 }

int CalcCnt(int (*graph)[101], int* cnt, int s, int n)
{
	if (s == n)
	{
		++cnt[s];
		return 1;
	}

	int child = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (graph[i][s])
		{
			child += CalcCnt(graph, cnt, i, n);
		}
	}
	cnt[s] += child;
	return child;
}

int main()
{
	// ���ͽ�Ʈ�� �����ϸ鼭 �� ����� ������ Ȯ��������
	// �� ���� ������ Ȥ�� ������ ������(�̶��� �������� ���� ��� ����) ��� ���� ���� �湮�ߴ��� ����� �����.
	// ���ͽ�Ʈ�� ������ ���� ���Ŀ� �� ����� ������� Ȯ�� ���
	int testN = 0;
	std::cin >> testN;
	for (int i = 0; i < testN; ++i)
	{
		int graph[101][101] = {0,};
		int n = 0;
		int v = 0;
		int e = 0;
		std::cin >> v >> e >> n;

		// ���� ������ �޴´�.
		int a = 0;
		int b = 0;
		int t = 0;
		for (int j = 0; j < e; ++j)
		{
			std::cin >> a >> b >> t;
			graph[a][b] = t;
		}
		
		// ���ͽ�Ʈ��� �湮 ������ ��θ� ���Ѵ�.
		int visit[101][101] = {0,};
		dijkstra(graph, v, visit);

		// �湮 ��θ� �������Ͽ� �� ���������� Ȯ���� ���Ѵ�.
		int cnt[101] = {0,};
		int mod = CalcCnt(visit, cnt, 1, v);

		// Ȯ���� ����Ѵ�.
		for (int j = 0; j < n; ++j)
		{
			int n_1 = 0;
			std::cin >> n_1;
			int num = cnt[n_1];
			int gcd = Gcd(num, mod);

			if (gcd == 0)
			{
				std::cout << "0/1" << std::endl;
			}
			else
			{
				std::cout << num / gcd << "/" << mod / gcd << std::endl;
			}
		}
	}

	return 0;
}



/*
#include <cstdio> 
#include <climits> 
#include <vector> 

using namespace std; 

const int MAX = 100; 

struct edge 
{ 
	int to; 
	int weight; 
	
	edge(int to, int weight) 
		: to(to), weight(weight) { } 
}; 

vector<edge> es[MAX+1]; 
int dist[MAX+1]; 
vector<int> parent[MAX+1]; 
bool check[MAX+1]; 
long long cnt[MAX+1];
long long ncnt[MAX+1];
int v; 

long long gcd(long long a, long long b) 
{ 
	while (a%b!=0) 
	{ 
		long long t = a%b; 
		a = b; 
		b = t; 
	} 
	
	return b; 
}

void calc() 
{ 
	for (int i=1; i<=v; ++i) 
	{ 
		check[i] = false; 
		ncnt[i] = 0;
	} 
	
	ncnt[v] = cnt[v];

	for (int i=0; i<v; ++i) 
	{ 
		int m = -1; 
		int mi = -1; 
		
		for (int j=1; j<=v; ++j) 
		{ 
			if ( ! check[j] && dist[j] > m) 
			{ 
				m = dist[j]; 
				mi = j; 
			} 
		} 
		
		check[mi] = true; 
		if (parent[mi].size() > 0)
		{
			for (vector<int>::iterator j=parent[mi].begin(); j!=parent[mi].end(); ++j)
				ncnt[*j] += ncnt[mi] / cnt[mi] * cnt[*j];
		}
	} 
}

void dijkstra() 
{ 
	for (int i=1; i<=v; ++i) 
	{ 
		check[i] = false; 
		dist[i] = INT_MAX; 
		parent[i].clear();
		cnt[i] = 0;
	} 
	
	dist[1] = 0; 
	cnt[1] = 1;
	for (int i=0; i<v; ++i) 
	{ 
		int m = INT_MAX; 
		int mi = -1; 
		
		for (int j=1; j<=v; ++j) 
		{ 
			if ( ! check[j] && dist[j] < m) 
			{ 
				m = dist[j]; 
				mi = j; 
			} 
		} 
		
		check[mi] = true; 
		for (vector<edge>::iterator j=es[mi].begin(); j!=es[mi].end(); ++j) 
		{ 
			if ( ! check[j->to]) 
			{ 
				int nv = dist[mi] + j->weight; 
				if (nv < dist[j->to]) 
				{ 
					dist[j->to] = nv; 
					parent[j->to].clear(); 
					parent[j->to].push_back(mi);
					cnt[j->to] = cnt[mi];
				} 
				else if (nv == dist[j->to])
				{
					parent[j->to].push_back(mi);
					cnt[j->to] += cnt[mi];
				}
			} 
		}
	} 
} 

int main() 
{
	int c; 
	scanf("%d", &c); 
	while (c--) 
	{ 
		int e, n; 
		scanf("%d %d %d", &v, &e, &n); 
		for (int i=1; i<=v; ++i) 
			es[i].clear(); 
		
		for (int i=0; i<e; ++i) 
		{ 
			int a, b, t; 
			scanf("%d %d %d", &a, &b, &t); 
			es[a].push_back(edge(b, t)); 
			es[b].push_back(edge(a, t)); 
		} 
		
		dijkstra(); 
		calc(); 
		
		for (int i=0; i<n; ++i) 
		{ 
			int t; 
			scanf("%d", &t); 
			if (t==1 || t==v) 
				printf("1/1\n"); 
			else if (ncnt[t] == 0)
				printf("0/1\n");
			else 
			{
				long long g = gcd(ncnt[v], ncnt[t]);
				printf("%lld/", ncnt[t]/g); 
				printf("%lld\n", ncnt[v]/g);
			}
		} 
	} 
	
	return 0; 
} 
*/

