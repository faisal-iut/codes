#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE 26
#define CHAR_INT_INDEX(c) ((int)c - (int)'a')
#define FREE(p) \
    free(p); \
    p = NULL;

typedef struct trieNode trieNodeT;
struct trieNode
{
    struct trieNode *children[26];
    int leaf_value;
};

typedef struct trieTree trieTreeT;
struct trieTree
{
    trieNodeT *root;
    int counts;
};

trieNodeT *createNode()
{
    trieNodeT *new_node = NULL;
    new_node = (trieNodeT*)malloc(sizeof(trieNodeT));
    if(new_node)
    {
        new_node->leaf_value = 0;
        for(int i=0;i< ALPHABET_SIZE;i++)
        {
            new_node->children[i] = NULL;
        }
    }
    return new_node;
};

void initialize(trieTreeT *trie)
{
    trie->root = createNode();
    trie->counts = 0;
}

int isLeafNode(trieNodeT *node)
{
    return (node->leaf_value!=0);
}

int isFreeNode(trieNodeT *node)
{
    for(int i=0;i<26;i++)
    {
        return (!node->children[i]);
    }
    return 0;
}

int getStrLength(const char *key)
{
    int length = 0;
    while(*key!='\0')
    {
        key++;
        length++;
    }
    return length;
}

void insertKey(trieTreeT *root_ref, const char *key)
{
    int index,length = getStrLength(key);
    trieNodeT *current_node;
    current_node = root_ref->root;
    root_ref->counts++;
    for(int i=0;i<length;i++)
    {
        index = CHAR_INT_INDEX(key[i]);
        if(current_node->children[index]==NULL)
        {
            current_node->children[index] = createNode();
        }
        current_node = current_node->children[index];
    }
    current_node->leaf_value = root_ref->counts;
}

bool prefixSearch(trieTreeT *root_ref, const char *key)
{
    int index,length = getStrLength(key);
    trieNodeT *current = root_ref->root;
    for(int i=0;i<length;i++)
    {
        index =CHAR_INT_INDEX(key[i]);
        if(!current->children[index])
        {
            return false;
        }
        current = current->children[index];
    }
    return (current!=NULL);
}

bool deleteHelper(trieNodeT *current_node, char key[], int len, int level)
{
    if(current_node)
    {
        if(len==level)
        {
            current_node->leaf_value = 0;
            if(isFreeNode(current_node))
            {
                return true;
            }
            return false;
        }
        else
        {
            int index = CHAR_INT_INDEX(key[level]);
            if(deleteHelper(current_node->children[index],key,len,level+1))
            {
                FREE(current_node->children[index]);
                return (!isLeafNode(current_node) && isFreeNode(current_node));
            }
        }
    }
    return false;

}

void deleteKey(trieTreeT *root_ref,char key[])
{
    int length = getStrLength(key);
    deleteHelper(root_ref->root,key,length,0);
}

bool wordSearch(trieTreeT *root_ref, const char *key)
{
    int index,length = getStrLength(key);
    trieNodeT *current = root_ref->root;
    for(int i=0;i<length;i++)
    {
        index =CHAR_INT_INDEX(key[i]);
        if(!current->children[index])
        {
            return false;
        }
        current = current->children[index];
    }
    return (current!=NULL && current->leaf_value!=0);
}

int main()
{
    char output[][32] = {"not in trie","in trie"};
    char keys[][10] = {"the", "there", "i", "he", "her", "any", "anyways", "anywhere"};
    char keysTest[][10] = {"these", "there", "i", "here", "her", "any", "anyway", "anywhere"};
    char keys_to_delete[][10] = {"the", "i", "her"};
    trieTreeT trie;
    initialize(&trie);
    for(int i=0; i<ARRAY_SIZE(keys); i++)
    {
        insertKey(&trie,keys[i]);
    }

    for(int i=0; i<ARRAY_SIZE(keysTest); i++)
    {
        printf("%s --- %s\n",keysTest[i], output[wordSearch(&trie,keysTest[i])]);
    }

    for(int i=0; i<ARRAY_SIZE(keys_to_delete); i++)
    {
        if(output[wordSearch(&trie,keys_to_delete[i])])
        {
            deleteKey(&trie, keys_to_delete[i]);
        }
    }
    printf("\n\nAfter delete\n\n");
    for(int i=0; i<ARRAY_SIZE(keys); i++)
    {
        printf("%s --- %s\n",keys[i], output[wordSearch(&trie,keys[i])]);
    }

}
