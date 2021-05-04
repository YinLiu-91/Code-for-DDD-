/*
 * @Author: Liu Dage
 * @Date: 2021-05-04 09:18:52
 * @LastEditTime: 2021-05-04 09:37:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\list.cpp
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    struct listnode *ln_next;
    int ln_value;
} Node;

static Node *Node_construct(int v)
{
    Node *n = malloc(sizeof(Node));
    n->ln_value = v;
    n->ln_next = 0;
    return n;
}

void List_insert(Node **n, int v)
{
    Node *p = Node_construct(v);
    Node *curr = *n;
    Node *prev = *n;
    if ((*n) == 0)
    {
        *n = p;
        return;
    }
    while ((curr != 0) && ((curr->ln_value) < v))
    {
        /*find the correct location of the new value*/
        prev = curr;
        curr = curr->ln_next;
    }
    if (curr == (*n))
    {
        /* the new value is smaller than all existing values*/
        p->ln_next = (*n);
        *n = p;
    }
    else
    {
        p->ln_next = prev->ln_next;
        prev->ln_next = p;
    }
}

static void Node_print(Node *n)
{
    printf("%d ", n->ln_value);
}
void List_print(Node *n)
{
    Node *curr = n;
    while (curr != 0)
    {
        Node_print(curr);
        curr = curr->ln_next;
    }
    printf("\n\n");
}

int main(int argc,char*argv[])
{
    if(argc<2)
    {
        printf("need a number\n");
        return -1;
    }

    srand(time(0));
    int num=strtol(argv[1],(char**)NULL,10);
    int iter;
    Node*list1=0;
    printf("insert %d numbers\n",num);
    for(iter=0;iter<num;iter++)
    {
        int val=rand()%10000;
        printf("insert %d\n",val);
        List_insert(& list1,val);
    }
    printf("\nlist: \n");
    List_print(list1);
    return 0;
    
}
