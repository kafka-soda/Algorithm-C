#include <stdlib.h>
#include <stdio.h>

/*定义图的边*/
typedef struct graph_side
{
    /* data */
    int    target_node;                /*该边指向的顶点*/
    struct graph_side  *next;     /*下一条边*/
    int    distance;              /*边的距离*/
}Side_S;

/*定义图的节点*/
typedef struct graph_node
{
    /* data */
    char data;            /*节点上的值*/
    Side_S *first_side;  /*指向第一条边*/
    bool visted;         /*遍历时标记是否访问过*/
}GNode_S;

/* 使用邻接表结构存储图，节点是顺序表，使用数组，出边有向边用链表*/
/*使用5个节点的图举例*/
/*
A ---->B---->C
|     |      |
V     V      V
D----->E<----

*/
/* 创建图*/
bool creat_graph_func(int n, GNode_S graph_nodeset[])
{
    graph_nodeset[0].data = 'A';
    graph_nodeset[1].data = 'B';
    graph_nodeset[2].data = 'C';
    graph_nodeset[3].data = 'D';
    graph_nodeset[4].data = 'E';

    /*A--B , A--D*/
    Side_S* psideAB = (Side_S*)malloc(sizeof(Side_S));
    psideAB->target_node = 1;

    Side_S* psideAD = (Side_S*)malloc(sizeof(Side_S));
    psideAD->target_node = 3;

    graph_nodeset[0].first_side = psideAB;
    graph_nodeset[0].visted = false;
    psideAB->next = psideAD;
    psideAD->next = NULL;

    /*B--C, B--E*/
    Side_S* psideBC = (Side_S*)malloc(sizeof(Side_S));
    psideBC->target_node = 2;

    Side_S* psideBE = (Side_S*)malloc(sizeof(Side_S));
    psideBE->target_node = 4;

    graph_nodeset[1].first_side = psideBC;
    graph_nodeset[1].visted = false;
    psideBC->next = psideBE;
    psideBE->next = NULL;

    /*C--E*/
    Side_S* psideCE = (Side_S*)malloc(sizeof(Side_S));
    psideCE->target_node = 4;

    graph_nodeset[2].first_side = psideCE;
    graph_nodeset[2].visted = false;
    psideCE->next = NULL;

    /*D--E*/
    Side_S* psideDE = (Side_S*)malloc(sizeof(Side_S));
    psideDE->target_node = 4;

    graph_nodeset[3].first_side = psideDE;
    graph_nodeset[3].visted = false;
    psideDE->next = NULL;    

    /*E*/
    graph_nodeset[4].first_side = NULL;
    graph_nodeset[4].visted = false;

}

/*深度优先遍历*/
/*A B C E, D*/

/*第一个带指向的边的节点信息*/
int  get_first_side(GNode_S graph_nodeset[], int v)
{
    if(graph_nodeset[v].first_side != NULL)  
    {
        return (graph_nodeset[v].first_side)->target_node;
    }
    return -1;
}

/*其他边的节点信息*/
int  get_next_tnode(GNode_S graph_nodeset[], int v)
{
    Side_S* pside;
    pside = graph_nodeset[v].first_side;
    while(pside!=NULL)
    {
        //未访问过的节点，返回节点编号
        if(graph_nodeset[pside->target_node].visted == false)
        {
            return pside->target_node;
        }
        //访问过的找下一个边
        pside = pside->next;
    }
    return -1;
}

/*深度优先遍历*/
void DFS(GNode_S graph_nodeset[], int v)
{
    char vistdata;
    vistdata = graph_nodeset[v].data;
    printf("vistdata: %c \n", vistdata);
    graph_nodeset[v].visted = true;

    int next_node_index = get_first_side(graph_nodeset, v);
    while (next_node_index != -1)
    {
        //如果找到的节点未被访问过
        if(graph_nodeset[next_node_index].visted == false)
        {
            DFS(graph_nodeset, next_node_index);
        }
        //找到的节点被访问过了
        next_node_index = get_next_tnode(graph_nodeset, v);
    }

}


int main()
{
    GNode_S testgraph[5];
    (void)creat_graph_func(5, testgraph);

    DFS(testgraph, 0);
    return 0;
}
