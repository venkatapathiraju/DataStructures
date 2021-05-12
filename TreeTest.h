#pragma once

#include <iostream>
#include <string>

namespace mytree {


	/*
	template<typename T>
	class Position
	{
	public:
		T& operator*();
		Position parent() const;
		//PositionList child() const;
		bool isRoot() const;
		bool isExternal() const;
	};

	template<typename T>
	class Tree
	{
	public:
		class Position;
	public:
		int size() const;
		bool empty() const;
		Position root() const;
	};

	template<typename T, typename R>
	class EulerTour
	{
	protected:
		struct Result {
			R leftResult;
			R rightResult;
			R finalResult;
		};

		typedef BinaryTree<E> BinaryTree;
		typedef typename BinaryTree::Position Position;
	protected:
		const BinaryTree* tree;
	public:
		void initialize(const BinaryTree& T)
		{
			tree = &T;
		}
	protected:
		int eulerTour(const Position& p) const;

		virtual void visitExternal(const Position& p, result& r) const {}
	};
	*/

	template<typename T>
	class Node
	{
	public:
		T position;
		Node* left;
		Node* right;
		Node(T s) : position(s), left(nullptr), right(nullptr)
		{

		}
	};

	template<typename T>
	class BTree
	{
		
	public:
		Node<T>* root;
		BTree() {}
		BTree(const T& s): root(new Node(s))
		{

		}

		Node<T>* find(const T& s, Node<T>* node)
		{
			if (node == nullptr)
				return nullptr;
			if (node->position == s)
				return node;
			auto firstFound = find(s, node->left);
			if (firstFound != nullptr) return firstFound;
			return find(s, node->right);
		}

		bool addSubordinate(const T& manager, const T& subordinate)
		{
			auto managerNode = find(manager,root);
			if (!managerNode)
			{
				std::cout << "No position named " << manager << std::endl;
				return false;
			}
			if (managerNode->left && managerNode->right)
			{
				std::cout << manager << " already has 2 subordinates." << std::endl;
				return false;
			}

			if (!managerNode->left)
				managerNode->left = new Node{ subordinate};
			else
				managerNode->right = new Node{ subordinate};

			return true;

		}

		void levelOrder()
		{

		}


	};

	void treetest()
	{
		BTree<string> tree("CEO");
		cout << tree.root->position << endl;
		if (tree.addSubordinate("CEO", "Deputy Director"))
			std::cout << "Added Deputy Director in the tree." << std::endl;
		else
			std::cout << "Couldn't add Deputy Director in the tree" << std::endl;

		if (tree.addSubordinate("Deputy Director", "IT Head"))

			std::cout << "Added IT Head in the tree." << std::endl;

		else

			std::cout << "Couldn't add IT Head in the tree" << std::endl;

		if (tree.addSubordinate("Deputy Director", "Marketing Head"))

			std::cout << "Added Marketing Head in the tree." << std::endl;

		else

			std::cout << "Couldn't add Marketing Head in the tree" << std::endl;

		if (tree.addSubordinate("IT Head", "Security Head"))

			std::cout << "Added Security Head in the tree." << std::endl;

		else

			std::cout << "Couldn't add Security Head in the tree" << std::endl;

		if (tree.addSubordinate("IT Head", "App Development Head"))

			std::cout << "Added App Development Head in the tree." << std::endl;

		else

			std::cout << "Couldn't add App Development Head in the tree" << std::endl;

		if (tree.addSubordinate("Marketing Head", "Logistics Head"))

			std::cout << "Added Logistics Head in the tree." << std::endl;

		else

			std::cout << "Couldn't add Logistics Head in the tree" << std::endl;

		if (tree.addSubordinate("Marketing Head", "Public Relations Head"))

			std::cout << "Added Public Relations Head in the tree." << std::endl;

		else

			std::cout << "Couldn't add Public Relations Head in the tree" << std::endl;

		if (tree.addSubordinate("Deputy Director", "Finance Head"))

			std::cout << "Added Finance Head in the tree." << std::endl;

		else

			std::cout << "Couldn't add Finance Head in the tree" << std::endl;
	}
}