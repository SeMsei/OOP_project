
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED



#include "employee.h"
#include "personaltask.h"
#include "worktask.h"
#include "project.h"

#pragma once


void update(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
            std::vector<PersonalTask> &ptask_vec, std::vector<Project> &proj_vec);


void remove_project(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                    std::vector<Project> &proj_vec);

void remove_personal_task(Employee &usr, std::vector<Employee> &empl_vec,
                          std::vector<PersonalTask> &ptask_vec);

void remove_work_task(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                      std::vector<Project> &proj_vec);

void fire_employee(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                   std::vector<PersonalTask> &ptask_vec, std::vector<Project> &proj_vec);

void change_employee_work_status(std::vector<Employee> &empl_vec);

void change_task_description(std::vector<PersonalTask> &ptask_vec);

void change_work_task_name(std::vector<WorkTask> &wtask_vec);

void change_personal_task_name(Employee &usr, std::vector<PersonalTask> &ptask_vec);

void change_employee_salary(std::vector<Employee> &empl_vec);

void change_finish_date_project(std::vector<Project> &proj_vec);

void change_finish_date_personal_task(Employee &usr, std::vector<PersonalTask> &ptask_vec);

void change_finish_date_work_task(std::vector<WorkTask> &wtask_vec); //validate work and project finish date

void complete_personal_task(Employee &usr, std::vector<PersonalTask> &ptask_vec);

void complete_work_task(Employee &cur_user, std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                        std::vector<Project> &proj_vec);

void complete_work_task(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                        std::vector<Project> &proj_vec);

void change_slave_project(int employee_id, int project_id, std::vector<Employee> &empl_vec,
                          std::vector<WorkTask> &wtask_vec, std::vector<Project> &proj_vec);

void add_slave_to_proj(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                       std::vector<Project> &proj_vec);
void add_slave_to_task(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec);

void add_personal_task(Employee &cur_user, std::vector<PersonalTask> &ptask_vec);

void add_task(std::vector<WorkTask> &wtask_vec, std::vector<Project> &proj_vec);

void add_slave(std::vector<Employee> &empl_vec, std::vector<Project> &proj_vec);

void add_project(std::vector<Project> &proj_vec);

//
void check_personal_task(Employee cur_user, std::vector<PersonalTask> &task_vec);

void check_work_tasks(Employee &usr, std::vector<WorkTask> &task_vec);

void check_work_tasks(int proj_id, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec);

//
void check_work_tasks(std::vector<Employee> &empl_vec, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec);

void check_cur_project(Employee &cur_user, std::vector<Project> proj_vec,
                       std::vector<WorkTask> &task_vec, std::vector<Employee> &empl_vec);

//
void check_projects(std::vector<Employee> &empl_vec, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec);

//
void check_employees(std::vector<Employee> &empl_vec, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec);

void check_kpi(Employee &cur_user);
#endif // FUNCTIONS_H
