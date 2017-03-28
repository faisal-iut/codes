#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
using namespace std;

int coun;
int N;
int A[100];
int Binary[100];
int used[100];
int palin[200];
int comb[100];

int validation(int i, int j, int k, int n)
{
	int fs, sn, tr, fr, sel,d,numb, valid = 1;
	fs = i - 0 + 1;
	sn = j - i;
	tr = k - j;
	fr = n - k - 1;
	if (fs > 2)
	{
		numb = palin[0];
		for (d = 1; d < i + 1; d++)
		{
			numb = numb * 10 + palin[d];
		}
		if (numb > 255 || palin[0]==0)
			valid = 0;
	}
	else if (fs > 1)
	{
		if (palin[0] == 0)
			valid = 0;
	}
	if (sn > 2)
	{
		numb = palin[i+1];
		for (d = i+2; d < j + 1; d++)
		{
			numb = numb * 10 + palin[d];
		}
		if (numb > 255 || palin[i+1] == 0)
			valid = 0;
	}
	else if (sn > 1)
	{
		if (palin[i+1] == 0)
			valid = 0;
	}
	if (tr > 2)
	{
		numb = palin[j + 1];
		for (d = j + 2; d < k + 1; d++)
		{
			numb = numb * 10 + palin[d];
		}
		if (numb > 255 || palin[j+1] == 0)
			valid = 0;
	}
	else if (tr > 1)
	{
		if (palin[j+1] == 0)
			valid = 0;
	}
	if (fr > 2)
	{
		numb = palin[k + 1];
		for (d = k + 2; d < n; d++)
		{
			numb = numb * 10 + palin[d];
		}
		if (numb > 255 || palin[k+1] == 0)
			valid = 0;
	}
	else if (fr > 1)
	{
		if (palin[k+1] == 0)
			valid = 0;
	}
	return valid;

}

void printpalin(int n, int i, int j, int k)
{
	int l;


	coun = coun + 1;


}

void print_ip(int r,int n)
{
	int i, j, k,val,coun = 0;

	for (i = 0; i < n-2; i++)
	{
		for (j = i + 1; j < n-1; j++)
		{
			for (k = j + 1; k < n-1; k++)
			{
				val = validation(i, j, k, n);
				if (val == 1)
				{
					printpalin(n, i, j, k);

				}

			}
		}
	}

}



void makepalin()
{
	int i;
	for (i = 0; i<N; i++)
	{
		palin[i] = Binary[i];
	}
	for (i = 0; i<N; i++)
	{
		palin[N + i] = Binary[N - i - 1];
	}
	print_ip(3,2 * N);
	for (i = 0; i<N; i++)
	{
		palin[N + i-1] = Binary[N - i - 1];
	}
	print_ip(3,2 * N-1);
}

void readArray()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}

}

void printArray()
{
	int i;
	for (i = 0; i < N; i++)
	{
		cout << A[i];
	}
	cout << endl;


}

void printBinary()
{
	int i;
	for (i = 0; i < N; i++)
	{
		cout << Binary[i];

	}
	cout << endl;
}
void solve(int i)
{
	int j;
	if (i == N)
	{
		makepalin();
		return;
	}
	for (j = 0; j<N; j++)
	{
		if (used[j]==0)
		{

			Binary[i] = A[j];
			used[j] = 1;
			solve(i + 1);
			used[j] = 0;

		}

	}

}

int main()
{
	int testcase, i;
	cin >> testcase;
	//freopen("input.txt", "r", stdin);
	for (i = 0; i < testcase; i++)
	{
		readArray();
		coun = 0;
		solve(0);
		cout << coun << endl;

	}

	return 0;
}
