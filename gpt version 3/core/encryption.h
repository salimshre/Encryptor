#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

namespace encryption {

bool processFile(const std::string& filename, bool encrypt, int shift);

} // namespace encryption

#endif // ENCRYPTION_H