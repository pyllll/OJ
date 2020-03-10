#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

//类似于快排，选一个mid，把比mid小的放到mid左边，比mid大的放到mid右边，但不保证左右的顺序
//那么mid左边有X个，右边有Y个，相等的mid有Z个
//k小于X，则答案在X中。k大于X且小于Y，则这个元素就是答案。k大于X+Z，则答案在Y中
//递归执行即可

int a[5000005];
int k;
void f(int low,int high) {				//搜索函数
	int l = low, h = high;					//设定左右指针							
	int mid = a[(l+h)/2];
	while (l <= h) {							  //当左指针小于等于右指针时
		while (a[l] < mid)						//把小于mid的放到左边，大于mid的放到右边
			l++;
		while (a[h] > mid)
			h--;
		if (l <= h) {
			swap(a[l], a[h]);
			l++; h--;
		}
	}
									              //这样整个数组变为：low—右指针h—左指针l—high
									              //low到h是小于mid的，h到l是等于mid的，l到high是大于mid的
	if (k <= h)									  //根据k和l,h的大小,递归执行或输出结果							
		f(low, h);
	else if (k >= l)
		f(l, high);
	else
		cout << a[h + 1];
}

int main()
{
	int n;
	cin >> n;
	cin >> k;
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	f(0, n - 1);
  //STL中有专门的函数来解决这个问题，调用以下函数
  //nth_element(a, a + k, a + n);
  //a[k]就是答案，但这个函数不保证k左边和右边的元素的有序性
	return 0;
}

