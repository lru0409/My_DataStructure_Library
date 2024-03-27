#ifndef DOUBLY_CIRCULAR_LINKED_LIST_HPP
# define DOUBLY_CIRCULAR_LINKED_LIST_HPP

# include "Node.hpp"

template <typename T>
class DoublyCircularLinkedList
{
	private:
		Node<T> *head;
		int count;
	
	public:
		DoublyCircularLinkedList() : head(nullptr), count(0) {}
		DoublyCircularLinkedList(int count, const T& data);
		DoublyCircularLinkedList(const DoublyCircularLinkedList& ref);
		const DoublyCircularLinkedList& operator=(const DoublyCircularLinkedList& ref);
		~DoublyCircularLinkedList();

		void push_front(const T& data);
		void push_back(const T& data);
		void pop_front();
		void pop_back();
		bool empty() const;
		size_t size() const;
		void clear();

		class Iterator
		{
			friend class DoublyCircularLinkedList<T>;
			private:
				Node<T> *node_ptr;
				Node<T> *head_ptr;
			public:
				Iterator() : node_ptr(nullptr), head_ptr(nullptr) {}
				Iterator(Node<T> *node_ptr, Node<T> *head_ptr)
					: node_ptr(node_ptr), head_ptr(head_ptr) {}

				T& operator*();
				Iterator& operator++();
				Iterator operator++(T);

				bool operator!=(const Iterator& ref) const;
		};

		void insert(const typename DoublyCircularLinkedList<T>::Iterator& pos, const T& data);
		void erase(const typename DoublyCircularLinkedList<T>::Iterator& pos);
		typename DoublyCircularLinkedList<T>::Iterator begin() const;
		typename DoublyCircularLinkedList<T>::Iterator end() const;
};

# include "DoublyCircularLinkedList.tpp"

#endif