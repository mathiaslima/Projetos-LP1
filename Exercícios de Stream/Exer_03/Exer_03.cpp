#include <iostream>
#include <sstream>
#include <string>

int getInteger( std::string inputStr_ ){
    int value;
    std::string number;

    while( true ){
        std::cout << inputStr_ << std::endl;
        std::getline(std::cin,number);
        std::istringstream iss( number );
        iss >> value >> std::ws;
        if ( !(iss.fail() or !iss.eof()) ) {
            return value;
        }
    }

}

int main(){

    auto val = getInteger("Forneca um inteiro : ");

}
