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
    for (int i = 0; i < secret.length(); i++) {//If odd, shift letter forward
        if (i % 2 == 0) {
            a = secret[i] + i;
        }
        else {//If odd, shift letter back
            a = secret[i] - i;
        }
        result.push_back(a);
    }
    return result;
}
string Decrypt(string truth) {
    string result="";
    char a;
    for (int i = 0; i < truth.length(); i++) {
        if (i % 2 == 0) { //If even, shift letter back
            a = truth[i] - i;
        }
        else {//If odd, shift letter forward
            a = truth[i] + i;
        }
        result.push_back(a);
    }
    return result;
}
void main()
{
    string secrets;
    string truth;
    stringstream h1,h2;
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
            h1.str(string()); //Clear past contents
            h1 << Encrypt(secrets);
            secrets = h1.str();
            sourceOutput << secrets << endl;
        }
    }
    //Decode
    else if (choice == 2) {
        while (getline(sourceInput, truth))
            {
                h2.str(string()); //Clear past contents
                h2 << Decrypt(truth);
                truth = h2.str();
                sourceOutput << truth << endl;
            }
    }
    else cout << "Invalid Choice";
    sourceOutput.close();
    sourceInput.close();

}
