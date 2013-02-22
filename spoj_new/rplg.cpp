// this is my firrst implementation of the map function in c plus plus along with some good string functions! :D enjoy ! 
#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int function(string& a){
//	printf("%s\n",a);
//	cout <<"erasing the zeros " << a << "\n" ;
//	b = string("ashutosh");
	
	// now here we have to remove whitespaces !! :D ! 
	// no need really ! :D ! 
	// here we will return the position of label if found ! :D ! 
	// Ok we remove spaces here ! :D !
//	if(a[0]==' ')
//	return 0;
	int pos = a.find_first_not_of(' ');
//	cout << "pos" << pos << "\n";
	a=a.erase(0,pos);
//	cout << a << "\n" ;
}
int labelname(string a , string& b){
	// let us find out what the labelname is ?
	if(a[a.size()-1]==':')
	{
		b=a.substr(0,a.size()-1);	
		return 1;
	}
	return 0;
}
int checkgoto(string a,string &b){
	if(a[0]=='g'&&a[1]=='o'&&a[2]=='t'&&a[3]=='o'){
		b=a.substr(5,a.size()-6);
		return 1;
	}
	return 0;
}
int main(){
	int test;
	scanf("%d",&test);
	int counter;
	long long int sum;
	map <string,int> mymap;
	for(counter=0;counter<test;counter++)
	{
		mymap.clear();
		sum=0;
		int len,i;
		scanf("%d",&len);
		char c;
		scanf("%c",&c);
		char s[1024];
		string a,b;
		for(i=0;i<len;i++){
			gets(s);
			a.clear();
			b.clear();
			a=s;
//			cout << "Starting here"<<a[0]<<"+" << a << "\n";
			if(a[0]==' '){
			function(a);
			}
	//		cout <<"here is a "<< a <<"\n";
			if(labelname(a,b)==1){
				// this is the function used if the label name is found ! fuck yeah ! 
				mymap[b]=i;
//				cout << "here is b "<<b<<"\n";
			}
			if(checkgoto(a,b)==1){
//				//
//				printf("match found at %d\n",i);
//				cout << mymap[b] <<"\n" ;
				sum = sum + i-mymap[b]-1;	
			}	
		}
			cout <<"Scenario #"<<counter+1<<": "<< sum << "\n";
	}
	return 0;
}
