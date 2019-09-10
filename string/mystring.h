#include <stdio.h>
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;


int get_next1(char *P,int next[ ]);
	//求模式串p的next函数修正值并写入数组next[]
	

int Find_KMP(char *S,char *P,int start,int next[ ]);
	//在串S中从start位置开始，查找第一次出现模式P的位置返回，没找到返回-1

int Find_BF(char *S,char *P,int start);
	//在串S中从start位置开始，查找第一次出现模式P的位置返回，没找到返回-1


/*int index(char *S,char *P,int start) {
	//字串查找选择函数
	cout<<"请选择查找字串算法："<<endl;
	cout<<"BF算法，请输入1"<<endl;
	cout<<"KMP算法，请输入2"<<endl;
	int n;
	cin>>n;
	if(n==1) {
		Find_BF(S,P,start);
		return 1;
	}
	if(n==2) {
		Find_KMP(S,P,start);
		return 2;
	} else cout<<"error "<<endl;
	return 0;
}*/

