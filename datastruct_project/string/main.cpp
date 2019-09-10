#include "mystring.h"

int main() {
	FILE *fp1;
	int i=0,j,t=0;
	char P[1024],S[1024],txt[20]; //P储存字串，即关键词，S储存母串 ,txt储存文件名
	cout<<"请输入文本文件名："<<endl;
	gets(txt);
	cout<<"请输入关键词："<<endl;
	cin>>P;
	if((fp1=fopen(txt,"r"))==NULL) { //以只读方式打开
		cout<<"cannot open file"<<endl;
	}
	cout<<"请选择查找字串算法："<<endl;
	cout<<"BF算法，请输入1"<<endl;
	cout<<"KMP算法，请输入2"<<endl;
	int n;
	cin>>n;
	while((fgets(S,1024,fp1))!=NULL) {
		i++;
		if(n==1)j=Find_BF(S,P,0);
		else if(n==2) {
			int next[100];
			get_next1(P,next);
			j=Find_KMP(S,P,0,next);
		} 
		else cout<<"error please start again"<<endl;
		if(j!=-1) {
			cout<<"该关键词在第"<<i<<"行"<<endl;
			cout<<"该行元素为"<<endl;
			cout<<S<<endl;
			t++;
		}
	}
	if (t == 0)cout << "can not find this word" << endl;
	fclose(fp1);
}
