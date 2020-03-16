#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

//一段low到mid到high的数列，要找到这段数列中的最大子数列，必然是三种情况
//第一种：全在mid左边
//第二种：全在mid右边
//第三种：一部分在mid左，一部分在mid右
//第1,2种只要递归即可，第三种要分别求出两边最大的然后拼起来。

int n;
int find_max_cross_subarray(int a[], int low, int mid, int high) {      //求第三种的最大子数列
	
	int lsum = -9999999, rsum = -9999999, sum = 0;                        //lsum表示左边最大的，rsum表示右边最大的
	for (int i = mid; i >= low; i--) {                                    //求以mid结尾的最大子数列
		sum += a[i];
		if (sum > lsum)
			lsum = sum;
	}
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {                               //求以mid开头的最大子数列
		sum += a[i];
		if (sum > rsum)
			rsum = sum;
	}
	return lsum+rsum;                                                     //加起来
}


int find_max_subarray(int a[],int low,int high) {                       //求最大子数列的函数
	if (low == high) {                                                    //low=high表示这时的数列只有一个元素
		return a[low];
	}
	else {
		int mid = (low + high) / 2;
		int left_sum = find_max_subarray(a, low, mid);                      //第一种
		int right_sum = find_max_subarray(a, mid + 1, high);                //第二种
		int cross_sum = find_max_cross_subarray(a, low, mid, high);         //第三种
		return max(max(left_sum, right_sum), cross_sum);                    //取最大
	}

}
int a[200005];
int main()
{

	int sum = -99999;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int an=find_max_subarray(a, 0, n - 1);


	cout << an;

	return 0;
}
