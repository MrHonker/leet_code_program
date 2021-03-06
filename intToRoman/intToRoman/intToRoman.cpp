// intToRoman.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include<map>
using namespace std;


using MAPTOSTRING = map<int, vector<string> >;

class Solution {
public:
	string analysisNum(int num1, int num2)
	{
		//函数调用地方已做过参数校验，此处不重复校验参数
		MAPTOSTRING mapIntToString = {
			{ 0,{ "M", "MM", "MMM" } },
			{ 1,{ "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" } },
			{ 2,{ "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" } },
			{ 3,{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" } },
		};
		MAPTOSTRING::const_iterator iPairFound = mapIntToString.find(num1);   //未做容错校验，由调用函数保证输入正确性。
		cout << (iPairFound->second)[num2 - 1] << endl;
		return (iPairFound->second)[num2 - 1];
	}

	string intToRoman(int num) {
		string nullStr = "0";
		string resStr;
		int i = 0;
		int buffVal = 0;
		if (num < 1 || num>3999) return nullStr;
		while (i<=3)
		{
			buffVal = num/(int)pow(10, 3-i);
			num = num % (int)pow(10, 3 - i);
			if (buffVal != 0)
			{
				resStr += analysisNum(i, buffVal);
			}
			i++;
		};
		return resStr;
	}
};

int main()
{
	Solution sol;
	string buffString;
	buffString = sol.intToRoman(1994);
	cout << buffString << endl;
    return 0;
}

