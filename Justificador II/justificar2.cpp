#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
 
using namespace std;
 
string aparar_esq( string s ) {
    return s.substr( s.find_first_not_of( " " ) );
}
 
string aparar_dir( string s ) {
    return s.substr( 0, s.find_last_not_of( " " ) + 1 );
}

string aparar( string s ) {
    return aparar_dir( aparar_esq( s ) );
}
 
 // remover espacos extras
string remove_espacos( string s ) {
    string result = "";
    // extrair texto principal
    //result = s.substr( s.find_first_not_of( " " ) );
    //result = result.substr( 0, result.find_last_not_of( " " ) + 1 );
    // remover espacos propriamente dito
    string::iterator it;
    int espacos = 0;
     
    for( it = s.begin(); it != s.end(); it++ ) {
        if( *it != ' ' ) {
            if( espacos > 0 ) {
                result += " ";
                espacos = 0;
            }
            result += *it;
        }
        else {
            espacos += 1;
        }
    }
    return result;
}
 
int main() {
     
    short sz;
    //char c, a = '';
    bool first = true;
     
    while( cin >> sz && sz != 0 ) {
        string *linhas = new string[ sz ];
        //string linhas[sz];
        cin.ignore();
        // para calcular linha com maior numero de caracteres no texto
        int mlns = 0;
        
        // saltar uma linha apos cada texto dado na saida
        if( first ) first = false;
        else cout << endl;
         
        // ler e consertar as linhas
        for( short i = 0; i < sz; i++ ) {
            getline( cin, linhas[ i ] );
            linhas[ i ] = remove_espacos(aparar( linhas[ i ] ) );
            //linhas[ i ] = remove_espacos( linhas[i] );
             
            if( linhas[ i ].size() > mlns ) {
                mlns = linhas[ i ].size();
            }
        }
        // imprimir as linhas com justificativa tamanho
        // linha com maior numero de caracteres no texto
        for( short i = 0; i < sz; i++ ) {
            cout << setw( mlns ) << linhas[ i ] << endl;
        }
    }
     
    return 0;
}
