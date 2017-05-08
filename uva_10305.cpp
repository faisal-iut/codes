#include<iostream>
#include<cstdio>
using namespace std;
#define N 101
#define M 101
int m,n;
int node1,node2;
int graph[N][N];
int visited[N];
int counts;
int sorted[N];

void printoutput()
{
    for(int i=n-1;i>=0;i--)
    {
        if(i==0)
        {
            printf("%d",sorted[i]);
        }
        else
        {
            printf("%d ",sorted[i]);
        }

    }

}

void dfs(int n1)
{

    visited[n1] = 1;
    for(int i=0; i<n;i++)
    {
        if(visited[i]==0 && graph[n1][i] == 1)
        {
            dfs(i);
        }
    }
    sorted[counts++] = n1+1;

}

void solve()
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }


    }
}

void readcase()
{
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&node1,&node2);
        graph[node1-1][node2-1]=1;
    }

}

void initpath()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j] = 0;
            visited[i] = 0;
        }
    }
    for(int i=0;i<n;i++)
    {

        visited[i] = 0;
        sorted[i] = 0;
    }
    counts = 0;

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(2==scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
        {
            break;
        }
        initpath();
        readcase();
        solve();
        printoutput();
        printf("\n");

    }

}
