#include "Joseph.h"
LinkList *MakeList(int n, int a[]) {
	LinkList *p, *q, *h;
	h= p = new LNode;
	p->num = 1;
	p->code = a[0];
	int i;
	for (i = 1; i<n; i++) {
		q = new LNode;
		q->code = a[i];
		q->num = (i + 1);
		p->next = q;
		p = q;
	}
	p->next = h;
	return h;
}
void FindJoseph(LinkList *L) {
	int m, i;
	LinkList *p, *q=NULL, *s;
	p = L;
	cout<<"请输入m的数值：";
	cin >> m;

	printf("出列顺序是:");
	while (p->next != p) {
		for (i = 1; i<m; i++){
			q = p;
			p = p->next;
		}
		cout << p->num << "  ";
		m = p->code;
		s = p;
		q->next = p->next;
		p = p->next;
		free(s);
	}

	cout << p->num << "  " << endl;
}
