
template <typename T>
void ListStack<T>::push(const T& data)
{
	Node<T> *new_node = new Node<T>(data);
	new_node->next = head;
	head = new_node;
	count++;
}

template <typename T>
void ListStack<T>::pop()
{
	if (empty())
		throw std::underflow_error("Stack underflow");
	
	Node<T> *del_node = head;
	head = head->next;
	delete del_node;
	count--;
}

template <typename T>
T& ListStack<T>::top()
{
	if (empty())
		throw std::underflow_error("Stack underflow");
	return head->data;
}

template <typename T>
bool ListStack<T>::empty() const
{
	return count == 0;
}

template <typename T>
size_t ListStack<T>::size() const
{
	return count;
}
