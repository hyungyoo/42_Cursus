#ifndef FT_CONTAINERS_SET_HPP
# define FT_CONTAINERS_SET_HPP

# include <iostream>
# include "utils.hpp"
# include "node.hpp"
# include "iterator/bidirectional_iterator.hpp"
# include "iterator/reverse_iterator.hpp"


namespace ft
{
	// set::key_type/value_type
	// set::key_compare/value_compare
	// set::allocator_type
	// set use just key (different point to map)
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:
			typedef T												key_type;
			typedef T												value_type;
			typedef Compare												key_compare;
			typedef Compare 											value_compare;
			typedef Alloc												allocator_type;
			typedef Node<T>												node_type;
			typedef typename allocator_type::template rebind<node_type>::other 					node_alloc_type;
			typedef typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer								pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef const_bidirectional_iterator<const T, node_type*>						iterator;
			typedef const_bidirectional_iterator<const T, node_type*>						const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef std::ptrdiff_t											difference_type;
			typedef std::size_t											size_type;

		private:
			key_compare 			_compare;
			allocator_type 			_alloc;
			size_type			_size;
			node_alloc_type			_node_alloc;
			node_type			*_root;

			//getter, setter, tool
			node_type	*get_root(void) const {
				return (_root->left);
				//it can be also return (_root->right) cause here _root is meta node.
			}

			key_compare	get_keycompare(void) const {
				return (_compare);
			}

			void	set_root(node_type* node) const {
				_root->left = node;
				_root->right = node;
				if (node)
					node->parent = _root;
			}

			void		ResetTree(void) {
				DeleteTree(get_root());
				set_root(NULL);
				_size = 0;
			}

			void		DeleteTree(node_type *node) {
				if (node)
				{
					DeleteTree(node->left);
					DeleteTree(node->right);
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);
				}
			}

			void	CopyTree(node_type *node)
			{
				if (node != NULL)
				{
					InsertValue(node->value);
					CopyTree(node->left);
					CopyTree(node->right);
				}
			}

		public:
			// Constructor / Destructor ============== //
			
			//empty
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _compare(comp), _alloc(alloc), _size(0), _node_alloc(node_alloc_type()), _root(NULL) {
					_root = _node_alloc.allocate(1);
					_node_alloc.construct(_root, node_type());
			}

			//range	
			template <class InputIterator>
			set (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
				InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _compare(comp), _alloc(alloc), _size(0), _root(NULL) {
					_root = _node_alloc.allocate(1);
					_node_alloc.construct(_root, node_type());
					insert(first, last);
			}
			
			//copy	
			set (const set& x) : _compare(x._compare), _alloc(x._alloc), _size(0) {
				_root = _node_alloc.allocate(1);
				_node_alloc.construct(_root, node_type());
				CopyTree(x.get_root());
			}

			~set() {
				ResetTree();
				if (_root != NULL)
				{
					_node_alloc.destroy(_root);
					_node_alloc.deallocate(_root, 1);
				}
			}

			// operator== ============== //

			set& operator= (const set& x) {
				ResetTree();
				_compare = x._compare;
				_alloc = x._alloc;
				_node_alloc = x._node_alloc;
				CopyTree(x.get_root());
				_size = x._size;
				return (*this);
			}

			// Iterators ============== //

			iterator begin() {
				return (iterator(FindMinVal(_root)));
			}

			const_iterator begin() const {
				return (const_iterator(FindMinVal(_root)));
			}

			iterator end() {
				return (iterator(_root));
			}

			const_iterator end() const {
				return (const_iterator(_root));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(end()--));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()--));
			}

			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			}

			// Capacity ============== //

			bool empty() const {
				return (_size == 0);
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (_node_alloc.max_size());
			}

			// Modifiers ============== //


			// single element (1)	
			pair<iterator,bool> insert (const value_type& val) {
				return (InsertValue(val));
			}
			
			// with hint (2)	
			iterator insert (iterator position, const value_type& val) {
				(void)position;
				return (InsertValue(val).first);
			}
			
			// range (3)	
			template <class InputIterator>
			void insert (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

			// erase (1)	
			void erase (iterator position) {
				DeleteValue(*position);
			}
			
			// erase (2)	
			size_type erase (const value_type& val) {
				return (DeleteValue(val));
			}
			
			// erase (3)	
			void erase (iterator first, iterator last) {
				for (iterator it = first; it != last; )
					erase(it++);
			}

			//swap
			void swap (set& x) {
				node_alloc_type temp_alloc_type = _node_alloc;
				key_compare temp_key_compare = _compare;
				size_type temp_size = _size;
				node_type *temp_root = _root;

				_node_alloc = x._node_alloc;
				_compare = x._compare;
				_size = x._size;
				_root = x._root;

				x._node_alloc = temp_alloc_type;
				x._compare = temp_key_compare;
				x._size = temp_size;
				x._root = temp_root;
			}

			//clear
			void clear() {
				DeleteTree(get_root());
				set_root(NULL);
				_size = 0;
			}

			// Observers ============== //

			key_compare key_comp() const {
				return (_compare);
			}

			value_compare value_comp() const {
				return (value_compare(key_compare()));
			}

			// Operations ============== //

			iterator find (const value_type& val) const {
				node_type *tmp;

				tmp = get_root();
				while (tmp)
 				{
					if (!_compare(tmp->value, val) && !_compare(val, tmp->value)) //difference
						break;
					else if (_compare(tmp->value, val))
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				if (!tmp)
					return (_root);
				return (tmp);
			}

			size_type count (const value_type& val) const {
				const_iterator tmp = find(val);
				if (tmp == end())
					return (false);
				return (true);
			}

			iterator lower_bound (const value_type& val) const {
				const_iterator it1 = begin();
				const_iterator it2 = end();

				while (it1 != it2)
				{
					if (_compare(*it1, val) == false) //difference
						break;
					++it1;
				}
				return (it1);
			}

			iterator upper_bound (const value_type& val) const {
				iterator it1 = begin();
				iterator it2 = end();

				while (it1 != it2)
				{
					if (_compare(val, *it1) == true) //difference
						break;
					++it1;
				}
				return (it1);
			}

			pair<iterator,iterator> equal_range (const value_type& val) const {
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(val), upper_bound(val)));
			}

			// Allocator ============== //
			allocator_type get_allocator() const {
				return (_node_alloc);
			}

			// Node & Tree tool ============== //
		private:
			// getter && setter	
			node_type *get_parent(node_type *node) const {
				if (!node)
					return (NULL);
				if (node->parent == _root)
					return (NULL);
				return (node->parent);
			}

			node_type *get_grandparent(node_type *node) {
				node_type *parent = get_parent(node);

				if (!parent)
					return (NULL);
				return (get_parent(parent));
			}

			node_type *get_uncle(node_type *node) {
				node_type *parent = get_parent(node);

				if (!parent)
					return (NULL);
				return (get_sibling(parent));
			}

			node_type *get_sibling(node_type *node) {
				node_type *parent = get_parent(node);

				if (!parent)
					return (NULL);
				if (node == parent->left)
					return (parent->right);
				return (parent->left);
			}

			Color get_color(node_type *node) {
				if (!node)
					return (BLACK);
				return (node->color);
			}

			void	set_color(node_type *node, Color color) {
				if (!node)
					return ;
				node->color = color;
			}

			//tools
			node_type *FindMinVal(node_type* node) const {
				if (!node)
					return (node);
				while (node->left)
					node = node->left;
				return (node);
			}

			pair<iterator, bool> InsertValue(const value_type &val) {
				node_type *node = _node_alloc.allocate(1);
				_node_alloc.construct(node, node_type(val));
				pair<iterator, bool> ret = InsertNode(node);

				if (ret.second == false)
				{
					_node_alloc.destroy(node);
					_node_alloc.deallocate(node, 1);
				}
				else
				{
					_size++;
					FixAfterInsert(node);
				}
				return (ret);
			}

			pair<iterator, bool> InsertNode(node_type *node) {
				node_type *tmp = get_root();
				node_type *parent;

				if (!tmp)
				{
					set_root(node);
					return (ft::make_pair(iterator(node), true));
				}
				while (tmp)
				{
					if (_compare(tmp->value, node->value)) //difference
					{
						parent = tmp;
						tmp = tmp->right;
					}
					else if (_compare(node->value, tmp->value)) //difference
					{
						parent = tmp;
						tmp = tmp->left;
					}
					else
						return (ft::make_pair(iterator(tmp), false));
				}
				if (_compare(parent->value, node->value))
				{
					parent->right = node;
					node->parent = parent;
				}
				else
				{
					parent->left = node;
					node->parent = parent;
				}
				return (ft::make_pair(iterator(node), true));
			}

			void	FixAfterInsert(node_type *node) {
				node_type *parent;
				node_type *grandparent;
				node_type *uncle;

				//red red violation
				while (node != get_root() && get_color(node) == RED && get_color(get_parent(node)) == RED)
				{
					parent = get_parent(node);
					grandparent = get_grandparent(node);
					uncle = get_uncle(node);

					if (get_color(uncle) == RED)
						insert_case1(node); //color change
					else if(grandparent->left == parent)
					{
						if (parent->right == node)
							insert_case2(node, parent);
						insert_case3(node, parent, grandparent);
					}
					else if (grandparent->right == parent)
					{
						if (parent->left == node)
							insert_case2(node, parent);
						insert_case3(node, parent, grandparent);
					}
				}
				set_color(get_root(), BLACK);
			}

			void	insert_case1(node_type* &node) {
				set_color(get_parent(node), BLACK);
				set_color(get_uncle(node), BLACK);
				set_color(get_grandparent(node), RED);
				node = get_grandparent(node);
			}

			void	insert_case2(node_type* &node, node_type* &parent) {
				if (parent == get_grandparent(node)->left)
				{
					rotate_left(parent);
					node = parent;
					parent = get_parent(node);
				}
				else if (parent == get_grandparent(node)->right)
				{
					rotate_right(parent);
					node = parent;
					parent = get_parent(node);
				}
			}

			void	insert_case3(node_type* &node, node_type* parent, node_type* grandparent) {
				if (parent == grandparent->left)
					rotate_right(grandparent);
				else if (parent == grandparent->right)
					rotate_left(grandparent);
				std::swap(parent->color, grandparent->color);
				node = parent;
			}

			void	rotate_left(node_type* &node) {
				node_type *rightChild;

				rightChild = node->right; // set y
				if (!rightChild) // protection if case child node is NULL 0.1%
					return ;
				node->right = rightChild->left; // Turn y's left subtree into x's right subtree
				if (node->right)
					node->right->parent = node; //?
				rightChild->parent = node->parent; // link x's parent to y
				if (!get_parent(node)) // case: node is root node
					set_root(rightChild);
				else if (node == node->parent->left)
					node->parent->left = rightChild;
				else
					node->parent->right = rightChild;
				rightChild->left = node; //put x on y's left
				node->parent = rightChild;
			}

			void	rotate_right(node_type* &node)
			{
				node_type *leftChild;

				leftChild = node->left;
				if (!leftChild)
					return ;
				node->left = leftChild->right;
				if (node->left)
					node->left->parent = node;
				leftChild->parent = node->parent;
				if (!get_parent(node))
					set_root(leftChild);
				else if (node == node->parent->right)
					node->parent->right = leftChild;
				else
					node->parent->left = leftChild;
				leftChild->right = node;
				node->parent = leftChild;
			}

			size_type DeleteValue(const key_type &val) {
				node_type *target = DeleteNode(get_root(), val);
				if (!target)
					return (0);
				FixAfterDelete(target);
				_size--;
				return (1);
			}

			node_type *DeleteNode(node_type *node, const key_type &val) {
				if (!node)
					return (node);
				// find delete node's position
				if (_compare(node->value, val)) //difference
					return (DeleteNode(node->right, val));
				if (_compare(val, node->value))
					return (DeleteNode(node->left, val)); //difference
				// easy case: node to be deleted has one child node => new link and delete
				if (!node->left || !node->right)
					return (node);
				// else: tree Successor(z)
				node_type *tmp = successor(node->right);
				// ===== Target Transplant ===== //
				// if target has left child or Null node
				// else target has right child or Null node
				// RB-Transplant (T,z,y)
				if (tmp->parent == node) // tmp == node->left case 
				{
					if (node->parent && node->parent->left == node)
						node->parent->left = tmp;
					if (node->parent && node->parent->right == node)
						node->parent->right = tmp;
					tmp->left = node->left;
					node->left->parent = tmp;
					node->left = NULL;
					tmp->parent = node->parent;
					node->parent = tmp;
					node->right = tmp->right;
					tmp->right = node;
					std::swap(tmp->color, node->color);
				}
				//RB-Transplant(T,y,y,right)
				else // else: tmp is successor 		node->right->left->left.......left == NULL
				{
					if(node->parent && node->parent->left == node)
						node->parent->left = tmp;
					if(node->parent && node->parent->right == node)
						node->parent->right = tmp;
					if (tmp->parent->left == tmp)
						tmp->parent->left = node;
					if (tmp->parent->right == tmp)
						tmp->parent->right = node;
					node_type* tmp2 = tmp->parent;
					node->right->parent =tmp;
					tmp->parent = node->parent;
					node->parent = tmp2;
					tmp->left = node->left;
					node->left->parent = tmp;
					node->left = NULL;
					node_type* tmp3 = tmp->right;
					tmp->right = node->right;
					node->right = tmp3;
					std::swap(tmp->color, node->color);
				}
				return (DeleteNode(tmp->right, val));
			}

			node_type *successor(node_type *node) const {
				if (!node)
					return (node);
				while (node->left)
					node = node->left;
				return (node);
			}

			void	FixAfterDelete(node_type *node) {
				if (!node)
					return ;
				if (node == get_root()) // if root node is red case
				{
					DeleteRootCase(node);
					return ;
				}
				// if x node is black or son of x node is black, go to next case
				// else we cas delete node
				if (get_color(node) == RED || get_color(node->left) == RED || get_color(node->right) == RED)
				{
					DeleteRedCase(node);
					return ;
				}

				node_type *w = NULL;
				node_type *p = NULL;
				node_type *tmp = node;
				// z == z->parent->left is 1234 // z == z->parent->right is 5678 case
				// case1: w node is RED
				// case2: w node is BLACK && child of w is also BLACK
				// case3: w node is BLACK && left child is RED
				// case4: w node is BLACK && right child is RED

				//	1)								2)												3)							4)
				// case 1(6) -> 2(7)                 case 2(7) 	-> case 1(6) (return case 1(6))     case 3(8) -> 4(9)          case 4(9)
				//        -> 3(8) -> 4(9)                   	-> 3(8) -> 4(9)
				//        -> 4(9)                        		-> 4(9)
				set_color(tmp, DBLACK);
				while (tmp != get_root() && get_color(tmp) == DBLACK)
				{
					p = tmp->parent;
					w = (tmp == p->left) ? p->right : p->left;
					if (get_color(w) == RED)
						delete_case1(w, p);
					else if (get_color(w->left) == BLACK && get_color(w->right) == BLACK)
						delete_case2(w, p, tmp);
					else
					{
						if ((tmp == p->left && get_color(w->right) == BLACK) || (tmp == p->right && get_color(w->left) == BLACK))
							delete_case3(w, p);
						delete_case4(w, p);
						break;
					}	
				}
				if (node == node->parent->left)
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				set_color(get_root(), BLACK);
			}

			void	DeleteRootCase(node_type *root) {
				if (root->right)
					set_root(root->right);
				else
					set_root(root->left);
				_node_alloc.destroy(root);
				_node_alloc.deallocate(root, 1);
				set_color(get_root(), BLACK);
				return ;
			}

			void	DeleteRedCase(node_type *node) {
				node_type *child = node->left != NULL ? node->left : node->right;
				if (node == node->parent->left)
					node->parent->left = child;
				else
					node->parent->right = child;
				if (child)
					child->parent = node->parent;
				set_color(child, BLACK);
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
			}

			void	delete_case1(node_type* &w, node_type* &p) {
				if (w == p->right)
					rotate_left(p);
				if (w == p->left)
					rotate_right(p);
				set_color(w, BLACK);
				set_color(p, RED);
			}

			void	delete_case2(node_type *w, node_type *p, node_type* &node) {
				set_color(w, RED);
				if (get_color(p) == RED)
					set_color(p, BLACK);
				else
					set_color(p, DBLACK);
				node = p;
			}

			void	delete_case3(node_type* &w, node_type* &p) {
				if (w == p->right)
				{
					rotate_right(w);
					set_color(w->left, BLACK);
					set_color(w, RED);
					w = p->right;
				}
				if (w == p->left)
				{
					rotate_left(w);
					set_color(w->right, BLACK);
					set_color(w, RED);
					w = p->left;
				}
			}

			void	delete_case4(node_type* &w, node_type* &p) {
				if (w == p->right)
				{
					rotate_left(p);
					set_color(w, get_color(p));
					set_color(p, BLACK);
					set_color(w->right, BLACK);
				}
				if (w == p->left)
				{
					rotate_right(p);
					set_color(w, get_color(p));
					set_color(p, BLACK);
					set_color(w->left, BLACK);
				}
			}
	};

	template <class T, class Compare, class Alloc>
	bool operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class Compare, class Alloc>
	bool operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Compare, class Alloc>
	bool operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Compare, class Alloc>
	bool operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator>=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) {
		return (lhs > rhs || lhs == rhs);
	}

	template <class T, class Compare, class Alloc>
	void swap(set<T, Compare, Alloc> &x, set<T, Compare, Alloc> &y) {
		x.swap(y);
	}
	
} // namespace ft

#endif
