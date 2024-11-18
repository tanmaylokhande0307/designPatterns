#include <iostream>
#include <string>

// Target interface (desired interface)
class Target
{
public:
    virtual std::string request() const = 0; // Abstract method to be implemented
    virtual ~Target() = default;
};

// Adaptee (existing class with a different interface)
class Adaptee
{
public:
    std::string specificRequest() const
    {
        return "Adaptee's behavior";
    }
};

// Class Adapter: Adapts Adaptee to Target
class ClassAdapter : public Target, public Adaptee
{
public:
    std::string request() const override
    {
        // Adapting Adaptee's method to Target's interface
        return specificRequest();
    }
};

class SubAdaptee : public Adaptee
{
public:
    std::string specificRequest() const
    {
        return "SubAdaptee's behavior";
    }
};

int main()
{
    // Using the Class Adapter
    SubAdaptee subAdaptee;

    ClassAdapter adapter;
    std::cout << "Using ClassAdapter with SubAdaptee: " << adapter.request() << std::endl;

    return 0;
}
