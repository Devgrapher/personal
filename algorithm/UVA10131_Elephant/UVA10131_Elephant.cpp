// UVA10131_Elephant.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Eelephant
{
	int idx;
	int weight;
	int iq;
};

bool CompareEle(Eelephant& el1, Eelephant& el2)
{
	return el1.weight < el2.weight;
};


int _tmain(int argc, _TCHAR* argv[])
{

	while (std::cin.eof() == false && std::cin.fail() == false)
	{
		std::vector<Eelephant> elephants;

		for (int i = 0; i < 1000; ++i)
		{
			std::string line;
			std::getline(std::cin, line);
			std::istringstream in(line);

			if (line.empty())
			{
				break;
			}

			Eelephant el;
			el.idx = i;
			in >> el.weight;
			in >> el.iq;
			elephants.push_back(el);
		}
		
		// ���Ը� �������� ����
		std::sort(elephants.begin(), elephants.end(), CompareEle);

		int dy[1000][2] = {0,};
		enum DY_VAL
		{
			CNT, // ���ӵǴ� ������ ��
			POS, // �ڽ��� �� ������ ��ȣ
		};

		for (int i = 0; i < elephants.size(); ++i)
		{
			dy[i][CNT] = 1;
			dy[i][POS] = -1; // �⺻��
			int max = 0;
			for (int j = i - 1; j >= 0; --j)
			{
				if (elephants[j].iq > elephants[i].iq && // �ڱ⺸�� ũ��
					elephants[j].weight < elephants[i].weight) // ���԰� ������(������� ���͸�)
				{
					if (max < dy[j][CNT])
					{
						max = dy[j][CNT];
						dy[i][CNT] = max + 1;
						dy[i][POS] = j;
					}
				}
			}
		}

		// ������̺��� �ִ� ī��Ʈ�� ���� ������ ã�´�.
		int max = 0;
		int maxIdx = 0;
		for (int i = 0; i < elephants.size(); ++i)
		{
			if (dy[i][CNT] > max)
			{
				max = dy[i][CNT];
				maxIdx = i;
			}
		}

		// �ִ� ���� ���
		std::cout << max << std::endl;

		int idx = maxIdx;
		std::vector<int> result;
		while (idx != -1)
		{
			result.push_back(elephants[idx].idx + 1); // �ε����� 0���� ���������Ƿ� 1 ������
			idx = dy[idx][POS];
		}

		// �� ������ ���
		for (int i = result.size() - 1; i >= 0; --i) // �������� ����Ѵ�.
		{
			std::cout << result[i] << std::endl;
		}

	}

	return 0;
}

