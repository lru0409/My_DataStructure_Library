#ifndef ARRAY_STACK
# define ARRAY_STACK

# include <cstddef>
# include <stdexcept>

# define STACK_MAX_SIZE 100

template <typename T>
class ArrayStack
{
	private:
		T array[STACK_MAX_SIZE];
		int top_index;
	
	public:
		ArrayStack() : top_index(-1) {}

		void push(const T& data);
		void pop();
		T& top();
		bool empty() const;
		size_t size() const;
};

# include "ArrayStack.tpp"

#endif