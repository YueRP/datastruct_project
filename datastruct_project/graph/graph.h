#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>

#define msize 100
#define MAX_VERTEX_NUM 40
#define FALSE 0
#define TRUE 1

using namespace std;
typedef int ElemType;
typedef double WeightType;//权值为double
typedef char VertexType;
typedef struct { //顺序栈定义
	ElemType *elem;
	int stacksize;     //栈容量
	int top;           //栈顶指针
} SqStack;
typedef struct ArcNode {
	int adjvex;//邻接点的位置下标
	WeightType weight;//边的权值
	struct ArcNode *nextarc;//边链后继指针
}ArcNode;//边结点类型名
typedef struct VertexNode {
	VertexType data;//顶点数据
	ArcNode *firstarc;//边链头指针
}VertexNode, AdjList[MAX_VERTEX_NUM];//表头结点类型名和表头结点数组类型名
typedef struct {
	AdjList vertices;//表头结点数据
	int vexnum, arcnum;//顶点数和边数
	int kind;//图的类别标志，0，1，2，3，4分别表示
}ALGraph;//图的邻接表表示法类型名有向图，有向网，无向图，无向网
void InitStack(SqStack &S);//初始化栈
bool GetTop(SqStack S, ElemType &e);//获取栈顶元素
void Push(SqStack &S, ElemType e);//入栈
bool Pop(SqStack &S, ElemType &e);//出栈
int StackLength(SqStack S);//求栈长度
void CreateGraph(ALGraph &G);
	//从文件输入G的顶点序列和边集，创建图G，G用邻接表表示
int LocateVex(ALGraph G, VertexType v);
	//查找值为V的顶点在图G中的存储位置
	//如果图G中存在v,返回v的位置下标，否则返回-1

int FirstAdjVex(ALGraph G, int v);
	//求存储下标为V的顶点的第一个邻接点
	//存在返回下标，否则返回-1

int NextAdjVex(ALGraph G, int v, int w);
	//求存储下标为V的顶点的第一个邻接点
	//即在下标为v的顶点边链表中，找值为w的边结点的直接后继，不存在返回-1
void Prim(ALGraph G, int v0);
	//从序号为v0的顶点出发，构造连通网G的最小生成树
	//adjvex[]用来存放最小生成树的边集	
int MinEdge(double lowcost[], ALGraph G);
	//在lowcost数组中选取权值最小的边，返回下标
int IsGraph(ALGraph G,int v0,int j);