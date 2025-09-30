#include <iostream>
#include <memory>
#include <string>
#include <memory>
#include <string>
#include <iostream>





class Furniture {
public:
    virtual ~Furniture() = default;
    virtual void assembly() = 0;
    virtual void painting() = 0;  // Fixed: was 'paint()' in usage but 'painting()' in declaration
    virtual std::string getName() = 0;
};

class Chair : public Furniture {  // Fixed: class name should be capitalized
public:
    std::string getName() override {
        return "Chair Furniture";
    }

    void assembly() override {
        std::cout << "We are assembling the chair" << std::endl;
    }
    
    void painting() override {  // Added missing implementation
        std::cout << "The process of painting the chair" << std::endl;
    }
};

class Table : public Furniture {
public:
    void assembly() override {
        std::cout << "We are assembling the table" << std::endl;
    }
    
    void painting() override {
        std::cout << "The process of painting the table" << std::endl;
    }

    std::string getName() override {
        return "Table Furniture";  // Fixed typo
    }
};

// Abstract class for the factory
class FurnitureFactory {
public:
    virtual ~FurnitureFactory() = default;
    
    // Fixed: should be pure virtual (add = 0)
    virtual std::unique_ptr<Furniture> createFurniture() = 0;
    
    void manufactureFurniture() {
        std::cout << "Start manufacturing process\n";
        auto furniture = createFurniture();  // This calls the subclass's implementation
        std::cout << "Manufacturing: " << furniture->getName() << "\n";
        furniture->assembly();
        furniture->painting();  // Fixed: was 'paint()' but should be 'painting()'
        std::cout << "========== Finished manufacturing =====\n\n";
    }
};

class ChairFactory : public FurnitureFactory {  // Fixed: class name should be capitalized
public: 
    std::unique_ptr<Furniture> createFurniture() override {
        return std::make_unique<Chair>();  // Fixed: was 'chair'
    }
};  // Fixed: missing semicolon

class TableFactory : public FurnitureFactory {
public:  // Added missing public access specifier
    std::unique_ptr<Furniture> createFurniture() override {
        return std::make_unique<Table>();
    }
};  // Fixed: missing semicolon

// Client code completely decoupled from concrete classes
void clientCode(FurnitureFactory& factory) {
    factory.manufactureFurniture();
}

int main() {
    std::cout << "BASIC FACTORY METHOD DEMONSTRATION" << std::endl;
    ChairFactory chairFactory;  // Fixed: was 'chairFactory' (lowercase)
    TableFactory tableFactory;
    
    std::cout << "Creating chair:\n";
    clientCode(chairFactory);
    std::cout << "Creating table:\n";
    clientCode(tableFactory);
    
    return 0;  // Added return statement
}






