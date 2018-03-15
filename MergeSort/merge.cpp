#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void merge(int array[], int inicio, int meio, int fim) 
{
	
	int j = inicio, aux = 0;
	int k = meio+1;
	int tamanho = fim-inicio+1;
  	int array2[tamanho];

  	while(j<=meio && k<=fim)
		{
 		if(array[j] <= array[k])
 		{
        	array2[aux] = array[j];
            j++;
        }
			
		else
		{
       		array2[aux] = array[k];
            k++;
        }

		aux++;
 	}

	while(j<=meio)
	{  
    	array2[aux] = array[j];
    	aux++;
    	j++;
 	}

 	while(k<=fim)
 	{   
    	array2[aux] = array[k];
    	aux++;
    	k++;
 	}

 	for(aux=inicio; aux<=fim; aux++)
    {
    	array[aux] = array2[aux-inicio];
 	}
}
 
void mergeSort(int array[], int inicio, int fim){
    if (inicio < fim) 
    {
        int meio = (inicio+fim)/2;
 
        mergeSort(array, inicio, meio);
        mergeSort(array, meio+1, fim);
        merge(array, inicio, meio, fim);
     }
 }

 int main() {

	char arquivo[30]; 
	cout << "Digite o nome do arquivo para o teste: " << endl;
	cin >> arquivo;

	int array[100000]; 
	int tamanho = 0; 

	ifstream myReadFile;
	myReadFile.open(arquivo);
	char output[1000];
	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			myReadFile >> output;
			array[tamanho] = atoi(output);
			tamanho++;
		}
	}
	
	myReadFile.close();  

	mergeSort(array, 0 , tamanho);


    for(int x=0; x<=(tamanho-1); x++)
    {
        cout << array[x] << endl;
    }
}