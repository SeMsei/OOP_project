
#include "../include/role_class.h"

void role_class::update(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                        std::vector<PersonalTask> &ptask_vec, std::vector<Project> &proj_vec) {
    db_manager::update_employees(empl_vec, "E:\\");
    db_manager::update_personal_tasks(ptask_vec, "E:\\");
    db_manager::update_work_tasks(wtask_vec, "E:\\");
    db_manager::update_projects(proj_vec, "E:\\");
}

void role_class::hr_mngr(Employee &cur_user, std::vector<Employee> &empl_vec,
                                std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                                std::vector<Project> &proj_vec) {
    std::string option;

    while (1) {
        std::cout << "Functions: \n";
        std::cout << "0: log out\n;";
        std::cout << "1: Hire employee\n";
        std::cout << "2: Fire employee\n";
        std::cout << "3: Complete work task\n";
        std::cout << "4: Check own work task\n";
        std::cout << "5: Check personal task\n";
        std::cout << "6: Add personal task\n";
        std::cout << "7: Complete personal task\n";

        std::cin >> option;

        if (option == "0") {
            break;
        } else if (option == "1") {
            add_slave(empl_vec, proj_vec);
        } else if (option == "2") {
            fire_employee(empl_vec, wtask_vec, ptask_vec, proj_vec);
        } else if (option == "3") {
            complete_work_task(cur_user, empl_vec, wtask_vec, proj_vec);
        } else if (option == "4") {
            check_work_tasks(cur_user, wtask_vec);
        } else if (option == "5") {
            check_personal_task(cur_user, ptask_vec);
        } else if (option == "6") {
            add_personal_task(cur_user, ptask_vec);
        } else if (option == "7") {
            complete_personal_task(cur_user, ptask_vec);
        } else {
            std::cout << "Wrong";
        }

        update(empl_vec, wtask_vec, ptask_vec, proj_vec);
    }


}

void role_class::manager(Employee &cur_user, std::vector<Employee> &empl_vec,
                         std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                         std::vector<Project> &proj_vec) {
    std::string option;

    while (1) {
        std::cout << "Functions: \n";
        std::cout << "0: log out\n;";
        std::cout << "1: check all tasks on project\n";
        std::cout << "2: check all personal tasks\n";
        std::cout << "3: check project info";
        std::cout << "4: Check own work tasks\n";
        std::cout << "5: Complete work task\n";
        std::cout << "6: Complete personal task\n";
        std::cout << "7: Check ur KPI\n";
        std::cout << "11: Add personal task\n";
        std::cout << "8: Add task to project\n";
        std::cout << "9: Add slave to task\n";
        std::cout << "10: Remove task\n";

        std::cin >> option;

        if (option == "0") {
            break;
        } else if (option == "1") {
            check_work_tasks(cur_user.get_project_id(), wtask_vec, proj_vec);
        } else if (option == "2") {
            check_personal_task(cur_user, ptask_vec);
        } else if (option == "3") {
            check_cur_project(cur_user, proj_vec, wtask_vec, empl_vec);
        } else if (option == "4") {
            check_work_tasks(cur_user, wtask_vec);
        } else if (option == "5") {
            complete_work_task(cur_user, empl_vec, wtask_vec, proj_vec);
        } else if (option == "6") {
            complete_personal_task(cur_user, ptask_vec);
        } else if (option == "7") {
            check_kpi(cur_user);
        } else if (option == "8") {
            add_task(wtask_vec, proj_vec); //
        } else if (option == "9") {
            add_slave_to_task(empl_vec, wtask_vec); //
        } else if (option == "10") {
            remove_work_task(empl_vec, wtask_vec, proj_vec); //
        } else if (option == "11") {
            add_personal_task(cur_user, ptask_vec);
        } else {
            std::cout << "Wrong func\n";
        }

        update(empl_vec, wtask_vec, ptask_vec, proj_vec);

    }
}

void role_class::slave(Employee &cur_user, std::vector<Employee> &empl_vec,
                       std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                       std::vector<Project> &proj_vec) {
    std::string option;

    while (1) {
        std::cout << "Functions: \n";
        std::cout << "0: log out\n;";
        std::cout << "1: check all tasks on project\n";
        std::cout << "2: check all personal tasks\n";
        std::cout << "3: check project info\n\n";
        std::cout << "4: Check own work tasks\n";
        std::cout << "5: Complete work task\n";
        std::cout << "6: Complete personal task\n";
        std::cout << "7: Check ur KPI\n";
        std::cout << "8: Add personal task";

        std::cin >> option;

        if (option == "0") {
            break;
        } else if (option == "1") {
            check_work_tasks(cur_user.get_project_id(), wtask_vec, proj_vec);
        } else if (option == "2") {
            check_personal_task(cur_user, ptask_vec);
        } else if (option == "3") {
            check_cur_project(cur_user, proj_vec, wtask_vec, empl_vec);
        } else if (option == "4") {
            check_work_tasks(cur_user, wtask_vec);
        } else if (option == "5") {
            complete_work_task(cur_user, empl_vec, wtask_vec, proj_vec);
        } else if (option == "6") {
            complete_personal_task(cur_user, ptask_vec);
        } else if (option == "7") {
            check_kpi(cur_user);
        } else if (option == "8") {
            add_personal_task(cur_user, ptask_vec);
        } else {
            std::cout << "Wrong option\n";
        }

        update(empl_vec, wtask_vec, ptask_vec, proj_vec);
    }
}

void role_class::boss(Employee &cur_user, std::vector<Employee> &empl_vec,
                      std::vector<WorkTask> &wtask_vec, std::vector<PersonalTask> &ptask_vec,
                      std::vector<Project> &proj_vec) {
    std::string option;

    while (1) {
        std::cout << "Functions: \n";
        std::cout << "0: log out\n";
        std::cout << "1: Check all employees\n";
        std::cout << "2: Check all projects\n";
        std::cout << "3: Check all tasks\n";
        std::cout << "4: Check all personal task\n";
        std::cout << "5: Add project\n";
        std::cout << "6: Add slave\n";
        std::cout << "7: Add task\n";
        std::cout << "8: Add personal task\n";
        std::cout << "9: Add slave to task\n";
        std::cout << "10: Add slave to project\n";
        std::cout << "11: complete task\n";
        std::cout << "12: Change finish date of task\n";
        std::cout << "13: Change finish date of project\n";
        std::cout << "14: Change employee salary\n";//
        std::cout << "15: Change task name\n";//
        std::cout << "16: Change task description\n";//
        std::cout << "17: Change employee work status\n";//
        std::cout << "18: Fire employee\n";//
        std::cout << "19: Remove work task\n";//
        std::cout << "20: Remove personal task\n";//
        std::cout << "21: Remove project\n";//

        std::cin >> option;

        if (option == "0") {
            break;
        } else if (option == "1") {
            check_employees(empl_vec, wtask_vec, proj_vec);
        } else if (option == "2") {
            check_projects(empl_vec, wtask_vec, proj_vec);
        } else if (option == "3") {
            check_work_tasks(empl_vec, wtask_vec, proj_vec);
        } else if (option == "4") {
            check_personal_task(cur_user, ptask_vec);
        } else if (option == "5") {
            add_project(proj_vec);
        } else if (option == "6") {
            add_slave(empl_vec, proj_vec);
        } else if (option == "7") {
            add_task(wtask_vec, proj_vec);
        } else if (option == "8") {
            add_personal_task(cur_user, ptask_vec);
        } else if (option == "9") {
            add_slave_to_task(empl_vec, wtask_vec);
        } else if (option == "10") {
            add_slave_to_proj(empl_vec, wtask_vec, proj_vec);
        } else if (option == "11") {
            std::string complete_task_option;
            std::cout << "work or personal?";
            std::cin >> complete_task_option;

            if (complete_task_option == "work") {
                complete_work_task(empl_vec, wtask_vec, proj_vec);
            } else if (complete_task_option == "personal") {
                complete_personal_task(cur_user, ptask_vec);
            }
        } else if (option == "12") {
            std::string change_date_option;
            std::cout << "work or personal?";
            std::cin >> change_date_option;

            if (change_date_option == "work") {
                change_finish_date_work_task(wtask_vec);
            } else if (change_date_option == "personal") {
                change_finish_date_personal_task(cur_user, ptask_vec);
            }
        } else if (option == "13") {
            change_finish_date_project(proj_vec);
        } else if (option == "14") {
            change_employee_salary(empl_vec);
        } else if (option == "15") {
            std::string tmp_option;
            std::cout << "Work or personal? ";
            std::cin >> tmp_option;

            if (tmp_option == "work")
                change_work_task_name(wtask_vec);
            else if (tmp_option == "personal")
                change_personal_task_name(cur_user, ptask_vec);
        } else if (option == "16") {
            change_task_description(ptask_vec);
        } else if (option == "17") {
            change_employee_work_status(empl_vec);
        } else if (option == "18") {
            fire_employee(empl_vec, wtask_vec, ptask_vec, proj_vec);
        } else if (option == "19") {
            remove_work_task(empl_vec, wtask_vec, proj_vec);
        } else if (option == "20") {
            remove_personal_task(cur_user, empl_vec, ptask_vec);
        } else if (option == "21") {
            remove_project(empl_vec, wtask_vec, proj_vec);
        }

        update(empl_vec, wtask_vec, ptask_vec, proj_vec);
    }
}

