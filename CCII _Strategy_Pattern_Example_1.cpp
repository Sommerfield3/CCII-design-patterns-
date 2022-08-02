#include <iostream>
using namespace std;

class Estrategia {
public:
	virtual void InterfazAlgoritmo() = 0;
};

class EstrategiaConcretaA: public Estrategia {
public:
	virtual void InterfazAlgoritmo() {
		cout<<"Uso estrategia A" <<endl;
	}
};
class EstrategiaConcretaB: public Estrategia {
public:
	virtual void InterfazAlgoritmo() {
		cout<<"Uso estrategia B" <<endl;
	}
};
class EstrategiaConcretaC: public Estrategia {
public:
	virtual void InterfazAlgoritmo() {
		cout<<"Uso estrategia C" <<endl;
	}
};

class Contexto {
private:
	Estrategia *_estrategia;
public:
	Contexto(Estrategia *estrategia):_estrategia(estrategia) {}
void set_estrategia(Estrategia *estrategia) {
		_estrategia = estrategia;
	}
void InterfazContexto() {
	_estrategia->InterfazAlgoritmo();
    }	
};
int main(int argc, char *argv[]) {
	Contexto contexto(new EstrategiaConcretaA);
	contexto.InterfazContexto();
	
	contexto.set_estrategia(new EstrategiaConcretaB);
	contexto.InterfazContexto();
	
	contexto.set_estrategia(new EstrategiaConcretaC);
	contexto.InterfazContexto();
	return 0;
}
