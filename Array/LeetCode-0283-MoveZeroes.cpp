#include <iostream>
#include <vector>
using namespace std;

/*
* LeetCode 283 移动零
*
* 思路：
* 利用 cnt 记录当前遇到的 0 的个数
* 遍历数组，遇到非零元素就向前移动 cnt 个位置
* 当前位置置 0，最终所有 0 都会被挤到数组末尾
*
* 注：当cnt为0的时候要单独讨论！因为我在移动后会将此处改为0（避免了再循环一次把尾部全部改为0）
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int size = nums.size();
		int i = 0, cnt = 0;
		while (i < size)
		{
			if (nums[i] == 0)
				cnt++;
			else if (cnt != 0)
			{
				nums[i - cnt] = nums[i];
				nums[i] = 0;
			}
			i++;
		}
	}
};

int main()
{
	vector<int> nums = {0, 11, 5, 0, 7, 0, 2, 11, 0, 22};
	Solution().moveZeroes(nums);
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		cout << nums[i] << " ";
	}
	return 0;
}
