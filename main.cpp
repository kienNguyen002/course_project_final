#include<iostream>
#include"Course.h"
using namespace std;

Course CS_256("CS_256");
static int student_id_auto_increasement = 1;
Time currentTime(14, 5, 2024);

void inputInformation() {
    int num;
    std::string name;
    std::cout << "The number of groups in the class?";
    std::cin >> num;
    //CS_256.setNumbeOfGroups(num);
    for (int i = 1; i <= num; i++)
    {
        CS_256.addNewGroup(i);
        int numstudent;
        std::cout << "How many students in group " << i << "? ";
        std::cin >> numstudent;
        while (numstudent < 1) {
            std::cout << "Each group has at least one member. Please re-enter data: ";
            std::cin >> numstudent;
        }
        cin.clear();
        cin.ignore();
        for (int j = 1; j <= numstudent; j++)
        {
            std::cout << "Name of student " << j << " ";
            getline(cin, name);
            CS_256.addNewStudent(student_id_auto_increasement, name);
            Student* student = CS_256.findStudentByID(student_id_auto_increasement);
            CS_256.addStudentToAGroup(student, i);
            student_id_auto_increasement++;
        }
    }
}
void displayInformation() {
    char display;
    int groupID;
    do
    {
        std::cout << "Do you want to display information for the whole class or by group (A/E(for the whole class/for each group)) ";
        std::cin >> display;
        if (display == 'A') {
            for (int i = 1; i <= CS_256.getNumberOfGroups(); i++) {
                CS_256.findGroupByID(i)->displayGroupInfor();
            }
        }
        if (display == 'E') {

            std::cout << "What group you want to display information? ";
            std::cin >> groupID;
            CS_256.findGroupByID(groupID)->displayGroupInfor();
        }
        std::cout << "Do you want to display information (Y/N)?";
        std::cin >> display;
    } while (display == 'Y');
}
void project_declaration() {
    int numproject;
    std::cout << "How many projects in the course  ";
    std::cin >> numproject;
    for (int i = 1; i <= numproject; i++) {
        std::cout << "Project " << i << "\n";
        int id, d, m, y;
        std::string description;
        std::cout << "ID:";
        std::cin >> id;
        std::cout << "description";
        std::cin.ignore();
        getline(std::cin, description);
        std::cout << "Deadline:";
        std::cin >> d >> m >> y;
        Time deadline(d, m, y);
        std::cout << std::endl;
        CS_256.addNewProject(id, deadline);
        CS_256.findProjectbyID(id)->setDescription(description);
    }
}
void project_information() {
    int projectID;
    std::cout << "What project do you want to check?";
    std::cin >> projectID;
    std::cout << "Description: " << CS_256.findProjectbyID(projectID)->getDescription() << '\n';
    std::cout << "Deadline: " << CS_256.findProjectbyID(projectID)->getDueDate().toString();
}
void submit_project() {

    std::cout << "Enter sequentially:\n";

    int grouID, projectID, sd, sm, sy;

    char submitt;

    std::cout << "If submit then type S else type N:";

    for (int i = 1; i <= CS_256.getNumberOfGroups(); i++) {

        std::cout << "Group " << i << '\n';

        for (int j = 1; j <= CS_256.findGroupByID(i)->getNumberOfStudent(); j++) {

            std::cout << "Student " << j << ':';

            std::cin >> submitt;

            if (submitt == 'S') {

                std::cout << "Submission date(dd/mm/yyyy): ";

                std::cin >> sd >> sm >> sy;

                Time submissiondate(sd, sm, sy);

                CS_256.submit(i, j, submissiondate);

            }

        }

    }

}

void displaysByProject() {
    int pid;
    std::cout << "Please enter project ID: ";
    std::cin >> pid;
    CS_256.statSubmissionByProjectID(pid, currentTime);
}
void displaysByGroup() {
    int gid;
    std::cout << "Please enter group ID: ";
    std::cin >> gid;
    CS_256.statSubmissionByGroupID(gid, currentTime);
}
void disPlaybyStatus() {
    //tìm tất cả những nhóm chưa nộp bài hoặc nộp bài muộn
}
void overrallStat(Time date) {
    CS_256.statOverall(date);
}
int main() {

    int choice;
    do {
        system("cls");
        std::cout << "Menu:\n";
        std::cout << "1. Group information\n";
        std::cout << "2. Project (assignment) deadline information\n";
        std::cout << "3. Submit project\n";
        std::cout << "4. Statistic\n";
        std::cout << "5. Overall Statistic\n";
        std::cout << "6. Find groups do not complete or submit on time\n";
        std::cout << "7. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            int choice_1 = 0;

            do {
                system("cls");
                std::cout << "Group information:\n";
                std::cout << "1.1 Input information\n";
                std::cout << "1.2 Display information\n";
                std::cout << "1.3 Save group information\n";
                std::cout << "1.4 Load group information\n";
                std::cout << "1.5 Quit\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice_1;

                switch (choice_1) {
                case 1: {
                    std::cout << "Input information\n";
                    inputInformation();
                    system("pause");
                    break;
                }
                case 2: {
                    std::cout << "Display information\n";
                    displayInformation();
                    system("pause");
                    break;
                }
                case 3: {
                    std::cout << "Save group information\n";
                    //tuan;
                    system("pause");
                    break;
                }
                case 4: {
                    std::cout << "Load group information\n";
                    //tuan;
                    system("pause");
                    break;
                }
                case 5:
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    system("pause");
                    break;
                }
            } while (choice_1 != 5);
            break;
        }
        case 2: {
            int choice_2 = 0;
            do {
                system("cls");
                std::cout << "Project (assignment) deadline information:\n";
                std::cout << "2.1 Project declaration\n";
                std::cout << "2.2 Project information\n";
                std::cout << "2.3 Quit\n";
                std::cin >> choice_2;
                switch (choice_2) {
                case 1: {
                    std::cout << "Project declaration\n";
                    project_declaration();
                    system("pause");
                    break;
                }
                case 2: {
                    std::cout << "Project information\n";
                    project_information();
                    system("pause");
                    break;
                }
                case 3:
                    break;
                }
            } while (choice_2 != 3);
            break;
        }
        case 3: {
            std::cout << "Submit project\n";
            submit_project();
            system("pause");
            break;
        }
        case 4: {
            int choice_4 = 0;
            do {
                system("cls");
                switch (choice_4) {
                case 0: {
                    std::cout << "Statistic\n";
                    std::cout << "4.1 Displays a table show the state of submission of a project for groups\n";
                    std::cout << "4.2 Displays a table show the state of submission of all projects  of a group.\n";
                    std::cout << "4.3 Quit\n";
                    std::cin >> choice_4;
                    system("pause");
                    break;
                }
                case 1: {
                    std::cout << "Displays a table show the state of submission of a project for groups.\n";
                    displaysByProject();
                    system("pause");
                    break;
                }
                case 2: {
                    std::cout << "Displays a table show the state of submission of all projects  of a group.\n";
                    displaysByGroup();
                    system("pause");
                    break;
                }
                case 3: {break; }
                default: {

                    std::cout << "Invalid choice. Please try again.\n";
                    system("pause");
                    break; }
                }
            } while (choice_4 != 3);
            system("pause");
            break; }
        case 5: {
            std::cout << "Overall Statistic\n";
            //help
            system("pause");
            break;
        }
        case 6: {
            std::cout << "Find groups do not complete or submit on time\n";
            //not_complete_or_submit();
            system("pause");
            break; }
        case 7: {
            std::cout << "Quitting...\n";
            //help
            break; }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            system("pause");
            break;
        }
               std::cout << std::endl;
        }
    } while (choice != 7);

    return 0;
}