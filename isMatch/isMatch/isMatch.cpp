// isMatch.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;




/*
doMatch为递归函数，实现功能如下：
1. 当前字符匹配的条件
curMatch = (s[i]==p[i]) || p[i] == '.'
2.下一个字符为*的情况有两种：a.s字符串向后移一位，这个是*号匹配一次和多次的场景；b.p向后移两位（p[i+2]）,这个是*号匹配0次的场景；
doMatch(s, strIndex+1, p, patIndex) || (curMatch && doMatch(s, strIndex, p, patIndex+2))
3.下一个字符不为*：
（1）如果当前字符串匹配，且下一个字符不是*，则
doMatch(s, strIndex+1, p, patIndex+1)
（2）下一个字符为*，如果当前字符不匹配，且下一个字符不是*，则直接返回false
*/

int pSize;
int sSize;
class Solution {
public:


	bool doMatch(const string& str, int sIndex, const string& pattern, int pIndex)
	{
		//当pIndex和sIndex同时超过边界，说明之前的字符串相等，返回true
		if (pIndex >= pSize) return (sIndex >= sSize);
		//一定要校验sIndex < sSize，否则递归边界条件不满足。
		bool curMatch = (sIndex < sSize) && (str[sIndex] == pattern[pIndex] || pattern[pIndex] == '.');
		if ((pIndex + 1 <= pSize) && pattern[pIndex + 1] == '*')
		{
			return  doMatch(str, sIndex, pattern, pIndex + 2) || (curMatch && doMatch(str, sIndex + 1, pattern, pIndex));
		}
		else
		{
			if (curMatch)
			{
				return doMatch(str, sIndex + 1, pattern, pIndex + 1);
			}
			else
			{
				return false;
			}
		} 
	}
	bool isMatch(const string& s, const  string& p)
	{
		pSize = p.size();
		sSize = s.size();
		return doMatch(s, 0, p, 0);
	}
};



int main()
{
	Solution sol;
	bool res = sol.isMatch("mississippi", "mis*is*p*.");
	cout << res << endl;
    return 0;
}



// 递归思路能理解后，动态规划也可以理解，晚上回来实现
https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/