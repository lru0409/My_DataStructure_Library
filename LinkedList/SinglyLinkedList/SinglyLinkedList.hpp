#ifndef SINGLY_LINKED_LIST_HPP
# define SINGLY_LINKED_LIST_HPP

# include "Node.hpp"

template <typename T>
class SinglyLinkedList
{
	private:
		Node<T> *head;
		int count;
	
	public:
		SinglyLinkedList() : head(nullptr), count(0) {}
		SinglyLinkedList(int count, const T& data);
		SinglyLinkedList(const SinglyLinkedList& ref);
		const SinglyLinkedList& operator=(const SinglyLinkedList& ref);
		~SinglyLinkedList();

		void push_front(const T& data);
		void push_back(const T& data);
		void pop_front();
		void pop_back();
		bool empty() const;
		size_t size() const;
		void clear();

		class Iterator
		{
			friend class SinglyLinkedList<T>;
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

		void insert(const typename SinglyLinkedList<T>::Iterator& pos, const T& data);
		void erase(const typename SinglyLinkedList<T>::Iterator& pos);
		typename SinglyLinkedList<T>::Iterator begin() const;
		typename SinglyLinkedList<T>::Iterator end() const;
};

# include "SinglyLinkedList.tpp"

#endif