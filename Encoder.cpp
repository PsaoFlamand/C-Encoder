#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
//Substitution Cipher
using namespace std;

string Encrypt(string secret) {
    string result;
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
    string result;
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
    while (getline(sourceInput, secrets))
    {
     
        h1 << Encrypt(secrets);
        secrets = h1.str();
        h2 << Decrypt(secrets);
        truth = h2.str();


    }
    sourceOutput << secrets;
    cout << secrets<<endl;
    cout << truth;
    sourceOutput.close();
    sourceInput.close();

}
