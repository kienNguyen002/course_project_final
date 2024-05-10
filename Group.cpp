#include "Group.h"

Group::Group(int groupID){
	this->groupID = groupID;
}

Group::~Group() = default;

int Group::getGroupID() const { return groupID; }

void Group::setGroupID(int groupID) { this->groupID = groupID; }

//void Group::deleteStudent(Student* student){}

int Group::getNumberOfStudent() const { return static_cast<int>(studentList.size()); }

void Group::addNewStudent(Student* student) {
	if (student->getGroupStatus() == true) {
		std::cout << "This student already been in other group";
		return;
	}
	else {
		student->setGroupID(this->groupID);
		student->setGroupStatus(true);
		studentList.push_back(*student);
	}
	
}

//void Group::saveGroupInfor(){}
//
//void Group::loadGroupInfor(){}
//
void Group::displayGroupInfor() const{
	std::cout << "\nGroup " << groupID << std::endl;
	for (Student student : studentList) {
		std::cout << student.getStudentName() << std::endl;
	}
}
