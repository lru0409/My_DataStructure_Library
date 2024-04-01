// #include "ArrayBasedStack/ArrayStack.hpp"
#include "LinkedListBasedStack/ListStack.hpp"
#include <iostream>
using namespace std;

// typedef ArrayStack<int> Stack;
typedef ListStack<int> Stack;

int main()
{
	Stack stack;
	cout << "========== Initial Stack ==========\n";
	cout << "size		: " << stack.size() << '\n';
	cout << boolalpha << "Is Empty	: " << stack.empty() << "\n\n";

	cout << "========== Push Test ==========\n";
	for(int i = 1; i <= 10; i++)
		stack.push(i);
	cout << "size		: " << stack.size() << '\n';
	cout << boolalpha << "Is Empty	: " << stack.empty() << '\n';
	cout << "top		: " << stack.top() << "\n\n";

	cout << "========== Change Top Test ==========\n";
	stack.top() = 100;
	cout << "top		: " << stack.top() << "\n\n";

	cout << "========== Pop Test ==========\n";
	while(!stack.empty())
	{
		cout << "popped data : " << stack.top() << '\n';
		stack.pop();
	}
	cout << "size		: " << stack.size() << '\n';
	cout << boolalpha << "Is Empty	: " << stack.empty() << "\n\n";

	return 0;
}

