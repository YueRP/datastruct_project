#include "Hash.h"
extern char KEY[32][10] = { "char","double","enum","float","int","long","short","signed","struct","union","unsigned","void","for","do","while", "break","continue", "if","else","goto","switch","case","default","return","auto","extern","register","static","const","sizeof","typedef","volatile" };//关键字数组
void InitH(LHashTable &H) {
	H.elem = (LHNode**)malloc(43 * sizeof(LHNode*));
	H.count = 0;
	H.sizeindex = 43;
	for (int i=0; i < 43; i++) {
		H.elem[i] = (LHNode*)malloc(sizeof(LHNode));
		H.elem[i]->data.key = -1;
		H.elem[i]->data.num = 0;
		H.elem[i]->next = NULL;
	}
}
void DestroyH(LHashTable &H) {
	for (int i = 0; i < 43; i++) {
		delete H.elem[i];
	}
}//销毁哈希表
int SearchHash(LHashTable H, int kval, LHNodeptr &p, int &c) {
	//在链地址哈希表H中查找关键码为kval的元素
	//若查找成功，以p指示位置，
	//否则，以p返回最后一个结点待插入
	LHNodeptr q = new LHNode;
	int d;
	q=NULL;
	d = Hash(kval);
	p = H.elem[d];
	while (p&&p->data.key!=kval) { q = p; p = p->next; c++; }//q紧随p
	if (p)return SUCCESS;
	else { p = q; return UNSUCCESS; }
}
int InsertHash(LHashTable &H, ElemType e) {
	//链地址插入
	int c = 0;
	LHNodeptr s, p;
	p = new LHNode;
	if (SearchHash(H, e.key, p, c) == SUCCESS) {
		p->data.num++;
		return 1;
	}
	//SearchHash(H, e.key, p, c);
	//else if (c < hashsize[H.sizeindex] / 2) {
		s = new LHNode;
		s->data = e;
		p->next = s;
		s->next = NULL;
		H.count++;
		return 1;
	//}
	//else cout << "重建哈希表" << endl;
}
void get_next1(char *P, int next[]) {
	//求模式串p的next函数修正值并写入数组next[]
	int j = 0, k = -1;
	next[0] = -1;
	while (j <=(signed)strlen(P) - 1)
		if (k == -1 || P[j] == P[k]) {
			j++;
			k++;
			if (P[j] != P[k])next[j] = k;//P[j]！=P[k]时才赋值为k
			else next[j] = next[k];
		}
		else k = next[k];
}//end get_next1

int Find_KMP(char *S, char *P, int start, int next[]) {
	//在串S中从start位置开始，查找第一次出现模式P的位置返回，没找到返回-1
	if (start<0 || start>(strlen(S) - strlen(P))) {
		//cout << "非法start值" << endl;
		return -1;
	}
	int i = start, j = 0;
	while (i<(signed)strlen(S) && j<(signed)strlen(P))
		if (j == -1 || S[i] == P[j])i++, j++;//当前 字符相等，继续下一个
		else j = next[j];              //当前字符不等滑动模式
		if (j == strlen(P))return(i - j);     //匹配成功，返回匹配开始的字符位置
		return -1;
}//end Find_KMP
int Hash(int key) {
	//哈希函数，Hash(key)=(key第一个字符序号*100+key最后一个字符序号)%41
	return (KEY[key][0] * 100 + KEY[key][strlen(KEY[key]) - 1]) % 41;
}

void CreateHash(LHashTable &H) {
	//建立哈希表
	int i,j,k;
	char txt[10];
	cout << "请输入文件名：" << endl;
	cin >> txt;
	FILE *fp;
	H.sizeindex = 43;
	ElemType e;
	char S[100]; //P储存即关键词，S储存母串 
	
	//i = 4;
	LHNodeptr p=new LHNode; int c;
	for (i = 0; i < 32; i++) {//依次处理32个关键字
		e.key = i;
		e.num = 0;
		if ((fp = fopen(txt, "r")) == NULL) { //以只读方式打开
			cout << "cannot open file" << endl;
			return;
		}
		while ((fgets(S, 100, fp)) != NULL) {
			if (S[0] == '\n')continue;
			int next[100];
			j = 0;
			while (j != -1) {
				get_next1(KEY[i], next);
				j = Find_KMP(S, KEY[i], j, next);
			    if (j != -1) { j++; e.num = 1; InsertHash(H, e); }//插入关键字及频度
				if (j != -1) { 
					if (SearchHash(H, i, p, c) == SUCCESS)p->data.num++;
				}//插入关键字及频度
			}
		}
		fclose(fp);
		//if (SearchHash(H, i, p, c) == SUCCESS)cout << p->data.num <<KEY[p->data.key]<< endl;
	}
}
double similar(int x1[], int x2[],int n) {
	//比较x1与x2的相似性
	int i;
	double S, s1 = 0, s2 = 0,s3=0;
	for (i = 0; i < n; i++) {
		s1 += x1[i] * x2[i];
		s2 += x1[i] * x1[i];
		s3 += x2[i] * x2[i];
	}
	return s1 / (sqrt(s2)*sqrt(s3));
}
double length(int x1[], int x2[], int n) {
	//求相似距离
	int i;
	double S = 0;
	for (i = 0; i < n; i++) {
		S+= (x1[i] - x2[i])*(x1[i] - x2[i]);
	}
	return sqrt(S);
}
double createsimilar(LHashTable H1, LHashTable H2) {
	//比较H1与H2的相似性
	int x1[32], x2[32];
	int i,c;
	for (i = 0; i < 32; i++)x1[i] = 0, x2[i] = 0;
	LHNodeptr p = new LHNode;
	for (i = 0; i < 32; i++) {
		if (SearchHash(H1, i, p, c) == SUCCESS)x1[i] = p->data.num;
		if (SearchHash(H2, i, p, c) == SUCCESS)x2[i] = p->data.num;
	}
	return similar(x1, x2, 32);
}
double createlength(LHashTable H1, LHashTable H2) {
	//比较H1与H2的几何距离
	int x1[32], x2[32];
	int i, c;
	for (i = 0; i < 32; i++)x1[i] = 0, x2[i] = 0;
	LHNodeptr p = new LHNode;
	for (i = 0; i < 32; i++) {
		if (SearchHash(H1, i, p, c) == SUCCESS)x1[i] = p->data.num;
		if (SearchHash(H2, i, p, c) == SUCCESS)x2[i] = p->data.num;
	}
	return length(x1, x2, 32);
}
/*void insert_node_to_hash(LHashTable plist, int id, int data)
{
	LHNode *ptail, *pre, *p=new LHNode;
	int temp = Hash(id);

	ptail = (LHNode *)malloc(sizeof(LHNode));
	ptail->next = NULL;
	ptail->data.num = data;
	ptail->data.key = id;

	if (NULL == plist.elem[temp]->next)
	{
		plist.elem[temp]->next = ptail;

//		printf("链表插入点id=%d\n", ptail->id);

		return ;
	}
	pre = plist.elem[temp]->next;
	while (pre)
	{
		p = pre;
		pre = pre->next;
	}
	p->next = ptail;
//	printf("链表插入点id=%d\n", ptail->id);

	return ;
}*/
