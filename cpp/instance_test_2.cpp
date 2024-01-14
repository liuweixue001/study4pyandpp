#include <memory>
#include <mutex>
#include <iostream>

template<typename T>
class Singleton {
public:
    static T *GetInstance() {
        if (m_pInstance == nullptr) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_pInstance == nullptr) {
                m_pInstance = std::make_shared<T>();
                // m_pInstance = std::shared_ptr<T>(new T());
            }
        }
        return m_pInstance.get();
    }

    Singleton(T &&) = delete;
    Singleton(const T &) = delete;
    void operator=(const T &) = delete;

protected:
    Singleton() = default;
    virtual ~Singleton() = default;

    static std::mutex m_mutex;
    static std::shared_ptr<T> m_pInstance;
};

template<typename T>
std::shared_ptr<T> Singleton<T>::m_pInstance = nullptr;

template<typename T>
std::mutex Singleton<T>::m_mutex;

class MySingletonClass : public Singleton<MySingletonClass> {
// private:
//     MySingletonClass() {
//         std::cout << "make a MySingletonClass" << std::endl;
//     }

public:
    void PrintMessage() {
        std::cout << "Hello from MySingletonClass!" << std::endl;
    }

    // friend class Singleton<MySingletonClass>;
};

int main() {
    MySingletonClass* instance = Singleton<MySingletonClass>::GetInstance();
    instance->PrintMessage();
    return 0;
}
