#include <iostream>
using namespace std;

//#include "../Linear_TADS/Stack.h"
//#include "../Linear_TADS/Queue.h"

//Exceptions.h

class ExcepcionTAD {
public:
	ExcepcionTAD() {}
	ExcepcionTAD(const std::string &msg) : _msg(msg) {}

	const std::string msg() const { return _msg; }

	friend std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e);

protected:
	std::string _msg;
};

inline std::ostream &operator<<(std::ostream &out, const ExcepcionTAD &e) {
	out << e._msg;
	return out;
}


#define DECLARA_EXCEPCION(Excepcion) \
class Excepcion : public ExcepcionTAD { \
public: \
Excepcion() {}; \
Excepcion(const std::string &msg) : ExcepcionTAD(msg) {} \
};

DECLARA_EXCEPCION(EmptyStackException);

DECLARA_EXCEPCION(FullStackException);


DECLARA_EXCEPCION(EmptyQueueException);


DECLARA_EXCEPCION(EmptyDequeException);

DECLARA_EXCEPCION(EmptyListException);


DECLARA_EXCEPCION(InvalidAccessException);

DECLARA_EXCEPCION(EArbolVacio);

DECLARA_EXCEPCION(EClaveErronea);

//Queue.h

template <class T>
class Queue {
public:

	Queue() : _prim(NULL), _ult(NULL), _numElems(0) {
	}

	~Queue() {
		libera();
		_prim = _ult = NULL;
	}

	void push_back(const T &elem) {
		Nodo *nuevo = new Nodo(elem, NULL);

		if (_ult != NULL)
			_ult->_sig = nuevo;
		_ult = nuevo;
		if (_prim == NULL)
			_prim = nuevo;
		_numElems++;
	}


	void pop_front() {
		if (empty())
			throw EmptyQueueException();
		Nodo *aBorrar = _prim;
		_prim = _prim->_sig;
		delete aBorrar;
		--_numElems;
		if (_prim == NULL)
			_ult = NULL;
	}

	const T &front() const {
		if (empty())
			throw EmptyQueueException();
		return _prim->_elem;
	}


	bool empty() const {
		return _prim == NULL;
	}

	int size() const {
		return _numElems;
	}


	Queue(const Queue<T> &other) : _prim(NULL), _ult(NULL) {
		copia(other);
	}

	Queue<T> &operator=(const Queue<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	bool operator==(const Queue<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		Nodo *p1 = _prim;
		Nodo *p2 = rhs._prim;
		while ((p1 != NULL) && (p2 != NULL)) {
			if (p1->_elem != p2->_elem)
				return false;
			p1 = p1->_sig;
			p2 = p2->_sig;
		}

		return (p1 == NULL) && (p2 == NULL);
	}

	bool operator!=(const Queue<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void libera() {
		libera(_prim);
	}

	void copia(const Queue &other) {

		if (other.empty()) {
			_prim = _ult = NULL;
			_numElems = 0;
		} else {
			Nodo *act = other._prim;
			Nodo *ant;
			_prim = new Nodo(act->_elem);
			ant = _prim;
			while (act->_sig != NULL) {
				act = act->_sig;
				ant->_sig = new Nodo(act->_elem);
				ant = ant->_sig;
			}
			_ult = ant;
			_numElems = other._numElems;
		}
	}

private:


	class Nodo {
	public:
		Nodo() : _sig(NULL) {}
		Nodo(const T &elem) : _elem(elem), _sig(NULL) {}
		Nodo(const T &elem, Nodo *sig) :
		    _elem(elem), _sig(sig) {}

		T _elem;
		Nodo *_sig;
	};

	static void libera(Nodo *prim) {
		while (prim != NULL) {
			Nodo *aux = prim;
			prim = prim->_sig;
			delete aux;
		}
	}

	Nodo *_prim;

	Nodo *_ult;

	int _numElems;
};

//Stack.h

template <class T>
class Stack {
public:

	static const int TAM_INICIAL = 10;

	Stack() {
		inicia();
	}
	~Stack() {
		libera();
	}

	void push(const T &elem) {
		_v[_numElems] = elem;
		_numElems++;
		if (_numElems == _tam)
			amplia();
	}


	void pop() {
		if (empty())
			throw EmptyStackException();
		--_numElems;
	}

	const T &top() const {
		if (empty())
			throw EmptyStackException();
		return _v[_numElems - 1];
	}

	bool empty() const {
		return _numElems == 0;
	}


	int size() const {
		return _numElems;
	}

	Stack(const Stack<T> &other) {
		copia(other);
	}

	Stack<T> &operator=(const Stack<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	bool operator==(const Stack<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		for (unsigned int i = 0; i < _numElems; ++i)
			if (_v[i] != rhs._v[i])
				return false;
		return true;
	}

	bool operator!=(const Stack<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void inicia() {
		_v = new T[TAM_INICIAL];
		_tam = TAM_INICIAL;
		_numElems = 0;
	}

	void libera() {
		delete []_v;
		_v = NULL;
	}

	void copia(const Stack &other) {
		_tam = other._numElems + TAM_INICIAL;
		_numElems = other._numElems;
		_v = new T[_tam];
		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = other._v[i];
	}

	void amplia() {
		T *viejo = _v;
		_tam *= 2;
		_v = new T[_tam];

		for (unsigned int i = 0; i < _numElems; ++i)
			_v[i] = viejo[i];

		delete []viejo;
	}

private:

	T *_v;

	unsigned int _tam;

	unsigned int _numElems;
};

template <typename T>
void invertBase(Stack<T> &s, int m);

int mainI83a(){
	int n, m, aux;

	cin >> n;
	while(n!=-1){
		Stack<int> auxs, s;
		cin >> m;

		for(int i=0;i<n;i++){
			cin >> aux;
			auxs.push(aux);
		}
		for(int j=0;j<n;j++){
			s.push(auxs.top());
			auxs.pop();
		}

		invertBase(s, m);

		for(int k = 0;k<n;k++){
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}

template <typename T>
void invertBase(Stack<T> &s, int m){
	Stack<T> original_part;
	Queue<T> aux;
	int size = s.size();

	for(int a=0;a<m;a++){
		original_part.push(s.top());
		s.pop();
	}

	while(!s.empty()){
		aux.push_back(s.top());
		s.pop();
	}
	for(int p=0;p<size;p++){
		if(!aux.empty()){
			s.push(aux.front());
			aux.pop_front();
		}
		else{
			s.push(original_part.top());
			original_part.pop();
		}
	}
}
