#include <iostream>
#include <string>
#include <fstream>

#include "trie.h"



int main(int argc, char* argv[])
{
	trie t;
	std::ifstream file(argv[1]);

	// input: a<ENTER>
	
	// ouptut: ^a

	// input: ab<ENTER>

	// output: ^ab

	// end: ^C

	// use muti-way trie

	return 0;
}
