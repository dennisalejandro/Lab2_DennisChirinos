#include <iostream>
#include <string>
using namespace std;

bool isPrime(int);
int SumaPrime(int);
int Suma(int, int, int);
void Goldbach(int);
bool isFactor(int, int);

int main() {
	//op siginifica opcion
	int op = 0;
	int Arg = 0;
	//a y b, son factores del ejericio 2
	int a = 0;
	int b = 0;
	while (op!=4) {
		cout << "Ingrese opcion: \n";
        cout << "------------------\n";
        cout << "1) Numeros primos\n";
        cout << "2) suma de numeros\n";
        cout << "3) Conjetura de Goldbach\n";
        cout << "4) Salir \n";
		cin >> op;
		switch (op) {
			case 1: {
				cout << "Ingrese Numero: ";
				cin >> Arg;
				for (int i = 0;i<Arg;i++) {
					if (isPrime(i)) {
						cout << i << " es un numero primo \n";
					}
				}
				cout << "La suma de ellos es de: " << SumaPrime(Arg) << " \n";
			} break;
			case 2: {
				cout << "Ingrese Numero: ";
				cin >> Arg;
				cout << "Ingrese factores A y B: \n";
				cin >> a;
				cin >> b;
				cout << "La suma de los factores de los Numeros es: " <<Suma(a, b, Arg) <<"\n";
			} break;
			case 3: {
				cout << "Ingrese Numero: ";
				cin >> Arg;
				Goldbach(Arg);	
			} break;
		}
	}
	return 0;
}
bool isPrime(int numero){
    if (numero != 2){
        if (numero < 2 || numero % 2 == 0) {
            return false;
        }
        for(int i=3; (i*i)<=numero; i+=2){
            if(numero % i == 0 ){
                return false;
            }
        }
    }
    return true;
}

int Suma(int a, int b, int n) {
	int Suma = 0;
	for (int i = 0;i<=n;i++) {
		if (isFactor(i, a)||isFactor(i, b)) {
			cout << i << "+";
			Suma += i;
		}
	}
	return Suma;
}
int SumaPrime(int Arg) {
	int Total = 0;
	for (int i = 0;i<Arg;i++) {
		if (isPrime(i)) {
			Total += i;
		}
	}
	return Total;
}
bool isFactor(int a, int b) {
	return (a%b==0);
}
void Goldbach(int Arg) {
	int Num1;
	int Num2;
	if ((Arg<=150)&&(Arg>2)) {
		for (int i = 0;i<Arg;i++) {
			if (isPrime(i)) {
				Num1 = i;
				if (isPrime(Arg-Num1)) {
					Num2 = Arg-Num1;
					cout << "Los Numeros son: " << Num1 << " y " << Num2 << "\n";
				}
			}
		} 
	} else {
		cout << "Ingrese un numero apropiado :P \n";
	}
}
