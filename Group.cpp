#include "Group.h"
#include <fstream>

Group::Group(int groupID){
	this->groupID = groupID;
}

Group::Group() 
{
}

Group::~Group() = default;

int Group::getGroupID() const { return groupID; }

void Group::setGroupID(int groupID) { this->groupID = groupID; }

void Group::setStudentList(std::vector<Student> studentList)
{
	this->studentList = studentList;
	Student student;
	student.getStudentID();
	student.getStudentName();
	student.getGroupID();
	student.getGroupStatus();
	studentList.push_back(student);
}

std::vector<Student> Group::getStudentList()
{
	return studentList;
}

//void Group::deleteStudent(Student* student){}

int Group::getNumberOfStudent() const { return static_cast<int>(studentList.size()); }

void Group::addNewStudent(Student* student) {
	if (student->getGroupStatus() == true) 
	{
		std::cout << "This student already been in other group";
		return;
	}
	else {
		student->setGroupID(this->groupID);
		student->setGroupStatus(true);
		studentList.push_back(*student);
	}
	
}
//đá
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

void Group::saveGroupInfor()
{
	std::fstream groupMember;
	groupMember.open("group.dat", std::ios::out | std::ios::binary);
	groupMember.write(reinterpret_cast<char*>(&studentList), sizeof(studentList));
	groupMember.close();
}

void Group::loadGroupInfor()
{
	std::fstream groupMember;
	groupMember.open("group.dat", std::ios::in | std::ios::binary);
	if (!groupMember)
	{
		std::cout << "file not found!";
	}
	while (!groupMember.eof())
	{
		groupMember.read(reinterpret_cast<char*>(&studentList), sizeof(studentList));
	}
	groupMember.close();
}
