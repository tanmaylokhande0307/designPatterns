#include <iostream>
#include <string>

class Prototype
{
public:
    virtual Prototype *clone() = 0;
    virtual std::string type() = 0;
};

class ConcretePrototypeA : public Prototype
{
public:
    Prototype *clone()
    {
        return new ConcretePrototypeA();
    }
    std::string type()
    {
        return "type A";
    }
};

class ConcretePrototypeB : public Prototype
{
public:
    Prototype *clone()
    {
        return new ConcretePrototypeB();
    }
    std::string type()
    {
        return "type B";
    }
};

class Client
{
public:
    static void init()
    {
        types[0] = new ConcretePrototypeA();
        types[1] = new ConcretePrototypeB();
    }

    static Prototype *make(const int index)
    {
        if (index >= n_types)
        {
            return nullptr;
        }
        return types[index]->clone();
    }

private:
    static Prototype *types[2];
    static int n_types;
};

Prototype *Client::types[2];
int Client::n_types = 2;

int main()
{
    Client::init();

    Prototype *prototype1 = Client::make(0);
    std::cout << "Prototype: " << prototype1->type() << std::endl;
    delete prototype1;

    Prototype *prototype2 = Client::make(1);
    std::cout << "Prototype: " << prototype2->type() << std::endl;
    delete prototype2;

    return 0;
}