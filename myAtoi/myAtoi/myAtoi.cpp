// myAtoi.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int res = 0;
		int flag = 1;   // 正整数还是负整数标志
		int i = 0;
		while (str[i] == ' ') i++;
		if (str[i] == '-') flag = -1;
		if (str[i] == '+' || str[i]=='-') i++;  //整号或者负号后面必须接数字，否则为无效值
		for (; i < str.size(); i++)
		{
			
			if (isdigit(str[i]))
			{
				// 如下if校验溢出情况
				if (res > INT_MAX / 10 || ((res == INT_MAX / 10) && (str[i] - '0' > 7))){
					return (flag>0? INT_MAX:INT_MIN);
				}
				res = res * 10 + (str[i] - '0');
			}
			else
			{
				break;    //异常情况，有无效字符，则退出for循环
			}
		}
		return (flag > 0 ? res : -res);
	}
};

int main()
{
	Solution solInstance;
	int result = solInstance.myAtoi("-2123+");
	cout << result << endl;
    return 0;
}

