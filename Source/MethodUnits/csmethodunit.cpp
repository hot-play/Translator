#include "csmethodunit.h"

CsMethodUnit::CsMethodUnit(const std::string &n, const std::string &t, Unit::Flags f) {
    methodName = n;
    returnType = t;
    flags = f;
}

void CsMethodUnit::add(const UnitPtr &unit, Unit::Flags flags) {
    body.push_back(unit);
}

std::string CsMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);
    if(flags & STATIC) {
        result += "static ";
    } else if(flags & VIRTUAL) {
        result += "final ";
    }
    result += returnType + " ";
    result += methodName + "()";
    if(flags & CONST) {
        result += " const";
    }
    result += " {\n";
    for(const auto& b : body) {
        result += b->compile(level + 2);
    }
    result += generateShift(level + 1) + "}\n";
    return result;
}
