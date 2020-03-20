#include <iostream>
#include<queue>
#include <math.h>
#include <algorithm>
using namespace std;

//用到了优先队列，就是堆做的
//贪心解法，问题的关键在于，理解从地点1出发以后是不回头的，因为如果回头去了某一个地点，可以在之前还在这个地点的时候就再钓一次鱼
//例如，如果要从地点3回到地点2，可以在刚到地点2时多钓几次鱼，在往后走，都在了呀

class C {
public:
	int f;
	int d;
	int number;
	int t;
	bool operator <(C x)const {               //重载操作符（这里不是很懂，但是自己手写堆这个问题不用考虑）
		return f < x.f;
	}
};


C a[1000005];
int n,h;                                    //n表示地点总数，h表示时间总数
long long ans = 0;                          //ans表示答案
priority_queue<C> q;                        //优先队列q
  

int main()
{
	cin >> n >> h;
	h*= 12;                                   //小时转换为5分钟制
                                            //以下3个for循环读入数据
	for (int i = 1; i <= n; i++) {
		cin >> a[i].f;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].d;
	}
	for (int i = 2; i <= n; i++) {
		cin >> a[i].t;
	}
	a[1].t = 0;

	for (int i = 1; i <= n; i++) {            //i表示最后停留的地点，从第一个地点遍历过去
		long long now_ans = 0;                  //以i为最后地点的最大得分
		h -= a[i].t;                            //减掉地点i耗费的时间
		while(!q.empty())                       //清除上一次循环的影响
			q.pop();
		for (int j = 1; j <= i; j++)            //地点1到i入队
			q.push(a[j]);
		for (int k = 1; k <= h; k++) {          //每一个5分钟能钓到的最大鱼数
			C x = q.top();                        //堆顶是最大的
			if(x.f>0)                             
				now_ans += x.f;
			x.f -= x.d;                           //减掉d后入队
			q.pop();
			q.push(x);
		}
		ans = max(ans, now_ans);
	}
	cout << ans;
	return 0;
}

