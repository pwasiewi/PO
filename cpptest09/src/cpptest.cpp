#include<iostream>
using namespace std;

class Node{
protected:
	enum {INT=100, MINUS};
	const int code;
public:
	Node(int c): code(c) {cout << "Powstaje obiekt Node o kodzie: " << code << endl;}
	int eval();
	~Node(){cout << "Usuwam obiekt Node o kodzie: " << code << endl;}
};

class Int: public Node{
public:
	int value;
	Int(int  v): Node(INT), value(v){cout << "Powstaje obiekt Int o wartości: " << value << endl;}
	~Int(){
		cout << "Usuwam obiekt Int o wartości: " << value << endl;
	}
};

class Minus: public Node{
public:
	Node *operand;
	Minus(Node *o):Node(MINUS){operand = o;}
	~Minus(){
		cout << "Usuwam obiekt Minus" << endl;
		delete (Int *)operand;
	}
};

int Node::eval(){
	switch(code){
	case INT: return ((Int *) this)->value;
	case MINUS: return - ((Minus*)this)->operand->eval();
	}
}

int main ()
{
	int i = 0;
	cout << "POCZĄTEK: " << i << endl;
	//Node A(1);
	//cout << A.eval() << endl;
	//Int B(2);
	//cout << B.value << " " << B.eval() << " " << ((Node)B).eval() << endl;
	Int *D = new Int(3);
	Minus C(D);
	cout << C.eval();
	//delete D;
}

