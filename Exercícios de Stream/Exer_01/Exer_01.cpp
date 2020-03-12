#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void printHeader( const std::vector< std::string > & fields_ ){

    cout << "+" << setw(fields_[0].length() + 3) << setfill('-') << "+" << setw(fields_[1].size() + 3) << setfill('-') <<
    "+" << setw(fields_[2].size() + 4) << setfill('-') << "+\n";
    for(string name : fields_){
        cout << "| " << name << " ";
    }
    cout << "|\n";
    for(string name : fields_){
        cout << "+" << setw(name.size() + 2) << setfill('-') << "" ;

    }
    cout << "+\n";

}

int main(){

    vector<string> fieldNames;
    fieldNames.push_back("ITEM");
    fieldNames.push_back("QUANTIDADE");
    fieldNames.push_back("VALOR UNITARIO");
    printHeader( fieldNames );

    return 0;

}
