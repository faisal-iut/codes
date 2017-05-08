#include<iostream>
#include<cstdio>
using namespace std;

#define h 110
#define w 110
int image[h][w];
int image_sample[h][w];
char feature[h][w];
int index[65535];
int row,col,counts;

void print_output()
{
    cout<<counts;
}

void solve(int total)
{
    int need;
    counts = 0;
    for(int i=total; i>0;i--)
    {
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<col;k++)
            {
                need = image_sample[j][k] - image[j][k];
                if((j+1)*(k+1)==i && image[j][k]!=image_sample[j][k])
                {
                    counts++;
                    for(int l=0;l<=j;l++)
                    {
                        for(int m=0;m<=k;m++)
                        {
                            image[l][m] = image[l][m] + need;

                        }
                    }

                }
            }
        }
    }
}


void read_input()
{
    cin>>row>>col;

    for(int i=0; i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>feature[i][j];
            image_sample[i][j] = (feature[i][j]=='B')? -1:1;
            image[i][j] = 0;
            index[(i+1)*(j+1)]=(i+1)*(j+1);
        }
    }

}

int main()
{
    int f =1;
    //freopen("input.txt","r",stdin);
    read_input();
    solve(row*col);
    print_output();

}
