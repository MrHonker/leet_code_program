 // longestPalindrome.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
回文串是中心对称的，所以只要找到回文串的中心，然后向两边扩展即可。这里的中心位置我们要奇偶分开考虑，
如果字符串长度是奇数的话，中心就只有一个元素；如果字符串是偶数的话，那么中心是两个元素。
*/


//暴力破解，遍历字符串，找出最长的回文字符串，利用反转后相等的特性，来识别回文字符串
/*
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) {
			return s;
		}
		string res = s.substr(0, 1);
		for (int i = 0; i < s.length(); i++) {
			for (int j = i + 1; j <= s.length(); j++) {
				string k = s.substr(i, j-i);
				string rk = k;
				reverse(rk.begin(), rk.end());
				if (!k.compare(rk) && k.length()>res.length()) {
					res = k;
				}
			}

		}

		return res;
	}
};
*/

//动态规划解法，时间复杂度O(n2)
/*动态规划转移方程
初始状态：
dp[i][i]=1; //单个字符是回文串
dp[i][i+1]=1 if s[i]=s[i+1]; //连续两个相同字符是回文串
https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-c-by-gpe3dbjds1/
另外还有马拉车算法，有时间了解，时间复杂度O(n)
https://leetcode-cn.com/problems/longest-palindromic-substring/solution/5-zui-chang-hui-wen-zi-chuan-cc-by-bian-bian-xiong/

*/

class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0;
		int substr_len = 1;
		int str_len = s.length();
		//用vector定义二维数组，不懂的请自行在搜索该定位方式；
		vector<vector<int> > dp(str_len, vector<int>(str_len));
		// 1.先将单个字符和两个连字符的情况赋值，单个字符、两个相邻的连字符相等dp[i][j]=1
		for (int i = 0; i < str_len; i++)
		{
			dp[i][i] = 1;
			if (i < str_len - 1)
			{
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = 1;
					start = i;
					substr_len = 2;
				}
			}
		}
		// 2. 遍历各个长度的子串，长度从3到str_len，最后记录最长子串的起始位置和长度；
		// 子串起始长度从3开始，长度为1和2的上面已经覆盖
		int substr_size = 3;
		int end_cnt = 0;
		for (; substr_size <= str_len; substr_size++)
		{
			for (int i = 0; i < str_len - substr_size + 1; i++)
			{
				end_cnt = i + substr_size - 1;
				//满足回文字符串两个条件
				if (s[i] == s[end_cnt] && dp[i + 1][end_cnt-1])
				{
					dp[i][end_cnt] = 1;
					//有多个长度为n的字符串，以第一个为准，满足用例需要
					if (substr_size > substr_len)
					{
						start = i;
						substr_len = substr_size;
					}

				}
			}
		}
		return s.substr(start, substr_len);
	}
};

int main()
{
	Solution sol;
	string input_str = "abacab";
	cout << input_str.length() << endl;
	//string res = input_str.substr(4, 2);
	string res = sol.longestPalindrome(input_str);
	cout << "the longestPalindrome is: " << res << endl;
    return 0;
}

