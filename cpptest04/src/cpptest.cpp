#include<iostream>
using namespace std;

class Node{
public:
	const int code;
	Node(int c): code(c) {}
	int eval(){
		return code;
	}
};


int main ()
{
	int i = 0;
	cout << i << endl;
	Node A(1);
	cout << A.eval();
}

