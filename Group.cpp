#include "Group.h"
#include <fstream>

Group::Group(int groupID)
{
	this->groupID = groupID;
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
	for (Student student : studentList) 
	{
		std::cout << student.getStudentName() << std::endl;
	}
}

void Group::saveGroupInfor()
{
	std::fstream groupMember;
	groupMember.open("group.dat", std::ios::out | std::ios::binary);

	for (Student& student : studentList)
	{
		groupMember.write(reinterpret_cast<char*>(student.getStudentID()), sizeof(student.getStudentID()));

		int nameLength = student.getStudentName().length();
		groupMember.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
		groupMember.write(student.getStudentName().c_str(), nameLength);

		groupMember.write(reinterpret_cast<char*>(student.getGroupStatus()), sizeof(student.getGroupStatus()));

		groupMember.write(reinterpret_cast<char*>(student.getGroupID()), sizeof(student.getGroupID()));
	}

	groupMember.close();
}

void Group::loadGroupInfor()
{
	std::fstream groupMember;
	groupMember.open("group.dat", std::ios::in | std::ios::binary);
	if (!groupMember.is_open())
	{
		std::cout << "file not found!";
		return;
	}

	studentList.clear();

	for (Student& student : studentList)
	{
		int studentID;
		bool groupStatus;
		int groupID;
		groupMember.read(reinterpret_cast<char*>(&studentID), sizeof(studentID));

		int nameLength;
		groupMember.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
		char* nameBuffer = new char[nameLength + 1];
		groupMember.read(nameBuffer, nameLength);
		nameBuffer[nameLength] = '\0';
		std::string studentName(nameBuffer);
		delete[] nameBuffer;

		groupMember.read(reinterpret_cast<char*>(&groupStatus), sizeof(groupStatus));

		groupMember.read(reinterpret_cast<char*>(&groupID), sizeof(groupID));

		Student student;
		student.setGroupID(groupID);
		student.setStudentID(studentID);
		student.setStudentName(studentName);
		student.setGroupStatus(groupStatus);
		studentList.push_back(student);
	}

	groupMember.close();
}
