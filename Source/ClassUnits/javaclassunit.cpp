#include "javaclassunit.h"

JavaClassUnit::JavaClassUnit(const std::string &n) {
    className = n;
    fields.resize(ACCESS_MODIFIERS.size());
}

void JavaClassUnit::add(const UnitPtr &unit, Unit::Flags flags) {

    int accessModifier = PRIVATE;

    if(flags < ACCESS_MODIFIERS.size()) {
        accessModifier = flags;
    }
    fields[accessModifier].push_back(unit);
}

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + className + " {\n";

    for(size_t i = 0; i < ACCESS_MODIFIERS.size(); i++) {
        if (fields[i].empty()) {
            continue;
        }
        for(const auto& field : fields[i]) {
            result += generateShift(level+1);
            result += ACCESS_MODIFIERS[i];
            result += " ";
            result += field->compile(level);
            result += "\n";
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}
