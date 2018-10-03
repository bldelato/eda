#include <iostream>
using namespace std;

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

//LinkedListStack.h

template <class T>
class LinkedListStack {
public:

	LinkedListStack() : _cima(NULL), _numElems(0) {
	}

	~LinkedListStack() {
		libera();
		_cima = NULL;
	}

	void invertBase(int m){
		int i=1;
		Nodo *auxcima = _cima, *n, *w, *ult;
		Nodo *top = _cima, *toptemp;

		if(m!=0){ //HAY CACHO QUE SE QUEDA IGUAL
			//si m = 1; entonces auxcima es el primer elemento
			while(i<m){ //coloco auxcima en el final del cacho que no debe cambiarse
				auxcima=auxcima->_sig;
				i++;
			}
			top = auxcima->_sig; // es el primer elemento en moverse
		}

		//CALCULO DEL ULTIMO ELEMENTO
		ult = auxcima;
		while(ult != NULL && ult->_sig != NULL){
			ult=ult->_sig;
		}

		while(top != ult && top != NULL){
			toptemp = top->_sig;

			n=top;
			w=ult->_sig;
			ult->_sig = n;
			if (m == 0) { _cima = n->_sig;}
			else { auxcima->_sig = n->_sig;}
			n->_sig = w;

			top = toptemp;
		}

		if(m==0){
			_cima = ult;
		}
	}

	void push(const T &elem) {
		_cima = new Nodo(elem, _cima);
		_numElems++;
	}

	void pop() {
		if (empty())
			throw EmptyStackException();
		Nodo *aBorrar = _cima;
		_cima = _cima->_sig;
		delete aBorrar;
		--_numElems;
	}

	const T &top() const {
		if (empty())
			throw EmptyStackException();
		return _cima->_elem;
	}

	bool empty() const {
		return _cima == NULL;
	}

	int size() const {
		return _numElems;
	}

	LinkedListStack(const LinkedListStack<T> &other) : _cima(NULL) {
		copia(other);
	}

	LinkedListStack<T> &operator=(const LinkedListStack<T> &other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	bool operator==(const LinkedListStack<T> &rhs) const {
		if (_numElems != rhs._numElems)
			return false;
		Nodo *cima1 = _cima;
		Nodo *cima2 = rhs._cima;
		while ((cima1 != NULL) && (cima2 != NULL)) {
			if (cima1->_elem != cima2->_elem)
				return false;
			cima1 = cima1->_sig;
			cima2 = cima2->_sig;
		}

		return (cima1 == NULL) && (cima2 == NULL);
	}

	bool operator!=(const LinkedListStack<T> &rhs) const {
		return !(*this == rhs);
	}

protected:

	void libera() {
		libera(_cima);
	}

	void copia(const LinkedListStack &other) {

		if (other.empty()) {
			_cima = NULL;
			_numElems = 0;
		} else {
			Nodo *act = other._cima;
			Nodo *ant;
			_cima = new Nodo(act->_elem);
			ant = _cima;
			while (act->_sig != NULL) {
				act = act->_sig;
				ant->_sig = new Nodo(act->_elem);
				ant = ant->_sig;
			}
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

	Nodo *_cima;

	int _numElems;
};

int main83b(){
	int n, m, aux;

	cin >> n;
	while(n!=-1){
		LinkedListStack<int> auxs, s;
		cin >> m;

		for(int i=0;i<n;i++){
			cin >> aux;
			auxs.push(aux);
		}
		for(int j=0;j<n;j++){
			s.push(auxs.top());
			auxs.pop();
		}

		s.invertBase(m);

		for(int k = 0;k<n;k++){
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}
