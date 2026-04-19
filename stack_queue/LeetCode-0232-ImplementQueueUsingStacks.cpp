#include <iostream>
#include <stack>
using namespace std;

/*
* LeetCode 232 用栈实现队列
* 核心：双栈模拟
* pushStack 常驻数据
* popStack 负责出队，空时才倒数据
*/
class MyQueue {
public:
	stack<int> pushStack; // 入队栈：数据常驻
	stack<int> popStack;  // 出队栈：取数据专用
	
	MyQueue() { }
	
	// 入队：永远只进 pushStack
	void push(int x) {
		pushStack.push(x);
	}
	
	// 出队：popStack 为空则把数据全部倒过来再取
	int pop() {
		int num;
		if (popStack.empty())
		{
			while(!pushStack.empty())
			{
				popStack.push(pushStack.top());
				pushStack.pop();
			}
		}
		num = popStack.top();
		popStack.pop();
		return num;
	}
	
	// 取队首：和 pop 逻辑一样，只是不删除
	int peek() {
		if (popStack.empty())
		{
			while(!pushStack.empty())
			{
				popStack.push(pushStack.top());
				pushStack.pop();
			}
		}
		return popStack.top();
	}
	
	// 两个栈都空，队列才是空
	bool empty() {
		return popStack.empty() && pushStack.empty();
	}
};

// 测试用例
int main()
{
	MyQueue myQueue;
	myQueue.push(1);
	myQueue.push(2);
	cout << myQueue.peek() << endl; // 1
	cout << myQueue.pop() << endl;  // 1
	cout << myQueue.empty() << endl; // 0 (false)
}
