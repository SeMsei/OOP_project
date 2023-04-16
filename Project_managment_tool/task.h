#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>

#pragma once

class Task
{
protected:
    int id;
    std::string name;
    bool is_done = false;
    std::chrono::year_month_day date_start;
    std::chrono::year_month_day date_finish;
    bool is_overdue = false;

public:
    Task() = default;
    Task(std::string name, std::chrono::year_month_day date_start, std::chrono::year_month_day date_finish)
        :name(name), date_start(date_start), date_finish(date_finish)
    {
    }
    Task(Task &other) = default;
    Task(Task &&other) = default;

    std::string get_name();
    void set_name(std::string name);
    void complete();
    bool is_task_done();
    bool is_task_overdue();
    std::chrono::year_month_day get_date_start();
    void set_date_start(std::chrono::year_month_day date_start);
    std::chrono::year_month_day get_date_finish();
    void set_date_finish(std::chrono::year_month_day start_date);
    int get_id();

    Task& operator=(Task &other) = default;
    Task& operator=(Task &&other) = default;
};

#endif // TASK_H
