#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

string Encrypt(string secret) {
    string result="";
    char a;
    for (int i = 0; i < secret.length(); i++) {

        if (i % 2 == 0) a = secret[i] + i;     //If even, shift letter forward
        else a = secret[i] - i;                //If odd, shift letter back

        result+=a;
    }
    return result;
}
string Decrypt(string truth) {
    string result="";
    char a;
    for (int i = 0; i < truth.length(); i++) {

        if (i % 2 == 0) a = truth[i] - i;    //If even, shift letter back
        else a = truth[i] + i;               //If odd, shift letter forward
        result+=a;
    }
    return result;
}
void main()
{
    string secrets;
    string truth;
    ifstream sourceInput;
    ofstream sourceOutput;
    sourceInput.open("Input.txt");
    sourceOutput.open("Output.txt");
    int choice;
    cout << "1: Encode" << endl << "2: Decode ->";
    cin >> choice;
    //Encode
    if (choice == 1) {
        while (getline(sourceInput, secrets))
        {
            sourceOutput << Encrypt(secrets) << endl;
        }
    }
    //Decode
    else if (choice == 2) {
        while (getline(sourceInput, truth))
            {
                sourceOutput << Decrypt(truth) << endl;
            }
    }
    else cout << "Invalid Choice";
    sourceOutput.close();
    sourceInput.close();

}
