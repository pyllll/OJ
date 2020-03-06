#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

//原理：如何计算a的b次幂
//举例：b=11，即计算a的11次幂
//从二进制角度看，a^11=a^8*a^2*a^1，b=11=1011
//结合上取余操作，有(A×B)%b=((A%b)×(B%b))%b

int main()
{
	long long b, p, k;
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k<<"=";
	long long ans = 1, base = b;
	while (p > 0) {													//判断指数是否还大于0
		
		if (p & 1) {												//如果指数的二进制形式，末位为1，则ans*=base
			ans *= base;
			ans %= k;												//这里相当于A%b
		}
		base *= base;												//base自乘，这样base的值就能跟二进制的每一位相对应
		base %= k;													//这里相当于B%b
		p >> 1;														//指数的二进制形式右移一位，相当于/2
	}
	cout << ans % k;
	return 0;
}

