#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

bool encryptFile(const string& filename, bool Encrypt);
bool performCaeserCipher(string& content, bool Encrypt);

#endif // ENCRYPTION_H
