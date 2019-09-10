#include "graph.h"

void InitStack(SqStack &S){
	//初始化栈
	S.elem = new ElemType[msize];
	S.stacksize = msize;
	S.top = -1;
}
bool GetTop(SqStack S, ElemType &e) {
	//获取栈顶元素
	if (S.top == -1)return FALSE;
	e = S.elem[S.top];
	return TRUE;
}
void Push(SqStack &S, ElemType e){
	//入栈
	if (S.top == S.stacksize - 1) {
		cout << "空间不足" << endl;
		return;
	}
	S.elem[++S.top] = e;
}
bool Pop(SqStack &S, ElemType &e) {
	//出栈
	if (S.top == -1)return FALSE;
	e = S.elem[S.top--];
	return TRUE;
}
int StackLength(SqStack S) {
	//栈长度
	return S.top + 1;
}
void CreateGraph(ALGraph &G) {
	//从文件输入G的顶点序列和边集，创建图G，G用邻接表表示
	FILE *fp;
	char m,vi,vj;
	int i, j, k;
	double w;
	ArcNode *p;
	if ((fp = fopen("/home/yuerp/Documents/CLionProjects/datastructure/graph/graph.txt", "r")) == NULL) {
		cout << "cannot open/create this file" << endl;
		exit(0);
	}
	fscanf(fp, "%d", &G.vexnum);//顶点数
	fscanf(fp, "%d", &G.arcnum);//边数
	fscanf(fp, "%d", &G.kind);//图类型
	m = fgetc(fp);
	for (i = 0; i < G.vexnum; i++) {
		fscanf(fp, "%c", &G.vertices[i].data);//读入顶点v[i]的值
		G.vertices[i].firstarc = NULL;//将边链的头指针置空
	}
	m = fgetc(fp);
	for (k = 0; k < G.arcnum; k++) {
		vi = fgetc(fp), vj = fgetc(fp);//读入弧<vi,vj>
		fscanf(fp, "%lf", &w);//读入权值
		m = fgetc(fp);
		i = LocateVex(G, vi);
		j = LocateVex(G, vj);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->weight = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;//将弧头插到vi的边链表
		if (G.kind == 3) {//G是无向网
			p = (ArcNode*)malloc(sizeof(ArcNode));
			p->adjvex = i;
			p->weight = w;
			p->nextarc = G.vertices[j].firstarc;
			G.vertices[j].firstarc = p;
		}

	}
}
int LocateVex(ALGraph G, VertexType v) {
	//查找值为V的顶点在图G中的存储位置
	//如果图G中存在v,返回v的位置下标，否则返回-1
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == v)return i;
	}
	return -1;
}
int FirstAdjVex(ALGraph G, int v) {
	//求存储下标为V的顶点的第一个邻接点
	//存在返回下标，否则返回-1
	if (G.vertices[v].firstarc != NULL)
		return G.vertices[v].firstarc->adjvex;
	else return -1;
}
int NextAdjVex(ALGraph G, int v, int w) {
	//求存储下标为V的顶点的第一个邻接点
	//即在下标为v的顶点边链表中，找值为的边结点的直接后继，不存在返回-1
	ArcNode *p = G.vertices[v].firstarc;
	while (p&&p->adjvex != w)p = p->nextarc;
	if (!p || !p->nextarc)
		return -1;
	else
		return p->nextarc->adjvex;
}
void Prim(ALGraph G, int v0) {
	//从序号为v0的顶点出发，构造连通网G的最小生成树
	//adjvex[]用来存放最小生成树的边集
	int i,j,k;
	ArcNode *p;
	double lowcost[MAX_VERTEX_NUM];
	int adjvex[MAX_VERTEX_NUM];
	for (j = 0; j < G.vexnum; j++)lowcost[j] = 1000;
	for (j = 0; j < G.vexnum; j++) {//初始化lowcost
		if (j != v0) {
			p = G.vertices[v0].firstarc;
			while (p&&p->adjvex != j)p = p->nextarc;
			if (p)lowcost[j] = p->weight;
			adjvex[j] = v0;
		}
	}
	lowcost[v0] = 0;//将v0标记为红点，即已经处理过
	for (i = 0; i < G.vexnum-1; i++) {
		k = MinEdge(lowcost, G);//在lowcost数组中选取权值最小的边，k为下标
		cout << "("  << G.vertices[adjvex[k]].data <<","<< G.vertices[k].data << ")"<<"权值为"<<lowcost[k]<< endl;//输出最小生成树上的一条边
		lowcost[k] = 0;//标记vk
		for (j = 0; j < G.vexnum; j++) {
			p = G.vertices[k].firstarc;
			while(p&&p->adjvex != j)p = p->nextarc;
			if (p) {
				if (p->weight < lowcost[j]) {
					adjvex[j] = k;
					lowcost[j] = p->weight;
				}
			}
		}
	}
}
int MinEdge(double lowcost[], ALGraph G){
	//在lowcost数组中选取权值最小的紫边，返回下标
	double t=1000;
	int i,k=-1;
	for (i = 0; i<G.vexnum; i++) {
		if (lowcost[i] != 0 && lowcost[i] < t) {
			t = lowcost[i];
			k=i;
		}
	}
	return k;
}