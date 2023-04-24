#include "cppclassunit.h"

CppClassUnit::CppClassUnit(const std::string &n) {
    className = n;
    fields.resize(ACCESS_MODIFIERS.size());
}

void CppClassUnit::add(const UnitPtr &unit, Unit::Flags flags) {

    int accessModifier = PRIVATE;

    if(flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    fields[accessModifier].push_back(unit);
}

std::string CppClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + className + " {\n";

    for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (fields[i].empty()) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for(const auto& field : fields[ i ]) {
            result += field->compile(level + 1);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}
