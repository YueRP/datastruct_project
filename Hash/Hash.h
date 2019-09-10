#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

typedef struct {
	int key;//关键字
	int num;   //数据，频度
}ElemType;

const int SUCCESS = 1;
const int UNSUCCESS = 0;
const int DUPLICATE = -1;
typedef struct LHNode{//链地址法
	ElemType data;
	LHNode *next;
}LHNode, *LHNodeptr;
typedef struct {
	LHNodeptr *elem;
	int count;//记录数
	int sizeindex;//哈希表容量
}LHashTable;
int SearchHash(LHashTable H, int key, LHNodeptr &p, int &c);
	//在链地址哈希表H中查找关键码为k的元素
	//若查找成功，以p指示位置，
	//否则，以p返回最后一个结点待插入
int InsertHash(LHashTable &H, ElemType e);
	//链地址插入
void get_next1(char *P, int next[]);
	//求模式串p的next函数修正值并写入数组next[]
int Find_KMP(char *S, char *P, int start, int next[]);
	//在串S中从start位置开始，查找第一次出现模式P的位置返回，没找到返回-1
int Hash(int key);
	//哈希函数，Hash(key)=(key第一个字符序号*100+key最后一个字符序号)%41

void CreateHash(LHashTable &H);
	//建立哈希表(已初始化），从文本文档读入源程序,H[]哈希表，txt[]文本文档名
void InitH(LHashTable &H);//初始化
void DestroyH(LHashTable &H);//销毁哈希表
double similar(int x1[], int x2[], int n);
	//比较x1与x2的相似性
double createsimilar(LHashTable H1, LHashTable H2);
	//比较H1与H2的相似性

double length(int x1[], int x2[], int n);
	//求相似距离
double createlength(LHashTable H1, LHashTable H2);//比较H1与H2的几何距离
//void insert_node_to_hash(LHashTable plist, int id, int data);
	/*typedef struct {
	ElemType *elem;//记录存储基址
	int count;//记录数
	int sizeindex;//哈希表容量
	}HashTable;*/