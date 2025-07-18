#ifndef HISTORY_H
#define HISTORY_H

#include <string>

namespace encryption {
namespace Logger {

void log(const std::string& action, const std::string& filename);

} // namespace Logger
} // namespace encryption

#endif // HISTORY_H