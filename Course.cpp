
#include "Course.h"

Course::Course(std::string courseID) {}

int Course::getNumberOfProjects() const {
	return projectList.size();
}
void Course::setNumberOfProjects(int number_of_projects) {
	this->number_of_projects = number_of_projects;
}
int Course::getNumberOfGroups() const {
	return groupList.size();
}
void Course::setNumbeOfGroups(int number_of_groups) {
	this->number_of_groups = number_of_groups;
}

void Course::addNewStudent(int studentID, std::string studentName) {
	Student newStudent = Student(studentID, studentName);
	studentList.push_back(newStudent);
}
void Course::addNewGroup(int groupID) {
	Group newGroup = Group(groupID);
	groupList.push_back(newGroup);

}
void Course::addStudentToAGroup(Student* student, int groupID) {
	if (student->getGroupStatus() == true) {
		std::cout << "This student was in another group, can not add";
	}
	else
	{
		Group* group = findGroupByID(groupID);
		group->addNewStudent(student);
	}

}
void Course::deleteStudentFromAGroup() {
}
void Course::addNewProject(int projectID, Time dueDate) {
	Project newProject = Project(projectID, dueDate);
	projectList.push_back(newProject);

}
void Course::submit(int groupID, int projectID, Time submitDate) {
	Project* project = findProjectbyID(projectID);
	Time dueDate = project->getDueDate();
	bool status = dueDate.isOnTime(submitDate);
	Submission submission_result = Submission(projectID, groupID, submitDate, status);
	submissionList.push_back(submission_result);
}
Student* Course::findStudentByID(int studentID) {
	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].getStudentID() == studentID)
		{
			return &studentList[i];
		}
	}
	return nullptr;

}
Group* Course::findGroupByID(int ID) {
	for (int i = 0; i < groupList.size(); i++) {
		if (groupList[i].getGroupID() == ID) {
			return &groupList[i];
		}
	}
	return nullptr;
}

Project* Course::findProjectbyID(int ID) {
	for (int i = 0; i < projectList.size(); i ++) {
		if (projectList[i].getProjectID() == ID) {
			return &projectList[i];
		}
	}
	return nullptr;
}

Submission* Course::findSubmission(int projectID, int groupID) {
	for (int i = 0; i < submissionList.size(); i++) {
		if ((submissionList[i].getGroupID() == groupID) && (submissionList[i].getProjectID() == projectID)) {
			return &submissionList[i];
		}
	}
	return nullptr;
}

void Course::statSubmissionByProjectID(int projectID, Time currentTime) {
	if (findProjectbyID(projectID) == nullptr) {
		std::cout << "Can not find project id";
	}
	else {
		for (int i = 0; i < groupList.size(); i++) {
			int groupID = groupList[i].getGroupID();
			Submission* submission = findSubmission(projectID, groupID);
			if (submission != nullptr) {
				std::cout << submission->submissionInfor() << std::endl;
				std::cout << "Project " << projectID <<  " deadline: " << findProjectbyID(projectID)->getDueDate().toString() << std::endl;
			}
			else {
				if (findProjectbyID(projectID)->getDueDate().isOnTime(currentTime)) {
					std::cout << "Project no" + std::to_string(projectID) << " Group " << std::to_string(groupID) << "  Status: not submitted\n";
				}
				else {
					std::cout << "Project no" + std::to_string(projectID) << " Group " << std::to_string(groupID) << "  Status: not yet submitted\n";
				}
			}
		}
	}
}

void Course::statSubmissionByGroupID(int groupID, Time currentTime) {
	if (findGroupByID(groupID) == nullptr) {
		std::cout << "Can not find group id";
	}
	else {
		int i = 0;
		for (auto project : projectList) {
			int projectID = project.getProjectID();
			for (auto submission : submissionList) {
				if (findSubmission(projectID, groupID) != nullptr) {
					std::cout << submission.submissionInfor() << std::endl;
					i++;
				}
				else if (findProjectbyID(projectID)->getDueDate().isOnTime(currentTime)) {
					std::cout << "Project no" + std::to_string(projectID) << " Group " << std::to_string(groupID) << "  Status: not submitted";
				}
				else
				{
					std::cout << "Project no" + std::to_string(projectID) << " Group " << std::to_string(groupID) << "  Status: not yet submitted";
				}
			}
		}
		if (i == 0) {
			std::cout << "Can not find submission information" << groupID;
		}
	}
}

void Course::statSubmissionByStatus(int projectID, bool status) {
	if (findProjectbyID(projectID) == nullptr) {
		std::cout << "Can not fine the project ID";
	}
	else {
		int i = 0;
		for (auto submission : submissionList) {
			if (submission.getProjectID() == projectID && submission.getStatus() == status) {
				std::cout << submission.submissionInfor() << std::endl;
				i++;
			}
		}
		if (i == 0) {
			std::cout << "Can not find submission information";
		}
	}
}

void Course::statOverall(Time date) {
	for (auto project : projectList) {
		if (project.getDueDate().isOnTime(date) == false) {
			statSubmissionByProjectID(project.getProjectID(), date);
		}
	}
}

void Course::saveAllGroupInfor(std::string fileName) {
	std::fstream outfile(fileName);
	for (auto group : groupList)
	{
		group.saveGroupInfor(outfile);
	}

}

void Course::loadAllGroupInfor(std::string fileName) {
	std::fstream infile(fileName);
	//đọc hết file
	//tạo đối tượng group từ file - > grouplist.pushbach()
	//group.display();


}
