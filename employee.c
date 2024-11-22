// Create structure of employees of ABC company consisting the following members ;empno,empname,age,basic ,da ,hra,medical allowance (MA),pt,tax,epf. da-30%of basic,medical allowance (MA)-1% of basic , pt-500,tax-5% of gross,epf-1%of gross. implement the following : 1.write a function to compute gross and net salary of each of employee using function pointer . 2.write a function to display all ther employees whose age is less than 50 yrs.


#include <stdio.h>

typedef struct {
    int empno;
    char empname[50];
    int age;
    float basic;
    float da;       // 30% of basic
    float hra;
    float ma;       // 1% of basic
    float pt;       // professional tax: 500
    float tax;      // 5% of gross
    float epf;      // 1% of gross
    float gross;
    float net;
} Employee;

// Function pointers for calculating gross and net salary
void calculateSalary(Employee *e) {
    e->da = 0.30 * e->basic;
    e->ma = 0.01 * e->basic;
    e->pt = 500;
    e->gross = e->basic + e->da + e->hra + e->ma;
    e->tax = 0.05 * e->gross;
    e->epf = 0.01 * e->gross;
    e->net = e->gross - (e->pt + e->tax + e->epf);
}

void displayEmployeesUnder50(Employee *employees, int count) {
    for (int i = 0; i < count; i++) {
        if (employees[i].age < 50) {
            printf("Employee No: %d, Name: %s, Age: %d\n", employees[i].empno, employees[i].empname, employees[i].age);
        }
    }
}

int main() {
    Employee employees[5] = {
        {1, "John", 45, 50000, 0, 10000, 0, 0, 0, 0, 0, 0},
        {2, "Jane", 30, 60000, 0, 12000, 0, 0, 0, 0, 0, 0},
        {3, "Alice", 52, 55000, 0, 11000, 0, 0, 0, 0, 0, 0},
        {4, "Bob", 48, 70000, 0, 14000, 0, 0, 0, 0, 0, 0},
        {5, "Charlie", 33, 65000, 0, 13000, 0, 0, 0, 0, 0, 0},
    };

    // Calculate gross and net salary for each employee
    for (int i = 0; i < 5; i++) {
        calculateSalary(&employees[i]);
    }

    // Display all employees whose age is less than 50 years
    printf("Employees under 50 years old:\n");
    displayEmployeesUnder50(employees, 5);

    return 0;
}
