
#ifndef ROLE_CLASS_H
#define ROLE_CLASS_H

#pragma once

#include "worktask.h"
#include "employee.h"
#include "personaltask.h"
#include "project.h"
#include <iostream>
#include "functions.h"
#include "db_manager.h"


class role_class
{
private:
    static void update(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                       std::vector<PersonalTask> &ptask_vec, std::vector<Project> &proj_vec);

public:
    static void boss(Employee &cur_user, std::vector<Employee> &empl_vec,
                     std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                     std::vector<Project> &proj_vec);

    static void slave(Employee &cur_user, std::vector<Employee> &empl_vec,
                 std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                 std::vector<Project> &proj_vec);

    static void manager(Employee &cur_user, std::vector<Employee> &empl_vec,
                      std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                      std::vector<Project> &proj_vec);

    static void hr_mngr(Employee &cur_user, std::vector<Employee> &empl_vec,
                      std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                      std::vector<Project> &proj_vec);
};

#endif // ROLE_CLASS_H
