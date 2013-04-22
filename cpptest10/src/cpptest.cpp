#include<iostream>
using namespace std;

class Node{
protected:
	enum{INT=100, MINUS, PLUS};
	const int code;
public:
	Node(int c): code(c) {cout << "Powstaje obiekt Node o kodzie: " << code << endl;}
	virtual int eval(){
		return code;
	}
	virtual ~Node(){cout << "Usuwam obiekt Node o kodzie: " << code << endl;}
};

class Int: public Node{
public:
	int value;
	Int(int  v): Node(INT), value(v){cout << "Powstaje obiekt Int o wartości: " << value << endl;}
	int eval(){
		return value;
	}
	~Int(){
		cout << "Usuwam obiekt Int o wartości: " << value << endl;
	}
};

class Minus: public Node{
public:
	Node *operand;
	Minus(Node *o):Node(MINUS){operand = o;}
	int eval(){
		return -operand->eval();
	}
	~Minus(){
		cout << "Usuwam obiekt Minus" << endl;
		delete operand;
	}
};

class BNode: public Node{
protected:
	Node *left, *right;
	BNode(Node *l, Node *r, int code):Node(code) {left=l; right=r;}
	~BNode(){delete left; delete right;}
};

class Plus: public BNode{
public:
	Plus(Node *l, Node *r): BNode(l,r,PLUS) {}
	int eval(){return left->eval()+right->eval();}
};

int main ()
{
	int i = 0;
	cout << "POCZĄTEK: " << i << endl;
	//Node A(1);
	//cout << A.eval() << endl;
	//Int B(2);
	//cout << B.value << " " << B.eval() << " " << ((Node)B).eval() << endl;
	Plus C(new Minus (new Int(3)), new Int(4));
	cout << C.eval();
}

