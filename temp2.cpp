#include<iostream>
using namespace std;
#define h 100
#define w 50


char image[w][h];
int n,m;
int counts;
int flags[26];

void print_output()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<image[i][j]<<" ";
            if(image[i][j]=='f')
            {
                cout<<"ddddddddddd";
            }
        }
        cout<<endl;
    }

}

int search_i(char ch, int row, int col)
{
    static int r_x[] = {0,1,1};
    static int c_y[] = {1,0,1};


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {

        }
    }
    return flag;

}

void solve()
{
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
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
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>image[i][j];
        }
    }
    counts =0;

}

int main()
{

    read_input();
    //solve();
    print_output();

}

