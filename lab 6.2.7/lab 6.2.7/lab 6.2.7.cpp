#include <iostream>
#include <string>

// Абстрактний базовий клас
class Worker {
public:
    Worker(const std::string& name) : name(name) {}
    virtual ~Worker() {}

    virtual double calculateSalary() const = 0; // Чиста віртуальна функція
    std::string getName() const { return name; }

private:
    std::string name;
};

class HourlyWorker : public Worker {
public:
    HourlyWorker(const std::string& name, double hourlyRate, int hoursWorked)
        : Worker(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

private:
    double hourlyRate;
    int hoursWorked;
};

class SalariedWorker : public Worker {
public:
    SalariedWorker(const std::string& name, double monthlySalary)
        : Worker(name), monthlySalary(monthlySalary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

private:
    double monthlySalary;
};


class CommissionWorker : public Worker {
public:
    CommissionWorker(const std::string& name, double sales, double commissionRate)
        : Worker(name), sales(sales), commissionRate(commissionRate) {}

    double calculateSalary() const override {
        return sales * commissionRate;
    }

private:
    double sales;
    double commissionRate;
};

int main() {

    setlocale(LC_CTYPE, "uk_UA");

    Worker* workers[] = {
        new HourlyWorker("Антон", 20.0, 40),
        new SalariedWorker("Аліса", 3000.0),
        new CommissionWorker("Андрій", 50000.0, 0.10)
    };

    for (Worker* worker : workers) {
        std::cout << "Зарплата працівника " << worker->getName() << " складає " << worker->calculateSalary()<< "грн." << std::endl;
        delete worker; // Звільнення пам'яті
    }

    return 0;
}