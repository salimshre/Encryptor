#include "history.h"
#include <fstream>
#include <ctime>

void logHistory(const std::string& action, const std::string& filename) {
    std::ofstream hist("history.txt", std::ios::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0'; // remove newline
    hist << "[" << dt << "] " << action << ": " << filename << "\n";
}