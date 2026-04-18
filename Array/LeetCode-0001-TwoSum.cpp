#include <iostream>
#include <vector>
using namespace std;

/*
LeetCode 1. 两数之和
思路：暴力枚举，双重循环遍历所有数对
时间复杂度：O(n²)
空间复杂度：O(1)
*/

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (nums[i] + nums[j] == target)
					return {i, j};
			}
		}
		return {};
	}
};

int main()
{
	vector<int> nums = {1, 9, 3, 9};
	vector<int> ret = Solution().twoSum(nums, 18);
	cout << ret[0] << " " << ret[1];
}
