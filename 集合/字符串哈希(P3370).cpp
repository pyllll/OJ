#include <iostream>
#include <math.h>
#include <string>
#include<string.h>
using namespace std;

//这是两次哈希的版本哦
//哈希就是一个像函数一样的东西，你放进去一个值，他就会还给你另一个值，这里就是把字符串丢进去，返回一个对应的哈希值
//进制哈希就是规定一个进制base，让字符串中的每个字符都对应为一个数，那么一个字符串就对应了一个数。然后再对一个数取模（好像这个数越大结果越准确？）
//但是哈希是会冲突的。避免冲突的办法，1是冲突时加上一个质数，2是多重哈希


typedef struct Node {
	long long x, y;
}Node;

long long base=233;
Node a[10005];
long long mod = 99999999;
long long mod2 = 14578965;
long long hashs(string s) {
	long long r = 0;
	for (int i = 0; i < s.length(); i++) {
		r = (r*base + (long long)s[i]) % mod;
	}
	return r;
}

long long hashs2(string s) {
	long long r = 0;
	for (int i = 0; i < s.length(); i++) {
		r = (r * base + (long long)s[i]) % mod2;
	}
	return r;
}
int ans = 1;

bool cmp(Node a,Node b) {
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[i].x = hashs(s);
		a[i].y = hashs2(s);
	}
	sort(a, a + n, cmp);
	for (int i = 1; i < n; i++) {
		if (a[i].x != a[i - 1].x || a[i].y != a[i].y)
			ans++;
	}
	cout << ans;
	return 0;
}

