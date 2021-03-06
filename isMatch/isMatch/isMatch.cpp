// isMatch.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<vector>
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


// 递归算法
//https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-he-di-gui-bi-jiao-fang-fa-shi-xia/
/*
算法实现
dp[i][j]表示s字符串的前i字符和p字符串的前j个字符匹配情况，匹配值则为1，否则为0；
状态转移方程：
1. s[0]=p[0] || p[0]='.' dp[0][0] = 1

class Solution {
public:
    // 动态规划
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();
        if(p.empty()) return s.empty();
        vector<vector<bool>> dp(ns+1, vector<bool>(np+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= np; i++){
            if(i-2 >= 0 && p[i-1] == '*' && p[i-2]){
                dp[0][i] = dp[0][i-2];
            }
        }
        
        for(int i = 1; i <= ns; i++){
            for(int j = 1; j <= np; j++){
                if(p[j-1] == s[i-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                if(p[j-1] == '*'){
                    bool zero, one;
                    if(j-2 >= 0){
                        zero = dp[i][j-2];
                        one = (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j];
                        dp[i][j] = zero || one;
                    }
                }
            }
        }
        return dp[ns][np];
    }
};


*/







int main()
{
	Solution sol;

	bool res = sol.isMatch("a", "b");
	cout << res << endl;
    return 0;
}




