#include<iostream>
#include<vector>
#include"tv.cpp"
#include"radio.cpp"

class Implementacion {
public:
	virtual ~Implementacion() {}
	virtual std::vector<tv> OperationImplementation() const = 0;
	virtual std::vector<radio> OperationImplementation2() const = 0;
	vector<radio> Operationradio() const override ;
};

/**
* Each Concrete Implementation corresponds to a specific platform and
* implements the Implementation interface using that platform's API.
*/
class Television : public Implementacion {
public:
	std::vector<tv> OperationImplementation() const override {
		vector<tv> canalnuevo;
		// atributos del televisor
		int vol;bool est;string marca;
		//atributos del canal
		int ncanal;string nom;
		cout<<"tv encendida"<<endl;
		est=true;
		cout<<"Intoduzca los datos de la tv y del canal"<<endl;
		cout<<"volumen"<<endl;
		cin>>vol;
		cout<<"Marca del televisor"<<endl;
		cin>>marca;
		cout<<"N° de canal"<<endl;
		cin>>ncanal;
		cout<<"Nombre del canal"<<endl;
		cin>>nom;
		canalnuevo.push_back(vol,canal(ncanal,nom),est,marca)
		
		return canal;
	}
};
class Radio : public Implementacion {
public:
	std::vector<radio> OperationImplementation2() const override {
		vector<radio> canalfloat;
		int vol1;float canal;bool est;
		cout<<"Radio encendida"<<endl;
		est=true;
		cout<<"Introduzca los datos de la radio "<<endl;
		cout<<"Canal"<<endl;
		cin>>canal;
		canalfloat.push_back(vol1,canal,est)
		return canalfloat;
	}
};

/**
* The Abstraction defines the interface for the "control" part of the two class
* hierarchies. It maintains a reference to an object of the Implementation
* hierarchy and delegates all of the real work to this object.
*/

class Abstraccion {
	/**
	* @var Implementation
	*/
protected:
	Implementacion* implementation_;
	
public:
	Abstraccion(Implementacion* implementation) : implementation_(implementation) {
	}
	
	virtual ~Abstraccion() {
	}
	
	virtual std::vector<tv> Operation() const {
	
		
		cout<<"Nuevo canal de tv:"<<endl;
		return this->implementation_->OperationImplementation();
	}
};
/**
* You can extend the Abstraction without changing the Implementation classes.
*/
class ExtendedAbstraction : public Abstraccion{
public:
	ExtendedAbstraction(Implementacion* implementation) : Abstraccion(implementation) {
	}
	std::vector<radio> Operation() const override {
	cout<<"Nuevo canal de radio:"<<endl;
		return this->implementation_->OperationImplementation2();
	}
};

void ClientCode(const Abstraccion& abstraction) {
	// ...
	std::cout<<abstraction.Operation();
	// ...
}

int main(){
	Implementacion* implementation = new Television;
	Abstraction* abstraction = new Abstraction(implementation);
	ClientCode(*abstraction);
	std::cout << std::endl;
	delete implementation;
	delete abstraction;
	
	implementation = new Radio;
	abstraction = new ExtendedAbstraction(implementation);
	ClientCode(*abstraction);
	
	delete implementation;
	delete abstraction;
	
	return 0;
}
