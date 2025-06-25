#include "history.h"
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace encryption {
namespace Logger {

void log(const std::string& action, const std::string& filename) {
    std::ofstream hist("history.txt", std::ios::app);
    if (!hist) return;

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm tm{};
#ifdef _WIN32
    std::tm* tm_ptr = std::localtime(&now_c);
if (tm_ptr) {
    tm = *tm_ptr;
}

#else
    localtime_r(&now_c, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
    hist << "[" << oss.str() << "] " << action << ": " << filename << "\n";
}

} // namespace Logger
} // namespace encryption