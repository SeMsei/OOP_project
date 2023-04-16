
#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <string>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <map>
#include "employee.h"
#include "role.h"
#include <iostream>
#include "worktask.h"
/*#include "personaltask.h"
#include "project.h"*/

class Employee;
class WorkTask;
class PersonalTask;
class Project;


std::map<std::string, Role> role_map {  {"Boss", Role::Boss},
    {"project_manager", Role::project_manager}, {"developer", Role::developer},
    {"designer", Role::designer}, {"hr_manager", Role::hr_manager}};

class db_manager
{
private:
    //static std::string connection_str;

public:
    static bool connect(std::string cnct_str) {
        struct stat sb;

        if (!stat(cnct_str.c_str(), &sb))
            //connection_str = cnct_str;
        {}
        else
            return false;

        return true;
    }

    static std::vector<Employee> get_employees(std::string connection_str) {
        std::vector<Employee> ret_vec;
        std::string line;
        std::ifstream in(connection_str + "\\employees.txt");
        while (std::getline(in, line)) {
            //id; first_name; middle_name; surname; date_birth; KPI; role; salary; date_start; is_cur_working, project_id;
            //work_task_vec;
            //personal_task_vec;
            //
            //Employee tmp();
            int id, tmp_id, project_id;
            std::string first_name, middle_name, surname, date_b_str, date_s_str, role;
            double KPI, salary;
            bool is_cur_working;
            std::vector<int> work_task_vec;
            std::vector<int> personal_task_vec;
            std::stringstream cont;
            std::chrono::sys_days date_b, date_s;
            std::chrono::year_month_day date_birth, date_start;

            cont << line;
            cont >> id >> first_name >> middle_name >> surname >> date_b_str >> KPI >> role >>
                salary >> date_s_str >> is_cur_working >> project_id;

            std::istringstream iss_b{date_b_str}, iss_s{date_s_str};

            std::chrono::from_stream(iss_b, "%F", date_b);
            std::chrono::from_stream(iss_s, "%F", date_s);
            date_birth = date_b;
            date_start = date_s;


            Employee tmp(id, first_name, middle_name, surname, date_birth, date_start);
            tmp.set_kpi(KPI);
            tmp.set_role(role_map[role]);
            tmp.set_salary(salary);
            tmp.set_working_status(is_cur_working);

            cont.clear();
            std::getline(in, line);
            cont << line;

            while (cont >> tmp_id) {
                work_task_vec.push_back(tmp_id);
                tmp.add_work_task(tmp_id);
            }

            cont.clear();
            std::getline(in, line);
            cont << line;

            while (cont >> tmp_id) {
                personal_task_vec.push_back(tmp_id);
                tmp.add_personal_task(tmp_id);
            }

            tmp.set_project_id(project_id);

            ret_vec.push_back(Employee(tmp));
        }

        return ret_vec;
    }


};

#endif // DB_MANAGER_H
