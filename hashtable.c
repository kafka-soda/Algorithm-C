#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//定义链表
typedef struct hashlist
{
    int data;
    struct hashlist *next;

}Node_S;


//定义hashtable
typedef struct hashtable
{
    /* data */
    Node_S *hashnode[10];
}Hashtable_S;


// hash 算法,求余
int hashcalc(int num)
{
    return (num % 10);
}

//hash表初始化
Hashtable_S* init_hashtable()
{
    Hashtable_S *pHashTbl = (Hashtable_S*)malloc(sizeof(Hashtable_S));
    if (pHashTbl == NULL)
    {
        return NULL;
    }

    memset(pHashTbl, 0, sizeof(Hashtable_S));
    return pHashTbl;
}

// hash表查询数据
Node_S* query_hashtable(int data, Hashtable_S *pHashTbl) 
{
    if (pHashTbl == NULL)
    {
        return NULL;
    }    
    // hash表索引
    int hashindex;
    hashindex = hashcalc(data);

    if (pHashTbl->hashnode[hashindex] == NULL)
    {
        return NULL;
    }
    else 
    {
        if(pHashTbl->hashnode[hashindex]->data != data )
        {
            Node_S *pCur = pHashTbl->hashnode[hashindex];
            while (pCur->next)
            {
                pCur = pCur->next;
                if (pCur->data == data)
                {
                    return pCur;
                }
            }
        }
        else
        {
            return pHashTbl->hashnode[hashindex];
        }
    }
}

// hash表添加数据
int adddata_hashtable(int data, Hashtable_S *pHashTbl)
{
    if (pHashTbl == NULL)
    {
        return -1;
    }

    if (query_hashtable(data, pHashTbl) != NULL)
    {
        //数据已经存在
        return 1;
    }
    // hash表索引
    int hashindex;
    hashindex = hashcalc(data);
    // hash 节点为空，则需要增加节点
    if (pHashTbl->hashnode[hashindex] == NULL)
    {
        Node_S *pNode = (Node_S*)malloc(sizeof(Node_S));
        pNode->data = data;
        pNode->next = NULL;
        pHashTbl->hashnode[hashindex] = pNode;
        return 0;
    }
    // hash 节点不为空，判断第一个是不是data，不是则冲突处理
    if (pHashTbl->hashnode[hashindex]->data != data )
    {
        /* code */
        Node_S *pCur = pHashTbl->hashnode[hashindex];
        while (pCur->next)
        {
            pCur = pCur->next;
        }
        Node_S *pNode = (Node_S*)malloc(sizeof(Node_S));
        pNode->data = data;
        pNode->next = NULL;
        pCur->next = pNode;
        return 0;
    }
}

//hash表数据删除
int deldata_hashtable(int data, Hashtable_S *pHashTbl)
{
    if (pHashTbl == NULL)
    {
        return -1;
    }
    
    if (query_hashtable(data, pHashTbl) == NULL)
    {
        //数据不存在
        return -1;
    }

    // hash表索引
    int hashindex;
    hashindex = hashcalc(data);

    // 目标数据在hash表首节点
    if (pHashTbl->hashnode[hashindex]->data == data )
    {
        Node_S *pCur = pHashTbl->hashnode[hashindex];
        if (pCur->next == NULL)
        {
            pCur = NULL;
        }
        else
        {
            pHashTbl->hashnode[hashindex] = pCur->next;
        }
    }
    else
    {
        Node_S *pCur = pHashTbl->hashnode[hashindex];
        while(pCur->next)
        {
            if (pCur->data == data)
            {
                pCur->next = pCur->next->next;
            }
            pCur = pCur->next;
            
        }
    }
    return 0;
}

int main()
{
    Hashtable_S *pHashTbl; 
    pHashTbl = init_hashtable();

    int i;
    for(i = 0; i<100;i++)
    {
        (void)adddata_hashtable(i, pHashTbl);
    }    

    Node_S *pNode = (Node_S*)malloc(sizeof(Node_S));
    pNode = query_hashtable(18, pHashTbl);
    printf("%d", pNode->data);

}
