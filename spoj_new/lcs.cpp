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
} *head[20];
int rock,I,i,cu;
void init(){
	for(i=0;i<20;i++){
		head[i]=new node();
		head[i]->prefix_count=0;
	}
}
void insert (string word,int papa)
{
	node *current = head[cu];
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
//			cout << "here daddt "<< current->child[letter]->parent << "\n";
			if(current->child[letter]->parent==papa)
				flag=1;
		}
		current->child[letter]->parent=papa;
		if(flag==0)
		current->child[letter]->prefix_count++;
//		printf("prefix count %d letter %c parent \n",current->child[letter]->prefix_count,letter+(int)'a');
//		cout << current->child[letter]->parent << "\n";
		current = current->child[letter];
	}
}
int words_with_prefix (string prefix)
{
	node *current = head[cu];
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
	cu=0;
	init();
	while(test--){
	cin>>I;
	string s,b;
	for (i=0; i<I; ++i)
	{
		cin>>s;
		b=s;
		for(int j=0;j<b.length();j++){
//			cout << s << "\n";
			insert(s,i);
			s.erase(0,1);
		}
	}
	s=b;
	int max=0;
	for(int j=0;j<b.length();j++){
//		cout << "tryng out " << s << "\n";
		int z = words_with_prefix(s);
			if(z>max)
				max=z;
		s.erase(0,1);
	}
	printf("%d\n",max);
	cu++;
	}
	return 0;
}
