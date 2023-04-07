#include <iostream>
#include <string>

using namespace std;

// an abstract class Food
class Food {
public:
    virtual void Prepare() = 0;
};

// an exact classes for meals (breakfast, lunch, and dinner)
class Breakfast : public Food {
public:
    void Prepare() override { cout << "Preparing breakfast..." << endl; }
};

class Lunch : public Food {
public:
    void Prepare() override { cout << "Preparing lunch..." << endl; }
};

class Dinner : public Food {
public:
    void Prepare() override { cout << "Preparing dinner..." << endl; }
};

// a Person class. Dependency Inversion Principle between Person and Food classes
class Person {
public:
    void Eat(Food* food) {
        food->Prepare();
        cout << "Eating " << typeid(*food).name() << endl;
    }
};

int main() {
    Person p;
    Breakfast b;
    Lunch l;
    Dinner d;

    p.Eat(&b);
    p.Eat(&l);
    p.Eat(&d);

    return 0;
}