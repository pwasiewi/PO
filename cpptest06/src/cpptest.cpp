#include<iostream>
using namespace std;

class Node{
protected:
	const int code;
public:
	Node(int c): code(c) {}
	virtual int eval(){
		return code;
	}
};

class Int: public Node{
public:
	int value;
	Int(int  v): Node(100), value(v){}
	int eval(){
		return code+1;
	}
};

int main ()
{
	int i = 0;
	cout << i << endl;
	Node A(1);
	cout << A.eval() << endl;
	Int B(2);
	cout << B.value << " " << B.eval() << " " << ((Node)B).eval();
}

