#include "SingletonPatternThreadSafe.h"

/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class SingletonTS
{
    /**
     * The Singleton's constructor/destructor should always be private to
     * prevent direct construction/desctruction calls with the `new`/`delete`
     * operator.
     */
private:
    static SingletonTS* pinstance_;
    static std::mutex mutex_;

protected:
    SingletonTS(const std::string value) : value_(value)
    {
    }
    ~SingletonTS() {}
    std::string value_;

public:

    
    SingletonTS(SingletonTS& other) = delete; // Singletons should not be cloneable
    void operator=(const SingletonTS&) = delete; // Singletons should not be assignable

    static SingletonTS* GetInstance(const std::string& value);

    void SomeBusinessLogic()
    {
        // ...
    }

    std::string value() const {
        return value_;
    }
};

// Static methods should be defined outside the class.
SingletonTS* SingletonTS::pinstance_{ nullptr };
std::mutex SingletonTS::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 * and then we make sure again that the variable is null and then we
 * set the value. RU:
 */
SingletonTS* SingletonTS::GetInstance(const std::string& value)
{
    if (pinstance_ == nullptr)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (pinstance_ == nullptr)
        {
            pinstance_ = new SingletonTS(value);
        }
    }
    return pinstance_;
}

void ThreadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // emulates slow initialization
    SingletonTS* singletonTS = SingletonTS::GetInstance("FOO");
    std::cout << singletonTS->value() << "\n";
}

void ThreadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // emulates slow initialization
    SingletonTS* singletonTS = SingletonTS::GetInstance("BAR");
    std::cout << singletonTS->value() << "\n";
}

int SingletonPatternThreadSafe()
{
    std::cout << "If you see the same value, then singleton was reused (yay!)\n" <<
        "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
        "RESULT:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}