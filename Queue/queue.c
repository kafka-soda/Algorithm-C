#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
//定义队列节点
typedef struct queuenode{
    ElemType         data;
    struct queuenode *next;
} QueueNode_S;

//定义队列
typedef struct queuelist{
    QueueNode_S *front;   //队头指针
    QueueNode_S *rear;    //队尾指针
}QueueList_S;

QueueList_S* init_queue()
{
    /*初始化一个空队列*/
    QueueList_S *pqueuelist = (QueueList_S*)malloc(sizeof(QueueList_S));
    if(!pqueuelist)
    {
        return NULL;
    }

    /*创建一个头结点，队头队尾指针指向该结点*/
    pqueuelist->front = pqueuelist->rear = (QueueNode_S*)malloc(sizeof(QueueNode_S)); 
    if(!pqueuelist->front)
    {
        /*创建失败*/
        return NULL;
    }
    /*创建成功，头结点指针域置NULL*/
    pqueuelist->front->next = NULL;
    pqueuelist->front->data = '$';
    
    return pqueuelist;
}

/*入队列函数， element为需要入队列的数据*/
bool enter_queue_func(QueueList_S *pqueuelist, ElemType element)
{
    /*申请一个节点用来存需要入队列的元素*/
    QueueNode_S *pqueuenode = (QueueNode_S*)malloc(sizeof(QueueNode_S));
    if(!pqueuenode)
    {
        return false;
    }
    pqueuenode->data = element;
    pqueuenode->next = NULL;

    /*队尾指针指向新建节点，队尾向后移*/
    pqueuelist->rear->next = pqueuenode;
    pqueuelist->rear = pqueuenode;
    return true;
}

/*出队列函数， element为出队列的数据*/
bool out_queue_func(QueueList_S *pqueuelist, ElemType *element)
{
    /*队列为空的情况*/
    if(pqueuelist->front == pqueuelist->rear) 
    {
        return false;
    }

    QueueNode_S *pqueuenode;
    pqueuenode = pqueuelist->front->next;
    *element = pqueuenode->data;

    pqueuelist->front->next = pqueuenode->next; 

    /*如果队头就是队尾，则修改队尾指针*/
    if(pqueuelist->rear == pqueuenode)
    {
        pqueuelist->rear = pqueuelist->front;
    }  
    free(pqueuenode);
    return true;
}

//释放队列
void destroy_queue_func(QueueList_S *pqueuelist)
{
    pqueuelist->rear = pqueuelist->front = NULL;
    free(pqueuelist->front);
    free(pqueuelist);
}
/*简单测试*/
int main()
{
    ElemType testdata;
    QueueList_S *ptestqueue;
    ptestqueue = init_queue();           /*初始化一个队列*/

    ElemType dataarr[10] = {'A','B','C','D','E','F','G','H','I','J'};
    bool flag = true;
    int i;
    for (i=0;i<10 && (flag == true);i++)
    {
        //入队列
        flag = enter_queue_func(ptestqueue, dataarr[i]);
    }

    /*将队列中的元素出队列*/
    flag = true;
    while(ptestqueue->front != ptestqueue->rear &&(flag == true))
    {   
        flag = out_queue_func(ptestqueue,&testdata);
        printf("%c ",testdata);
    }

    destroy_queue_func(ptestqueue);
    return 0;
}

