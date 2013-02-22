//This is the trie cpp implementation
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#define ALPHABET_SIZE 26
using namespace std;
struct node
{
	bool is_end;
	int prefix_count;
	int  parent;
	struct node* child[ALPHABET_SIZE];
} *head;
int rock,I,i;
void insert (string word,int papa)
{
	node *current = head;
	current->prefix_count++;
	int flag=0;
	for (unsigned int i=0; i<word.length(); ++i)
	{
		flag=0;
		int letter = (int)word[i] - (int)'a';
		if (current->child[letter] == NULL){
		current->child[letter] = new node();
		}
		else{
			if(current->child[letter]->parent==papa)
				flag=1;
		}
		current->child[letter]->parent=papa;
		if(flag==0)
		current->child[letter]->prefix_count++;
		current = current->child[letter];
	}
}
int words_with_prefix (string prefix)
{
	node *current = head;
	rock=0;
	int rec;
	for (unsigned int i=0; i<prefix.length(); ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		rec=current->child[letter]->prefix_count;
//		printf("prefix count %d letter %c parent \n",current->child[letter]->prefix_count,letter+(int)'a');
		if(rec!=I)
			return rock;
			current = current->child[((int)prefix[i]-(int)'a')];
		rock++;
		
	}
	if(current->prefix_count==I)
	return rock;
	else
		return 0;
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
	head=new node();
	head->prefix_count=0;
	cin>>I;
	string s,b;
	for (i=0; i<I; ++i)
	{
		cin>>s;
		b=s;
		for(int j=0;j<b.length();j++){
			insert(s,i);
			s.erase(0,1);
		}
	}
	s=b;
	int max=0;
	for(int j=0;j<b.length();j++){
		int z = words_with_prefix(s);
			if(z>max)
				max=z;
		s.erase(0,1);
	}
	printf("%d\n",max);
	}
	return 0;
}
