#include "encryption.h"
#include <fstream>
#include <cctype>
#include <vector>
#include <string>

namespace encryption {

static void caesarCipher(std::vector<char>& data, int shift) {
    for (char& ch : data) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            char base = std::isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }
}

bool processFile(const std::string& filename, bool encrypt, int shift) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) return false;

    std::vector<char> content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    caesarCipher(content, encrypt ? shift : -shift);

    // Manual output path construction
    size_t lastSlash = filename.find_last_of("/\\");
    std::string dir = (lastSlash == std::string::npos) ? "" : filename.substr(0, lastSlash + 1);
    std::string base = (lastSlash == std::string::npos) ? filename : filename.substr(lastSlash + 1);

    std::string outFilename = dir + (encrypt ? "encrypted_" : "decrypted_") + base;

    std::ofstream outFile(outFilename, std::ios::binary);
    if (!outFile) return false;

    outFile.write(content.data(), content.size());
    outFile.close();

    return true;
}

} // namespace encryption
