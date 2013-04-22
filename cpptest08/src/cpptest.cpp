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
	virtual ~Node(){}
};

class Int: public Node{
public:
	int value;
	Int(int  v): Node(100), value(v){cout << "Powstaje obiekt o wartości" << value << endl;}
	int eval(){
		return value;
	}
	~Int(){
		cout << "Usuwam obiekt o wartości" << value << endl;
	}
};

class Minus: public Node{
public:
	Node *operand;
	Minus(Node *o):Node(102){operand = o;}
	int eval(){
		return -operand->eval();
	}
	~Minus(){
		delete operand;
	}
};

int main ()
{
	int i = 0;
	cout << i << endl;
	Node A(1);
	cout << A.eval() << endl;
	Int B(2);
	cout << B.value << " " << B.eval() << " " << ((Node)B).eval() << endl;
	Minus C(new Int(3));
	cout << C.eval();
}

