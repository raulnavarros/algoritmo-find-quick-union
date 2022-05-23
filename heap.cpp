#include <iostream>
using namespace std;

enum TipoPalo {Espada, Oro, Basto, Copa};

struct Carta{
	TipoPalo palo;
	int valor;
};

struct Mazo{
	int cantidadCartas;
	Carta** cartas;
}

void MostrarCarta(Mazo* cartas);
void Destruir(Mazo* carta);
void MostrarMazo(Mazo* cartas, int cantidad);
Mazo* CrearMazoEspanol();
Carta* CrearMazoTruco();


int main() {
	Mazo* mazo = CrearMazoEspanol();
        Mazo* mazoTruco = CrearMazoTruco();//implementar
	MostrarMazo(mazo, 48);
        MostrarMazo(mazoTruco, 40);//implementar

	// TODO hacer que las variables mazo y mazoTructo sean de tipo Mazo
	// y refactorizar las funciones creacionalaes para que ande todo
	// Hacer funcion DestruirMazo para no tener memory leaks
	return 0;
}

void IncializarPorPalo(Mazo* mazo, int indiceCarta, TipoPalo palo){
	for(int i = 0 ; i < 12; ++i){
		mazo->cartas[i+indiceCarta] = new Carta;
	        mazo->cartas[i+indiceCarta]->palo= palo;
		mazo->cartas[i+indiceCarta]->valor = i + 1;
	}
}

Mazo* CrearMazoEspanol(){
	Mazo* mazo = new Mazo;
	mazo->cantidadCartas = 48;
	mazo->cartas = new Carta*[48];
	IncializarPorPalo(mazo, 0, Espada);
	IncializarPorPalo(mazo, 12, Oro);
	IncializarPorPalo(mazo, 24, Basto);
	IncializarPorPalo(mazo, 36, Copa);
	return mazo;
}

void MostrarCarta(Carta* cartas){
	switch(cartas->palo){
		case Espada:
			cout<<"Espada";
			break;
		case Oro:
			cout<<"Oro";
			break;
		case Copa:
			cout<<"Copa";
			break;
		case Basto:
			cout<<"Basto";
			break;
		default:
			break;
	}
}

void MostrarMazo(Mazo* mazo, int cantidad){
	for(int i=0; i<cantidad; ++i){
	cout<<mazo->cartas[i]->valor<<" ";
	MostrarCarta(mazo->cartas[i]);
		if(((i+1)%12) == 0)
			cout<<endl;
		else
			cout<<"-> ";
	}
}

void DestruirMazoCartas(Mazo* mazo){
	if(mazo != NULL){
		for(int i=0; i < mazo->cantidadCartas; ++i){
			delete mazo->cartas[i];
    	        }
		delete mazo;
        }
}

Mazo* CrearMazoTruco(){
	Mazo* mazoEspanol = new Mazo[40];
	//TODO Terminar


	return mazoEspanol;
}
