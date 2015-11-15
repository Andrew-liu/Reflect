/*
 * Author: Andrew Liu
 * Email: liu.bin.coder@gmail.com
 */

#ifndef _REFLECTOR_H_

#define _REFLECTOR_H_
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <boost/any.hpp>
using namespace std;

// 工厂的基类
class BaseFactory {
public:
    virtual boost::any Init() const {
        std::cout << "BaseFactory" << std::endl;
        return boost::any();  // 这里返回我们想要在反射后调用类的实例
    }
};

// 工厂的继承类
class TestFactory : public BaseFactory {
    public:
        boost::any Init() const {
            std::cout << "TestFactory" << std::endl;
            return boost::any();
        }
};

// reflect
// extern map<string, BaseFactory*> reflector_map;
map<string, BaseFactory*>& GetReflectorMap();

// register and get method
boost::any GetInstanceFromMap(const string& class_name);
void RegisterInstanceIntoMap(const string& class_name, BaseFactory*);

#endif /* _REFLECTOR_H_ */
