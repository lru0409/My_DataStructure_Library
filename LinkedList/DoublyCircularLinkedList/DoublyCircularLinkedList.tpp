
template <typename T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList(int count, const T& data)
	: head(nullptr), count(0)
{
	for(int i = 0; i < count; i++)
		push_front(data);
}

template <typename T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList(const DoublyCircularLinkedList<T>& ref)
	: head(nullptr), count(0)
{
	if (this != &ref)
	{
		typename DoublyCircularLinkedList<T>::Iterator iter;
		for(iter = ref.begin(); iter != ref.end(); iter++)
			push_back(iter.node_ptr->data);
	}
}

template <typename T>
const DoublyCircularLinkedList<T>& DoublyCircularLinkedList<T>::operator=(const DoublyCircularLinkedList<T>& ref)
{
	if (this != &ref)
	{
		clear();
		typename DoublyCircularLinkedList<T>::Iterator iter;
		for(iter = ref.begin(); iter != ref.end(); iter++)
			push_back(iter.node_ptr->data);
		count = ref.size();
	}
	return *this;
}

template <typename T>
DoublyCircularLinkedList<T>::~DoublyCircularLinkedList()
{
	clear();
}

template <typename T>
void DoublyCircularLinkedList<T>::push_front(const T& data)
{
	Node<T> *new_node = new Node<T>(data);
	if (head) {
		Node<T> *tail = head->prev;
		new_node->prev = tail;
		tail->next = new_node;
		new_node->next = head;
		head->prev = new_node;
	} else {
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	head = new_node;
	count += 1;
}

template <typename T>
void DoublyCircularLinkedList<T>::push_back(const T& data)
{
	Node<T> *new_node = new Node<T>(data);
	if (head) {
		Node<T> *tail = head->prev;
		new_node->prev = tail;
		tail->next = new_node;
		new_node->next = head;
		head->prev = new_node;
	} else {
		new_node->prev = new_node;
		new_node->next = new_node;
		head = new_node;
	}
	count += 1;
}

template <typename T>
void DoublyCircularLinkedList<T>::pop_front()
{
	if (head == nullptr)
		return;
	Node<T> *del_node = head;
	if (head->next == head) {
		head = nullptr;
	} else {
		Node<T> *tail = head->prev;
		head = head->next;
		head->prev = tail;
		tail->next = head;
	}
	delete del_node;
	count -= 1;
}

template <typename T>
void DoublyCircularLinkedList<T>::pop_back()
{
	if (head == nullptr)
		return;
	Node<T> *tail = head->prev;
	if (head->next == head) {
		head = nullptr;
	} else {
		head->prev = tail->prev;
		tail->prev->next = head;
	}
	delete tail;
	count -= 1;
}

template <typename T>
bool DoublyCircularLinkedList<T>::empty() const
{
	if (count == 0)
		return true;
	else
		return false;
}

template <typename T>
size_t DoublyCircularLinkedList<T>::size() const
{
	return count;
}

template <typename T>
void DoublyCircularLinkedList<T>::clear()
{
	if (head == nullptr)
		return;
	Node<T> *node = head;
	do {
		Node<T> *del_node = node;
		node = node->next;
		delete del_node;
	} while (node != head);
	head = nullptr;
	count = 0;
}

template <typename T>
void DoublyCircularLinkedList<T>::insert(const typename DoublyCircularLinkedList<T>::Iterator& pos, const T& data)
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
void DoublyCircularLinkedList<T>::erase(const typename DoublyCircularLinkedList<T>::Iterator& pos)
{
	if (pos.node_ptr == nullptr)
		return;
	else if (pos.node_ptr == head)
		pop_front();
	else if (head && pos.node_ptr == head->prev)
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
typename DoublyCircularLinkedList<T>::Iterator DoublyCircularLinkedList<T>::begin() const
{
	return Iterator(head, head);
}

template <typename T>
typename DoublyCircularLinkedList<T>::Iterator DoublyCircularLinkedList<T>::end() const
{
	return Iterator(nullptr, head);
}

template <typename T>
T& DoublyCircularLinkedList<T>::Iterator::operator*()
{
	return node_ptr->data;
}

template <typename T>
typename DoublyCircularLinkedList<T>::Iterator&  DoublyCircularLinkedList<T>::Iterator::operator++()
{
	if (node_ptr != nullptr)
		node_ptr = node_ptr->next;
	return *this;
}

template <typename T>
typename DoublyCircularLinkedList<T>::Iterator DoublyCircularLinkedList<T>::Iterator::operator++(T)
{
	Iterator temp = *this;
	if (node_ptr != nullptr)
		node_ptr = node_ptr->next;
	return temp;
}

template <typename T>
bool DoublyCircularLinkedList<T>::Iterator::operator!=(const typename DoublyCircularLinkedList<T>::Iterator& ref) const
{
	return node_ptr != ref.node_ptr;
}
