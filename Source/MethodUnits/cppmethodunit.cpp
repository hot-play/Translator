#include "cppmethodunit.h"

CppMethodUnit::CppMethodUnit(const std::string &n, const std::string &t, Unit::Flags f) {
    methodName = n;
    returnType = t;
    flags = f;
}

void CppMethodUnit::add(const UnitPtr &unit, Unit::Flags flags) {
    body.push_back(unit);
}

std::string CppMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift( level );
    if( flags & STATIC ) {
        result += "static ";
    } else if( flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += returnType + " ";
    result += methodName + "()";
    if( flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}
