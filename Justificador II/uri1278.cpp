#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
 
using namespace std;
 
string left_trim( string s ) {
    return s.substr( s.find_first_not_of( " " ) );
}
 
string right_trim( string s ) {
    return s.substr( 0, s.find_last_not_of( " " ) + 1 );
}
 
string trim( string s ) {
    return right_trim( left_trim( s ) );
}
 
string remove_middle_spaces( string s ) {
	//cout << s << endl;
    string r = "";
    //string::iterator it;
	short it;
    bool typed = false;
     
    for( it = 0; it < s.size(); it++ ) {
        if( s[it] >= 'A' && s[it] <= 'Z' ) {
            //cout << s[it] << endl;
            /*if( spaces > 0 ) {
                r += " ";
                spaces = 0;
            }*/
             
            r += s[it];
			typed = true;
        }
        else if (typed) {
            r += " ";
			typed = false;
        }
    }
    r = r.substr (0, r.find_last_not_of (" ") + 1);
	//cout << r << endl;
    return r;
}
 
int main() {
     
    short n;
    //char c, a = '\0';
    bool primeiro = true;
     
    while( cin >> n && n != 0 ) {
        string *linhas = new string[ n ];
        cin.ignore();
        int max = 0;
         
        if( primeiro ) primeiro = false;
        else cout << endl;
         
        for( short i = 0; i < n; i++ ) {
            getline( cin, linhas[ i ] );
            linhas[ i ] = remove_middle_spaces( trim( linhas[ i ] ) );
             
            if( linhas[ i ].size() > max ) {
                max = linhas[ i ].size();
            }
        }
         
        for( short i = 0; i < n; i++ ) {
            cout << setw( max ) << linhas[ i ] << endl;
        }
    }
     
    return 0;
}
