#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

//状态转移方程：f[i]=max(f[i-1]+a[i],a[i])
//其实就是，后一个如果加上前一个，更大了，那就要前一个，不然就把前面的扔掉，从后一个单独开始

int a[200005];
int ans[200005];
int main()
{

	int sum = -99999;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	
	for (int i = 0; i < n; i++) {
		ans[i] = max(ans[i - 1] + a[i], a[i]);      //状态转移方程
		sum = max(sum, ans[i]);                     //记录出现过的最大子数列的和
	}

	cout << sum;

	return 0;
}

