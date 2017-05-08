#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;
#define SIZE 1000000

int X[SIZE], Y[SIZE];
int Len[SIZE];
int visited[SIZE];
int *List[SIZE];
int counts[SIZE];
int in_degree[SIZE];
int Q[SIZE];
int ans[SIZE];
int M,N,fronts,rear, index;
int temp;

void printoutput()
{
    if(index==N)
    {
        for(int i=0;i<N;i++)
        {
            printf("%d",ans[i]);
            if(i!=N-1)
                printf("\n");
        }
    }
    else
    {
        printf("IMPOSSIBLE");
    }

}

void readStick()
{
    for(int i=1; i<=N;i++)
    {
        List[i] = (int *)malloc(sizeof(int)*Len[i]);
        counts[i] = 0;
    }
    for(int i=1; i<=M; i++)
    {
        List[X[i]][counts[X[i]]++] = Y[i];
        in_degree[Y[i]]++;
    }


}

void init_queue()
{
    fronts = rear = 0;
}

void push(int i)
{
    Q[rear++] = i;
}

int pop()
{
    fronts++;
    return Q[fronts-1];
}

int is_emptys()
{
    if(fronts==rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    index = 0;
    for(int i =1;i<=N;i++)
    {
        if(in_degree[i]==0)
        {
            push(i);
        }
    }
    while(!is_emptys())
    {
        temp = pop();
        ans[index++] = temp;
        for(int i=0; i<Len[temp];i++)
        {
            if(--in_degree[List[temp][i]]==0)
            {
                push(List[temp][i]);
            }
        }
    }


}

void readcase()
{
    for(int i=1;i<=M;i++)
    {
        scanf("%d%d",&X[i],&Y[i]);
        Len[X[i]]++;
    }

}

void initpath()
{
    for(int i = 1;i<=N;i++)
    {
        Len[i] = 0;
        visited[i] = 0;
        in_degree[i] = 0;
        Q[i] = 0;
        ans[i] = 0;
    }

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(2==scanf("%d%d",&N,&M))
    {
        if(N==0 && M==0)
        {
            break;
        }
        initpath();
        readcase();
        readStick();
        solve();
        printoutput();
        printf("\n");

    }

}

