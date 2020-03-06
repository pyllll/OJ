#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class C {
public:
	int x;
	int y;
};

void Merge(int a[],int low,int mid,int high) {
	int i = low, j = mid + 1, k = 0;
	vector<int> v;
	while (i <= mid && j <= high) {										//把两个段有序的存放到新的向量v中
		if (a[i] <= a[j]) {												//升序
			v.push_back(a[i]); i++;
		}
		else {
			v.push_back(a[j]); j++;
		}
	}
	while (i <= mid)													//如果有一个段没有放完，把没放完的全部放到v中
		v.push_back(a[i++]);
	while (j <= high)
		v.push_back(a[j++]);
	for (int i = low; i <= high; i++,k++)								//v中的元素都是有序的，这里把他依次放到原数组的对应位置中
		a[i] = v[k];													//这样一来，原数组的对应位置的这两小段，就是有序的了
}



void Mergesort(int a[],int low,int high) {								//递归执行合并操作
	if (low < high) {													//
		int mid = (low + high) / 2;										//两个段的中间点
		Mergesort(a, low, mid);											//递归左边
		Mergesort(a, mid + 1, high);									//递归右边
		Merge(a, low, mid, high);										//把low到high这一段拿去归并排序。这一段又在mid处分为2小段
	}
}

int main()
{
	int a[10] = { 5,1,9,3,7,4,8,6,2,0 };
	Mergesort(a, 0, 9);
		
	return 0;
}

