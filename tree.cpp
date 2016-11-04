#include "tree.hpp"
int Tree::create_tree(Tree *&MyTree,istream &fo,ostream &f2)
{
	Node *node=NULL;
	char cbuf[1000]={};

	while(!fo.eof())
	{
		fo>>cbuf;

		int ibuf=atoi(cbuf);

		if(MyTree->add_node(ibuf,node,root,MyTree)!=1)
		{
			cout<<"error";
			return 0;
		}
	}

	cbuf[0]='\0';

	MyTree->show_tree(MyTree->root,f2);
	MyTree->del_tree(MyTree->root);

	delete MyTree->root;
	MyTree->root=NULL;
	
	delete MyTree;
	MyTree=NULL;
	
	return 1;
}

int Tree::add_node(int buf,Node *&node, Node *&root,Tree *&MyTree)
{
    if (NULL==MyTree)
    {
    	MyTree=new Tree;
    	MyTree->root=new Node;
        node=new Node;
		node->data=buf;
        node->l=node->r=NULL;
        MyTree->root=node;

		return 1;
    }
 
	if (buf<node->data)
	{
		if (node->l!=NULL)
		{
			add_node(buf,node->l,root,MyTree);
		}
			
		else
		{
			node->l=new Node; 
			node->l->l=node->l->r=NULL;
			node->l->data=buf;
		}
		return 1;
	}

	if (buf>node->data)
	{
		if (node->r!=NULL)
		{
			add_node(buf,node->r,root,MyTree);
        }
		else
		{
			node->r=new Node;
			node->r->l=node->r->r=NULL;
			node->r->data=buf;
		}
		return 1;
	}   

}
 
void Tree::show_tree(Node *&node,ostream &f2)
{
	if (NULL==node)
	{
		return;
	}

    show_tree(node->l,f2); 

    cout<<node->data<<endl;
    f2<<node->data;
    f2<<endl;

    show_tree(node->r,f2);
}

void Tree::del_tree(Node *&node){
	if (node!=NULL)
	{
		del_tree(node->l);
		del_tree(node->r);
		
		delete node;	   
		node = NULL;
	}
}