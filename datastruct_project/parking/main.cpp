#include "stdparking.h"
int main(){
	
	sqstack S1,S2,p; //栈 
	//S1储存车牌， S2储存时间 
	LinkQueue Q1,Q2;  //队列 
    int n,m,i,price;
    int e[3],t1,t2,po=1;//po表示进入队列车辆位置 
    char a[3];
    initstack_sq(S1);   
	initstack_sq(S2);
    cout<<"请输入停车场最大车位数："<<endl;    
    cin>>n;
    S1.stacksize=n;
    S2.stacksize=n;
	InitQueue_L(Q1);
	InitQueue_L(Q2);
	cout<<"请输入便道最大车位数："<<endl;    
    cin>>m;
    cout<<"请输入停车场收费单价："<<endl;    
    cin>>price;
    cout<<"请输入车辆信息：停车/离开；车牌号；时间："<<endl;
    while(1){
    	cin>>a>>e[1]>>e[2];
    	if(a[1]=='E')break;
    	if(a[1]!='A'&&a[1]!='D'&&a[1]!='P'&&a[1]!='W'){
    		cout<<"输入数据格式错误，请重新输入"<<endl;
    		clearstack_sq(S1);
    		clearstack_sq(S2);
			continue;
		}
		if(a[1]=='A'){
			if(S1.top==S1.stacksize-1){
		    	EnQueue_L(Q1,e[1]);
				EnQueue_L(Q2,e[2]);
				if(LengthQueue(Q1)>=m)cout<<"无候车位"<<endl;
				else cout<<"车牌号为"<<e[1]<<"的车应停在候车场"<<LengthQueue(Q1)<<"号位"<<endl;
				
				}
			else {
				push_sq(S1,e[1]),push_sq(S2,e[2]);
				cout<<"车牌号为"<<e[1]<<"的车应停在停车场"<<S1.top+1<<"号位"<<endl;
			}
			
		}
		if(a[1]=='D'){
			for(i=S1.top;i>=0;i--){
				gettop_sq(S1,t1),gettop_sq(S2,t2);
				if(e[1]==t1){
		             cout<<e[1]<<"停留时间为"<<e[2]-t2<<"应收费"<<price*(e[2]-t2)<<"元"<<endl;
					 pop_sq(S1,t1),pop_sq(S2,t2);
					 break; }
				else pop_sq(S1,t1),pop_sq(S2,t2),EnQueue_L(Q1,t1),EnQueue_L(Q2,t2);
			}
			while((S1.top<=S1.stacksize-1)&&(Q1.front!=Q1.rear)){
			    DeQueue_L(Q1,t1),DeQueue_L(Q2,t2);push_sq(S1,t1),push_sq(S2,t2);}
		}
		if(a[1]=='P')outp(S1);
		if(a[1]=='W')outw(Q1);
	} 
	
}
