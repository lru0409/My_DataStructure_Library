#ifndef LIST_STACK
# define LIST_STACK

# include "Node.hpp"
# include <stdexcept>

template <typename T>
class ListStack
{
	private:
		Node<T> *head;
		int count;
	
	public:
		ListStack() : head(nullptr), count(0) {}

		void push(const T& data);
		void pop();
		T& top();
		bool empty() const;
		size_t size() const;
};

# include "ListStack.tpp"

#endif