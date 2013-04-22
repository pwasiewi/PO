#include<iostream>
using namespace std;

class Node{
	const int code;
public:
	Node(int c): code(c) {}
	int eval(){
		return code;
	}
};

struct {
	int code;
} node;

int eval(){
	return node.code;
}

int main ()
{
	int i = 0;
	cout << i << endl;
	Node A(1);
	cout << A.eval() << endl;
	Node B(2);
	cout << B.eval();
}

