#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string RESET_STYLE = "\033[0m";
const string BOLD_STYLE = "\033[1m";

const string RESET_COLOR = "\033[0m";
const string RED_COLOR = "\033[31m";
const string GREEN_COLOR = "\033[32m";
const string YELLOW_COLOR = "\033[33m";
const string BLUE_COLOR = "\033[34m";

class Bicycle {
    
private:
    string brand;
    string name;
    double wheel;
    double weight;
    string color;
    double price;
    int year;
    
public:
    ~Bicycle() {}
    
    Bicycle(const string brand, const string name, const double wheel, const double weight, const string color, const double price , const int year){
        this->brand = brand;
        this->name = name;
        this->wheel = wheel;
        this->weight = weight;
        this->color = color;
        this->price = price;
        this-> year = year;
    }
    
    string getBrand() const {
        return brand;
    }
    
    string getName() const {
        return name;
    }
    
    double getWheel() const {
        return wheel;
    }
    
    double getWeight() const {
        return weight;
    }
    
    string getColor() const {
        return color;
    }
    
    double getPrice() const {
        return price;
    }
    
    int getYear() const {
        return year;
    }
    
    void printBicycle() const {
        cout << "Brand: " << brand << endl;
        cout << "Name: " << name << endl;
        cout << "Wheel size: " << wheel << "″" << endl;
        cout << "Weight: " << weight << "kg" << endl;
        cout << "Color: " << color << endl;
        cout << "Price: " << price << "$" << endl;
        cout << "Year: " << year << endl;
    }
};

class Person {
private:
    string name;
    string surname;
    int age;
public:
    ~Person() {}
    Person(const string name, const string surname, const int age){
        this->name = name;
        this->surname = surname;
        this->age = age;
    }
    string getName() const {
        return name;
    }
    string getSurname() const {
        return surname;
    }
    int getAge() const {
        return age;
    }
    void printPerson() const {
            cout << "Name: " << name << endl;
            cout << "Surname: " << surname << endl;
            cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
private:
    string store;
    double salary;
public:
    ~Employee() {}
    Employee(const string name, const string surname, const int age, const string store, const double salary) : Person(name, surname, age) {
        this->store = store;
        this->salary = salary;
    }
    
    string getStore() const {
        return store;
    }
    
    double getSalary() const {
        return salary;
    }
    
    void printEmployee() const {
        printPerson();
        cout << "Store: " << store << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Buyer : public Person {
private:
    string product;
    double budget;
public:
    ~Buyer() {}
    Buyer(const string name, const string surname, const int age, const string product, const double budget) : Person(name, surname, age) {
        this->product = product;
        this->budget = budget;
    }
    
    string getProduct() const {
        return product;
    }
    
    double getBudget() const {
        return budget;
    }
    
    void printBuyer() const {
        printPerson();
        cout << "Product: " << product << endl;
        cout << "Budget: " << budget << endl;
    }
};

void employeesDetails(const vector<Employee> employees){
    cout << "\nEmployee Details:\n" << endl;
    for (const auto &employee : employees) {
        employee.printEmployee();
        cout << endl;
    }
}

void addEmployee(vector<Employee>& employees) {
    string name, surname, store;
    int age;
    double salary;
    
    cout << "Enter employee details:\n" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Age: ";
    cin >> age;
    cout << "Store: ";
    cin >> store;
    cout << "Salary: ";
    cin >> salary;
    
    employees.emplace_back(name, surname, age, store, salary);
}

void removeEmployee(vector<Employee>& employees) {
    int index;
    cout << "Enter the index of the employee to remove: ";
    cin >> index;
    
    if (index >= 0 && index < employees.size()) {
        employees.erase(employees.begin() + index);
        cout << "Employee removed successfully.\n" << endl;
    } else {
        cout << "Invalid index.\n" << endl;
    }
}

void modifyEmployee(vector<Employee>& employees) {
    int index;
    cout << "Enter the index of the employee to modify: ";
    cin >> index;
    
    if (index >= 0 && index < employees.size()) {
        string name, surname, store;
        int age;
        double salary;
        
        cout << "Enter new details for the employee:\n" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Age: ";
        cin >> age;
        cout << "Store: ";
        cin >> store;
        cout << "Salary: ";
        cin >> salary;
        
        employees[index] = Employee(name, surname, age, store, salary);
        cout << "Employee modified successfully.\n" << endl;
    } else {
        cout << "Invalid index.\n" << endl;
    }
}

void buyesDetails(const vector<Buyer> buyers){
    cout << "Buyer Details:\n" << endl;
    for (const auto &buyer : buyers) {
        buyer.printBuyer();
        cout << endl;
    }
}

void bicycleDetalis(const vector<Bicycle> bicycles){
    cout << "Bicycles Details:\n" << endl;
    for (const auto &bicycle : bicycles) {
        bicycle.printBicycle();
        cout << endl;
    }
}

void addBuyer(vector<Buyer>& buyers) {
    string name, surname, product;
    int age;
    double budget;
    
    cout << "Enter buyer details:\n" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;
    cout << "Age: ";
    cin >> age;
    cout << "Product: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, product);
    cout << "Budget: ";
    cin >> budget;
    
    buyers.emplace_back(name, surname, age, product, budget);
}

void removeBuyer(vector<Buyer>& buyers) {
    int index;
    cout << "Enter the index of the buyer to remove: ";
    cin >> index;
    
    if (index >= 0 && index < buyers.size()) {
        buyers.erase(buyers.begin() + index);
        cout << "Buyer removed successfully.\n" << endl;
    } else {
        cout << "Invalid index.\n" << endl;
    }
}

void modifyBuyer(vector<Buyer>& buyers) {
    int index;
    cout << "Enter the index of the buyer to modify: ";
    cin >> index;
    
    if (index >= 0 && index < buyers.size()) {
        string name, surname, product;
        int age;
        double budget;
        
        cout << "Enter new details for the buyer:\n" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Surname: ";
        cin >> surname;
        cout << "Age: ";
        cin >> age;
        cout << "Product: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, product);
        cout << "Budget: ";
        cin >> budget;
        
        buyers[index] = Buyer(name, surname, age, product, budget);
        cout << "Buyer modified successfully.\n" << endl;
    } else {
        cout << "Invalid index.\n" << endl;
    }
}

void addBicycle(vector<Bicycle>& bicycles) {
    string brand, name, color;
    double wheel, weight, price;
    int year;
    
    cout << "Enter bicycle details:\n" << endl;
    cout << "Brand: ";
    cin >> brand;
    cout << "Name: ";
    cin >> name;
    cout << "Wheel size: ";
    cin >> wheel;
    cout << "Weight: ";
    cin >> weight;
    cout << "Color: ";
    cin >> color;
    cout << "Price: ";
    cin >> price;
    cout << "Year: ";
    cin >> year;
    
    bicycles.emplace_back(brand, name, wheel, weight, color, price, year);
}

void removeBicycle(vector<Bicycle>& bicycles) {
    int index;
    cout << "Enter the index of the bicycle to remove: ";
    cin >> index;
    
    if (index >= 0 && index < bicycles.size()) {
        bicycles.erase(bicycles.begin() + index);
        cout << "Bicycle removed successfully.\n" << endl;
    } else {
        cout << "Invalid index.\n" << endl;
    }
}

void modifyBicycle(vector<Bicycle>& bicycles) {
    int index;
    cout << "Enter the index of the bicycle to modify: ";
    cin >> index;
    
    if (index >= 0 && index < bicycles.size()) {
        string brand, name, color;
        double wheel, weight, price;
        int year;
        
        cout << "Enter new details for the bicycle:\n" << endl;
        cout << "Brand: ";
        cin >> brand;
        cout << "Name: ";
        cin >> name;
        cout << "Wheel size: ";
        cin >> wheel;
        cout << "Weight: ";
        cin >> weight;
        cout << "Color: ";
        cin >> color;
        cout << "Price: ";
        cin >> price;
        cout << "Year: ";
        cin >> year;
        
        bicycles[index] = Bicycle(brand, name, wheel, weight, color, price, year);
        cout << "Bicycle modified successfully.\n" << endl;
    } else {
        cout << "Invalid index.\n" << endl;
    }
}

void editElements(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles){
    while (true) {
        int a;
        cout << "Choose the Vector:\n" << endl;
        cout << "0. Back" << endl;
        cout << "1. Employees" << endl;
        cout << "2. Buyers" << endl;
        cout << "3. Bicycles" << endl;
        cin >> a;
        switch (a) {
            case 1:
                modifyEmployee(employees);
                break;
            case 2:
                modifyBuyer(buyers);
                break;
            case 3:
                modifyBicycle(bicycles);
                break;
            case 0:
                cout << "Return to Main Menu...\n" << endl;
                return;
            default:
                break;
        }
    }
}

void addElements(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles){
    while (true) {
        int a;
        cout << "Choose the Vector:\n" << endl;
        cout << "0. Back" << endl;
        cout << "1. Employees" << endl;
        cout << "2. Buyers" << endl;
        cout << "3. Bicycles" << endl;
        cin >> a;
        switch (a) {
            case 1:
                addEmployee(employees);
                break;
            case 0:
                cout << "Return to Main Menu...\n" << endl;
                return;;
            default:
                break;
        }
    }
}

void removeElements(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles){
    while (true) {
        int a;
        cout << "Choose the Vector:\n" << endl;
        cout << "0. Back" << endl;
        cout << "1. Employees" << endl;
        cout << "2. Buyers" << endl;
        cout << "3. Bicycles" << endl;
        cin >> a;
        switch (a) {
            case 1:
                removeEmployee(employees);
                break;
            case 0:
                cout << "Return to Main Menu...\n" << endl;
                return;
            default:
                break;
        }
    }
}

void searchElements(const vector<Buyer>& buyers, const vector<Employee>& employees, const vector<Bicycle>& bicycles) {
    int choice;
    cout << "Choose the Vector to search in:\n" << endl;
    cout << "1. Employees" << endl;
    cout << "2. Buyers" << endl;
    cout << "3. Bicycles" << endl;
    cin >> choice;

    switch (choice) {
        case 1: {
            string searchTerm;
            cout << "Enter the employee's name to search for: ";
            cin >> searchTerm;

            cout << "Matching employees:" << endl;
            for (const auto& employee : employees) {
                if (employee.getName() == searchTerm) {
                    employee.printEmployee();
                    cout << endl;
                }
            }
            break;
        }
        case 2: {
            string searchTerm;
            cout << "Enter the buyer's surname to search for: ";
            cin >> searchTerm;

            cout << "Matching buyers:" << endl;
            for (const auto& buyer : buyers) {
                if (buyer.getSurname() == searchTerm) {
                    buyer.printBuyer();
                    cout << endl;
                }
            }
            break;
        }
        case 3: {
            string searchTerm;
            cout << "Enter the bicycle's brand to search for: ";
            cin >> searchTerm;

            cout << "Matching bicycles:" << endl;
            for (const auto& bicycle : bicycles) {
                if (bicycle.getBrand() == searchTerm) {
                    bicycle.printBicycle();
                    cout << endl;
                }
            }
            break;
        }
        default:
            cout << "Invalid choice.\n" << endl;
            break;
    }
}

void saveDatabase(const vector<Buyer>& buyers, const vector<Employee>& employees, const vector<Bicycle>& bicycles, const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }

    // Сохранение покупателей
    outFile << "Buyers:" << endl;
    for (const auto& buyer : buyers) {
        outFile << buyer.getName() << " " << buyer.getSurname() << " " << buyer.getAge() << " " << buyer.getProduct() << " " << buyer.getBudget() << endl;
    }

    // Сохранение сотрудников
    outFile << "Employees:" << endl;
    for (const auto& employee : employees) {
        outFile << employee.getName() << " " << employee.getSurname() << " " << employee.getAge() << " " << employee.getStore() << " " << employee.getSalary() << endl;
    }

    // Сохранение велосипедов
    outFile << "Bicycles:" << endl;
    for (const auto& bicycle : bicycles) {
        outFile << bicycle.getBrand() << " " << bicycle.getName() << " " << bicycle.getWheel() << " " << bicycle.getWeight() << " " << bicycle.getColor() << " " << bicycle.getPrice() << " " << bicycle.getYear() << endl;
    }

    outFile.close();
    cout << "Database saved successfully to " << filename << endl;
}

void loadDatabase(vector<Buyer>& buyers, vector<Employee>& employees, vector<Bicycle>& bicycles, const string& filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    buyers.clear();
    employees.clear();
    bicycles.clear();

    string category;
    while (inFile >> category) {
        if (category == "Buyers:") {
            string name, surname, product;
            int age;
            double budget;
            while (inFile >> name >> surname >> age >> product >> budget) {
                buyers.emplace_back(name, surname, age, product, budget);
            }
        } else if (category == "Employees:") {
            string name, surname, store;
            int age;
            double salary;
            while (inFile >> name >> surname >> age >> store >> salary) {
                employees.emplace_back(name, surname, age, store, salary);
            }
        } else if (category == "Bicycles:") {
            string brand, name, color;
            double wheel, weight, price;
            int year;
            while (inFile >> brand >> name >> wheel >> weight >> color >> price >> year) {
                bicycles.emplace_back(brand, name, wheel, weight, color, price, year);
            }
        }
    }

    inFile.close();
    cout << "Database loaded successfully from " << filename << endl;
}

void interface(vector<Buyer> buyers, vector<Employee> employees, vector<Bicycle> bicycles){
    while (true) {
        int a;
        string fileName;
        cout << "Choose the Function:\n" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Print Details" << endl;
        cout << "2. Add Element" << endl;
        cout << "3. Remove Element" << endl;
        cout << "4. Edit Element" << endl;
        cout << "5. Search by Element" << endl;
        cout << "6. Save" << endl;
        cin >> a;
        
        switch (a) {
            case 1:
                employeesDetails(employees);
                buyesDetails(buyers);
                bicycleDetalis(bicycles);
                break;
            case 2:
                addElements(buyers, employees, bicycles);
                break;
            case 3:
                removeElements(buyers, employees, bicycles);
                break;
            case 4:
                editElements(buyers, employees, bicycles);
                break;
            case 5:
                searchElements(buyers, employees, bicycles);
                break;
            case 6:
                saveDatabase(buyers, employees, bicycles, "database.txt");
                break;
            case 0:
                cout << "\nGoodbye!\n" << endl;
                return;
            default:
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<Buyer> buyers = {
        Buyer("Alice", "Smith", 25, "Bicycle Red", 1000),
        Buyer("Bob", "Johnson", 40, "Mountain Bike", 2000)
    };
    
    vector<Employee> employees = {
        Employee("John", "Doe", 30, "Alt Store", 50000)
    };
    
    vector<Bicycle> bicycles = {
        Bicycle("Stels", "Quantum", 20, 7, "Blue", 550, 2024)
    };
    
    interface(buyers, employees, bicycles);
    return 0;
}
