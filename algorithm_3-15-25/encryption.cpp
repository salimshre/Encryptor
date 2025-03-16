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
    // Open the input file
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    // Read the content of the file
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (performCaeserCipher(content, Encrypt)) {
        // Create an output file and write the modified content
        ofstream outFile(Encrypt ? "encrypted_" + filename : "decrypted_" + filename);
        if (!outFile) {
            return false;
        }

        outFile << content;
        outFile.close();
        return true;
    }

    return false;
}
