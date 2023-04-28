#include "trie.h"

#include <algorithm>

trie_node::trie_node()
	: end_of_word(false)
{

}

trie_node::~trie_node()
{
	for (auto child : children)
	{
		if (child.second) delete child.second;
	}
}

void trie::insert(const std::string& word)
{
	trie_node* current = root;

	if (!current)	return;

	for (auto c : word)
	{
		if (current->children.find(c)== current->children.cend())
		{
			current->children[c] = new trie_node;
		}

		current = current->children[c];
	}

	current->end_of_word = true;
}

bool trie::search(const std::string& word) const
{
	trie_node* current = root;

	for (auto ch : word)
	{
		if (current->children.find(ch) == current->children.cend())
		{
			return false;
		}

		current = current->children[ch];
	}

	return current->end_of_word;
}

bool trie::starts_with(const std::string& word) const
{
	trie_node* now = root;

	for (auto ch : word)
	{
		if (!std::none_of(now->children.cbegin(), 
			now->children.cend(), 
			std::string()))
		{
			return false;
		}
	}
}

std::vector<std::string> trie::start_with(const std::string& word)
{
	std::vector<std::string> list;
	if (starts_with(word))
	{
		for (const char& c: word)
		{
			list.push_back(c);
		}
	}

	
}