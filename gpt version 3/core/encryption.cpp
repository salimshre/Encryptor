#include "encryption.h"
#include <fstream>
#include <cctype>
#include <vector>

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

    std::string outFilename = (encrypt ? "encrypted_" : "decrypted_") + filename;
    std::ofstream outFile(outFilename, std::ios::binary);
    if (!outFile) return false;

    outFile.write(content.data(), content.size());
    outFile.close();

    return true;
}

} // namespace encryption