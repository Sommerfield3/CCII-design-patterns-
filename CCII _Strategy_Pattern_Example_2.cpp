#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Clase abstracta de Algoritmos de busqueda de arbol recubridor minimo
class MinSpanTreeAlgorithm {
public:
	virtual ~MinSpanTreeAlgorithm() {}
	virtual std::string ejecutar() const = 0;
	// parametros se pueden implementar el paso del grafo como vectores
	// (const vector<int> &FirstNode, const vector<int> &LastNode)
	// o como matriz (int** Matrix)
};

class Context {
private:
	MinSpanTreeAlgorithm *algorythm_;
public:
	Context(MinSpanTreeAlgorithm *MinSpanTreeAlgorithm = nullptr) : algorythm_(MinSpanTreeAlgorithm){}
	~Context(){
		delete this->algorythm_;
	}
	void set_algorithm(MinSpanTreeAlgorithm *MinSpanTreeAlgorithm){
		delete this->algorythm_;
		this->algorythm_ = MinSpanTreeAlgorithm;
	}
	void EjecutarAlgoritmo() const {
		std::cout << "Context: Buscando el Arbol Recubridor Minimo usando el algoritmo especificado\n";
		std::string result = this->algorythm_->ejecutar();
		std::cout << result << "\n";
	}
};

class PrimAlgorithm : public MinSpanTreeAlgorithm {
public:
	std::string ejecutar() const override {
		std::string result;
		result = "Resultado de PrimAlgorithm.";
		// Aquí aplicar la lógica del algoritmo Prim, segun a los
		// parametros que podría recibir ejecutar()
		return result;
	}
};
class KruskalAlgorithm : public MinSpanTreeAlgorithm {
public:
	std::string ejecutar() const override {
		std::string result;
		result = "Resultado de KruskalAlgorithm.";
		// Aquí aplicar la lógica del algoritmo Kruskal, segun a los
		// parametros que podría recibir ejecutar()
		return result;
	}
};

void CodigoCliente() {
	Context *context = new Context(new PrimAlgorithm);
	std::cout << "Cliente: MinSpanTreeAlgorithm ha sido establecido a PrimAlgorithm\n";
	context->EjecutarAlgoritmo();
	std::cout << "\n";
	std::cout << "Cliente: MinSpanTreeAlgorithm ha sido establecido a KruskalAlgorithm.\n";
	context->set_algorithm(new KruskalAlgorithm);
	context->EjecutarAlgoritmo();
	delete context;
}

int main() {
	CodigoCliente();
	return 0;
}
