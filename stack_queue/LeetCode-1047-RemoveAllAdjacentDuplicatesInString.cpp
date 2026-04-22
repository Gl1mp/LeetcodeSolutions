#include <iostream>
#include <string>
#include <stack>
using  namespace std;

/*
* LeetCode 1047 删除字符串中的所有相邻重复项
* 方法：栈 标准解法
* 思路：
* 1. 遍历字符串
* 2. 当前字符与栈顶相同 → 弹栈（消除重复）
* 3. 否则 → 入栈
* 4. 最后将栈中元素倒序拼接成结果字符串
*/
class Solution
{
public:
	stack<char> S;
	string removeDuplicates(string s)
	{
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			// 栈空 或 字符不同，入栈
			if (S.size() == 0 || s[i] != S.top())
				S.push(s[i]);
			// 与栈顶相同，弹栈（消除重复）
			else
				S.pop();
		}
		
		// 把栈里的内容拼成字符串
		size = S.size();
		string str = "";
		for (int i = 0; i < size; i++)
		{
			str = S.top() + str;
			S.pop();
		}
		return str;
	}
};

int main()
{
	string str = "abbaca";
	string ret = Solution().removeDuplicates(str);
	cout << ret;
}
