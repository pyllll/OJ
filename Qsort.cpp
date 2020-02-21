#include <iostream>
#include <vector>
#include <math.h> 
#include <algorithm>
using namespace std;

class C {
public:
	int a;
	int b;
	int g;
	int k;
};




void Qsort(vector<int> &v, int low, int high) {
	if (low < high) {
		int mid = v[(low + high) / 2];  //取中间数
		int i = low, j = high;
		while (i <= j) {                  
			while (v[i] < mid)            //左边小就左边++
				i++;
			while (v[j] > mid)            //右边大就右边--
				j--;
			if (i <= j) {                 //如果有一组不满足排序条件，就交换
				swap(v[i], v[j]);
				i++;
				j--;
			}
		}
		if(low<j)                       //递归排序左边部分
			Qsort(v, low, j);
		if(i<high)                      //递归排序右边部分
			Qsort(v, i, high);
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	//sort(v.begin(), v.end());
	Qsort(v, 0, v.size() - 1);
	for (int i = 0; i < v.size(); i++) {
		if (i == 0)
			cout << v[i];
		else
			cout << " " << v[i];
	}
	return 0;
}

