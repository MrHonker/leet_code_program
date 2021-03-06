// findMedianSortedArrays.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
该题目主要考察二分法排序，题目的难点主要在于要给两个有序数组都要做二分法排序；
1. 得出数组的长短，需要找出短数组，并操作短数组的二分高低门限；
2. 需要将长短两个数组都要二分，得到左右两部分；
3. 显然LMax1<RMin1,LMax2<Rmin2,当LMax1<Rmin2且LMax2<Rmin1时，记得到左部门的最大值max(LMax1,LMax2),右部分的最小值min(RMin1,Rmin2),
   （max+min）/2即等于要求的中位数；
4. 当有LMax1>Rmin2且LMax2>Rmin1时,需要调整割的范围，注意只调整短数组c1；
5. 无论数组长度是基数还是偶数，如下结论总成立：
LMaxi = (Ci-1)/2 位置上的元素
RMini = Ci/2 位置上的元素
具体解析如下：
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/4-xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-shu/
*/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int vec_length1 = nums1.size();
		int vec_length2 = nums2.size();

		if (vec_length1 > vec_length2)
		{
			cout << "sort the para of the function" << endl;
			return findMedianSortedArrays(nums2, nums1);
		}

		int hi = 2*vec_length1, lo = 0;
		//记录和nums1和num2割（cut）的位置
		int c1 = 0, c2 = 0;
		//nums1的左侧最大值和右侧最小值
		int left_max1 = 0, right_min1 = 0;
		//nums2的左侧最大值和右侧最小值
		int left_max2 = 0, right_min2 = 0;
		while (lo <= hi)
		{
			c1 = (lo + hi) / 2;
			c2 = vec_length1 + vec_length2 - c1;
			left_max1 = (c1 == 0) ? INT_MIN: nums1[(c1 - 1) / 2];
			right_min1 = (c1 == 2 * vec_length1) ? INT_MAX: nums1[c1/2];
			left_max2 = (c2 == 0) ? INT_MIN: nums2[(c2 - 1)/2];
			right_min2 = (c2 == 2 * vec_length2) ? INT_MAX: nums2[c2/2];

			// 只对较短的数组c1进行操作
			if (left_max1 > right_min2)
			{//当数组1的左部门较大时，将c1的高门限降低；
				hi = c1 - 1;
			}
			else if (left_max2 > right_min1)
			{//当数组2的左部分较大时，将c1的低门限加大；
				lo = c1 + 1;
			}
			else
			{
				break;
			}
		}
		cout << "calculate the result! " << max(left_max1, left_max2)<<" "<< min(right_min1, right_min2)<<  endl;
		return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0;

	}
};

int main()
{
	Solution sol;
	vector<int> vec_input1;
	vector<int> vec_input2;
	vec_input1.push_back(1);
	vec_input1.push_back(2);
	//vec_input1.push_back(5);
	vec_input2.push_back(3);
	vec_input2.push_back(4);
	double midVal = sol.findMedianSortedArrays(vec_input1, vec_input2);
	cout << "the middle value is:" << midVal << endl;

    return 0;
}

