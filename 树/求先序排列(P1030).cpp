#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include<string.h>
using namespace std;

//已知二叉树的中序和后序，求先序
//思路是，后序的最后一个元素一定是二叉树的根节点。然后在中序里找到这个元素对应的位置pos，pos左边即为左子树，右边为右子树
//中序和后序的左右子树元素位置是有对应关系的
//例如，中序ACGDBHZKX，后序CDGAHXKZB。根节点B，左子树分别是ACGD和CDGA，右子树分别是HZKX和HXKZ，都是按顺序来的
//那么相当于知道了左子树和右子树的中序和后序，重复以上步骤，问题就可以递归解决了
//同理知道先序后中序求后序，也是一样的思路，注意后序排列先递归再输出


void xian(string z,string h) {
	if (z.size() > 0) {
		char c = h[h.size() - 1];                                      //后序的第一个是
		cout << c;                                                     //因为是求先序排列，所以在递归前输出
		int pos = z.find(c);                                           //找到根节点在中序排列中的位置             
		xian(z.substr(0, pos), h.substr(0, pos));                       //递归左子树
		xian(z.substr(pos + 1), h.substr(pos,z.size()-1-pos));          //递归右子树
	}
}

int main()
{
	string zhong, hou;
	cin >> zhong >> hou;
	xian(zhong, hou);
	return 0;
}

