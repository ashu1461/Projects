/*Ashutosh Singla  <ashu1461@gmail.com>
programm-> 'new_stack'
date->Tue Jan  1 20:46:09 IST 2013*/
#include<stdio.h>
#include<string>
#include<stack>
#include<cstring>
#include<iostream>
using namespace std ;
int function(char a,char b,char c){

}
int que(string S){
	int A[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};
	stack<int> op;
//	stack<int> va;
	int i,a,b,c;
	for(i=0;i<S.length();i++){
//		cout << S.at(i) << "\n" ;
		if(S.at(i)=='('){
		}
		else if(S.at(i)==')'){
			 a = op.top();
			op.pop();
			 b = op.top();
			op.pop();
			 c = op.top();
			op.pop();
//			cout << a <<  " " << b <<" " << c << "\n";
			if(b==-2)
			op.push(a+c);
			else
				op.push(a*c);
		}
		else 
		{
			if(S.at(i)=='*')
				op.push(-1);
			else if(S.at(i)=='+')
				op.push(-2);
			else
				op.push(A[int(S.at(i))-97]);
		}
	}
//	cout << "here we are \n" ;
//	while(!op.empty()){
//		cout << op.top() << "\n";
//		op.pop();
//	}
//	cout << S;
//	que(S);
	return op.top();
}
int main(){

	string S;
	while(1){
	cin >>  S ;
	if(S.at(0)=='0')
		return 0;
	int ans1=que(S);
	cin >> S ;
	int ans2=que(S);
	if(ans1==ans2)
		cout << "Y\n";
	else
		cout << "N\n";
	}

return 0;
}

