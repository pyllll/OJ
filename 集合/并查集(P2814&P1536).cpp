#include <iostream>
#include <math.h>
using namespace std;

//并查集是简单的版本，还有升级版本link-cut-tree(动态树)，先放着以后看吧
//并查集是一个森林，初始化数组a使得每一个元素都是一颗单独的树
//find操作找到x的根，combine操作让x的根成为y的根的父亲。相当于把y所在的这一棵树插在了x的根上。


int a[5005];
int b[5005];
int find(int x) {
	if (a[x] == x)                            //如果a[x]=x，说明这棵树只有一个元素，x本身就是根
		return x;
	else {
		return find(a[x]);                      //否则，递归找根
	}
}

void combine(int x,int y) {
	a[find(y)] = find(x);                     //让x的根成为y的根的父亲
}

int main()
{
	int n;
	cin >> n;
	while (n != 0) {
		int m;
		cin >> m;
		for (int i = 1; i <= n; i++) {          //初始化数组a，让每一个元素成为一棵树
			a[i] = i; b[i] = 0;
		}
		for (int i = 0; i < m; i++) {           //构建并查集
			int x, y;
			cin >> x >> y;
			combine(x, y);
		}
		for (int i = 1; i <= n; i++) {          //路径压缩，让同一棵树中的结点的父亲都变为这棵树的根(本来数组a中的a[i]存的是i的父亲，压缩以后存的是i所在的这棵树的根)
			a[i] = find(a[i]);
		}
		for (int i = 1; i <= n; i++) {          //i是根则b[i]+1，数组b记录了树的个数
			b[a[i]]++;
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {          //b[i]中有几个元素不为0则表明有几棵树
			if (b[i] != 0)
				ans++;
		}
		cout << ans << endl;
		cin >> n;

	}

	return 0;
}

