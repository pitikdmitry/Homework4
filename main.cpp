//Homework4 Var11
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h>
#include <cstring>
#include "tree.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 3) 
	{
        printf("Usage: %s number_of_words_to_generate\n", argv[0]);
        return EXIT_FAILURE;
    }

	ifstream fo(argv[1]);

	if(!fo.is_open())
	{
		cout<<"cant open file";
		exit(1);
	}

	ofstream f2(argv[2]);

	if(!f2.is_open())
	{
		cout<<"cant open file";
		exit(1);
	}

	Tree *MyTree=NULL;

	if(MyTree->create_tree(MyTree,fo,f2)!=1)
	{
		cout<<"error";
		exit(1);
	}
	
	return 0;
}