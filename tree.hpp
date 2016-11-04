#ifndef _TREE_HPP_
#define _TREE_HPP_
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct Node
{	
		int data;
		Node *l;
		Node *r;
};

class Tree
{
	private:
		Node *root;
	public:
		int create_tree(Tree *&MyTree,istream &fo,ostream &f2);
		int add_node(int buf,Node *&node,Node *&root,Tree *&MyTree);
		void show_tree(Node *&node,ostream &f2);
		void del_tree(Node *&node);
};

#endif