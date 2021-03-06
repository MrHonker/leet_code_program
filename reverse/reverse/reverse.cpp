// reverse.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "stdio.h"
#include<cmath>

using namespace std;

// 优化解法：弹出和推入数字 & 溢出前进行检查
// 只需要进行一次循环搞定弹出和推入数字
class Solution {
public:
	int reverse(int x) {
		int temp = 0;
		int recv = 0;
		int pop = 0;
		while (x != 0)
		{
			pop = x % 10;
			x = x / 10;

			temp = recv * 10 + pop;
			recv = temp;
			if (recv > INT_MAX / 10 ||
				(recv == INT_MAX && pop > 7))
			{
				return 0;
			}
			if (recv < INT_MIN / 10 ||
				(recv == INT_MIN && pop < -8))
			{
				return 0;
			}
		};
		return recv;

	}
};




/*
class Solution {
public:
	int reverse(int x) {
		//1. 先用循环把整数每个位上的数字取出来；
		int i = 0;
		int num_last = 0;
		int a[32] = {0};
		int num = x;
		int num_count = 0;
		while (num != 0)
		{
	
			num_count = num % 10;
			num = num / 10;
			a[i] = num_count;
			i++;

		};

		//2. 开始组装各位上的数字
		long long revert_num = 0;
		int j = 0;
		for (; i > 0; i--)
		{
			revert_num += a[i-1] * (long long)pow(10, j);
			j++;
		}
		// 处理溢出情况
		if (revert_num > ((int)pow(2, 31) -1) ||
			revert_num < (~(int)pow(2, 31) +1))
		{
			revert_num = 0;
		}
		return revert_num;


	}
};
*/

int main()
{
	int revert_num = -34612;
	Solution sol;
	int result = sol.reverse(revert_num);
	cout << "reverse result is: " << result << endl;
    return 0;
}


