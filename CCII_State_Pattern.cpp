#include <iostream>
using namespace std;

//UN REPRODUCTOR DE AUDIO/MUSICA (PUEDE SER UN ALTAVOZ) QUE TIENE DISTINTOS
//MODOS Y DE ACUERDO A CADA UNO SUS BOTONES TIENEN FUNCIONALIDADES DISTINTAS

//Declaramos la clase reproductor antes para que la clase que guarda el estado
//del objeto reproductor la pueda usar
class Reproductor;

class ReproductorEstado {
protected:
	//Reproductor que estamos usando
	Reproductor* repactual;
public:
	
	//Destructor de estados
	virtual ~ReproductorEstado() {
	}
	
	//Botones del reproductor y funciones que existirán en la mayoría de estados
	virtual void Anterior() const = 0;
	virtual void Siguiente() const = 0;
	virtual void PlayPause() const;
	virtual void ChangeMode() const = 0;
	
	//Ingresar el resproductor
	void set_reproductor(Reproductor *r) {
		this->repactual = r;
	}
};

class Reproductor {
public:
	
	//Indica si el reproductor está reproduciendo
	bool reproduccion;
	int volumen;
	
//	Reproductor(ReproductorEstado *estini) : estadoactual(nullptr) {
//		ChangeMode(estini);
//	}
	
	//Constructor
	Reproductor();
	
	//Destructor del estado actual
	~Reproductor() {
		delete estadoactual;
	}
	
	//Funciones que direccionana las funciones de los botones en el estado
	void Anterior() {
		estadoactual->Anterior();
	}
	void Siguiente() {
		estadoactual->Siguiente();
	}
	void PlayPause() {
		estadoactual->PlayPause();
	}
	
	void SubirVolumen() {
		if (volumen == 100) {
			cout << "Volumen MAXIMO!\n";
		} else {
			this->volumen++;
			cout << "Volumen: " << this->volumen << endl;
		}
	}
	void BajarVolumen() {
		if (volumen == 0) {
			cout << "Volumen minimo! MUTE\n";
		} else {
			this->volumen--;
			cout << "Volumen: " << this->volumen << endl;
		}
	}
	
	//Funciones para cambiar de estado
	void ChangeMode(ReproductorEstado *nuevoest) {
		if (this->estadoactual != nullptr)
			delete this->estadoactual;
		this->estadoactual = nuevoest;
		this->estadoactual->set_reproductor(this);
		reproduccion = true;
	}
	void ChangeMode() {
		estadoactual->ChangeMode();
	}
private:
	//Estado actual del reproductor
	ReproductorEstado* estadoactual;
};

void ReproductorEstado :: PlayPause() const {
	if (this->repactual->reproduccion == true) {
		this->repactual->reproduccion = false;
		cout << "Reproducccion en pausa\n";
	} else {
		this->repactual->reproduccion = true;
		cout << "Reproducccion activada\n";
	}
}

//Modo Radio
class RadioMode : public ReproductorEstado {
public:
	void Anterior() const override{
		cout << "RADIO: Regresa a la anterior estacion\n";
	}
	void Siguiente() const override{
		cout << "RADIO: Reproduce la siguiente estacion\n";
	}
	void PlayPause() const override{
		cout << "RADIO: El modo RADIO siempre está en reproduccion\n";
	}
	void ChangeMode() const override;
};

//Modo USB
class USBMode : public ReproductorEstado {
public:
	void Anterior() const override{
		cout << "USB: Regresa a la anterior carpeta\n";
	}
	void Siguiente() const override{
		cout << "USB: Avanza a la anterior carpeta\n";
	}
	void ChangeMode() const override;
};

//Modo CD
class BluetoothMode : public ReproductorEstado {
public:
	void Anterior() const override{
		cout << "Bluetooth: Regresa a la anterior cancion\n";
	}
	void Siguiente() const override{
		cout << "Bluetooth: Avanza a la siguiente cancion\n";
	}
	void ChangeMode() const override;
};

//Cambiar de modo al estar en RadioMode
void RadioMode :: ChangeMode() const {
	this->repactual->ChangeMode(new USBMode);
	cout << "Modo USB activado\n";
}

//Cambiar de modo al estar en USBMode
void USBMode :: ChangeMode() const {
	this->repactual->ChangeMode(new BluetoothMode);
	cout << "Modo Bluetooth activado\n";
}

//Cambiar de modo al estar en CDMode
void BluetoothMode :: ChangeMode() const {
	this->repactual->ChangeMode(new RadioMode);
	cout << "Modo Radio activado\n";
}

//Constructor del reproductor
Reproductor :: Reproductor() : estadoactual(nullptr){
	volumen = 30;
	reproduccion = true;
	this->ChangeMode(new RadioMode);
}

int main(int argc, char *argv[]) {
	Reproductor* Zealot_S7 = new Reproductor();
	Zealot_S7->Anterior();
	Zealot_S7->PlayPause();
	Zealot_S7->Siguiente();
	Zealot_S7->PlayPause();
	Zealot_S7->SubirVolumen();
	Zealot_S7->ChangeMode();
	
	Zealot_S7->Anterior();
	Zealot_S7->PlayPause();
	Zealot_S7->Siguiente();
	Zealot_S7->PlayPause();
	Zealot_S7->BajarVolumen();
	Zealot_S7->ChangeMode();
	
	Zealot_S7->Anterior();
	Zealot_S7->PlayPause();
	Zealot_S7->Siguiente();
	Zealot_S7->PlayPause();
	Zealot_S7->BajarVolumen();
	Zealot_S7->ChangeMode();
	
	delete Zealot_S7;
	return 0;
}

