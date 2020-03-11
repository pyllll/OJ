#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int v[1005];    
int w[1005];
int f[105][1005];
int t, m;

//记忆化搜索方法
int dfs(int pos,int wleft) {                          //pos表示当前正在考虑第pos个物品放不放，wleft表示还剩下的空间
	if (f[pos][wleft] != -1)                            //如果不等于-1，说明已经搜索过，直接返回记忆的值
		return f[pos][wleft];
	if (pos == m)                                       //
		return f[pos][wleft]=0;
	int dfs1 = -2, dfs2 = -2;                           //dfs1和dfs2分别是不加入第pos个物品和加入第pos个物品的得分
	dfs1 = dfs(pos + 1, wleft);                         //dfs1是不加入的，直接跳到第pos+1个物品，wleft不变
	if (wleft >= w[pos])                                //如果剩下的空间还足够放入第pos个物品
		dfs2 = dfs(pos + 1, wleft - w[pos])+v[pos];       //就计算dfs2是加入的，那么下一步不仅要pos+1，wleft还要减去第pos个物品的重量
	return f[pos][wleft] = max(dfs1, dfs2);
}

int main()
{
	//读入数据
	cin >> t >> m;
	for (int i = 0; i < m; i++) {
		cin >> w[i] >> v[i];
	}
  
  //首先是1维DP方法
	/*
	for (int i = 0; i < m; i++) {
		for (int j = t; j >= w[i]; j--) {                   //从后往前，保证了不会影响之后的结果
			f[j] = max(f[j], f[j - w[i]] + v[i]);             //状态转移方程
		}
	}
	cout << f[t];
	*/

  //这是记忆化搜索方法
	memset(f, -1, sizeof(f));
	int x=dfs(0, t);
	cout << x;

	return 0;
}






