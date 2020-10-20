#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
#include <cstdlib>
using namespace std;

string Encrypt(string secret) {
    string result;
    //convert char into its hex equivalent
    for (int i = 0; i < secret.length(); i++) {
        stringstream ss;
        char a = secret[i];
        int ia = a; ////Convert ASCII
        ss << hex << ia + 32; // Convert dec to hex
        string res(ss.str());
        wchar_t uni = strtol(res.c_str(), NULL, 16); //Convert to unicode     
        result.push_back(uni);
    }
    return result;
}
void main()
{
    string secrets;
    stringstream holder;
    ifstream sourceInput;
    string out;
    ofstream sourceOutput;
    sourceInput.open("Input.txt");
    sourceOutput.open("Output.txt");
    while (getline(sourceInput, secrets))
    {
        holder.clear();
        holder << Encrypt(secrets);
        secrets = holder.str();
    }
    sourceOutput << secrets;
    sourceOutput.close();
    sourceInput.close();

}
