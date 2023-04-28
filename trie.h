#pragma once

#include <string>
#include <vector>
#include <unordered_map>

struct trie_node
{
	trie_node() = default;
	~trie_node();

	std::unordered_map<char, trie_node*> children;
	bool end_of_word;
};

class trie
{
public:
	void insert(const std::string&);
	bool search(const std::string&) const;
	bool starts_with(const std::string&) const;
	std::vector<std::string> start_with(const std::string&);
private:
	trie_node* root;
};
