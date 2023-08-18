#include <iostream>

using namespace std;

int mayor(int arrNum[15], int n);
void Fibonacci(int fibonacci[30]);
void orden(int fibonacci[30], char arrWord[15], int arrNum[15], int n, int mayor);

int main(int argc, char** argv) {
	int n, i, num, Mayor;
	int serie[15];
	int arrNum[15], fibonacci[30];
	char arrWord[15];
	char word;
	cout << "Ingrese la cantidad de numeros fibonacci y caracteres que tendra la palabra:  ";
	cin >> n;
	cout << "Ingrese la serie de numeros: ";
	for (i = 0; i < n; i++) {
		cin >> num;
		arrNum[i] = num;
	}
	cout << "Ingrese la serie de letras:  ";
	for (i = 0; i < n; i++) {
		cin >> word;
		arrWord[i] = word;
	}
	Fibonacci(fibonacci);
	Mayor = mayor(arrNum, n);
	orden(fibonacci, arrWord, arrNum, n, Mayor);
	return 0;
}

int mayor(int arrNum[15], int n) {
	int i = 0, mayor = 0;
	while (i < n) {
		if (arrNum[i] > mayor) {

			mayor = arrNum[i];
		}
		i++;
	}
	return mayor;
}

void Fibonacci(int fibonacci[30]) {
	fibonacci[0] = 1;
	fibonacci[1] = 2;
	for (int i = 2; i < 30; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

}
void orden(int fibonacci[30], char arrWord[15], int arrNum[15], int n, int mayor) {
	int i = 0, j = 0;
	bool stop = false, found = false;
	cout << "La palabra decodificada es: ";
	while (!stop) {

		while (i < n) {
			if (fibonacci[j] == arrNum[i]) {
				cout << arrWord[i];
				found = true;
			}
			i++;
			if (i == n && found == false) {
				cout << " ";
			}
		}
		if (fibonacci[j] == mayor) {
			stop = true;
		}
		j++;
		i = 0;
		found = false;
	}
}