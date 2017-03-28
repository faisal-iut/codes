#define _CRT_SECURE_NO_WARNINGS
////author faisal
#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX_N 17
#define MAX_M 9

int T;
int Case;
int N, M;
int Good1[MAX_M], Good2[MAX_M], Good3[MAX_M], Price[MAX_M];
int Ans;
int Used[MAX_N];
int sum;

void init_used()
{
	int i;
	for (i = 0; i < N; i++)
	{
		Used[i] = 0;
	}
}

void read_case()
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &Good1[i], &Good2[i], &Good3[i], &Price[i]);
	}
}

void max_sum(int s)
{
	if (s > Ans)
	{
		Ans = s;
	}
}

void solve(int i)
{
	if (i == M)
	{
		if (sum > Ans)
		{
			Ans = sum;
		}
		return;
	}
	solve(i + 1);
	if (0 == Used[Good1[i]] && 0 == Used[Good2[i]])
	{
		Used[Good1[i]] = 1;
		Used[Good2[i]] = 1;
		sum = sum + 2*Price[i];
		solve(i + 1);
		sum = sum - 2*Price[i];
		Used[Good1[i]] = 0;
		Used[Good2[i]] = 0;

	}
	if (0 == Used[Good1[i]] && 0 == Used[Good3[i]])
	{
		Used[Good1[i]] = 1;
		Used[Good3[i]] = 1;
		sum = sum + 2*Price[i];
		solve(i + 1);
		sum = sum - 2 * Price[i];
		Used[Good1[i]] = 0;
		Used[Good3[i]] = 0;
	}
	if (0 == Used[Good2[i]] && 0 == Used[Good3[i]])
	{
		Used[Good2[i]] = 1;
		Used[Good3[i]] = 1;
		sum = sum + 2 * Price[i];
		solve(i + 1);
		sum = sum - 2 * Price[i];
		Used[Good2[i]] = 0;
		Used[Good3[i]] = 0;
	}
	if (0 == Used[Good2[i]] && 0 == Used[Good3[i]] && 0 == Used[Good1[i]])
	{
		Used[Good1[i]] = 1;
		Used[Good2[i]] = 1;
		Used[Good3[i]] = 1;
		sum = sum + 3 * Price[i];
		solve(i + 1);
		sum = sum - 3 * Price[i];
		Used[Good1[i]] = 0;
		Used[Good2[i]] = 0;
		Used[Good3[i]] = 0;
	}

}

void solve_case()
{
	Ans = 0;
	sum = 0;
	init_used();
	solve(0);
}

void print_case()
{
	printf("#%d %d\n", Case, Ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++)
	{
		read_case();
		solve_case();
		print_case();
	}

	return 0;
}
