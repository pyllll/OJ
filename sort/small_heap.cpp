#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int heap[1000];                                     //堆数组
int Size = 0;                                       //初始化堆大小为0
void up(int p){                                     //上浮
	while (p > 1) {                                   //如果当前位置在堆顶，就不上浮了
		if (heap[p] < heap[p / 2]) {                    //p/2是p的父亲。如果p的孩子比p小，则交换
			swap(heap[p], heap[p / 2]);
			p /= 2;
		}
		else
			break;
	}
}
void down(int p) {                                  //下沉
	int s = p * 2;                                    //p*2是p的做孩子，p*2+1是p的右孩子
	while (s <= Size) {                               //如果s超过堆大小，就不下沉了
		if (s < Size&&heap[s] > heap[s + 1])            //如果p有右孩子，并且右孩子比左孩子小，那么选择右孩子跟p比较
			s++;
		if (heap[s] < heap[p]) {                        //如果p的孩子比p小，则交换
			swap(heap[s], heap[p]);
			p = s;
			s = p * 2;
		}
		else
			break;
	}
}
void push(int val) {                                //插入元素
	heap[++Size] = val;                               //在堆底插入
	up(Size);
}
void pop() {                                        //删除元素
	heap[1] = heap[Size--];                           //把堆顶元素换到堆底
	down(1);
}
int getTop() {                                      //返回堆顶元素
	return heap[1];
}
int main()
{
	for (int i =1 ; i <= 7; i++) {                    //建堆
		int x; cin >> x;
		push(x);
	}
	
	for (int i = 1; i <= 7; i++) {                    //循环输出堆顶元素
		int x = getTop();
		cout << x << " ";
		pop();
	}

	return 0;
}

