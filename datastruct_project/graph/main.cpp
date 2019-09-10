#include "graph.h"

int  main() {
	ALGraph G;
	int n;
	CreateGraph(G);//从文件创建图G
	cout << "请输入开始位置"<<endl;
	cin >> n;
	cout <<endl<<"最小生成树边集为"<< endl;
	if(n<=G.vexnum)Prim(G, n);//求最小生成树
	cout << "谢谢" << endl;
	return 0;
}