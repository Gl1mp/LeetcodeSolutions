#include <iostream>
#include <vector>
using namespace std;

/*
* LeetCode 88 合并两个有序数组
* 解法1：辅助数组 + 正向双指针（暴力解法）
* 思路：
* 1. 创建一个大小为 m+n 的辅助数组
* 2. 双指针分别从 nums1、nums2 头部开始，从小到大合并到辅助数组
* 3. 将辅助数组的结果覆盖回 nums1
*
* 时间复杂度：O(m + n)
* 空间复杂度：O(m + n)
*/


/*
* LeetCode 88 合并两个有序数组
*
* 解法：从后往前双指针（最优解）
* 思路：
* 1. 利用 nums1 尾部空间，从后往前填充，避免覆盖有效元素
* 2. 三个指针分别指向 nums1 有效尾部、nums2 尾部、合并后位置
* 3. 每次将较大值放入当前位置，指针前移
* 4. 最后将 nums2 剩余元素直接复制
*
* 时间复杂度：O(m + n)
* 空间复杂度：O(1)
*/

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int ptr1, ptr2, ptr;
		ptr1 = m - 1;
		ptr2 = n - 1;
		ptr = m + n - 1;
		
		// 从后往前比较，将较大元素放入目标位置
		while (ptr1 >= 0 && ptr2 >= 0)
		{
			if (nums1[ptr1] >= nums2[ptr2])
			{
				nums1[ptr] = nums1[ptr1];
				ptr1--;
				ptr--;
			}
			else
			{
				nums1[ptr] = nums2[ptr2];
				ptr2--;
				ptr--;
			}
		}
		
		// 处理 nums2 剩余元素
		while (ptr2 >= 0)
			nums1[ptr--] = nums2[ptr2--];
	}
};

int main()
{
	vector<int> nums1 = {1, 3, 5, 7, 7, 8, 11, 13};
	nums1.resize(14);
	vector<int> nums2 = {2, 3, 4, 5, 5, 10};
	
	Solution().merge(nums1, 8, nums2, 6);
	
	for (int i = 0; i < 14; i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl;
	
	return 0;
}
