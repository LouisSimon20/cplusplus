// C++ program to convert
// Hexadecimal number to Binary

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// function to convert
// Hexadecimal to Binary Number
void HexToBin(string hexdec)
{
    long int i = 0;
    ofstream file("./binary", ios::binary);
    
    while (hexdec[i])
    {

        switch (hexdec[i])
        {
        case '0':
            file << "0000";
            break;
        case '1':
            file << "0001";
            break;
        case '2':
            file << "0010";
            break;
        case '3':
            file << "0011";
            break;
        case '4':
            file << "0100";
            break;
        case '5':
            file << "0101";
            break;
        case '6':
            file << "0110";
            break;
        case '7':
            file << "0111";
            break;
        case '8':
            file << "1000";
            break;
        case '9':
            file << "1001";
            break;
        case 'A':
        case 'a':
            file << "1010";
            break;
        case 'B':
        case 'b':
            file << "1011";
            break;
        case 'C':
        case 'c':
            file << "1100";
            break;
        case 'D':
        case 'd':
            file << "1101";
            break;
        case 'E':
        case 'e':
            file << "1110";
            break;
        case 'F':
        case 'f':
            file << "1111";
            break;
        default:
            file << "\nInvalid hexadecimal digit "
                 << hexdec[i];
        }
        i++;
    }
    file.close();
}

string* GetHex(string path)
{
    ifstream file(path.c_str(), ios::in);
    if(file){
        char cara;
        string* chainehex = new string;
        int i =0;
        while(file.get(cara)){
            if((cara !='\n') and (cara!=' ')){
                //c'est un bon
                *chainehex += cara;
                i++;
            }

        }
        file.close();
        return chainehex;
    }
}
// driver code
int main()
{
    // Get the Hexadecimal number
    string* hexdec;
    hexdec = GetHex("./hexx");
    cout << *hexdec;
    ofstream file2("./binary2", ios::binary);
    file2 << *hexdec;
    delete hexdec;
    file2.close();



    // Convert HexaDecimal to Binary
    cout << "\nEquivalent Binary value is : ";
    HexToBin(*hexdec);
    cout << endl;

    return 0;
}