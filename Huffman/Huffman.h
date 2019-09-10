#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>

#define msize 100
#define FALSE 0
#define TRUE 1
using namespace std;
typedef char ElemType;
typedef int WeightType;
typedef struct { //字符型顺序栈定义
	ElemType *elem;
	int stacksize;     //栈容量
	int top;           //栈顶指针
} sqstack;

//哈夫曼的存储类型定义
typedef int WeightType;
typedef struct {
	WeightType weight;    //WeightType是权值
	int parent, lchild, rchild;   //双亲，左孩子，右孩子
} HTNode;  //哈夫曼树节点类型
typedef HTNode *HuffTree;   //存放哈夫曼树的静态三叉链表类型

void initstack_sq(sqstack &S);
//初始化栈


bool gettop_sq(sqstack S, ElemType &e);
//获取栈顶元素



void push_sq(sqstack &S, ElemType e);
//入栈


bool pop_sq(sqstack &S, ElemType &e);
//出栈

int StackLength(sqstack S);//求栈长度





void Select(HuffTree &HT, int i, int &s1, int &s2);




//构造哈夫曼树
void HuffmanTree(HuffTree &HT, WeightType *w, int n);

void Coding(HuffTree HT, char **HC, int root, sqstack &S, char *c);
//先序遍历哈夫曼数HT，求得每个叶子结点的编码字符串，存入数组HC
//S是一个顺序栈，用来记录遍历路径
//root是哈夫曼数数组HT中根节点的位置下标v
void HuffmanCoding(HuffTree HT, char **&HC, int n, char *c);
void Initialization(HuffTree &HT, WeightType *&w, char *&c, int &n, FILE *fp4);
//初始化哈夫曼数
//从终端读入字符集大小n，以及n个字符和n个权值，建立Huffman 树，并将它存入hfmTree(fp4)中

void ReHuffman(HuffTree &HT, int *&w, char *&c, int &n);
//由fp4所指文件建立Huffman树


void Encoding(HuffTree HT, char **&HC, FILE *fp1, FILE *fp2, char *c, WeightType *w, int n);
//利用已经建好的Huffman树（如果不在内存，则应从文件hfmTree中读取），
//对文件ToBeTran(fp1)中的正文进行编码， 然后将结果存入文件CodeFile(fp2)中

void Decoing(char **HC, FILE *fp2, FILE *fp3, char *c, int n);
//解码（Decoding）。利用已经建立好的Huffman树将文件CodeFile(fp2)中的代码进行解码，结果存入TextFile(fp3)中

void Print(FILE *fp2, FILE *fp5);
//打印代码文件（Print）。将文件CodeFile（fp2)以紧凑的格式显示在终端上，每行 50个代码。
//同时将此字符形式的编码文件写入文件CodePrint(fp5)中。

void TreePrinting(HuffTree HT, char **HC, char *c, WeightType *w, int n, FILE *fp5);
//打印Huffman树（Tree Printing）。将已经在内存中的Huffman树以直观的形式（树或者凹入的形式）显示在终端上，
//同时将此字符形式的Huffman 树写入文件TreePrint(fp5)中。
//int mid=15;  //mid为根节点打印位置可变动


#pragma once
