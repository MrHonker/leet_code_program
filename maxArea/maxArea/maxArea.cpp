// maxArea.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

/*初步看本题有暴力求解和动态规划两种解法*/

/*1. 暴力求解,会超出时间限制
class Solution {
public:
	int maxArea(vector<int>& height) {
		int vecSize = height.size();
		int heightDiff = 0;
		int maxSquare = 0;
		int buffSquare = 0;
		int maxI = 0;
		int maxJ = 0;
		for (int i = 0;i < vecSize;i++)
		{
			for (int j = i + 1;j < vecSize;j++)
			{
				heightDiff = (height[j] > height[i])? height[i]: height[j];
				buffSquare = heightDiff * (j - i);
				if (buffSquare > maxSquare)
				{
					maxSquare = buffSquare;
					maxI = i;
					maxJ = j;
				}

			}
		}
		cout << "vecSize=" << vecSize << endl;
		cout << "maxI=" << maxI << endl;
		cout << "maxJ=" << maxJ << endl;
		return maxSquare;
		
	}
};
*/
//2. 双指针法，时间复杂度O(n)
/*
https://leetcode-cn.com/problems/container-with-most-water/solution/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/
每次向前或者向后移动一根柱子，其实是是减少了一系列搜索
*/
class Solution {
public:
	int maxArea(vector<int>& height) {
		int vecSize = height.size();
		int heightDiff = 0;
		int maxSquare = 0;
		int buffSquare = 0;
		int maxI = 0;
		int maxJ = 0;
		int i = 0;
		int j = vecSize - 1;
		int minHeight = 0;
		while (i < j)
		{
			minHeight= min(height[i], height[j]);
			buffSquare = minHeight * (j - i);
			maxSquare = max(buffSquare, maxSquare);
			if (maxSquare == buffSquare)
			{
				maxI = i;
				maxJ = j;
			}
			if (height[i] < height[j])
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		cout << "maxI=" << maxI << endl;
		cout << "maxJ=" << maxJ << endl;
		return maxSquare;
		
	}
};



int main()
{

	Solution sol;
	vector<int>heightArray = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int maxArea = sol.maxArea(heightArray);
	cout << maxArea << endl;
    return 0;
}

