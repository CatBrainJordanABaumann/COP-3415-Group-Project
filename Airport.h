#pragma once

#include <string>

struct Airport {
    std::string code;
    std::string state;
    bool useCode;

    Airport(const std::string& code = "", const std::string& state = "");
};