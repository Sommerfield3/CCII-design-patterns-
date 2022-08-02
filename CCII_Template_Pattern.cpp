#include <iostream>
using namespace std;
class Sandvich{
public:
	void ArmarSandwich() const{
		this->CortarPan();
		if (ConCarne()){/*Si la condición es falsa, no avanza en el condicional*/
			this->AgregarCarne();
		}
		if (ConQueso()){
			this->AgregarQueso();
		}
		if (ConVegetales()){
			this->AgregarVegetales();
		}
		
		this->ColocarPanEncima();
		
		if (ConAceituna()){
			this->AgregarAceituna();
		}
	}
protected:	
	void CortarPan() const{
		cout<<"Colocamos un trozo de pan sobre un plato. \n";
}
	void ColocarPanEncima() const{
		cout<<"Cerramos el sandwich con otro trozo de pan. \n";
	}
		
	/*Los contenidos se agregan en las subclases.*/
	virtual void AgregarCarne() const=0;
	virtual void AgregarQueso() const=0;
	virtual void AgregarVegetales() const=0;
	virtual void AgregarAceituna() const=0;
	/*Los contenidos pueden ser sobrecargados, pero ya tienen un valor por defecto.*/
	virtual bool ConCarne() const {return true;}
	virtual bool ConQueso() const {return true;}
	virtual bool ConVegetales() const {return true;}
	virtual bool ConAceituna() const {return true;}
};
class SandwichNormal:public Sandvich{
protected:
	void AgregarCarne() const override{
		cout<<"Agregamos una rebanada mediana de jamón. \n";
	}
	void AgregarQueso() const override{
		cout<<"Agregamos 3 rebanadas de queso suizo. \n";
	}
	void AgregarVegetales() const override{
		cout<<"Agregamos 2 trozos de tomate y un trozo de lechuga. \n";
	}
	void AgregarAceituna() const override{
		cout<<"Colocamos una aceituna encima. \n";
	}
};
class SandwichSinCarne:public Sandvich{
protected:
	void AgregarCarne() const override{
		cout<<"Agregamos una rebanada mediana de jamón. \n";
	}
	void AgregarQueso() const override{
		cout<<"Agregamos 3 rebanadas de queso suizo. \n";
	}
	void AgregarVegetales() const override{
		cout<<"Agregamos 2 trozos de tomate y un trozo de lechuga. \n";
	}
	void AgregarAceituna() const override{
		cout<<"Colocamos una aceituna encima. \n";
	}
	bool ConCarne() const override{return false;}
};
int main(int argc, char *argv[]) {
	cout<<"Sandwich normal: "<<endl;
	Sandvich *SandvichTF2=new SandwichNormal;
	SandvichTF2->ArmarSandwich();
	cout<<endl;
	
	cout<<"Sandwich sin carne: "<<endl;
	Sandvich *SandvichTF2SinCarne=new SandwichSinCarne;
	SandvichTF2SinCarne->ArmarSandwich();
	cout<<endl;
	return 0;
}

