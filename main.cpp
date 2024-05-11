#include <iostream>

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
                    system("pause");
                    break;
                }
                case 2: {
                    std::cout << "Display information\n";
                    system("pause");
                    break;
                }
                case 3: {
                    std::cout << "Save group information\n";
                    system("pause");
                    break;
                }
                case 4: {
                    std::cout << "Load group information\n";
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
        case 2:
            std::cout << "Project (assignment) deadline information:\n";
            std::cout << "2.1 Project declaration\n";
            std::cout << "2.2 Project information\n";
            break;
        case 3:
            std::cout << "Submit project\n";
            system("pause");
            break;
        case 4:
            std::cout << "Statistic\n";
            system("pause");
            break;
        case 5:
            std::cout << "Overall Statistic\n";
            system("pause");
            break;
        case 6:
            std::cout << "Find groups do not complete or submit on time\n";
            system("pause");
            break;
        case 7:
            std::cout << "Quitting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            system("pause");
            break;
        }

        std::cout << std::endl;
    } while (choice != 7);

    return 0;
}