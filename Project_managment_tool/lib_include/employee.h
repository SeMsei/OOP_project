#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once

#include <string>
#include <vector>
#include <chrono>
#include "role.h"
#include <openssl/sha.h>
#include <openssl/evp.h>

class Employee
{
private:
    int id;
    int project_id;

    std::string first_name;
    std::string middle_name;
    std::string surname;
    std::chrono::year_month_day date_birth;
    double KPI = 0;
    Role role;
    double salary;
    std::chrono::year_month_day date_start;
    bool is_cur_working = 1;
    std::vector<int> work_task_vec;
    std::vector<int> personal_task_vec;

    std::string login;
    std::string password;

public:
    Employee() = default;
    Employee(const Employee &other) = default;
    Employee(Employee &&other) = default;
    Employee(int id, std::string first_name, std::string middle_name, std::string surname,
             std::chrono::year_month_day date_birth);
    Employee(int id, std::string first_name, std::string middle_name, std::string surname,
             std::chrono::year_month_day date_birth, std::chrono::year_month_day date_start);
    Employee(int id, std::string first_name, std::string middle_name, std::string surname,
             std::chrono::year_month_day date_birth, std::chrono::year_month_day date_start,
             std::string login, std::string password);
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
    void set_project_id(int new_project_id);
    int get_project_id();
    std::string get_login();
    void set_login(std::string);
    std::string get_password();
    void set_password(std::string);
    void remove_task(int id);
    void remove_personal_task(int id);

    Employee& operator=(Employee &other) = default;
    Employee& operator=(Employee &&other) = default;
};

#endif // EMPLOYEE_H
