#include <ostream>// std :: cout , std :: cin
#include <fstream> // std :: ifstream
#include <string> // std :: string
#include <iostream>
#include <vector>

using namespace std;

void getNumbersInFile( vector<string> & numeros ){
    ifstream file;
    file.open("input.txt", ios::in);
    std::string numero;
    while(file >> numero){
        numeros.push_back(numero);
    }
    for(string n : numeros){
        cout << n << " ";
    }
    file.close();
}

void setNumbersInFile( vector<string> & numeros ){
    ofstream file("InvertedOutput.txt", ios::out);

    for(int i = numeros.size(); i >= 0; --i ){
        file << numeros[i] << endl;
    }
    file.close();
}


int main(){
    vector<string> numeros;

    getNumbersInFile(numeros);
    setNumbersInFile(numeros);

    return 0;
}
