#include "stdparking.h"

void initstack_sq(sqstack &S)
{//初始化栈 
    S.elem=new int[size];
    S.stacksize=size;
    S.top=-1;
}

bool gettop_sq(sqstack S,int &e)
{//获取栈顶元素 
	if(S.top==-1)return FALSE;
	e=S.elem[S.top];
	return TRUE;
}

void clearstack_sq(sqstack S){
	
	
}
void push_sq(sqstack &S,int e)
{//入栈 
	if(S.top==S.stacksize-1){cout<<"空间不足"<<endl;return;}
	S.elem[++S.top]=e; 
} 

bool pop_sq(sqstack &S,int &e)
{//出栈 
	if(S.top==-1)return FALSE;
	e=S.elem[S.top--];
	return TRUE;
 } 

void InitQueue_L(LinkQueue &Q)
{//初始化队列 
	Q.front=Q.rear=new LNode;
	Q.front->next=NULL;
}

void DestroyQueue_L(LinkQueue &Q)
{//销毁链队列 
	while(Q.front){
		Q.rear=Q.front->next;
		delete Q.front;
		Q.front=Q.rear;
	}
 } 

bool GetHead_L(LinkQueue Q,int &e)
{//链队列获取队首元素 ，不改变队首元素 
	if(Q.front==Q.rear)return FALSE;
	e=Q.front->next->elem;
	return TRUE; 
 } 
 
void EnQueue_L(LinkQueue &Q,int e)
{//入队列 
    Queueptr p;
	p=new LNode;
	p->elem=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
 } 
 
bool DeQueue_L(LinkQueue &Q,int &e)
{//出队列，删除队首元素并赋予e 
    Queueptr p; 
	if(Q.front==Q.rear)return FALSE;
	p=Q.front->next;
	Q.front->next=p->next;
	e=p->elem;
	if(Q.rear==p)Q.rear=Q.front;
	delete p;
	return TRUE;
}

int LengthQueue(LinkQueue Q){
//判断队列Q长度 
    int l=0;
    Queueptr p=Q.front;
    if(Q.front==Q.rear)return l;
    while(p!=Q.rear){
    	p=p->next;
    	l++;
	}
    return l;
}
/*void insqstack_sq(sqstack &S)
{//建立一个顺序栈，然后输入元素 
    
	cout<<"请输入车辆信息：停车/离开；车牌号；时间："<<endl;
	for(i=0;i<n;i++){
		cin>>e[0]>>e[1]>>e[2];
		if(e[0]=='E') 
		push_sq(S,e);
	}
		
    
}*/
void outp(sqstack S){
//输出S中元素,即输出停车场中车俩信息	
    int i;
	if(S.top==-1)cout<<"停车场无车"<<endl;
	else {
		cout<<"停车场各车车牌号为："<<endl;
		for(i=0;i<=S.top;i++)cout<<S.elem[i]<<"  "<<endl;
	} 
}
void outw(LinkQueue &Q){
//	输出Q中元素,即输出候车场中车俩信息
    int l=0;
    Queueptr p=Q.front;
    if(Q.front==Q.rear){cout<<"候车场无车"<<endl;return;}
    cout<<"侯车场各车车牌号为："<<endl;
    while(p!=Q.rear){
        p=p->next;
		cout<<p->elem<<endl;
	} 
}
