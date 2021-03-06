// string_no_reapted_length.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
该方法采用滑窗法，重点是要找准滑窗的左右边沿；
1. 滑窗的右边沿用i表示，i为对string字符串的遍历；
2. 左边沿用left表示，left初始化为-1，当最长子串从第一个子串开始也满足，当i遍历到滑窗中的字符时，只需要将left指向滑窗中该字符串，新的子串
   从下一个字符开始，并且将该字符的位置更新为当前的i；
3. res为滑窗的大小，当左边沿-右边沿(i-left)大于之前的res时，更新res的值；
具体解析见如下链接：
https://www.cnblogs.com/grandyang/p/4480780.html
*/


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int>symbol_slide(128, -1);
		int str_len = s.size();
		//滑窗左指针，右指针为当前的i
		int left = -1;
		// 滑窗大小
		int res = 0;
		for (int i = 0; i < str_len; i++)
		{
			left = max(left, symbol_slide[s[i]]);
			symbol_slide[s[i]] = i;
			res = max(res, i - left);
		}
		return res;
	}

};

/*  该做法会超出时间限制
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		
		// 记录子串长度
		int count = 0;
		//最长子串长度
		int max_len = 0;
		string str_sub;
		string max_str;
		//string length和size用法相同
		int string_len = s.length();
		// 构造两层字符串遍历
		for (int i = 0; i < string_len; i++)
		{
			for (int j = i; j < string_len; j++)
			{
				size_t char_pos = str_sub.find(s[j], 0);
				if (char_pos != string::npos)
				{//如果子串中找到了当前的字符
				 // 如果子串计数大于子串最大长度
					if (count > max_len)
					{
						max_len = count;
						max_str = str_sub;
					}
					str_sub.clear();
					str_sub = str_sub + s[j];
					//子串重新从该字符开始，因此count=1
					count = 1;

				}
				else
				{//如果子串中未找到当前字符串
					str_sub = str_sub + s[j];
					count++;
				}
			}
			//如果字符串中无重复字符情况或者后续子串比之前子串长的情况
			if (count > max_len)
			{
				max_len = count;
				max_str = str_sub;
			}
			//从下一个字符开始重新遍历，子串和计数都要初始化
			count = 0;
			str_sub.clear();
		}

		cout << "the max len sub string is: "<< max_str <<endl;
		return max_len;
	}
};
*/


int main()
{
	Solution sol;
	string s = "abcdeb123";
	int str_len = sol.lengthOfLongestSubstring(s);
	cout << "the max length is: " << str_len << endl;
    return 0;
}

