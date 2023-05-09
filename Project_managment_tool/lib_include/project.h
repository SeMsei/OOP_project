
#ifndef PROJECT_H
#define PROJECT_H

#pragma once


#include <vector>
#include <string>
#include <chrono>

#pragma once

class Employee;
class WorkTask;

class Project
{
private:
    int id;
    std::string project_name;
    std::vector<int> tasks_vec;
    std::chrono::year_month_day date_start;
    std::chrono::year_month_day date_finish;
    int task_count = 0;
    int done_task_count = 0;
    bool is_done = false;
    std::vector<int> employee_vec;

public:
    Project() = default;
    Project(const Project &other) = default;
    Project(Project &&other) = default;
    Project(int id, std::string project_name, std::chrono::year_month_day date_start, std::chrono::year_month_day date_finish);

    int get_id();
    void set_name(std::string new_name);
    std::string get_name();
    std::vector<int> get_tasks();
    std::chrono::year_month_day get_date_start();
    std::chrono::year_month_day get_date_finish();
    void set_date_finish(std::chrono::year_month_day new_date_finish);
    void add_task(int task);
    void remove_task(int num);
    void complete_task();
    int get_task_count();
    int get_done_task_count();
    bool is_completed();
    void complete();
    void add_employee(int empl);
    std::vector<int> get_employees_id();
    void remove_employee(int id);

    Project& operator=(Project &other) = default;
    Project& operator=(Project &&other) = default;
};

#endif // PROJECT_H
