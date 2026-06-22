#include "Airport.h"

Airport::Airport(const std::string& code, const std::string& state) :
    code(code), state(state), useCode(false) { }
    
bool Airport::operator==(const Airport& other) const {
    return code == other.code;
}

std::ostream &operator<<(std::ostream &os, const Airport &airport) { 
    return os << (airport.useCode ? airport.code : airport.state);
}