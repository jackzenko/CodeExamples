#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iterator>
#include <list>
#include <mutex>
#include "BuilderPattern.h"
#include "SingletonPatternNaive.h"
#include "SingletonPatternThreadSafe.h"
#include "PrototypePattern.h"
#include "FactoryMethodPattern.h"
#include "AbstractFactoryPattern.h"
#include "AdapterPattern.h"
#include "BridgePattern.h"
#include "CompositePattern.h"
#include "DecoratorPattern.h"
#include "FacadePattern.h"
#include "FlyweightPattern.h"
#include "ProxyPattern.h"
#include "ChainOfResponsibilityPattern.h"
#include "ObserverPattern.h"
#include "InterpreterPattern.h"
#include "CommandPattern.h"
#include "IteratorPattern.h"
#include "MediatorPattern.h"
#include "MementoPattern.h"
#include "StatePattern.h"
#include "TemplateMethod.h"
#include "StrategyPattern.h"
#include "VisitorPattern.h"

using namespace std;

// _CRT_SECURE_NO_WARNINGS
// memory leak
// move output to cpp files
// remove headers

int main() {

    /* === Creational Patterns === */
    BuilderPattern();
    SingletonPatternNaive();
    SingletonPatternThreadSafe();
    PrototypePattern();
    FactoryMethodPattern();
    AbstractFactoryPattern();

    /* === Structural Patterns === */
    AdapterPattern();
    BridgePattern();
    CompositePattern();
    DecoratorPattern();
    FacadePattern();
    FlyweightPattern();
    // ProxyPattern();

    /* === Behavioral Patterns === */
    ChainOfResponsibilityPattern();
    ObserverPattern();
    // InterpreterPattern();
    CommandPattern();
    IteratorPattern();
    MediatorPattern();
    MementoPattern();
    StatePattern();
    TemplateMethod();
    StrategyPattern();
    VisitorPattern();

    return 0;
}