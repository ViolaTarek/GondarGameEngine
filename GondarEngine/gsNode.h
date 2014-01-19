#ifndef __GS_NODE__
#define __GS_NODE__

#define generics template <class T>

generics
class gsNode {
private:
	T value;
	gsNode* next;
	
public:
	gsNode<T>(void);
	gsNode<T>(T value);
	~gsNode<T>(void);

	gsNode<T>* getNext(void);
	void setNext(gsNode<T>* next);

	T getValue(void);
	void setValue(T value);
};

#endif