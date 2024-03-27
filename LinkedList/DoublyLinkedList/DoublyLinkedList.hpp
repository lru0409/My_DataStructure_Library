#ifndef DOUBLY_LINKED_LIST_HPP
# define DOUBLY_LINKED_LIST_HPP

# include "Node.hpp"

template <typename T>
class DoublyLinkedList
{
	private:
		Node<T> *head;
		Node<T> *tail;
		int count;
	
	public:
		DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
		DoublyLinkedList(int count, const T& data);
		DoublyLinkedList(const DoublyLinkedList& ref);
		const DoublyLinkedList& operator=(const DoublyLinkedList& ref);
		~DoublyLinkedList();

		void push_front(const T& data);
		void push_back(const T& data);
		void pop_front();
		void pop_back();
		bool empty() const;
		size_t size() const;
		void clear();

		class Iterator
		{
			friend class DoublyLinkedList<T>;
			private:
				Node<T> *node_ptr;
			public:
				Iterator() : node_ptr(nullptr) {}
				Iterator(Node<T> *node_ptr) : node_ptr(node_ptr) {}

				T& operator*();
				Iterator& operator++();
				Iterator operator++(T);

				bool operator!=(const Iterator& ref) const;
		};

		void insert(const typename DoublyLinkedList<T>::Iterator& pos, const T& data);
		void erase(const typename DoublyLinkedList<T>::Iterator& pos);
		typename DoublyLinkedList<T>::Iterator begin() const;
		typename DoublyLinkedList<T>::Iterator end() const;
};

# include "DoublyLinkedList.tpp"

#endif