#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode 26. 删除有序数组中的重复项
思路：双指针（快慢指针）
k：慢指针，记录最后一个不重复元素位置
i：快指针，遍历数组
时间复杂度：O(n)
空间复杂度：O(1) 原地算法
*/

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int k = 0;
		int i = 1;
		int size = nums.size();
		for (; i < size; i++)
		{

			if (nums[k] != nums[i])
			{
				k++;
				nums[k] = nums[i];
			}

		}
		i++;
		return k + 1;
	}
};

int main()
{
	vector<int> nums = {1, 9, 3, 9, 5, 7, 8, 3, 4, 9, 9};
	int k = Solution().removeDuplicates(nums);
	for (int i = 0; i < k; i++)
	{
		cout << nums[i] << endl;
	}
}
