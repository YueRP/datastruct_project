#include "mystring.h"

int get_next1(char *P,int next[ ]) {
	//求模式串p的next函数修正值并写入数组next[]
	int j=0,k=-1;
	next [0]=-1;
	while(j<=strlen(P)-1)
		if(k==-1||P[j]==P[k]) {
			j++;
			k++;
			if(P[j]!=P[k])next[j]=k;//P[j]！=P[k]时才赋值为k
			else next[j]=next[k];
		} else k=next[k];
	return 0;
}//end get_next1

int Find_KMP(char *S,char *P,int start,int next[ ]) {
	//在串S中从start位置开始，查找第一次出现模式P的位置返回，没找到返回-1
	if(start<0||start>strlen(S)-strlen(P)) {
		cout<<"非法start值"<<endl;
		return -1;
	}
	int i=start,j=0;
	while(i<strlen(S)&&j<(int)strlen(P))
		if(j==-1||S[i]==P[j])i++,j++;//当前 字符相等，继续下一个
		else j=next[j];              //当前字符不等滑动模式
	if(j==strlen(P))return(i-j);     //匹配成功，返回匹配开始的字符位置
	return -1;
}//end Find_KMP

int Find_BF(char *S,char *P,int start) {
	//在串S中从start位置开始，查找第一次出现模式P的位置返回，没找到返回-1
	if(start<0||start>strlen(S)-strlen(P)) {
		cout<<"非法start值"<<endl;
		return -1;
	}
	int i=start,j=0;
	while(i<strlen(S)&&j<strlen(P))
		if(S[i]==P[j])i++,j++;  //当前 字符相等，继续下一个
		else i=i-j+1,j=0;  //当前字符不等，回溯指针
	if(j==strlen(P))return(i-j);
	return -1;
}//endl Find_BF

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


