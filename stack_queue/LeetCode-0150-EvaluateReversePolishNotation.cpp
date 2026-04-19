#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
* LeetCode 150 逆波兰表达式求值
* 方法：栈
* 遇到数字入栈，遇到符号取出两个数计算，结果重新入栈
* 时间 O(n)，空间 O(n)
*/
class Solution {
public:
	stack<int> S;
	
	int evalRPN(vector<string>& tokens)
	{
		int size = tokens.size();
		int b, a, num;
		
		for (int i = 0; i < size; i++)
		{
			// 判断是否是运算符
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				// 先取右操作数，再取左操作数
				b = S.top(); S.pop();
				a = S.top(); S.pop();
				
				if (tokens[i] == "+") num = a + b;
				else if (tokens[i] == "-") num = a - b;
				else if (tokens[i] == "*") num = a * b;
				else num = a / b;
				
				S.push(num);
			}
			else
			{
				// 字符串转整数，入栈
				S.push(stoi(tokens[i]));
			}
		}
		
		// 最后栈里只剩结果
		return S.top();
	}
};

// 测试用例
int main()
{
	Solution sol;
	
	vector<string> t1 = {"2","1","+","3","*"};
	cout << sol.evalRPN(t1) << endl; // 9
	
	vector<string> t2 = {"4","13","5","/","+"};
	cout << sol.evalRPN(t2) << endl; //6
	
	return 0;
}
