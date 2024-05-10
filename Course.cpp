
#include "Course.h"

Course::Course(std::string courseID){}

int Course::getNumberOfProjects() const {
	return number_of_projects;
}
void Course::setNumberOfProjects(int number_of_projects) {
	this->number_of_projects = number_of_projects;
}
int Course::getNumberOfGroups() const {
	return number_of_groups;
}
void Course::setNumbeOfGroups(int number_of_groups) {
	this->number_of_groups=number_of_groups;
}

void Course::addNewStudent(int studentID, std::string studentName){
	Student newStudent = Student(studentID, studentName);
	studentList.push_back(newStudent);
}
void Course::addNewGroup(int groupID){
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
void Course::deleteStudentFromAGroup(){
}
void Course::addNewProject(int projectID, Time dueDate){
	Project newProject = Project(projectID, dueDate);
	projectList.push_back(newProject);

}
void Course::submit(int groupID, int projectID, Time submitDate){
	Project *project = findProjectbyID(projectID);
	Time dueDate= project->getDueDate();
	bool status = dueDate.isOnTime(submitDate);
	Submission submission_result = Submission(projectID, groupID, submitDate, status);
	submissionList.push_back(submission_result);
}
Student* Course::findStudentByID(int studentID) {
	for (Student student : studentList) {
		if (student.getStudentID() == studentID)
		{
			return &student;
		}
	}
	return nullptr;

}
Group* Course::findGroupByID(int ID){
	for (Group group : groupList) {
		if (group.getGroupID() == ID) {
			return &group;
		}
	}
	return nullptr;
}

Project* Course::findProjectbyID(int ID){
	for (Project project : projectList) {
		if (project.getProjectID() ==ID){
			return &project;
		}
	}
	return nullptr;
}

Submission* Course::findSubmission(int projectID, int groupID){
	for (auto submission : submissionList) {
		if ((submission.getGroupID() == groupID) && (submission.getProjectID() == projectID)) {
			return &submission;
		}
	}
	return nullptr;
}

void Course::statSubmissionByProjectID(int projectID){
	if (findProjectbyID(projectID) == nullptr) {
		std::cout << "Can not find project id";
	}
	else {
		int i = 0;
		for (auto submission : submissionList) {
			if (submission.getProjectID() == projectID) {
				std::cout << submission.submissionInfor() << std::endl;
				i++;
			}
		}
		if (i == 0) {
			std::cout << "Can not find submission information" << projectID;
		}
	}
}

void Course::statSubmissionByGroupID(int groupID) {
	if (findGroupByID(groupID) == nullptr) {
		std::cout << "Can not find group id";
	}
	else {
		int i = 0;
		for (auto submission : submissionList) {
			if (submission.getGroupID() == groupID) {
				std::cout << submission.submissionInfor() << std::endl;
				i++;
			}
		}
		if (i == 0) {
			std::cout << "Can not find submission information" << groupID;
		}
	}
}

void Course::statSubmissionByStatus(int projectID, bool status){
	if (findProjectbyID(projectID) == nullptr) {
		std::cout << "Can not fine the project ID";
	}
	else{
	int i = 0;
	for (auto submission : submissionList) {
		if (submission.getProjectID()==projectID && submission.getStatus() == status) {
			std::cout << submission.submissionInfor()<<std::endl;
			i++;
		}
	}
	if(i==0){	
	 std::cout << "Can not find submission information";
	}
	}
}

void Course::statSubmissionToDate(int projectID, Time date){
	if (findProjectbyID(projectID) == nullptr) {
		std::cout << "Can not fine the project ID";
	}
	else {
		int i = 0;
		for (auto submission : submissionList) {
			if (submission.getProjectID() == projectID && (submission.getSubmitDate().isOnTime(date)==false)){
				std::cout << submission.submissionInfor()<< std::endl;
				i++;
			}
		}
		if (i == 0) {
			std::cout << "Can not find submission information";
		}
	}
}