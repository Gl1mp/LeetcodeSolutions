/*
LeetCode 27. 移除元素
思路：双指针，保留不等于 val 的元素，覆盖到数组前面
时间复杂度：O(n)
空间复杂度：O(1) 原地算法
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		int size = nums.size();
		int k = 0;
		int i = 0;
		for (i = 0; i < size; i++)
		{
			if (nums[i] != val)
			{
				nums[k] = nums[i];
				k++;
			}
		}
		return k;
	}
};

int main()
{
	vector<int> nums = {1, 9, 3, 9, 5, 7, 8, 3, 4, 9, 9};
	int k = Solution().removeElement(nums, 9);
	cout << k << endl;
	for (int i = 0; i < k; i++)
	{
		cout << nums[i] << endl;
	}
}
