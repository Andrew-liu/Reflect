/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */
#include "reflector.h"
using namespace std;

int main(int argc, const char *argv[]) {
    // <string, BaseFactory*> reflector_map = GetReflectorMap();
    string name_one = "basefactory";
    RegisterInstanceIntoMap(name_one, new BaseFactory());
    GetReflectorMap();
    string name_two = "testfactory";
    TestFactory* test = new TestFactory();
    GetReflectorMap();
    RegisterInstanceIntoMap(name_two, test);
    GetReflectorMap();
    GetInstanceFromMap("basefactory");
    GetInstanceFromMap("testfactory");
    return 0;
}
