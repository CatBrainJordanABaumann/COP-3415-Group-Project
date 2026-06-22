#pragma once

#include <string>

struct Airport {
    std::string code;
    std::string state;
    bool useCode;

    Airport(const std::string& code = "", const std::string& state = "");

    bool operator==(const Airport& other) const;
};

std::ostream &operator<<(std::ostream &os, const Airport &airport);