#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#include<string.h> 
#include<iostream>
using namespace std;
typedef struct LNode {
	int num;
	int code;
	struct LNode *next;
}LinkList, LNode;
LinkList *MakeList(int n, int a[]);
void FindJoseph(LinkList *L);

