
template <typename T>
void ArrayStack<T>::push(const T& data)
{
	if (top_index == STACK_MAX_SIZE - 1)
		throw std::overflow_error("Stack overflow");
	top_index++;
	array[top_index] = data;
}

template <typename T>
void ArrayStack<T>::pop()
{
	if (empty())
		throw std::underflow_error("Stack underflow");
	top_index--;
}

template <typename T>
T& ArrayStack<T>::top()
{
	if (empty())
		throw std::underflow_error("Stack underflow");
	return array[top_index];
}

template <typename T>
bool ArrayStack<T>::empty() const
{
	return top_index == -1;
}

template <typename T>
size_t ArrayStack<T>::size() const
{
	return top_index + 1;
}
