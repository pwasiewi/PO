#include<iostream>
#include <boost/shared_ptr.hpp>

using namespace std;

enum{INT=100, MINUS, PLUS};

template<class T>
class Plus;

template<class T>
class Node{
protected:
	const int code;
public:
	Node(int c): code(c) {cout << "Powstaje obiekt Node o kodzie: " << code << endl;}
	virtual T eval(){
		return code;
	}
	virtual ~Node(){cout << "Usuwam obiekt Node o kodzie: " << code << endl;}
	Plus<T> * operator+(Node &b);
};

template<class T>
class Number: public Node<T>{
public:
	T value;
	Number(T  v): Node<T>(INT), value(v){cout << "Powstaje obiekt Number o wartości: " << value << "\n";}
	T eval(){
		return value;
	}
	~Number(){
		cout << "Usuwam obiekt Number o wartości: " << value <<  "\n";
	}
};

template<class T>
class Minus: public Node<T>{
public:
	Node<T> *operand;
	Minus(Node<T> *o):Node<T>(MINUS){operand = o;}
	T eval(){
		return -operand->eval();
	}
	~Minus(){
		cout << "Usuwam obiekt Minus" << endl;
		delete operand; operand = NULL;
	}
};

template<class T>
class BNode: public Node<T>{
protected:
	Node<T> *left, *right;
	BNode(Node<T> *l, Node<T> *r, int code):Node<T>(code) {left=l; right=r;}
	~BNode(){cout<< "Usuwam obiekt BNode" << endl; delete left; delete right; left=NULL; right=NULL;}
};

template<class T>
class Plus: public BNode<T>{
public:
	Plus(Node<T> *l, Node<T> *r): BNode<T>(l,r,PLUS) {}
	T eval(){return this->left->eval()+this->right->eval();}
};

template<class T>
Plus<T> * Node<T>::operator+(Node<T> &b){
	return new Plus<T>(this, &b);
}

template<class T>
ostream & operator<<(ostream &sout, Node<T> &n){
	return sout << n.eval();
}

int main ()
{
	int i = 0;
	cout << "POCZĄTEK: " << i << endl;
	//Plus C(new Minus (new Number(3.3)), new Number(4.2));
	boost::shared_ptr<Node<float>> C1(new Number<float>(1.1));
	boost::shared_ptr<Node<float>> C(new Minus<float> (C1.get()));
	boost::shared_ptr<Node<float>> D(new Number<float>(4.2));
	cout << *C << " " << *D << endl;
	Node<float> *E = *C + *D;
	cout << *E << endl;
	//nie potrzeba delete E, kiedy boost::shared_ptr lub unique_ptr
	cout << "KONIEC" << endl;
}

