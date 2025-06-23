#include "encryption.h"
#include <fstream>
#include <cctype>

bool performCaesarCipher(std::string& content, bool Encrypt) {
    int shift = Encrypt ? 3 : -3;
    for (char& ch : content) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }
    return true;
}

bool encryptFile(const std::string& filename, bool Encrypt) {
    std::ifstream inFile(filename);
    if (!inFile) return false;

    std::string content((std::istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (performCaesarCipher(content, Encrypt)) {
        std::ofstream outFile(Encrypt ? "encrypted_" + filename : "decrypted_" + filename);
        if (!outFile) return false;
        outFile << content;
        outFile.close();
        return true;
    }
    return false;
}