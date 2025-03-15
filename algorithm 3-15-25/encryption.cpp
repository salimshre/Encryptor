#include "encryption.h"
#include <fstream>
#include <cctype>

using namespace std;

bool performCaeserCiphe(string& content, bool Encrypt) {
    int shift = Encrypt ? 3 : -3;
    
    for (char& ch: content) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shif +26) % 26 + base);
        }
    }
    return true;
}

bool encryptFile(const string& filename, bool Encrypt){
    //open the input file
    ifstream inFile(filename);
    if (!infile) {
        return false;

    }
    

    //read the content of the file
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (performCaeserCiphe(content, Encrypt)) {
        //create an output file and writing the modified content
        ofstream outFile(Encrypt ? "encrypted_" + filename : "decrypted_" + filename);
        if (!outFile) {
            return false;

        }

        outFile << content;
        outFile.close();

        return true;

    }



}