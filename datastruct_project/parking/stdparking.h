#include <stdio.h>
#include <iostream>


#define FALSE 0
#define TRUE 1 
#define size 100  //栈的初始化空间大小
//#define FALSE 0 
//#define TRUE 1 


using namespace std;

typedef struct{   //顺序栈定义  
    int *elem;
	int stacksize;     //栈容量 
	int top;           //栈顶指针 
}sqstack; 
 
typedef struct LNode{
    int elem;
    struct LNode *next;
}LNode,*LinkList;
typedef LinkList Queueptr;
typedef struct{     //链队列 
	Queueptr front;    //队首指针 
	Queueptr rear;     //队尾指针 
}LinkQueue;

void initstack_sq(sqstack &S);//初始化栈


bool gettop_sq(sqstack S,int &e);//获取栈顶元素 


void clearstack_sq(sqstack S);
void push_sq(sqstack &S,int e);//入栈 


bool pop_sq(sqstack &S,int &e);//出栈


void InitQueue_L(LinkQueue &Q);//初始化队列 


void DestroyQueue_L(LinkQueue &Q);//销毁链队列

bool GetHead_L(LinkQueue Q,int &e);//链队列获取队首元素 ，不改变队首元素 

 
void EnQueue_L(LinkQueue &Q,int e);//入队列 

 
bool DeQueue_L(LinkQueue &Q,int &e);//出队列，删除队首元素并赋予e 


int LengthQueue(LinkQueue Q);//判断队列Q长度 

void outp(sqstack S);//输出S中元素,即输出停车场中车俩信息

void outw(LinkQueue &Q);//	输出Q中元素,即输出候车场中车俩信息
