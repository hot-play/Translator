#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include<Source/MethodUnits/methodunit.h>

class JavaMethodUnit : public MethodUnit {
public:
    JavaMethodUnit(const std::string& n, const std::string& t, Flags f) {
        methodName = n;
        returnType = t;
        flags = f;
    }
    void add(const UnitPtr& unit, Flags flags = 0) override {
        body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level);
        if (flags & STATIC) {
            result += "static ";
        } else if (flags & VIRTUAL) {
            result += "virtual ";
        } else if (flags & FINAL) {
            result += "final ";
        } else if (flags & ABSTRACT) {
            result += "abstract ";
        } else if (flags & SYNCHRONIZED) {
            result += "synchronized ";
        } else if (flags & VOLATILE) {
            result += "volatile ";
        }
        result += returnType + " ";
        result += methodName + "()";
        if( flags & CONST ) {
            result += " const";
        }
        result += " {\n";
        for(const auto& b : body) {
            result += b->compile(level + 2);
        }
        result += generateShift(level + 1) + "}\n";
        return result;
    }
};

#endif // JAVAMETHODUNIT_H
