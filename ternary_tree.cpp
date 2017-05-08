#include<cstdio>
#include<iostream>
#include<malloc.h>
using namespace std;
#define MAX 50
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
typedef struct ternary_node node;
struct ternary_node
{
    char data;
    unsigned is_eof: 1;
    node *left, *right, *eq;
};

node *newNode(char data)
{
    node *root_node = (node*)malloc(sizeof(node));
    root_node->data = data;
    root_node->is_eof = 0;
    root_node->left = root_node->right = root_node->eq = NULL;
}

void insertIntoNode(node **root_ref, char *word)
{
    if(!*root_ref)
    {
        *root_ref = newNode(*word);
    }
    if(*word<(*root_ref)->data)
    {
        insertIntoNode(&((*root_ref)->left),word);
    }
    else if(*word>(*root_ref)->data)
    {
        insertIntoNode(&((*root_ref)->right),word);
    }
    else
    {
        if(*(word+1))
        {
            insertIntoNode(&((*root_ref)->eq),word+1);
        }
        else
        {
            (*root_ref)->is_eof = 1;
        }
    }

}

int searchTst(node *root_ref, char *word)
{
    if(!root_ref)
    {
        return 0;
    }
    if(*word<root_ref->data)
    {
        searchTst(root_ref->left,word);
    }
    else if(*word>root_ref->data)
    {
        searchTst(root_ref->right,word);
    }
    else
    {
        if(*(word+1)=='\0')
        {
            return root_ref->is_eof;
        }
        searchTst(root_ref->eq,word+1);
    }
}

void traverseUtil(node *root_ref, char* buffer, int depth)
{
    if(root_ref)
    {
            traverseUtil(root_ref->left,buffer,depth);
            buffer[depth] = root_ref->data;
            if(root_ref->is_eof)
            {
                buffer[depth+1] = '\0';
                printf("%s\n",buffer);
            }
            traverseUtil(root_ref->eq,buffer,depth+1);
            traverseUtil(root_ref->right,buffer,depth);
    }

}

void traverseTst(node *root_ref)
{
    char buffer[MAX];
    traverseUtil(root_ref,buffer,0);
}

int main()
{
    char output[][32] = {"not in tst","in tst"};
    char keys[][10] = {"the", "there", "i", "he", "her", "any", "anyways", "anywhere"};
    char keysTest[][10] = {"these", "there", "i", "here", "her", "any", "anyway", "anywhere"};
    node *root=NULL;
    for(int i=0; i<ARRAY_SIZE(keys); i++)
    {
        insertIntoNode(&root,keys[i]);
    }
    traverseTst(root);
    for(int i=0; i<ARRAY_SIZE(keysTest); i++)
    {
        printf("%s --- %s\n",keysTest[i], output[searchTst(root,keysTest[i])]);
    }

}
