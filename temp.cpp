#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

struct node
{
    char data;
    struct node* next;
};


int main()
{
    freopen("input.txt","r",stdin);
    struct node *current, *prev, *head;
    int length = 0;
    char c, *input, *f;
    input = (char *) malloc(sizeof(char));
    while((c=getchar())!=EOF)
    {
        realloc(input,sizeof(char));
        input[length]=c;
        length++;
    }
    length = length -1;
    free(input+length);
    printf("%s",input);

}

