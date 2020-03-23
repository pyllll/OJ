
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;



//其实是个链表问题
//但是链表修改快，查询慢，而我们要先找到要插入的位置才能插入，怎么办呢
//通过一个结构体数组a，a[i]就是i

typedef struct Node {               //其实是个双向链表
	int val;                          //值
	int l;                            //l表示a[i]左边连着哪个元素
	int r;                            //r表示a[i]右边连着哪个元素
}Node;

Node a[100005];                     //结构体数组

int main()
{
	int n;
	cin >> n;
	a[1].val = 1;                     //这三行是初始化第一个元素进队以后的情况
	a[1].l = 0;
	a[1].r = 0;
	for(int i = 2; i <= n; i++){      
		int pos, dir;                   //pos是位置，dir是左边还是右边
		cin >> pos >> dir;
		a[i].val = i;                   //这里a[i]就是i啦，这样查询i的时候直接用a[i]就能找到，如果是普通的链表，只能从头就开始一个个遍历去找
		if (dir == 0) {                 //0和1分别表示左边和右边，正常插入即可
			a[i].r = pos;
			a[i].l = a[pos].l;
			a[a[pos].l].r = i;
			a[pos].l = i;
		}
		else {
			a[i].l = pos;
			a[i].r = a[pos].r;
			a[a[pos].r].l = i;
			a[pos].r = i;
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int pos;                         //pos是要删除的元素
		cin >> pos;
		if (a[pos].val!=-1) {            //删掉的元素val置为-1
			a[pos].val = -1;
			a[a[pos].l].r = a[pos].r;
			a[a[pos].r].l = a[pos].l;
		}
	}
	int tag = a[0].r;                  //从0开始，通过右指针r遍历链表
	while (a[tag].val > 0) {
		cout << tag << " ";
		tag = a[tag].r;
	}
	return 0;
}
