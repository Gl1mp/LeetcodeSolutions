#include <iostream>
#include <vector>
using namespace std;

/*
* LeetCode 35 搜索插入位置
*
* 思路：
* 给定有序数组，要求 O(log n) 复杂度，因此使用二分查找
* 循环中：
* 1. 找到中间位置 mid
* 2. 若 mid 位置值 == target，直接返回 mid
* 3. 若 mid 位置值 > target，说明在左区间，调整右指针
* 4. 若 mid 位置值 < target，说明在右区间，调整左指针
* 循环结束未找到，i 即为目标应该插入的位置
*
* 时间复杂度：O(log n)
* 空间复杂度：O(1)
*/

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int size = nums.size();
		int i = 0, j = size - 1;
		while(i <= j)
		{
			int mid = (i + j) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				j = mid - 1;
			else
				i = mid + 1;
		}
		return i;
	}
};

// 测试用例
int main()
{
	vector<int> nums = {1, 3, 5, 6};
	
	// 测试1：存在的元素 5
	// 预期输出：2
	cout << Solution().searchInsert(nums, 5) << endl;
	
	// 测试2：不存在的元素 2
	// 预期输出：1
	cout << Solution().searchInsert(nums, 2) << endl;
	
	// 测试3：比所有数大 7
	// 预期输出：4
	cout << Solution().searchInsert(nums, 7) << endl;
	
	// 测试4：比所有数小 0
	// 预期输出：0
	cout << Solution().searchInsert(nums, 0) << endl;
}
