#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int partition (int array[], int inicio, int fim)
{
    int pivot = array[fim]; 
    int j= (inicio - 1);
 
    for (int k = inicio; k <= fim- 1; k++)
    {

        if (array[k] <= pivot)
        {
            j++;
            int aux = array[j];
            array[j] = array[k];
            array[k] = aux;
        }
    }

    int aux = array[j+ 1];
    array[j+ 1] = array[fim];
    array[fim] = aux;
    
    return (j+ 1);
}
 
void quickSort(int array[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int x = partition(array, inicio, fim);

        quickSort(array, inicio, x - 1);
        quickSort(array, x + 1, fim);
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

    quickSort(array, 0 , tamanho);

    for(int x=0; x<=(tamanho-1); x++)
    {
        cout << array[x] << endl;
    }
}
