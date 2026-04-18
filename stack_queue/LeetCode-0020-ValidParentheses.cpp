#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
* LeetCode 20 有效的括号
*
* 思路：
* 1. 遇到左括号入栈
* 2. 遇到右括号，检查栈顶是否匹配
* 3. 不匹配直接返回 false
* 4. 最终栈空表示全部匹配成功
*
* 时间复杂度：O(n)
* 空间复杂度：O(n)
*/

class Solution {
public:
	bool isValid(string s) {
		int size = s.size();
		stack<char> S;
		
		for (int i = 0; i < size; i++) {
			// 左括号入栈
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				S.push(s[i]);
			}
			// 右括号
			else {
				// 栈空直接不匹配
				// *这句非常重要 不加的话可能会出现读取空栈的情况！！！
				if (S.empty()) return false;
				
				// 匹配成功
				if ((S.top() == '[' && s[i] == ']') ||
					(S.top() == '(' && s[i] == ')') ||
					(S.top() == '{' && s[i] == '}')) {
					S.pop();
				}
				// 匹配失败
				else {
					return false;
				}
			}
		}
		
		// 最终栈必须为空
		return S.empty();
	}
};

// 测试
int main() {
	Solution sol;
	cout << sol.isValid("()") << endl;         // 1
	cout << sol.isValid("()[]{}") << endl;     // 1
	cout << sol.isValid("(]") << endl;         // 0
	cout << sol.isValid("([])") << endl;       // 1
	cout << sol.isValid("([)]") << endl;       // 0
	return 0;
}
