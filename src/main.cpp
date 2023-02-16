#include <iostream>
#include <map>

#include "file_handler.h"
#include "json_handler.h"

int main(void) {
    CsvHandler DataFile("test.csv");

    std::cout << DataFile.header[0] << std::endl;
    std::cout << DataFile.content[0][0] << std::endl;

    JsonHandler json;

    std::string test = "{\"test\": \"loads\"}";
    json.loads(test);

    for (const auto& [key, value] : json.json)
        std::cout << '[' << key << "] = " << value << "; " << std::endl;

    std::map<std::string, std::string> m;
    m["key"] = "value";
    m["key2"] = "value2";

    json.dumps(m);
    std::cout << json.content << std::endl;

    return 0;
}