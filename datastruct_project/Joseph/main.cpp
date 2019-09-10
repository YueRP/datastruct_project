#include "Joseph.h"
int main() {
	int i, n;
	int a[100];
	LinkList *L;
	cout << "请输入要参加约瑟夫环的人数：";
	cin >> n;
	cout << "请依次输入密码";
	for (i = 0; i<n; i++) {
	//	cout<<""
		//printf("请输入第%d个人的密码：", (i + 1));
		cin >> a[i];
	}
	L = MakeList(n, a);
	FindJoseph(L);
	system("pause");
}
