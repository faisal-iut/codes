#include<iostream>
using namespace std;
#define h 100
#define w 100


char image[h][w];
int n,m;
int counts;
int flags[26];
int is_emptys[h][w];

void print_output()
{

    cout<<counts;

}

int flag_search(char ch)
{
    flags[ch-97]=1;
}

int search_i(char ch, int row, int col)
{
    static int r_x[] = {0,0,1,1};
    static int c_y[] = {0,1,0,1};
    int flag=0;

    for(int i=0;i<4;i++)
    {
        flag_search(image[row+r_x[i]][col+c_y[i]]);
    }
    if(flags[0]==1&&flags[5]==1&&flags[2]==1&&flags[4]==1)
    {

        flag = 1;
        flags[0]=0;
        flags[5]=0;
        flags[2]=0;
        flags[4]=0;
    }
    else
    {
        flag =0;
        flags[0]=0;
        flags[5]=0;
        flags[2]=0;
        flags[4]=0;
    }
    return flag;

}

void solve()
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(search_i(image[i][j],i,j)==1)
            {
                counts++;
            }
        }
    }

}

void read_input()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>image[i][j];
            is_emptys[i][j]=0;
        }
    }
    counts =0;
    for(int i=0;i<26;i++)
    {
        flags[i]=0;
    }

}

int main()
{

    read_input();
    solve();
    print_output();

}
