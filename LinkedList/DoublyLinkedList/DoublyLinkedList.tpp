
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(int count, const T& data)
	: head(nullptr), tail(nullptr), count(0)
{
	for(int i = 0; i < count; i++)
		push_front(data);
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& ref)
	: head(nullptr), tail(nullptr), count(0)
{
	if (this != &ref)
	{
		typename DoublyLinkedList<T>::Iterator iter;
		for(iter = ref.begin(); iter != ref.end(); iter++)
			push_back(iter.node_ptr->data);
	}
}

template <typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& ref)
{
	if (this != &ref)
	{
		clear();
		typename DoublyLinkedList<T>::Iterator iter;
		for(iter = ref.begin(); iter != ref.end(); iter++)
			push_back(iter.node_ptr->data);
		count = ref.size();
	}
	return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& data)
{
	Node<T> *new_node = new Node<T>(data);
	if (head) {
		new_node->next = head;
		head->prev = new_node;
	} else {
		tail = new_node;
	}
	head = new_node;
	count += 1;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& data)
{
	Node<T> *new_node = new Node<T>(data);
	if (tail) {
		new_node->prev = tail;
		tail->next = new_node;
	} else {
		head = new_node;
	}
	tail = new_node;
	count += 1;
}

template <typename T>
void DoublyLinkedList<T>::pop_front()
{
	if (head == nullptr)
		return;
	Node<T> *del_node = head;
	head = head->next;
	if (head)
		head->prev = nullptr;
	else
		tail = nullptr;
	delete del_node;
	count -= 1;
}

template <typename T>
void DoublyLinkedList<T>::pop_back()
{
	if (head == nullptr)
		return;
	Node<T> *del_node = tail;
	tail = tail->prev;
	if (tail)
		tail->next = nullptr;
	else
		head = nullptr;
	delete del_node;
	count -= 1;
}

template <typename T>
bool DoublyLinkedList<T>::empty() const
{
	if (count == 0)
		return true;
	else
		return false;
}

template <typename T>
size_t DoublyLinkedList<T>::size() const
{
	return count;
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
	Node<T> *node = head;
	while (node)
	{
		Node<T> *del_node = node;
		node = node->next;
		delete del_node;
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template <typename T>
void DoublyLinkedList<T>::insert(const typename DoublyLinkedList<T>::Iterator& pos, const T& data)
{
	if (pos.node_ptr == nullptr)
		push_back(data);
	else if (pos.node_ptr == head)
		push_front(data);
	else
	{
		Node<T> *node = head->next;
		while (node)
		{
			if (node == pos.node_ptr)
			{
				Node<T> *new_node = new Node<T>(data);
				new_node->prev = node->prev;
				node->prev->next = new_node;
				new_node->next = node;
				node->prev = new_node;
				count += 1;
				break;
			}
			node = node->next;
		}
	}
}

template <typename T>
void DoublyLinkedList<T>::erase(const typename DoublyLinkedList<T>::Iterator& pos)
{
	if (pos.node_ptr == nullptr)
		return;
	else if (pos.node_ptr == head)
		pop_front();
	else if (pos.node_ptr == tail)
		pop_back();
	else
	{
		Node<T> *node = head;
		while (node)
		{
			if (node == pos.node_ptr)
			{
				node->prev->next = node->next;
				node->next->prev = node->prev;
				delete node;
				count -= 1;
				break;
			}
			node = node->next;
		}
	}
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() const
{
	return Iterator(head);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() const
{
	return Iterator(nullptr);
}

template <typename T>
T& DoublyLinkedList<T>::Iterator::operator*()
{
	return node_ptr->data;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator&  DoublyLinkedList<T>::Iterator::operator++()
{
	if (node_ptr != nullptr)
		node_ptr = node_ptr->next;
	return *this;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(T)
{
	Iterator temp = *this;
	if (node_ptr != nullptr)
		node_ptr = node_ptr->next;
	return temp;
}

template <typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const typename DoublyLinkedList<T>::Iterator& ref) const
{
	return node_ptr != ref.node_ptr;
}
