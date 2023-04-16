#ifndef WORKTASK_H
#define WORKTASK_H

#pragma once

#include "task.h"
#include <vector>
#include <memory>
#include <boost/signals2.hpp>

class WorkTask:public Task
{
private:
    std::vector<int> employees_id;
    int project_id;


public:
    WorkTask() = default;
    WorkTask(int id, std::string name, std::chrono::year_month_day date_start, std::chrono::year_month_day date_finish, int project_id);
    WorkTask(WorkTask &other) = default;
    WorkTask(WorkTask &&other) = default;

    void add_employee(int new_employee_id);
    std::vector<int> get_employees_id();
    void change_project(int new_project_id);
    int get_project();

    WorkTask& operator=(WorkTask &other) = default;
    WorkTask& operator=(WorkTask &&other) = default;
};

#endif // WORKTASK_H
