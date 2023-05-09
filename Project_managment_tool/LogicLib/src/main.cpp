#include <iostream>
#include <chrono>
#include "db_manager.h"
#include "employee.h"
#include <boost/signals2.hpp>
#include <boost/signals2/slot.hpp>
#include "role_class.h"

int main()
{

    //add dynamic KPI
    //task name using getline

    extern void serialize_personal_task();

    std::string login, password;

    std::vector<Employee> vec =  db_manager::get_employees("E:\\");
    std::vector<WorkTask> vec1 = db_manager::get_work_tasks("E:\\");
    std::vector<PersonalTask> vec2 = db_manager::get_personal_tasks("E:\\");
    std::vector<Project> vec3 = db_manager::get_projects("E:\\");

    while (1) {
        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> password;

        auto cur_user = std::find_if(vec.begin(), vec.end(),
                [login, password](Employee tmp){return tmp.get_login() == login && tmp.get_password() == password;});

        if (cur_user == vec.end()) {
            std::cout << "Incorrect password";
        } else if (cur_user->get_role() == Role::Boss) {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a boss\n";
            role_class::boss(*cur_user, vec, vec1, vec2, vec3);
        } else if (cur_user->get_role() == Role::hr_manager) {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a manager\n";
            role_class::hr_mngr(*cur_user, vec, vec1, vec2, vec3);
        } else if (cur_user->get_role() == Role::project_manager) {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a pm\n";
            role_class::manager(*cur_user, vec, vec1, vec2, vec3);
        } else {
            std::cout << "Hi, " << cur_user->get_first_name() << ' ' <<
                cur_user->get_middle_name() << ' ' << cur_user->get_surname() << "!\n";
            std::cout << "You are a slave\n";
            role_class::slave(*cur_user, vec, vec1, vec2, vec3);
        }


    }



    return 0;
}
