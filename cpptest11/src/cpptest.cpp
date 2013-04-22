#include<iostream>
using namespace std;

class Plus;

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
	Plus * operator+(Node &b);
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
		delete operand; operand = NULL;
	}
};

class BNode: public Node{
protected:
	Node *left, *right;
	BNode(Node *l, Node *r, int code):Node(code) {left=l; right=r;}
	~BNode(){cout<< "Usuwam obiekt BNode" << endl; delete left; delete right; left=NULL; right=NULL;}
};

class Plus: public BNode{
public:
	Plus(Node *l, Node *r): BNode(l,r,PLUS) {}
	int eval(){return left->eval()+right->eval();}
};

ostream & operator<<(ostream &sout, Node *n){
	return sout << n->eval();
}

Plus * Node::operator+(Node &b){
	return new Plus(this, &b);
}

int main ()
{
	int i = 0;
	cout << "POCZĄTEK: " << i << endl;
	//Plus C(new Minus (new Int(3)), new Int(4));
	Node *C = new Minus (new Int(3));
	Node *D = new Int(4);
	cout << C << " " << D << endl;
	Node *E = *C + *D;
	cout << E << endl;
	delete E;
	delete D;
	delete C;
}

