// isPalindrome.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//官方更简单做法，直接看代码就能一目了然
class Solution {
public:
	bool isPalindrome(int x) {
		int reverseNum = 0;
		// 负数和能被10整除的数一定不是回文数
		if (x < 0 || (x % 10 == 0 && x != 0))
		{
			return false;
		}

		while (x > reverseNum)
		{
			reverseNum = reverseNum*10 + x % 10;
			x = x / 10;
		}
		// 如果是回文数，在奇数位情况下x == reverseNum / 10，偶数位情况下x == reverseNum
		return (x == reverseNum) || (x == reverseNum / 10);
	}
};


/*
class Solution {
public:
	bool isPalindrome(int x) {
		string strElement;
		string strReverse;
		int intNum = x;
		int intTmp = 0;
		while (intNum / 10 != 0)
		{
			intTmp  = (intNum < 0) ? -(intNum % 10) : (intNum % 10);
			strElement += (intTmp + '0');
			intNum /= 10;
		}
		intTmp = (intNum < 0) ? -(intNum % 10) : (intNum % 10);
		strElement += (intTmp + '0');

		if (intNum < 0)
		{
			strElement += '-';
		}
		strReverse = strElement;
		reverse(strElement.begin(), strElement.end());
		if (strElement.compare(strReverse) == 0)
		{
			return true;
		}

		return false;
	}
};*/

int main()
{
	Solution sol;
	int inputPara = 12321;
	bool flag = sol.isPalindrome(inputPara);
	cout << flag << endl;
    return 0;
}

