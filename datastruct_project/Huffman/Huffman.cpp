#include "Huffman.h"


void initstack_sq(sqstack &S) {
	//初始化栈
	S.elem = new ElemType[msize];
	S.stacksize = msize;
	S.top = -1;
}

bool gettop_sq(sqstack S, ElemType &e) {
	//获取栈顶元素
	if (S.top == -1)return FALSE;
	e = S.elem[S.top];
	return TRUE;
}


void push_sq(sqstack &S, ElemType e) {
	//入栈
	if (S.top == S.stacksize - 1) {
		cout << "空间不足" << endl;
		return;
	}
	S.elem[++S.top] = e;
}

bool pop_sq(sqstack &S, ElemType &e) {
	//出栈
	if (S.top == -1)return FALSE;
	e = S.elem[S.top--];
	return TRUE;
}
int StackLength(sqstack S) {
	return S.top + 1;
}





void Select(HuffTree &HT, int i, int &s1, int &s2) {
	int j = 1, k;
	while (HT[j].parent != 0)j++;
	s1 = j;
	j++;
	while (HT[j].parent != 0)j++;
	s2 = j;
	if (HT[s1].weight>HT[s2].weight)k = s1, s1 = s2, s2 = k;
	for (j = j + 1; j <= i - 1; j++) {
		if (HT[j].parent == 0) {
			if (HT[j].weight<HT[s1].weight)s2 = s1, s1 = j;
			else if (HT[j].weight<HT[s2].weight)s2 = j;
		}
	}
}



//构造哈夫曼树
void HuffmanTree(HuffTree &HT, WeightType *w, int n) {
	//根据给定的n个权值，构造哈夫曼树。*w是存放n个权值的数组
	int i;
	int m = n * 2 - 1;      //计算哈夫曼结点总数m
	HT = (HuffTree)malloc(sizeof(HTNode)*(m + 1));   //分配HT数组空间。0号单元空闲不用
	for (i = 1; i <= m; i++) {       //初始化数组HT[]
		HT[i].weight = i <= n ? w[i] : 0;
		HT[i].lchild = HT[i].rchild = HT[i].parent = 0;
	}
	int s1 = 0, s2 = 0;
	for (i = n + 1; i <= m; i++) {   //主循环，完成n-1次合并
		Select(HT, i, s1, s2);       //在HT[1..i-1]中选择parent为0且weight为最小的两个结点
									 //其下标分别为s1和s2
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[s1].parent = HT[s2].parent = i;
	}
}
/*void Coding(HuffTree HT,int root,char **HC,sqstack &S) {
//先序遍历哈夫曼数HT，求得每个叶子结点的编码字符串，存入数组HC
//S是一个顺序栈，用来记录遍历路径
//root是哈夫曼数数组HT中根节点的位置下标
char ch;
if(root!=0) {                            //当二叉树非空
if(HT[root].lchild==0) {             //root是树叶
push_sq(S,'\0');
HC[root]=(char *)malloc(S.top+1);
strcpy(HC[root],S.elem);
pop_sq(S,ch);
}
push_sq(S,'0');
Coding(HT,HT[root].lchild,HC,S);
pop_sq(S,ch);
push_sq(S,'1');
Coding(HT,HT[root].rchild,HC,S);
pop_sq(S,ch);
}
}*/
void Coding(HuffTree HT, char **HC, int root, sqstack &S, char *c) {
	char e;
	if (root != 0) {
		if (HT[root].lchild == 0) {
			push_sq(S, '\0');
			HC[root] = (char *)malloc(S.top + 1);
			strcpy(HC[root], S.elem);
			//printf("%c",c[root]);
			//puts(HC[root]);
			pop_sq(S, e);
		}
		else {
			push_sq(S, '0');
			Coding(HT, HC, HT[root].lchild, S, c);
			pop_sq(S, e);
			push_sq(S, '1');
			Coding(HT, HC, HT[root].rchild, S, c);
			pop_sq(S, e);
		}
	}
}

void HuffmanCoding(HuffTree HT, char **&HC, int n, char *c) {
	//从哈夫曼数HT上求得n个叶子结点的哈夫曼编码并存入数组HC
	sqstack S;              //S是一个字符型的顺序栈
	initstack_sq(S);    //初始化栈
	HC = (char **)malloc(sizeof(char *)*(n + 1));                   //分配HC的空间
	Coding(HT, HC, 2 * n - 1, S, c); //哈夫曼数根节点下标为2n-1

}
void Initialization(HuffTree &HT, WeightType *&w, char *&c, int &n, FILE *fp4) {
	//初始化哈夫曼数
	//从终端读入字符集大小n，以及n个字符和n个权值，建立Huffman 树，并将它存入hfmTree(fp4)中
	


	cout << "请输入权值数" << endl;
	cin >> n;
	fprintf(fp4, "%d", n);
	fputc('\n', fp4);
	int i;
	w = (WeightType *)malloc(sizeof(WeightType)*(n + 1));
	c = (char *)malloc(sizeof(char)*(n + 1));
	for (i = 1; i <= n; i++) {
		cout << "请输入第" << i << "个权值数  ";
		cin >> w[i];//0号单元空闲不用
		fprintf(fp4, "%d", w[i]);//将w数组存入fp4所指文件
		fputc(' ', fp4);
		cout << endl;
	}
	//	fputc('\n',fp4);
	HuffmanTree(HT, w, n);
	cout << "请依次输入字符 ";
	for (i = 1; i <= n; i++) {
		c[i] = getchar();//0号单元空闲不用
		fputc(c[i], fp4);
		//fprintf(fp4,"%c",c[i]); //将c数组存入fp4所指文件
	}
	getchar();

	
}
void ReHuffman(HuffTree &HT, int *&w, char *&c, int &n) {
	//由fp4所指文件建立Huffman树
	FILE *fp4;
	if ((fp4 = fopen("hfmTree.txt", "r")) == NULL) {
		cout << "cannot open/create this file" << endl;
		exit(0);
	}

	int i;
	cout << "文件信息为" << endl;
	fscanf(fp4, "%d", &n);
	cout << "权值数为 " << n << endl;
	cout << "权值分别为 ";
	for (i = 1; i <= n; i++) { //0号单元空闲不用
		fscanf(fp4, "%d", &w[i]);
		cout << w[i] << "  ";

	}
	cout << endl;

	HuffmanTree(HT, w, n);

	cout << "字符依次为";
	i = 1;
	char m;

	m = fgetc(fp4);
	for (i = 1; i <= n; i++) { //0号单元空闲不用
							   //fgtec(fp4)
		while (m == '\n')m = fgetc(fp4);
		c[i] = fgetc(fp4);
		cout << c[i] << "  ";
	}
	cout << endl;


	//
}
void Encoding(HuffTree HT, char **&HC, FILE *fp1, FILE *fp2, char *c, WeightType *w, int n) {
	//利用已经建好的Huffman树（如果不在内存，则应从文件hfmTree中读取），
	//对文件ToBeTran(fp1)中的正文进行编码， 然后将结果存入文件CodeFile(fp2)中
	char t;
	int i;
	HuffmanCoding(HT, HC, n, c);     //从哈夫曼数HT上求得n个叶子结点的哈夫曼编码并存入数组HC
	while (1) {
		t = fgetc(fp1);
		if (t == EOF)break;
		i = 1;
		while (c[i] != t)i++;
		fputs(HC[i], fp2);
		fputc('\n', fp2);
	}
}
void Decoing(char **HC, FILE *fp2, FILE *fp3, char *c, int n) {
	//解码（Decoding）。利用已经建立好的Huffman树将文件CodeFile(fp2)中的代码进行解码，结果存入TextFile(fp3)中
	char str[20];
	int i;
	while (feof(fp2) == 0) {
		i = 0;
		str[i] = fgetc(fp2);
		if (str[i] == EOF)break;
		while (str[i] != '\n')i++, str[i] = fgetc(fp2);
		str[i] = '\0';
		i = 1;
		while (strcmp(str, HC[i]) != 0)i++;
		fprintf(fp3, "%c", c[i]);
	}
}
void Print(FILE *fp2, FILE *fp5) {
	//打印代码文件（Print）。将文件CodeFile（fp2)以紧凑的格式显示在终端上，每行 50个代码。
	//同时将此字符形式的编码文件写入文件CodePrint(fp5)中。
	char str;
	int l = 0;
	while (feof(fp2) == 0) {
		str = fgetc(fp2);
		while (str == '\n')str = fgetc(fp2);
		cout << str;
		//	printf("%c",str);
		fputc(str, fp5);
		l++;
		if (l>49) {
			cout << endl;
			fputc('\n', fp5);
			l = 0;
		}
	}
	cout << endl;
}
void TreePrinting(HuffTree HT, char **HC, char *c, WeightType *w, int n, FILE *fp5) {
	//打印Huffman树（Tree Printing）。将已经在内存中的Huffman树以直观的形式（树或者凹入的形式）显示在终端上，
	//同时将此字符形式的Huffman 树写入文件TreePrint(fp5)中。
	//int mid=15;  //mid为根节点打印位置可变动
	int i;
	char tt[msize] = "mumber    weight     parent   lchild    rchild";

	cout << tt << endl;
	fputs(tt, fp5);
	fputc('\n', fp5);
	for (i = 1; i <= n * 2 - 1; i++) {
		cout << i << "  " << HT[i].weight << "  " << HT[i].parent << "  " << HT[i].lchild << "  " << HT[i].rchild << endl;
		fprintf(fp5, "%d", i);
		fputc(' ', fp5);
		fprintf(fp5, "%d", HT[i].weight);
		fputc(' ', fp5);
		fprintf(fp5, "%d", HT[i].parent);
		fputc(' ', fp5);
		fprintf(fp5, "%d", HT[i].lchild);
		fputc(' ', fp5);
		fprintf(fp5, "%d", HT[i].rchild);
		fputc(' ', fp5);
		fputc('\n', fp5);
	}
}
