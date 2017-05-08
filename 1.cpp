#include<bits/stdc++.h>

using namespace std;

int fib(int t1,int t2,int n);

int main()
{
   int t1,t2,n,tn;
   cin>>t1>>t2>>n;
   tn = fib(t1,t2,n-1);

   printf("%d",tn);
}


int fib(int t1,int t2,int n)
{

    if (n==t1) return t1;
    if (n==t2) return t2;
    return pow(fib(t1,t2,n-1),2)+fib(t1,t2,n-2);
}
