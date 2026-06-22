#include "Airport.h"

//constructor stores the airports code and state
//useCode is false so by default we print the state
Airport::Airport(const std::string& code, const std::string& state) :
    code(code), state(state), useCode(false) { }

//two airports are equal if code name matches
bool Airport::operator==(const Airport& other) const {
    return code == other.code;
}

//prints the code or the state, dependant on usecode
std::ostream &operator<<(std::ostream &os, const Airport &airport) { 
    return os << (airport.useCode ? airport.code : airport.state);
}