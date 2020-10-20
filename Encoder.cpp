#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
 
using namespace std;
const char alphabet[] = { ' ', '!', '"', '#', '$', '%', '&', '\'','(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', 'ˆ', '_', '`','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '}', '~' };
int chunkSize = 2;
string results="";

string Encrypt(string secret) {
    string str3;
    unordered_map <char, int> map;
    int alphaSize = sizeof(alphabet) / sizeof(alphabet[0]);
    //Convert ASCII data to map
    for (int i = 0; i < alphaSize; i++) {
        map[alphabet[i]] = i;
    }
    //convert char into its hex equivalent
    for (int i1 = 0; i1 < secret.length(); i1++) {
        stringstream ss;
        int i = map[secret[i1]];
        ss << hex << i + 32; // int decimal_value
        string res(ss.str());                
        results+=res;
    }
    //Now convert chunks of two ints into their unicode equivalent
    for (int i2 = 0; i2 < results.length(); i2 += chunkSize)
    {
        if (i2 + chunkSize > stringLength) {
            chunkSize = stringLength - i2;
        }
        string str2 = results.substr(i2, chunkSize);
        stringstream ss2(str2);
        int x = 0;
        ss2 >> x;
        str3.push_back(char(x));
    }
    return str3;
}
void main()
{
    string secrets;
    stringstream holder;
    ifstream sourceInput;
    ofstream sourceOutput;
    sourceInput.open("Input.txt");
    sourceOutput.open("Output.txt");
    while (getline(sourceInput, secrets))
    {
        results.clear();
        holder.clear();
        holder << Encrypt(secrets);
        secrets = holder.str();
    }
    sourceOutput << secrets;
    sourceOutput.close();
    sourceInput.close();
 
}
