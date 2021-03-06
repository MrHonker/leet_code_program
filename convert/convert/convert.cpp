// convert.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 方法1. 采用从上到下从左到右的方式将字符串路录入到二维数组中
/*总结：
1. 该方法很精妙的地方在于定义了一个多维string vector<string> string_element();
2. 对z字形进行遍历，设置了reverse_flag变量，string_element[num] +=c;
3. 当row =0 或者numRows-1时，需要反转
4. 请熟悉遍历这种遍历string的方式： for(char& c : s)

https://leetcode-cn.com/problems/zigzag-conversion/solution/6-z-zi-xing-bian-huan-c-c-by-bian-bian-xiong/
方法2. z字形每个字符的坐标起始时有规律的，找到这种规律然后遍历string，有空再实现；

*/

class Solution {
public:
	string convert(string s, int numRows) {
		//行数索引
		int row_num = 0;
		bool  reverse_flag = false;
		if (numRows <= 1)
		{
			return s;
		}
		//1. 构造一个vector<string>数组，这是本地的精妙之处
		cout << min(int(s.length()), numRows) << endl;
		vector<string> string_element(min(int(s.length()),numRows));

		for (char& c : s)
		{
			string_element[row_num] += c;
			if (row_num == 0 || row_num == (numRows - 1))
			{
				reverse_flag = !reverse_flag;
			}
			row_num += reverse_flag ? 1 : -1;
		}

		string str_result;
		for (string& str_row : string_element)
		{
			str_result += str_row;
		}
		return str_result;
	}
};



int main()
{
	Solution sol;
	string str_input = sol.convert("LEETCODEISHIRING", 4);
	cout << str_input << endl;
    return 0;
}

