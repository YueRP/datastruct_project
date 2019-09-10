#include "Hash.h"
void main() {
	LHashTable H1,H2;
	double k=-1,j=-1;
	int i,b;
	InitH(H1);
	InitH(H2);
//	while (1) {
	//	fflush(stdin);
	//	cout << "请确定您是否继续程序，继续输入1回车，否则输入0回车结束" << endl;
	//	cin >> b;
//if (b != 1)break;
		
		CreateHash(H1);
		CreateHash(H2);
		k = createsimilar(H1, H2);
		cout << "这两个程序的相似性为" << k << endl;
		cout << "换算为弧度为（arccos）" << 180 * acos(k) / 3.14 << "°" << endl;
		j = createlength(H1, H2);
		cout << "这两个程序的几何距离为" << j << endl;
	//	DestroyH(H1);
	//	DestroyH(H2);
	//}
	cout << "程序已结束，谢谢您的访问" << endl;
	//CreateHash(H1);
	system("pause");
	/*char KEY[32][10] = { "char","double","enum","float","int","long","short","signed","struct","union","unsigned","void","for","do","while", "break","continue", "if","else","goto","switch","case","default","return","auto","extern","register","static","const","sizeof","typedef","volatile" };//关键字数组
	for (i = 0; i < 32; i++) {
		
		cout << KEY[i];
		
	}
	/*int x1[43], x2[43];
	for (i = 0; i < 32; i++) {
		x1[i] = Hash(i);
		cout << x1[i]<<endl;
		x2[i] = i + 1;
	}
	
	cout << similar(x1, x2, 32);*/
	
}