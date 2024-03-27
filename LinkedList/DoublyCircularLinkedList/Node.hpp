#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>

template <typename T>
class Node
{
	public:
		T data;
		Node<T> *prev;
		Node<T>	*next;

		Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};

#endif