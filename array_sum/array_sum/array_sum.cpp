// array_sum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0, j = 0;
		int index1 = 0;
		int index2 = 0;
		int sum = 0;
		vector<int> vecResult;
		vector<int>::iterator iElement = nums.begin();
		//构造冒泡法遍历
		for (; iElement != nums.end(); iElement++)
		{
			vector<int>::iterator iVec = iElement+1;
			index2 = index1 + 1;
			for (; iVec != nums.end(); iVec++)
			{
				sum = *iElement + *iVec;
				if (sum != target)
				{
					index2++;
				}
				else
				{//找到两个元素的位置并返回。
					cout << "index1 is " << index1 << "index2 is " << index2 << endl;
					vecResult.push_back(index1);
					vecResult.push_back(index2);
					return vecResult;
				}
			
			}
			index1++;	
		}
		//走到此return就是没找到,返回两个0
		cout << "there is no such 2 elements's sum is " << target << endl;
		vecResult.push_back(0);
		vecResult.push_back(0);
		return vecResult;
	}
};

void printVec(vector<int> vecParam)
{
	cout << "the position in vector is:" << endl;
	vector<int>::iterator iVector = vecParam.begin();
	for (; iVector != vecParam.end(); iVector++)
	{
		cout << *iVector << " ";
	}
}

int main()
{
	vector <int> num;
	num.push_back(2);
	num.push_back(7);
	num.push_back(11);
	num.push_back(15);

	Solution sol;
	vector<int> vecRetval(2, 0);
	vecRetval = sol.twoSum(num, 9);
	printVec(vecRetval);
    return 0;
}

