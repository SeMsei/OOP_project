#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once

#include <string>
#include <vector>
#include <chrono>
#include "role.h"

class Employee
{
private:
    int id;

    std::string first_name;
    std::string middle_name;
    std::string surname;
    std::chrono::year_month_day date_birth;
    double KPI;
    Role role;
    double salary;
    std::chrono::year_month_day date_start;
    bool is_cur_working;
    std::vector<int> work_task_vec;
    std::vector<int> personal_task_vec;

public:
    Employee();
    Employee(Employee &other) = default;
    Employee(Employee &&other) = default;
    Employee(int id, std::string first_name, std::string middle_name, std::string surname,
             std::chrono::year_month_day date_birth);
    Employee(int id, std::string first_name, std::string middle_name, std::string surname,
             std::chrono::year_month_day date_birth, std::chrono::year_month_day date_start);
    ~Employee() = default;
    void set_salary(double new_salary);
    double get_salary();
    void set_role(Role new_role);
    Role get_role();
    void set_kpi(double new_kpi);
    double get_kpi();
    void set_working_status(bool new_status);
    bool get_working_status();
    std::chrono::year_month_day get_start_date();
    std::chrono::year_month_day get_date_birth();
    std::string get_middle_name();
    std::string get_first_name();
    std::string get_surname();
    std::vector<int> get_work_tasks();
    std::vector<int> get_personal_tasks();
    void add_work_task(int new_task);
    void add_personal_task(int new_task);
    int get_id();

    Employee& operator=(Employee &other) = default;
    Employee& operator=(Employee &&other) = default;
};

#endif // EMPLOYEE_H
