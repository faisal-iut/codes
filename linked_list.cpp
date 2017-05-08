#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};


struct node* createNode(int item)
{
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    return temp;
};


void insertNodeLast(struct node** head_ref, int item)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* last = *head_ref;
    new_node = createNode(item);
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

struct node* createList(struct node** head_ref)
{
    int number_of_item,item;
    scanf("%d", &number_of_item);
    scanf("%d",&item);
    *head_ref = createNode(item);
    for(int i=0;i<number_of_item-1;i++)
    {
        scanf("%d",&item);
        insertNodeLast(head_ref, item);
    }
    return *head_ref;
}

void printList(struct node* head_ref)
{
    while(head_ref!=NULL)
    {
        printf("%d ",head_ref->data);
        head_ref = head_ref->next;
    }

}

struct node* convertArrayToLinkedList(int n, int a[])
{
    struct node* head = NULL;
    head = createNode(a[0]);
    for(int i=1;i<n;i++)
    {
        insertNodeLast(&head,a[i]);
    }
    return head;
};

int countNodeNumber(struct node* head_ref)
{
    int counts = 0;
    while(head_ref!=NULL)
    {
        counts++;
        head_ref = head_ref->next;
    }
    return counts;
}

int searchValue(struct node* head_ref, int value)
{
    while(head_ref!=NULL)
    {
        if(head_ref->data == value)
        {
            return 1;
        }
        head_ref = head_ref->next;
    }
    return 0;
}

struct node* listReverse(struct node* head_ref)
{
    struct node *current, *next, *prev = NULL;
    current = head_ref;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;

    return head_ref;
}



struct node* deleteLinkedList(struct node* head)
{
    struct node* temp = head;
};

struct node* MergeLists(struct node *headA, struct node *headB)
{
  // This is a "method-only" submission.
  // You only need to complete this method
  struct node * new_node = (struct node*)malloc(sizeof(struct node));
  struct node *headC, *prev;
  headC = new_node;
  while(headA!=NULL && headB!=NULL)
  {
      if(headA->data<=headB->data)
      {
            new_node->data = headA->data;
            headA = headA->next;
      }
      else
      {
            new_node->data = headB->data;
            headB = headB->next;
      }


      prev = new_node;
      new_node->next = (struct node*)malloc(sizeof(struct node));
      new_node = new_node->next;
  }
  prev->next = NULL;

  return headC;

}


int main()
{
    int arr[] = {2,3,4,5,6,7,4};
    int array_length, counts, search_result, value_to_search;
    struct node* head = NULL, *headA = NULL, *headB = NULL, *headC = NULL;
    //head = createList(&head);
    //printList(head);
    array_length = sizeof(arr)/sizeof(arr[0]);
    headB = convertArrayToLinkedList(array_length, arr);
    headA = convertArrayToLinkedList(array_length, arr);
    //printList(headA);
    //counts = countNodeNumber(headA);
    //printf("\ntotal node: %d\n",counts);
    //printf("Value to be searched: ");
    //scanf("%d",&value_to_search);
    //search_result = searchValue(head, value_to_search);
    //printf("Search result: %d\n",search_result);
    headB = listReverse(headB);
    printList(headA);
    cout<<endl;
    printList(headB);
    headC = MergeLists(headA,headB);
    cout<<endl;
    printList(headC);
    return 0;
}



