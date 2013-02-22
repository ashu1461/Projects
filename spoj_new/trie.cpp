//This is the trie cpp implementation

#include <iostream>
#include <fstream>
#include <string>
#define ALPHABET_SIZE 26

using namespace std;

/*
 * A Trie supporting the following operations for n words with lengths k
 * Only words of small latin alphabets are supported. To modify it to
 * work for other, you will have to map the child array indexes properly
 * 1. insert - O(k) 
 * 2. search - O(k)
 * 3. count of words with a given prefix of length k - O(k)
 * visit http://youtube.com/algoKing for more such implementations.
 */


struct node
{
	bool is_end;
	int prefix_count;
	struct node* child[ALPHABET_SIZE];
} *head;

// Initializes the trie. DO NOT forget to call this before using trie.
void init()
{
	head = new node();
	head->prefix_count = 0;
	head->is_end = false;
}

// Inserts the given word in the trie
void insert (string word)
{
	node *current = head;
	current->prefix_count++;
	for (unsigned int i=0; i<word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if (current->child[letter] == NULL)
			current->child[letter] = new node();
		current->child[letter]->prefix_count++;
		current = current->child[letter];
	}
	current->is_end = true;
}

// Searches the trie for the given prefix and returns the count of words
// with it as a prefix
int words_with_prefix (string prefix)
{
	node *current = head;
	for (unsigned int i=0; i<prefix.length(); ++i)
	{
		if (current->child[((int)prefix[i]-(int)'a')] == NULL)
			return 0;
		else
			current = current->child[((int)prefix[i]-(int)'a')];
	}
	return current->prefix_count;
}

// searches the trie for the given word and returns true if found
bool search (string word)
{
	node *current = head;
	for (unsigned int i=0; i<word.length(); ++i)
	{
		if (current->child[((int)word[i]-(int)'a')] == NULL)
			return false;
		else
			current = current->child[((int)word[i]-(int)'a')];
	}
	return current->is_end;
}

// Example usage of the trie
int main()
{
	init();
	int I,Q,S;
	cout<<"Enter the no. of inserts,prefix queries and searches"<<endl;
	cin>>I>>Q>>S;
	for (int i=0; i<I; ++i)
	{
		string s;
		cin>>s;
		insert(s);
	}
	for (int i=0; i<Q; ++i)
	{
		string s;
		cin>>s;
		cout<<words_with_prefix(s)<<endl;
	}
	for (int i=0; i<S; ++i)
	{
		string s;
		cin>>s;
		cout<<search(s)<<endl;
	}
	return 0;
}

