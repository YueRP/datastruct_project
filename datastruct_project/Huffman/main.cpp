

#include "Huffman.h"

int main() {
	WeightType *w;  //w存储权值数组
	w = (WeightType *)malloc(sizeof(WeightType)*3*(msize));
	char *c;	//c存储权值对应字符数组
	c = (char *)malloc(sizeof(char)*(msize));
	int n;   //n存储字符数
	HuffTree HT;//Huffman树
	HT = (HuffTree)malloc(sizeof(HTNode)*(msize));
	char **HC;//HC数组存储二进制编码
	HC = (char **)malloc(sizeof(char *)*(msize));
	FILE *fp1, *fp2, *fp3, *fp4, *fp5;
	//对文件ToBeTran(fp1)中的正文进行编码， 然后将结果存入文件CodeFile(fp2)中
	//文件CodeFile(fp2)中的代码进行解码，结果存入TextFile(fp3)
	//fp4所指文本文件hfmTree存储Huffman树，
	cout << "I  初始化    R  从文件读入数据" << endl;
	cout << "E  编码      D  解码" << endl;
	cout << "P  打印代码文件    T  打印Huffman树" << endl;
	cout << "Q 退出程序" << endl;
	char menu;//菜单指令
	while (1) {
		cout << "请输入您要执行的指令" << endl;
		cin >> menu;
		switch (menu) {
		case 'I':
			if ((fp4 = fopen("hfmTree.txt", "w")) == NULL) {
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			Initialization(HT, w, c, n, fp4);
			fclose(fp4);
			break;//初始化Huffman树,从键盘输入
		case 'R':// 由文件构造Huffman树
		
			ReHuffman(HT, w, c, n);
			break;
		case 'E'://编码
			HuffmanCoding(HT, HC, n, c);
			if ((fp1 = fopen("ToBeTran.txt", "r")) == NULL) { //只读打开
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			if ((fp2 = fopen("CodeFile.txt", "w")) == NULL) {
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			Encoding(HT, HC, fp1, fp2, c, w, n);
			//利用已经建好的Huffman树（如果不在内存，则应从文件hfmTree中读取），
			//对文件ToBeTran(fp1)中的正文进行编码， 然后将结果存入文件CodeFile(fp2)中
			fclose(fp1);
			fclose(fp2);
			cout << "已执行" << endl;
			break;
		case 'D'://解码
			if ((fp2 = fopen("CodeFile.txt", "r")) == NULL) {
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			if ((fp3 = fopen("TextFile.txt", "w")) == NULL) {
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			Decoing(HC, fp2, fp3, c, n);
			//解码（Decoding）。利用已经建立好的Huffman树将文件CodeFile(fp2)中的代码进行解码，结果存入TextFile(fp3)中
			fclose(fp3);
			fclose(fp2);
			cout << "已执行" << endl;
			break;
		case 'P'://打印代码文件CodeFile（fp2),同时将此字符形式的编码文件写入文件CodePrint()fp5中。
			if ((fp2 = fopen("CodeFile.txt", "r")) == NULL) {
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			if ((fp5 = fopen("CodePrint.txt", "w")) == NULL) {
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			Print(fp2, fp5);
			fclose(fp2);
			fclose(fp5);
			cout << "已执行" << endl;
			break;
		case 'T':
			if ((fp5 = fopen("TreePrint.txt", "w")) == NULL) {
				cout << "cannot open/create this file" << endl;
				exit(0);
			}
			TreePrinting(HT, HC, c, w, n, fp5);
			fclose(fp5);
			cout << "已执行" << endl;
			//打印Huffman树（Tree Printing）。将已经在内存中的Huffman树以直观的形式（树或者凹入的形式）显示在终端上，
		case 'Q':
			break;
			cout << "已执行" << endl;
		default:
			cout << "输入错误" << endl;
			break;
		}
		if (menu == 'Q')break;
	}
	cout << "谢谢您的访问" << endl;
}

