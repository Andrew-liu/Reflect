#include "reflector.h"
using namespace std;

map<string, BaseFactory*>& GetReflectorMap() {
    static map<string, BaseFactory*> reflector_map;
    return reflector_map;
}

boost::any GetInstanceFromMap(const string& class_name) {
    assert(GetReflectorMap().find(class_name) != GetReflectorMap().end());
    return (GetReflectorMap()[class_name])->Init();  // 动态绑定的机制
}

void RegisterInstanceIntoMap(const string& class_name, BaseFactory* base) {
    map<string, BaseFactory*> reflector_map = GetReflectorMap();
    if(GetReflectorMap().find(class_name) == GetReflectorMap().end()) {
        GetReflectorMap()[class_name] = base;
        std::cout << "Register Success!" << std::endl;
    }
}
