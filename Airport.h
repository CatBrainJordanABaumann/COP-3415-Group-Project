#pragma once

#include <string>

//represents one airport a vertex on the graph
struct Airport {
    std::string code;
    std::string state;
    bool useCode; 

    Airport(const std::string& code = "", const std::string& state = "");

    //returns true if airport code is true
    bool operator==(const Airport& other) const;
};

//prints a Airport directly
std::ostream &operator<<(std::ostream &os, const Airport &airport);