#include <iostream>
#include <string>

class Plant {
public:
    virtual ~Plant() = default;

    virtual void info() const = 0; 
protected:
    std::string name;
    std::string size;
    float height;

    Plant(const std::string& name, const std::string& size, float height)
        : name(name), size(size), height(height) {}
};

class shrub : public Plant {
public:
    shrub(const std::string& name, float height)
        : Plant(name, "low", height) {}

    void info() const override {
        std::cout << "name: " << name << "\n"
            << "size: " << size << "\n"
            << "height: " << height << "\n";
    }

    virtual std::string fruitType() const = 0; 
};

class Tree : public Plant {
public:
    Tree(const std::string& name, float height)
        : Plant(name, "big", height) {}

    void info() const override {
        std::cout << "name: " << name << "\n"
            << "size: " << size << "\n"
            << "height: " << height << "\n";
    }

    virtual std::string fruitType() const = 0; 
};

class Apple : public Tree {
public:
    Apple(float height) : Tree("Apple Tree", height) {}

    std::string fruitType() const override {
        return "Apple";
    }
};

class Pear : public Tree {
public:
    Pear(float height) : Tree("Pear Tree", height) {}

    std::string fruitType() const override {
        return "Pear";
    }
};

class Blueberry : public shrub {
public:
    Blueberry(float height) : shrub("Blueberry Bush", height) {}

    std::string fruitType() const override {
        return "Blueberry";
    }
};

class Raspberry : public shrub {
public:
    Raspberry(float height) : shrub("Raspberry Bush", height) {}

    std::string fruitType() const override {
        return "Raspberry";
    }
};

int main() {
    Blueberry blueberryBush(1.2);
    Apple appleTree(5.5);
    Pear pearTree(4.0);

    std::cout << "Blueberry bush height:\n";
    blueberryBush.info();
    std::cout << "Fruit type: " << blueberryBush.fruitType() << "\n";

    std::cout << "\nApple tree height:\n";
    appleTree.info();
    std::cout << "Fruit type: " << appleTree.fruitType() << "\n";

    std::cout << "\nPear tree height:\n";
    pearTree.info();
    std::cout << "Fruit type: " << pearTree.fruitType() << "\n";

    return 0;
}

