#include <iostream>
#include <vector>
using namespace std;

/*
* LeetCode 66 加一
*
* 思路：
* 1. 从数组尾部开始逐位 +1
* 2. 若当前位变为 10，说明需要进位：置 0，继续处理前一位
* 3. 若无需进位，直接退出
* 4. 若最高位也进位（如 999），在头部插入 1
*
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int size = digits.size();
		
		// 从最后一位开始 ++，统一处理进位
		for (int i = size - 1; i >= 0; --i) {
			digits[i]++;
			// 无进位，直接结束
			if (digits[i] != 10) break;
			// 有进位，置 0，继续循环
			digits[i] = 0;
		}
		
		// 最高位进位：999 → 1000
		if (digits[0] == 0) {
			digits.insert(digits.begin(), 1);
		}
		
		return digits;
	}
};

// 测试用例
int main() {
	vector<int> d1 = {1,2,3};   // 输出 1 2 4
	vector<int> d2 = {9};       // 输出 1 0
	vector<int> d3 = {9,9,9};   // 输出 1 0 0 0
	
	Solution sol;
	for (int num : sol.plusOne(d1)) cout << num << " "; cout << endl;
	for (int num : sol.plusOne(d2)) cout << num << " "; cout << endl;
	for (int num : sol.plusOne(d3)) cout << num << " "; cout << endl;
	
	return 0;
}
