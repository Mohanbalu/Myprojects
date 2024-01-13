#include <iostream>
#include <unordered_map>
#include <ctime>
#include <algorithm>

using namespace std;

class Phone {
protected:
    int ramTotal;
    int romTotal;
    int ramUsed;
    int romUsed;
    unordered_map<string, double> apps;

public:
    Phone(int ram, int rom) : ramTotal(ram), romTotal(rom), ramUsed(0), romUsed(0) {}

    void allocateSystemMemory(int ram, int rom) {
        ramUsed += ram;
        romUsed += rom;
    }

    void installApp(string appName, double ramPercent, double romPercent) {
        if (ramPercent < 0 || romPercent < 0 || ramPercent > 100 || romPercent > 100) {
            cout << "Error: Invalid memory percentage provided." << endl;
            return;
        }

        double ram = ramPercent * ramTotal / 100.0;
        int rom = static_cast<int>((romTotal * romPercent) / 100);

        if (ramUsed + ram <= ramTotal && romUsed + rom <= romTotal) {
            apps[appName] = ram;
            ramUsed += ram;
            romUsed += rom;
            cout << "App '" << appName << "' installed with " << ram << "GB RAM and " << rom << "GB ROM" << endl;
            cout << "The RAM consumption for this app is " << ram << "GB" << endl;
        } else {
            cout << "Insufficient memory to install app '" << appName << "'" << endl;
        }
    }

    void displayMemoryUsage() {
        cout << "Memory Usage:" << endl;
        cout << "RAM Total: " << ramTotal << "GB" << endl;
        cout << "RAM Used: " << ramUsed << "GB" << endl;
        cout << "RAM Free: " << ramTotal - ramUsed << "GB" << endl;
        cout << "ROM Total: " << romTotal << "GB" << endl;
        cout << "ROM Used: " << romUsed << "GB" << endl;
        cout << "ROM Free: " << romTotal - romUsed << "GB" << endl;
    }

    virtual void displayUniqueData() = 0;

    void displayAppConsumption() {
        cout << "App Memory Usage:" << endl;
        for (const auto& app : apps) {
            cout << app.first << " - RAM: " << app.second << "GB" << endl;
        }
    }
};

class Oppo : public Phone {
private:
    string model;
    string uniqueData;

public:
    Oppo(int ram, int rom, string modelName, string data) : Phone(ram, rom), model(modelName), uniqueData(data) {}

    void displayUniqueData() override {
        cout << "Oppo " << model << ": " << uniqueData << endl;
    }
};

class Samsung : public Phone {
private:
    string model;
    string uniqueData;

public:
    Samsung(int ram, int rom, string modelName, string data) : Phone(ram, rom), model(modelName), uniqueData(data) {}

    void displayUniqueData() override {
        cout << "Samsung " << model << ": " << uniqueData << endl;
    }
};

class Apple : public Phone {
private:
    string model;
    string uniqueData;

public:
    Apple(int ram, int rom, string modelName, string data) : Phone(ram, rom), model(modelName), uniqueData(data) {}

    void displayUniqueData() override {
        cout << "Apple " << model << ": " << uniqueData << endl;
    }
};

int main() {
    srand(static_cast<unsigned int>(std::time(nullptr)));

    string companyName, modelName;
    cout << "Enter the company name (oppo, samsung, apple): ";
    cin >> companyName;

    transform(companyName.begin(), companyName.end(), companyName.begin(), ::tolower);

    if (companyName == "oppo") {
        string modelName;
        cout << "Enter the Oppo model name (A or B): ";
        cin >> modelName;
        transform(modelName.begin(), modelName.end(), modelName.begin(), ::tolower);

        if (modelName == "a") {
            Oppo oppoModelA(8, 128, "Model A", "Unique data for Model A");
            oppoModelA.allocateSystemMemory(2, 20);
            oppoModelA.installApp("Instagram", 10, 5);
            oppoModelA.installApp("WhatsApp", 15, 7);
            cout << endl << "Oppo Model A:" << endl;
            oppoModelA.displayMemoryUsage();
            oppoModelA.displayAppConsumption();
            oppoModelA.displayUniqueData();
        } else if (modelName == "b") {
            Oppo oppoModelB(6, 64, "Model B", "Unique data for Model B");
            oppoModelB.allocateSystemMemory(1, 10);
            oppoModelB.installApp("PUBG", 25, 12);
            oppoModelB.installApp("WhatsApp", 7, 4);
            cout << endl << "Oppo Model B:" << endl;
            oppoModelB.displayMemoryUsage();
            oppoModelB.displayAppConsumption();
            oppoModelB.displayUniqueData();
        } else {
            cout << "Invalid Oppo model name" << endl;
        }
    } else if (companyName == "samsung") {
        string modelName;
        cout << "Enter the Samsung model name (A, B, C, D): ";
        cin >> modelName;
        transform(modelName.begin(), modelName.end(), modelName.begin(), ::tolower);

        if (modelName == "a" || modelName == "b" || modelName == "c" || modelName == "d") {
            Samsung samsung(12, 256, modelName, "Unique data for " + modelName);
            samsung.allocateSystemMemory(3, 30);
            samsung.installApp("WhatsApp", 15, 8);
            samsung.installApp("PUBG", 30, 20);
            cout << endl << "Samsung " << modelName << ":" << endl;
            samsung.displayMemoryUsage();
            samsung.displayAppConsumption();
            samsung.displayUniqueData();
        } else {
            cout << "Invalid Samsung model name" << endl;
        }
    } else if (companyName == "apple") {
        string modelName;
        cout << "Enter the Apple model name (A, B, C, D): ";
        cin >> modelName;
        transform(modelName.begin(), modelName.end(), modelName.begin(), ::tolower);

        if (modelName == "a" || modelName == "b" || modelName == "c" || modelName == "d") {
            Apple apple(6, 128, modelName, "Unique data for " + modelName);
            apple.allocateSystemMemory(2, 16);
            apple.installApp("Instagram", 8, 4);
            apple.installApp("WhatsApp", 10, 6);
            cout << endl << "Apple " << modelName << ":" << endl;
            apple.displayMemoryUsage();
            apple.displayAppConsumption();
            apple.displayUniqueData();
        } else {
            cout << "Invalid Apple model name" << endl;
        }
    } else {
        cout << "Invalid company name" << endl;
    }

    return 0;
}
