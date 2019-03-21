#include <stdio.h>
#include <stdlib.h>

#define MaxStackSize 20
#define StackExtecdSpace 10  //需要扩展栈空间时，一次扩展10个

//定义数据的类型，这里简化为int
typedef int DataType;

//定义栈
typedef struct stack
{
    DataType* base;
    DataType* top;
    int stacksize;
}Stack_S;

//初始化栈
Stack_S* init_stack()
{
    Stack_S* pstack = (Stack_S*)malloc(sizeof(Stack_S));
    if (!pstack)
    {
        return NULL;
    }
    
    //内存开辟一段连续内存作为栈空间，首地址给base
    pstack->base = (DataType*)malloc(MaxStackSize * sizeof(DataType));
    if (!pstack->base)
    {
        return NULL; //分配空间失败
    }
    pstack->top = pstack->base;  //初始时，栈顶等于栈底
    pstack->stacksize = MaxStackSize;
    return pstack;
}

//获得当前栈长度
int get_stack_len(Stack_S* pstack)
{
    return(pstack->top - pstack->base);
}

// push 操作
bool push_func(Stack_S* pstack, DataType data)
{
    if (!pstack) 
    {
        return false;
    }
    
    //栈满的情况
    if(pstack->top - pstack->base >= pstack->stacksize)
    {
        //扩展空间
        pstack->base = (DataType*)realloc(pstack->base, (pstack->stacksize+StackExtecdSpace)*sizeof(DataType));
        if(!pstack->base)
        {
            //扩展空间分配失败
            return false;
        }
        //扩展成功，更新栈信息
        pstack->top = pstack->base + pstack->stacksize; 
        pstack->stacksize = pstack->stacksize + StackExtecdSpace;
    }

    *(pstack->top)= data; //栈顶压入数据
    pstack->top++;

    return true;
}

// pop 操作
bool pop_func(Stack_S* pstack)
{
    if(!pstack)
    {
        return false;
    }
    if(pstack->top == pstack->base)
    {
        //栈中已经没有数据
        return false;
    }
    pstack->top-- ;
    return true;
}

//pop 操作，获取弹出的数据
bool pop_and_getdata_func(Stack_S* pstack, DataType* data)
{
    if(!pstack || !data)
    {
        return false;
    }

    if(pstack->top == pstack->base)
    {
        //栈中已经没有数据
        return false;
    }

    
    *data = *(pstack->top-1);
    pstack->top--;

    return true;
}

//释放栈
void destroy_stack_func(Stack_S* pstack)
{
    free(pstack->base);
    pstack->base = pstack->top = NULL;
    pstack->stacksize = 0;
    free(pstack);
}

int main()
{
    //简单测试
    Stack_S *pteststack;
    pteststack = init_stack();

    int i;
    bool flag = true;
    for(i=0;(i<15) && (flag == true);i++)
    {
        flag = push_func(pteststack, (DataType)i);
        int topdata = *(pteststack->top-1);
        int base = *(pteststack->base);
    }
    int len;
    len = get_stack_len(pteststack);

    int testdata;
    while(pop_and_getdata_func(pteststack, &testdata))
    {
        printf("stack pop data: %d", testdata);
    }

    len = get_stack_len(pteststack);

    for(i=0;(i<25) && (flag == true);i++)
    {
        flag = push_func(pteststack, (DataType)i);
        int topdata = *(pteststack->top-1);
        int base = *(pteststack->base);
    }
    destroy_stack_func(pteststack);
    return 0;

}
