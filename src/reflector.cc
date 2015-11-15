#include "reflector.h"
using namespace std;

map<string, BaseFactory*>& GetReflectorMap() {
    static map<string, BaseFactory*> reflector_map;
    std::cout << "GetReflectorMap: "<< &reflector_map << std::endl;
    return reflector_map;
}

boost::any GetInstanceFromMap(const string& class_name) {
    map<string, BaseFactory*> reflector_map = GetReflectorMap();
    std::cout << "GetInstanceFromMap: " << &reflector_map << std::endl;
    assert(reflector_map.find(class_name) != reflector_map.end());
    return (reflector_map[class_name])->Init();  // 动态绑定的机制
}

void RegisterInstanceIntoMap(const string& class_name, BaseFactory* base) {
    map<string, BaseFactory*> reflector_map = GetReflectorMap();
    std::cout << "RegisterInstanceIntoMap: " << &reflector_map << std::endl;
    if(reflector_map.find(class_name) == reflector_map.end()) {
        reflector_map[class_name] = base;
        std::cout << "Register Success!" << std::endl;
    }
}
