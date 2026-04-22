#include <iostream>
#include <string>
using namespace std;

/*
* LeetCode 1047 删除字符串中的所有相邻重复项
* 解法1：字符串模拟栈（最推荐、最好写、最好理解）
* 思路：
* 用 string 当作栈
* stk.back() 就是栈顶
* 相同就弹栈，不同就入栈
* 最后直接返回 string 即可
* 复杂度：时间 O(n)，空间 O(n)
*/
//class Solution
//{
//public:
//	string removeDuplicates(string s)
//	{
//		string stk;  // 用字符串直接模拟栈
//		
//		// 遍历每个字符
//		for (char c : s)
//		{
//			// 如果栈不为空，且当前字符 == 栈顶 → 重复，删除栈顶
//			if (!stk.empty() && c == stk.back())
//				stk.pop_back();
//			// 否则入栈
//			else
//				stk.push_back(c);
//		}
//		
//		// 最终栈里的内容就是答案
//		return stk;
//	}
//};

/*
* LeetCode 1047 删除字符串中的所有相邻重复项
* 解法2：双指针（原地栈）（better）
* 思路：
* left  ：指向栈顶位置
* right ：遍历字符串的指针
* 1. s[right] == s[left] → 重复，left--（弹栈）
* 2. 否则 → 入栈 s[++left] = s[right]
* 3. 最后截取 0 ~ left 就是答案
* 复杂度：时间 O(n)，空间 O(1)
*/
class Solution
{
public:
	string removeDuplicates(string s)
	{
		int left = 0, right;
		for (right = 1; right < (int)s.size(); right++)
		{
			// 当前字符 == 栈顶 → 消除重复（必须加上栈不空的判断）
			if (left != -1 && s[right] == s[left])
				left--;
			// 否则入栈
			else
				s[++left] = s[right];
		}
		// 截取结果
		return s.substr(0, left + 1); 
	}
};

int main()
{
	string str = "abbaca";
	cout << Solution().removeDuplicates(str);
}
