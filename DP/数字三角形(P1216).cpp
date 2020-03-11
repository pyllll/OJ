#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

//动态规划，要整一个状态转移方程，就是k到k+1的递推式子
//这道题，自下而上做，对于每一个点，下面要是最大的，加上这个点的值，才有可能是最大的
//也就是说，要符合最优子结构性质，最优策略的子策略也是最优策略
//好像动态规划都是从后往前多一点


int a[1005][1005];
int f[1005][1005];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {												//读入数据
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
			f[i][j] = a[i][j];
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];				//这就是状态转移方程吗，i了i了
		}																		
	}

	cout << f[0][0];
	return 0;
}

