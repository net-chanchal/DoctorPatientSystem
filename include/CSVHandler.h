#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class CSVHandler {
public:
    static std::vector<std::vector<std::string>> readCSV(const std::string& filename);
    static void writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data);
};

#endif // CSVHANDLER_H