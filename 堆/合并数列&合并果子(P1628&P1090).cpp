#include <iostream>
#include <math.h>
#include <iomanip>  //不要忘了头文件
#include <algorithm>
using namespace std;

//这道题的关键在于，选择两个合并的时候，记录的是这两个的和，而不是堆最后留了个什么数

int heap[1000005];
int Size = 0;
int n;
//以下是堆的基本操作，就不多说了
void up(int p) {
	while (p >= 1) {
		if (heap[p] < heap[p / 2]) {
			swap(heap[p], heap[p / 2]);
			p /= 2;
		}
		else
			break;
	}
}
void down(int p) {
	int s = p * 2;
	while (s <= Size) {
		if (s < Size&&heap[s + 1] < heap[s])
			s++;
		if (heap[s] < heap[p]) {
			swap(heap[s], heap[p]);
			p = s;
			s = p * 2;
		}
		else
			break;
	}
}
void insert(int x) {
	heap[++Size] = x;
	up(Size);
}
void del() {
	heap[1] = heap[Size--];
	down(1);
}
int getTop() {
	return heap[1];
}

int main()
{
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		insert(x);
	}

	while (Size > 1) {
		int x = getTop();
		del();
		int y = getTop();
		del();
		int r = x + y;
		insert(r);
		ans += r;
	}
	cout << ans;

	return 0;
}

