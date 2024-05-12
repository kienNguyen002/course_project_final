#include<iostream>
#include"Course.h"

void addGroupMember(Course &course) {
	int groupID;
	int studentID;
	std::cout << "\nInput ID of the student: ";
	std::cin >> studentID;
	Student* st = course.findStudentByID(studentID);
	if (st != nullptr) {
		std::cout << "\nInput ID of the group: ";
		std::cin >> groupID;
		Group* group = course.findGroupByID(groupID);
		if (group != nullptr) {
			group->addNewStudent(st);
			std::cout << st->toString();
		}
		else
		{
			std::cout << "Can not find the group";
		}
	}
	else {
		std::cout << "Can not find the student";
	}
}

int main() {
	Course CS_256 = Course("CS256");
	CS_256.addNewStudent(1, "John");
	CS_256.addNewStudent(2, "David");
	CS_256.addNewStudent(3, "Michael");
	CS_256.addNewStudent(4, "Vladimir");
	CS_256.addNewStudent(5, "Joe");
	CS_256.addNewGroup(1);
	CS_256.addNewGroup(2);
	CS_256.addNewGroup(3);
	CS_256.addNewGroup(4);
	CS_256.addNewGroup(5);
	Time dueDate = Time(23, 3, 2020);
	CS_256.addNewProject(1, dueDate);
	CS_256.addNewProject(2, dueDate);
	CS_256.addNewProject(3, dueDate);
	CS_256.addNewProject(4, dueDate);
	CS_256.submit(1, 1, Time(21, 3, 2020));
	CS_256.submit(1, 2, Time(21, 1, 2020));
	CS_256.submit(1, 3, Time(21, 2, 2020));
	CS_256.submit(1, 4, Time(21, 4, 2020));
	CS_256.submit(2, 4, Time(21, 3, 2020));
	CS_256.submit(2, 3, Time(21, 1, 2020));
	CS_256.submit(3, 3, Time(20, 4, 2020));
	CS_256.submit(3, 2, Time(17, 3, 2020));
	CS_256.submit(4, 3, Time(15, 6, 2020));
	CS_256.submit(4, 3, Time(20, 2, 2019));

	std::cout << "\nStatistic by group, group 1" << std::endl;
	CS_256.statSubmissionByGroupID(1);
	std::cout << '\n';
	std::cout << "\nStatistic by group, group 2" << std::endl;
	CS_256.statSubmissionByGroupID(2);
	std::cout << '\n';
	std::cout <<"\nStatistic by project, projec 2" << std::endl;
	CS_256.statSubmissionByProjectID(2);
	Time date = Time(22, 4 ,2024);
	std::cout << '\n';
	std::cout << "\nStatistic by to date, project 2, date: "<<date.toString()<< std::endl;
	CS_256.statSubmissionToDate(2, date);
}