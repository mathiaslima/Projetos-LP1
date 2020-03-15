#include <iostream> // geral
#include <sstream> // istringstream and ostringstream
#include <iomanip>
#include <vector>
#include <ostream>// std :: cout , std :: cin
#include <fstream> // std :: ifstream
#include <string> // std :: string

void readFile( std::string urlTitle, std::string urlNumbers, std::vector< std::string > & numbers, std::vector< std::string > & titles ){

    std::ifstream fileNumber;
    fileNumber.open(urlNumbers, std::ios::in);
    std::string number;

    std::ifstream fileTitle;
    fileTitle.open(urlTitle, std::ios::in);
    std::string title;

    while( (fileNumber >> number) )
    {
        numbers.push_back(number);
    }

    while( (std::getline(fileTitle, title)) )
    {
        titles.push_back(title);
    }

    fileNumber.close();
    fileTitle.close();

}

void  WriteInFile( std::string urlTitle, std::string urlNumbers, std::vector< std::string > & numbers, std::vector< std::string > & titles )
{
    std::string line;
    std::ofstream fileDataTable("DataTable.txt", std::ios::out);
    std::ostringstream oss;
    for(std::string name : titles){
        oss << "+" << std::setw(name.size() + 2) << std::setfill('-') << "" ;
    }
    oss << "+\n";

    for(std::string name : titles){
        oss << "| " << name << " ";
    }
    oss << "|\n";

    for(std::string name : titles){
        oss << "+" << std::setw(name.size() + 2) << std::setfill('-') << "" ;
    }
    oss << "+\n";
    int i(0);
    for(std::string number: numbers){
        for(std::string name: titles){
            oss << std::setfill (' '); // Preencher com espaco em branco .
            oss << std::fixed << "|" << std::setw(name.size() + 2) << numbers.at(i);
            i++;
        }
        oss << "|\n";
        if(i == numbers.size()){
            break;
        }
    }

    for(std::string name : titles){
        oss << "+" << std::setw(name.size() + 2) << std::setfill('-') << "" ;
    }
    oss << "+\n";

    fileDataTable << oss.str();

    fileDataTable.close();
}

void printFile(std::string urlDataTable){
    std::string line;
    std::ifstream dataTable;
    dataTable.open(urlDataTable, std::ios::in);
    std::string number;

    while( std::getline(dataTable, line) )
    {
        std::cout << line << std::endl;
    }


}

// int main(int argc, std::string *argv[])
int main()
{
    std::vector<std::string> numbers;
    std::vector<std::string> titles;
    readFile("inputRotulos.txt","inputNumeros.txt", numbers, titles);
    WriteInFile("inputRotulos.txt","inputNumeros.txt", numbers, titles);
    printFile("DataTable.txt");

}

