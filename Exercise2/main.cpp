#include <iostream>
#include <fstream>
#include <iomanip>

//per semplificare le cose
using namespace std;

//creo funzione che mi serve per mappare i punti dell'intervallo
//devo mappare un valore dall'intervallo [1,5] all' intervallo [-1,2]
double mapValue(double x){
	return -1.0 + (x - 1.0) * (3.0 / 4.0);
}




int main()
{
	//devo aprire i file di input e di output e devo assicurarmi non ci siano errori
	ifstream inputFile("data.txt");
	ofstream outputFile("result.txt");
	//controllo eventuali errori 
	if (!inputFile || !outputFile){
		cerr << "Errore nell'apertura del file" << endl;
		return 1;
	}
	
	//Scrivo nel file "result.txt" la riga di intestazione 
	outputFile << "# N Mean" << endl;
	
	//dichiaro le variabili e creo un ciclo while che risolve l'esercizio
	double somma = 0.0;
	double x;
	int cont = 0;
	
	while(inputFile >> x){
		double valore_mappato = mapValue(x);
		somma = somma + valore_mappato;
		cont++;
		
		//calcolo la media 
		double media = somma / cont;
		//scrivo nel file di output il valore ottenuto utilizzando la precisione di 16 cifre
		outputFile << cont << " " << scientific << setprecision(16) << media << endl;
	}
	
	//chiudo entrambi i file di input e output
	inputFile.close();
	outputFile.close();
	
		
    return 0;
}
