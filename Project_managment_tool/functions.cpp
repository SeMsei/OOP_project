
#include "functions.h"
#include <iostream>




void remove_project(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                    std::vector<Project> &proj_vec) { //
    int id;

    std::cout << "\nEnter project id: ";
    std::cin >> id;

    auto it = std::find_if(proj_vec.begin(), proj_vec.end(),
                           [id](Project tmp){return tmp.get_id() == id;});

    if (it == proj_vec.end()) {
        std::cout << "Wrong\n";
        return;
    }

    std::vector<int> tasks_id = it->get_tasks();

    for(auto x:tasks_id) {
        auto task_it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                                    [x](WorkTask tmp){return tmp.get_id() == x;});

        std::vector<int> employee_id = task_it->get_employees_id();

        for (auto y:employee_id) {
            auto empl_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                        [y](Employee tmp){return tmp.get_id() == y;});

            empl_it->remove_task(x);
            empl_it->set_project_id(-1);
        }

        wtask_vec.erase(task_it);
    }

    proj_vec.erase(it);

    //update();
}

void remove_personal_task(Employee &usr, std::vector<Employee> &empl_vec,
                          std::vector<PersonalTask> &ptask_vec) { //
    int id;

    std::cout << "\nEnter task id: ";
    std::cin >> id;

    auto it = std::find_if(ptask_vec.begin(), ptask_vec.end(),
                           [id](PersonalTask tmp){return tmp.get_id() == id;});

    if (it == ptask_vec.end()) {
        std::cout << "Wrong";
        return;
    }

    if (it->get_employee_id() != usr.get_id()) {
        std::cout << "Wrong";
        return;
    }

    int employee_id = it->get_employee_id();

    auto empl_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                [employee_id](Employee tmp){return tmp.get_id() == employee_id;});

    auto t = empl_it->get_personal_tasks();
    for (auto x:t) std::cout << x;

    empl_it->remove_personal_task(id);
    ptask_vec.erase(it);
    //update();
}

void remove_work_task(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                      std::vector<Project> &proj_vec) { //
    int id;

    std::cout << "\nEnter task id: ";
    std::cin >> id;

    auto it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                           [id](WorkTask task){return task.get_id() == id;});

    if (it == wtask_vec.end()) {
        std::cout << "Wrong";
        return;
    }

    std::vector<int> employees_id = it->get_employees_id();
    int proj_id = it->get_project();

    for (auto x:employees_id) {


        auto empl_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                    [x](Employee tmp){return tmp.get_id() == x;});
        empl_it->remove_task(id);
    }

    auto proj_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                [proj_id](Project proj_tmp){return proj_tmp.get_id() == proj_id;});


    proj_it->remove_task(id);

    wtask_vec.erase(it);

    //update();
}

void fire_employee(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                   std::vector<PersonalTask> &ptask_vec, std::vector<Project> &proj_vec) { //
    int id;

    std::cout << "\nEnter employee id: ";
    std::cin >> id;
    auto empl_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                [id](Employee tmp){return tmp.get_id() == id;});

    if (empl_it == empl_vec.end()) {
        std::cout << "Wrong";
        return;
    }

    //clear tasks from employee
    std::vector<int> tasks = empl_it->get_work_tasks();

    for (auto x:tasks) {
        auto task_it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                                    [x](WorkTask tmp){return x == tmp.get_id();});

        task_it->remove_employee(id);
    }


    //remove employee from project
    auto proj_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                [empl_it](Project tmp){return tmp.get_id() == empl_it->get_project_id();});

    proj_it->remove_employee(id);


    //clear personal tasks
    auto vec_tasks = empl_it->get_personal_tasks();
    for (auto x:vec_tasks) {
        auto it = std::find_if(ptask_vec.begin(), ptask_vec.end(),
                               [x](PersonalTask tmp){return tmp.get_id() == x;});

        ptask_vec.erase(it);
    }


    //remove empoyee
    empl_vec.erase(empl_it);


    //update();
}

void change_employee_work_status(std::vector<Employee> &empl_vec) { //
    int id;

    std::cout << "\nEnter employee id: ";
    std::cin >> id;

    auto employee_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                    [id](Employee tmp){return tmp.get_id() == id;});

    if (employee_it == empl_vec.end()) {
        std::cout << "Wrong\n";
        return;
    }

    employee_it->set_working_status(employee_it->get_working_status() ^ 1);

    //update();
}

void change_task_description(std::vector<PersonalTask> &ptask_vec) { //
    std::string new_description;
    int id;

    std::cout << "\nEnter task id: ";
    std::cin >> id;
    std::cout << "\nEnter new description: \n";
    std::cin.ignore();
    std::getline(std::cin, new_description);

    auto task_it = std::find_if(ptask_vec.begin(), ptask_vec.end(),
                                [id](PersonalTask tmp){return tmp.get_id() == id;});

    if (task_it == ptask_vec.end()) {
        std::cout << "Wrong";
        return;
    }

    task_it->set_description(new_description);

    //update();
}

void change_work_task_name(std::vector<WorkTask> &wtask_vec) { //
    std::string new_name;
    int id;

    std::cout << "\nEnter task id: ";
    std::cin >> id;
    std::cout << "Enter new task name: \n";
    std::cin.ignore();
    std::getline(std::cin, new_name);
    auto task_it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                                [id](WorkTask tmp){return id == tmp.get_id();});

    if (task_it == wtask_vec.end()) {
        std::cout << "Wrong";
        return;
    }

    task_it->set_name(new_name);

    //update();
}

void change_personal_task_name(Employee &usr, std::vector<PersonalTask> &ptask_vec) { //
    std::string new_name;
    int id;

    std::cout << "\nEnter task id: ";
    std::cin >> id;
    std::cout << "Enter new task name: \n";
    std::cin.ignore();
    std::getline(std::cin, new_name);
    auto task_it = std::find_if(ptask_vec.begin(), ptask_vec.end(),
                                [id](PersonalTask tmp){return id == tmp.get_id();});

    if (task_it == ptask_vec.end()) {
        std::cout << "Wrong";
        return;
    }

    if (task_it->get_employee_id() != usr.get_id()) {
        std::cout << "wrong";
        return;
    }

    task_it->set_name(new_name);

    //update();
}

void change_employee_salary(std::vector<Employee> &empl_vec) { //
    int id;
    double salary;
    std::cout << "\nEnter employee id: ";
    std::cin >> id;
    std::cout << "Enter new salary: ";
    std::cin >> salary;

    auto empl_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                [id](Employee empl){return id == empl.get_id();});

    if (empl_it == empl_vec.end()) {
        std::cout << "worng";
        return;
    }

    empl_it->set_salary(salary);

    //update();
}

void change_finish_date_project(std::vector<Project> &proj_vec) { //
    int project_id;
    std::string new_str;
    std::chrono::year_month_day new_date;

    std::cout << "\nEnter project id: ";
    std::cin >> project_id;
    std::cout << "\nEnter new date: ";
    std::cin >> new_str;

    std::istringstream f{new_str};
    std::chrono::from_stream(f, "%F", new_date);

    auto proj_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                [project_id](Project tmp){return project_id == tmp.get_id();});

    if (proj_it == proj_vec.end()) {
        std::cout << "Worn\n";
        return;
    }

    if (new_date < proj_it->get_date_start()) {
        std::cout << "Worng date\n:";
        return;
    }

    proj_it->set_date_finish(new_date);

    //update();
}

void change_finish_date_personal_task(Employee &usr, std::vector<PersonalTask> &ptask_vec) { //
    int task_id;
    std::string new_str;
    std::chrono::year_month_day new_date;

    std::cout << "\nEnter task id: ";
    std::cin >> task_id;
    std::cout << "\nEnter new finish date: ";
    std::cin >> new_str;

    std::istringstream f{new_str};
    std::chrono::from_stream(f, "%F", new_date);

    auto task_it = std::find_if(ptask_vec.begin(), ptask_vec.end(),
                                [task_id](PersonalTask tmp){return tmp.get_id() == task_id;});

    if (task_it == ptask_vec.end()) {
        std::cout << "Worn\n";
        return;
    }

    if (task_it->get_employee_id() != usr.get_id()) {
        std::cout << "wrong\n";
        return;
    }

    if (new_date < task_it->get_date_start()) {
        std::cout << "Worng date\n:";
        return;
    }

    task_it->set_date_finish(new_date);

    //update();
}

void change_finish_date_work_task(std::vector<WorkTask> &wtask_vec) { //
    int task_id;
    std::string new_str;
    std::chrono::year_month_day new_date;

    std::cout << "\nEnter task id: ";
    std::cin >> task_id;
    std::cout << "\nEnter new finish date: ";
    std::cin >> new_str;

    std::istringstream f{new_str};
    std::chrono::from_stream(f, "%F", new_date);

    auto task_it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                                [task_id](WorkTask tmp){return tmp.get_id() == task_id;});

    if (task_it == wtask_vec.end()) {
        std::cout << "Worn\n";
        return;
    }

    if (new_date < task_it->get_date_start()) {
        std::cout << "Worng date\n:";
        return;
    }

    task_it->set_date_finish(new_date);

    //update();
}

void complete_personal_task(Employee &usr, std::vector<PersonalTask> &ptask_vec) { //
    int task_id;
    std::cout << "\nEnter task id: ";
    std::cin >> task_id;
    auto task_it = std::find_if(ptask_vec.begin(), ptask_vec.end(),
                                [task_id](PersonalTask tmp){return task_id == tmp.get_id();});

    if (task_it == ptask_vec.end()) {
        std::cout << "Worn\n";
        return;
    }

    if (task_it->get_employee_id() != usr.get_id()) {
        std::cout << "wong\n";
        return;
    }

    task_it->complete();

    //update();
}

void complete_work_task(std::vector<WorkTask> &wtask_vec,
                        std::vector<Project> &proj_vec) { //
    int task_id, project_id;

    std::cout << "\nEnter task to complete: ";
    std::cin >> task_id;

    auto task_it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                                [task_id](WorkTask tmp){return task_id == tmp.get_id();});

    if (task_it == wtask_vec.end()) {
        std::cout << "Worn\n";
        return;
    }

    task_it->complete();

    project_id = task_it->get_project();
    auto project_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                   [project_id](Project tmp){return project_id == tmp.get_id();});

    project_it->complete_task();

    //update();
}

void complete_work_task(Employee &cur_user, std::vector<WorkTask> &wtask_vec,
                        std::vector<Project> &proj_vec) {
    int task_id, project_id;

    std::cout << "\nEnter task to complete: ";
    std::cin >> task_id;

    auto task_it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                                [task_id](WorkTask tmp){return task_id == tmp.get_id();});

    if (task_it == wtask_vec.end()) {
        std::cout << "Worng";
        return;
    }

    if (task_it ->get_project() != cur_user.get_project_id()) {
        std::cout << "Worng";
        return;
    }

    std::vector<int> tmp_vec = cur_user.get_work_tasks();

    auto tmp_it = std::find_if(tmp_vec.begin(), tmp_vec.end(),
                               [task_id](int id){return task_id == id;});

    if (tmp_it == tmp_vec.end()) {
        std::cout << "Worng";
        return;
    }

    project_id = task_it->get_project();
    auto project_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                   [project_id](Project tmp){return project_id == tmp.get_id();});

    project_it->complete_task();

    //update();
}

void change_slave_project(int employee_id, int project_id, std::vector<Employee> &empl_vec,
                          std::vector<WorkTask> &wtask_vec, std::vector<Project> &proj_vec) { //
    auto employee_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                    [employee_id](Employee tmp){return employee_id == tmp.get_id();});

    auto new_project_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                       [project_id](Project tmp){return project_id == tmp.get_id();});

    if (employee_it == empl_vec.end() || new_project_it == proj_vec.end()) {
        std::cout << "Wrong\n";
        return;
    }

    if (employee_it->get_project_id() == project_id) {
        std::cout << "Already\n";
        return;
    }

    if (employee_it->get_project_id() == -1) {
        employee_it->set_project_id(project_id);
        auto new_project_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                           [project_id](Project tmp){return project_id == tmp.get_id();});
        new_project_it->add_employee(employee_id);
        //update();
        return;
    }


    //clear old tasks from employee
    std::vector<int> tmp;
    for (auto &x:wtask_vec) {
        tmp = x.get_employees_id();
        auto tmp_it = std::find_if(tmp.begin(), tmp.end(),
                                   [employee_id](int id){return employee_id == id;});

        if (tmp_it != tmp.end())
            x.remove_employee(employee_id);
    }

    //clear old project
    int old_id = employee_it->get_project_id();
    auto project_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                   [old_id](Project tmp){return old_id == tmp.get_id();});


    project_it->remove_employee(employee_id);
    //clear employee from old tasks
    for (auto x:employee_it->get_work_tasks()) {
        employee_it->remove_task(x);
    }
    //s
    employee_it->set_project_id(project_id);

    new_project_it->add_employee(employee_id);

    //update();
}

void add_slave_to_proj(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec,
                       std::vector<Project> &proj_vec) { //
    int employee_id, project_id;

    std::cout << "\nEnter employee id: ";
    std::cin >> employee_id;
    std::cout << "\nEnter new project_id: ";
    std::cin >> project_id;

    change_slave_project(employee_id, project_id, empl_vec, wtask_vec, proj_vec);

    //update();
}

void add_slave_to_task(std::vector<Employee> &empl_vec, std::vector<WorkTask> &wtask_vec) { //
    //validate task id(it can't repeat)

    int employee_id, task_id;
    std::cout << "\nEnter slave id: ";
    std::cin >> employee_id;
    std::cout << "\nEnter task id: ";
    std::cin >> task_id;

    auto employee_it = std::find_if(empl_vec.begin(), empl_vec.end(),
                                    [employee_id](Employee tmp) {return employee_id == tmp.get_id();});

    auto task_it = std::find_if(wtask_vec.begin(), wtask_vec.end(),
                                [task_id](WorkTask tmp) {return task_id == tmp.get_id();});

    if (employee_it == empl_vec.end() || task_it == wtask_vec.end()) {
        std::cout << "Wronh\n";
        return;
    }

    if (employee_it->get_project_id() != task_it->get_project()){
        std::cout << "wrong\n";
        return;
    }

    auto vec_tmp = employee_it->get_work_tasks();
    if (std::find_if(vec_tmp.begin(), vec_tmp.end(),
                     [task_id](int id){return id == task_id;}) != vec_tmp.end()) {
        std::cout << "Already added\n";
        return;
    }

    employee_it->add_work_task(task_id);
    task_it->add_employee(employee_id);

    //update();
}

void add_personal_task(Employee &cur_user, std::vector<PersonalTask> &ptask_vec) { //
    int id, employee_id = cur_user.get_id();
    if (ptask_vec.size() > 0)
        id = ptask_vec.back().get_id() + 1;
    else
        id = 1;
    std::string name, description, date_s, date_f;
    std::chrono::year_month_day date_start, date_finish;
    std::cout << "\nEnter name: ";
    std::cin >> name;
    std::cout << "\nEnter description: \n";
    std::cin.ignore();
    std::getline(std::cin, description);
    std::cout << "\nEnter start date: ";
    std::cin >> date_s;
    std::cout << "\nEnter finish date: ";
    std::cin >> date_f;
    std::istringstream s{date_s}, f{date_f};

    std::chrono::from_stream(s, "%F", date_start);
    std::chrono::from_stream(f, "%F", date_finish);

    if (date_start < std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()))) {
        std::cout << "Wrong\n";
        return;
    }

    if (date_finish < date_start) {
        std::cout << "Wrong\n";
        return;
    }

    PersonalTask tmp(id, name, date_start, date_finish, employee_id);
    tmp.set_description(description);

    cur_user.add_personal_task(id);

    ptask_vec.push_back(tmp);

    //update();
}

void add_task(std::vector<WorkTask> &wtask_vec, std::vector<Project> &proj_vec) { //
    int id, project_id;
    if (wtask_vec.size() > 0)
        id = wtask_vec.back().get_id() + 1;
    else
        id = 1;
    std::string name, date_s, date_f;
    std::chrono::year_month_day date_start, date_finish;
    std::cout << "\nEnter task name: ";
    std::cin >> name;
    std::cout << "\nEnter project id: ";
    std::cin >> project_id;
    std::cout << "\nEnter start date: ";
    std::cin >> date_s;
    std::cout << "\nEnter finish date: ";
    std::cin >> date_f;

    auto proj_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                [project_id](Project tmp){return tmp.get_id() == project_id;});

    if (proj_it == proj_vec.end()) {
        std::cout << "Wrong project id\n";
        return;
    }

    std::istringstream s{date_s}, f{date_f};

    std::chrono::from_stream(s, "%F", date_start);
    std::chrono::from_stream(f, "%F", date_finish);

    if (date_start < std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()))) {
        std::cout << "Wrong\n";
        return;
    }

    if (date_finish < date_start) {
        std::cout << "Wrong\n";
        return;
    }

    WorkTask tmp(id, name, date_start, date_finish, project_id);

    auto proj = std::find_if(proj_vec.begin(), proj_vec.end(), [project_id](Project tmp){return project_id == tmp.get_id();});
    proj->add_task(id);

    wtask_vec.push_back(WorkTask(tmp));

    //update();
}

void add_slave(std::vector<Employee> &empl_vec, std::vector<Project> &proj_vec) { //
    int id, project_id;
    if (empl_vec.size() > 0)
        id = empl_vec.back().get_id() + 1;
    else
        id = 1;
    std::string first_name, middle_name, surname, date_b;
    std::chrono::year_month_day date_birth;
    double salary;
    std::cout << "\nEnter first name: ";
    std::cin >> first_name;
    std::cout << "\nEnter middle name: ";
    std::cin >> middle_name;
    std::cout << "\nEnter surname: ";
    std::cin >> surname;
    std::cout << "\nEnter birth date: ";
    std::cin >> date_b;
    std::istringstream db{date_b};
    std::chrono::from_stream(db, "%F", date_birth);
    std::cout << "\nEnter project id: ";
    std::cin >> project_id;
    std::cout << "\nEnter salary: ";
    std::cin >> salary;

    auto proj_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                [project_id](Project tmp){return tmp.get_id() == project_id;});

    if (proj_it == proj_vec.end()) {
        std::cout << "Wrong project id\n";
        return;
    }

    Employee tmp(id, first_name, middle_name, surname, date_birth);
    tmp.set_salary(salary);
    tmp.set_project_id(project_id);

    auto it = std::find_if(proj_vec.begin(), proj_vec.end(),
                           [project_id](Project tmp){return tmp.get_id() == project_id;});

    it->add_employee(id);

    empl_vec.push_back(Employee(tmp));

    //update();
}

void add_project(std::vector<Project> &proj_vec) { //
    int id;
    if (proj_vec.size() > 0)
        id = proj_vec.back().get_id() + 1;
    else
        id = 1;
    std::string name, date_s, date_f;
    std::chrono::year_month_day date_start, date_finish;
    std::cout << "\nEnter new name: ";
    std::cin >> name;
    std::cout << "Enter start date or \"skip\" to choose current date: ";
    std::cin >> date_s;

    if (date_s == "skip") {
        date_start = std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()));
    } else {
        std::istringstream s{date_s};
        std::chrono::from_stream(s, "%F", date_start);

        if (date_start < std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()))) {
            std::cout << "Wrong\n";
            return;
        }
    }

    std::cout << "Enter finish date or \"skip\" to choose current date: ";
    std::cin >> date_f;

    if (date_f == "skip") {
        date_finish = std::chrono::year_month_day(std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()));
    } else {
        std::istringstream s{date_f};
        std::chrono::from_stream(s, "%F", date_finish);


    }

    if (date_finish < date_start) {
        std::cout << "Wrong\n";
        return;
    }

    Project pr(id, name, date_start, date_finish);
    proj_vec.push_back(Project(pr));

    //update();
}

//
void check_personal_task(Employee cur_user, std::vector<PersonalTask> &task_vec) {
    std::vector<PersonalTask> cout_vec;
    int id = cur_user.get_id();

    std::copy_if(task_vec.begin(), task_vec.end(), std::back_inserter(cout_vec),
                 [id](PersonalTask tmp){return id == tmp.get_employee_id();});

    std::cout << "\nPersonal tasks list: \n";

    for (auto x:cout_vec) {
        std::cout << "Id: " << x.get_id();
        std::cout << "\nTask name: " << x.get_name();
        std::cout << "\nTask description: " << x.get_description();
        std::cout << "\nStart date: " << x.get_date_start();
        std::cout << "\nFinish date: " << x.get_date_finish();
        std::cout << "\nIs done: " << x.is_task_done();
        std::cout << "\nIs overdue: " << x.is_task_overdue();

        std::cout << "\n-----------------------\n";
    }
}

void check_work_tasks(Employee &usr, std::vector<WorkTask> &task_vec) {
    std::cout << "\nWork tasks list: \n";

    for (auto x:task_vec) {
        std::vector<int> id_vec = x.get_employees_id();

        auto it = std::find(id_vec.begin(), id_vec.end(), usr.get_id());

        if (it != id_vec.end())
            std::cout << x.get_name() << '\n';
    }
}

void check_work_tasks(int proj_id, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec) {
    std::cout << "\nWork tasks on this project: \n";

    auto proj_it = std::find_if(proj_vec.begin(), proj_vec.end(),
                                [proj_id](Project proj){return proj.get_id() == proj_id;});
    std::vector<int> vec_id = proj_it->get_tasks();

    for (auto x:vec_id) {
        auto it =std::find_if(task_vec.begin(), task_vec.end(),
                               [x](WorkTask task){return x == task.get_id();});

        std::cout << it->get_name() << '\n';
    }
}

//
void check_work_tasks(std::vector<Employee> &empl_vec, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec) {
    std::cout << "\nWork tasks list: \n";

    for (auto tmp:task_vec) {
        std::cout << "Id: " << tmp.get_id();
        std::cout << "\nTask name: " << tmp.get_name();
        std::cout << "\nStart date: " << tmp.get_date_start();
        std::cout << "\nFinish date: " << tmp.get_date_finish();
        int id = tmp.get_project();
        std::cout << "\nProject name: " << std::find_if(proj_vec.begin(), proj_vec.end(),
                                                        [id](Project tmp_pr){return id == tmp_pr.get_id();})->get_name();
        std::cout << "\nEmployees on this task: \n";

        for (auto x:tmp.get_employees_id()) {
            std::cout << "\nEmployees name: " << std::find_if(empl_vec.begin(), empl_vec.end(),
                                                              [x](Employee empl){return x == empl.get_id();})->get_first_name() << ' ';
        }

        std::cout << "\n-----------------------\n";
    }
}

void check_cur_project(Employee &cur_user, std::vector<Project> proj_vec,
                       std::vector<WorkTask> &task_vec, std::vector<Employee> &empl_vec) {
    std::cout << "Project info: \n";
    int id = cur_user.get_project_id();

    auto it = std::find_if(proj_vec.begin(), proj_vec.end(),
                           [id](Project proj_tmp){return proj_tmp.get_id() == id;});

    std::cout << "Id: " << it->get_id();
    std::cout << "\nProject name: " << it->get_name();
    std::cout << "\nStart date: " << it->get_date_start();
    std::cout << "\nFinish date: " << it->get_date_finish();
    std::cout << "\nTask count: " << it->get_task_count();
    std::cout << "\nDone task count: " << it->get_done_task_count();
    std::cout << "\nIs done: " << it->is_completed();
    std::cout << "\nList of tasks in this project: \n";

    for (auto x:it->get_tasks()) {
        std::cout << std::find_if(task_vec.begin(), task_vec.end(),
                                  [x](WorkTask tmp_task){return x == tmp_task.get_id();})->get_name() << ' ';
    }

    std::cout << "\nList of employees on this project: \n";

    for (auto x:it->get_employees_id()) {
        std::cout << std::find_if(empl_vec.begin(), empl_vec.end(),
                                  [x](Employee tmp_empl){return x == tmp_empl.get_id();})->get_first_name() << ' ';
    }
}

//
void check_projects(std::vector<Employee> &empl_vec, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec) {
    std::cout << "\nProjects list: \n";

    for (auto tmp:proj_vec){
        std::cout << "Id: " << tmp.get_id();
        std::cout << "\nProject name: " << tmp.get_name();
        std::cout << "\nStart date: " << tmp.get_date_start();
        std::cout << "\nFinish date: " << tmp.get_date_finish();
        std::cout << "\nTask count: " << tmp.get_task_count();
        std::cout << "\nDone task count: " << tmp.get_done_task_count();
        std::cout << "\nIs done: " << tmp.is_completed();
        std::cout << "\nList of tasks in this project: \n";

        for (auto x:tmp.get_tasks()) {
            std::cout << std::find_if(task_vec.begin(), task_vec.end(),
                                      [x](WorkTask tmp_task){return x == tmp_task.get_id();})->get_name() << ' ';
        }

        std::cout << "\nList of employees on this project: \n";

        for (auto x:tmp.get_employees_id()) {
            std::cout << std::find_if(empl_vec.begin(), empl_vec.end(),
                                      [x](Employee tmp_empl){return x == tmp_empl.get_id();})->get_first_name() << ' ';
        }

        std::cout << "\n-----------------------\n";
    }
}

//
void check_employees(std::vector<Employee> &empl_vec, std::vector<WorkTask> &task_vec, std::vector<Project> &proj_vec) {
    std::cout << "\nEmployees list: \n";
    for (auto tmp: empl_vec) {
        std::cout << "Id: " << tmp.get_id();
        std::cout << "\nFirst name: " << tmp.get_first_name();
        std::cout << "\nMiddle name: " << tmp.get_middle_name();
        std::cout << "\nSurname: " << tmp.get_surname();
        std::cout << "\nDate birth: " << tmp.get_date_birth();
        std::cout << "\nRole: " << tmp.get_role();
        std::cout << "\nDate staart: " << tmp.get_start_date();
        std::cout << "\nKPI: " << tmp.get_kpi();
        std::cout << "\nSalary: " << tmp.get_salary();
        int project_id = tmp.get_project_id();
        auto tmp_pr = std::find_if(proj_vec.begin(), proj_vec.end(), [project_id](Project tmp_pr)
                                   {return tmp_pr.get_id() == project_id;});
        if (tmp_pr != proj_vec.end())
            std::cout << "\nCurrent project: " << tmp_pr->get_name();
        else
            std::cout << "\nCurrently no project";
        std::cout << "\nIs currently working: " << tmp.get_working_status();
        std::cout << "\nWork tasks:";

        for (auto x:tmp.get_work_tasks()) {
            std::cout << std::find_if(task_vec.begin(), task_vec.end(),
                                      [x](WorkTask tmp_task){return x == tmp_task.get_id();})->get_name() << ' ';
        }

        std::cout << "\n-----------------------\n";
    }
}

void check_kpi(Employee &cur_user) {
    std::cout << "\nUr KPI == " << cur_user.get_kpi() << '\n';
}
