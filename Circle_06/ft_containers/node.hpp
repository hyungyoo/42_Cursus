#ifndef FT_CONTAINERS_NODE_HPP
# define FT_CONTAINERS_NODE_HPP

namespace ft {

	//Color needed to do RBNode (DBlack for delete node process)	
	enum Color
	{
		RED,
		BLACK,
		DBLACK
	};

	template<class T>
	struct Node
	{
		typedef T		value_type;
		typedef Color	color_type;

		value_type		value; //content of node
		Node			*parent; //address of parent node
		Node			*left; //address of left node
		Node			*right; //address of right node
		color_type		color; //color of node

		Node(void) : value(), parent(NULL), left(NULL), right(NULL), color(RED) {}
		Node(const value_type &v, Node *p = NULL, Node *l = NULL, Node *r = NULL, color_type c = RED)
			: value(v), parent(p), left(l), right(r), color(c) {}
		virtual ~Node(void) {}

		Node(const Node &x) : value(x.value), parent(x.parent), left(x.left), right(x.right), color(x.color) {}

		Node	&operator=(const Node &x) {
			if (this != &x)
			{
				value = x.value;
				parent = x.parent;
				left = x.left;
				right = x.right;
				color = x.color;
			}
			return (*this);
		}
	};
}

#endif