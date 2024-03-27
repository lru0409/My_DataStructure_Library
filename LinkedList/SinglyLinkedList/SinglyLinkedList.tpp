
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(int count, const T& data)
	: head(nullptr), count(0)
{
	for(int i = 0; i < count; i++)
		push_front(data);
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& ref)
	: head(nullptr), count(0)
{
	if (this != &ref)
	{
		typename SinglyLinkedList<T>::Iterator iter;
		for(iter = ref.begin(); iter != ref.end(); iter++)
			push_back(iter.node_ptr->data);
	}
}

template <typename T>
const SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& ref)
{
	if (this != &ref)
	{
		clear();
		typename SinglyLinkedList<T>::Iterator iter;
		for(iter = ref.begin(); iter != ref.end(); iter++)
			push_back(iter.node_ptr->data);
		count = ref.size();
		return *this;
	}
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	clear();
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T& data)
{
	Node<T> *new_node = new Node<T>(data, head);
	head = new_node;
	count += 1;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& data)
{
	Node<T> *new_node = new Node<T>(data);
	if (head == nullptr)
	{
		head = new_node;
	}
	else
	{
		Node<T> *node = head;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	count += 1;
}

template <typename T>
void SinglyLinkedList<T>::pop_front()
{
	if (head == nullptr)
		return;
	Node<T> *node = head;
	head = head->next;
	delete node;
	count -= 1;
}

template <typename T>
void SinglyLinkedList<T>::pop_back()
{
	if (head == nullptr)
		return;
	if (count == 1)
	{
		delete head;
		head = NULL;
	}
	else
	{
		Node<T> *node = head;
		while (node->next->next)
			node = node->next;
		delete node->next;
		node->next = NULL;
	}
	count -= 1;	
}

template <typename T>
bool SinglyLinkedList<T>::empty() const
{
	if (count == 0)
		return true;
	else
		return false;
}

template <typename T>
size_t SinglyLinkedList<T>::size() const
{
	return count;
}

template <typename T>
void SinglyLinkedList<T>::clear()
{
	Node<T> *node = head;
	Node<T> *del_node;
	while (node)
	{
		del_node = node;
		node = node->next;
		delete del_node;
	}
	count = 0;
	head = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::insert(const typename SinglyLinkedList<T>::Iterator& pos, const T& data)
{
	if (pos.node_ptr == nullptr)
	{
		push_back(data);
	}
	else if (pos.node_ptr == head || head == nullptr)
	{
		push_front(data);
	}
	else
	{
		Node<T> *node = head;
		while (node)
		{
			if (node->next == pos.node_ptr)
			{
				Node<T> *new_node = new Node<T>(data, node->next);
				node->next = new_node;
				count += 1;
				break;
			}
			node = node->next;
		}
	}
}

template <typename T>
void SinglyLinkedList<T>::erase(const typename SinglyLinkedList<T>::Iterator& pos)
{
	if (pos.node_ptr == nullptr)
	{
		return;
	}
	else if (pos.node_ptr == head)
	{
		pop_front();
	}
	else
	{
		Node<T> *node = head;
		while (node)
		{
			if (node->next == pos.node_ptr)
			{
				Node<T> *del_node = node->next;
				node->next = node->next->next;
				delete del_node;
				count -= 1;
				break;
			}
			node = node->next;
		}
	}
}

template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::begin() const
{
	return Iterator(head);
}

template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::end() const
{
	return Iterator(nullptr);
}

template <typename T>
T& SinglyLinkedList<T>::Iterator::operator*()
{
	return node_ptr->data;
}

template <typename T>
typename SinglyLinkedList<T>::Iterator&  SinglyLinkedList<T>::Iterator::operator++()
{
	if (node_ptr != nullptr)
		node_ptr = node_ptr->next;
	return *this;
}

template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator++(T)
{
	Iterator temp = *this;
	if (node_ptr != nullptr)
		node_ptr = node_ptr->next;
	return temp;
}

template <typename T>
bool SinglyLinkedList<T>::Iterator::operator!=(const typename SinglyLinkedList<T>::Iterator& ref) const
{
	return node_ptr != ref.node_ptr;
}
