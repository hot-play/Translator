#include <QCoreApplication>
#include <iostream>
#include <memory>
#include <Source/unit.h>
#include <Source/ClassUnits/cppclassunit.h>
#include <Source/MethodUnits/cppmethodunit.h>
#include <Source/PrintOperatorUnits/cppprintoperatorunit.h>

const std::vector<std::string> CppClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };

std::string generateProgram(/*QString language*/) {
    ClassUnit * myClass = new CppClassUnit("MyClass");
//    if (language == "cpp") {
//        myClass = new CppClassUnit("MyClass");
//    }
//    if (language == "cs") {
//        myClass = new CsClassUnit("MyClass");
//    }
//    if (language == "java") {
//        myClass = new JavaClassUnit("MyClass");
//    }
    myClass->add(std::make_shared<CppMethodUnit>("testFunc1", "void", 0), CppClassUnit::PUBLIC);
    myClass->add(std::make_shared<CppMethodUnit>("testFunc2", "void", CppMethodUnit::STATIC), CppClassUnit::PRIVATE);
    myClass->add(std::make_shared<CppMethodUnit>("testFunc3", "void", CppMethodUnit::VIRTUAL | CppMethodUnit::CONST), CppClassUnit::PUBLIC);
    auto method = std::make_shared<CppMethodUnit>("testFunc4", "void", CppMethodUnit::STATIC);
    method->add( std::make_shared<CppPrintOperatorUnit>(R"(Hello, world!\n)"));
    myClass->add( method, CppClassUnit::PROTECTED );
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram() << std::endl;
    return a.exec();
}
