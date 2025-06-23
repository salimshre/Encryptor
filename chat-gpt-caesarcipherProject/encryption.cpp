#include "encryption.h"
#include <fstream>
#include <cctype>

using namespace std;

bool performCaeserCipher(string& content, bool Encrypt) {
    int shift = Encrypt ? 3 : -3;
    for (char& ch : content) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }
    return true;
}

bool encryptFile(const string& filename, bool Encrypt) {
    ifstream inFile(filename);
    if (!inFile) return false;

    string content((istreambuf_iterator<char>(inFile)), {}); 
    //Reads entire file content into a string.
    inFile.close();

    if (performCaeserCipher(content, Encrypt)) {
        ofstream outFile(Encrypt 
            ? "encrypted_" + filename 
            : "decrypted_" + filename);
        if (!outFile) return false;
        outFile << content;
        outFile.close();
        return true;
    }
    return false;
}
