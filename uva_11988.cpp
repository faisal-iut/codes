#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define MAX 100000
char input[MAX];
typedef struct node node_t;
struct node
{
    char data;
    struct node* next;
};

node_t *createNode(char item)
{
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = item;
    new_node->next = NULL;
    return new_node;
}


void printList(node_t *root_ref)
{
    while(root_ref!=NULL)
    {
        printf("%c",root_ref->data);
        root_ref = root_ref->next;
    }
}

void solve()
{
    node_t *head = NULL, *current = NULL, *tail =NULL, *prev = NULL, *head_prev = NULL;
    int h_flag=0, brak=0, t_flag = 0, i=0;
        for(i=0; input[i]; i++)
        {
            if(input[i]=='[')
            {
                brak = -1;
                h_flag = 1;
            }
            else if(input[i]==']')
            {
                brak = 1;
                t_flag = 1;
            }
            else
            {
                current = createNode(input[i]);
                if(head==NULL)
                    {
                        head = current;
                        prev = head;
                        tail = prev;
                        h_flag = 0;
                        brak = 0;
                    }
                else if(brak ==0)
                {
                    prev->next = current;
                    prev = current;
                    tail = prev;
                }
                else if(brak==-1)
                {
                    if(h_flag==1)
                    {
                        head_prev = head;
                        head = current;
                        prev = head;
                        prev->next = head_prev;
                        h_flag = 0;
                    }
                    else
                    {
                        prev->next = current;
                        current->next = head_prev;
                        prev = current;
                    }
                }
                else if(brak==1)
                {
                    tail->next =current;
                    tail = current;
                    prev = current;
                    brak = 0;

                }

            }
        }
        //prev->next = createNode(input[i]);


    printList(head);
    cout<<endl;
}


int main()
{
    int n;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        while(gets(input))
        {
            solve();
        }

    }
}
