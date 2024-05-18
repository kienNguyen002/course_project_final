﻿#include "Group.h"
#include <fstream>
#include <cstring>

Group::Group(int groupID){
	this->groupID = groupID;
}

Group::Group() = default;

Group::~Group() = default;

int Group::getGroupID() const { return groupID; }

void Group::setGroupID(int groupID) { this->groupID = groupID; }

std::vector<Student> Group::getStudentList()
{
	return studentList;
}

int Group::getNumberOfStudent() const { return static_cast<int>(studentList.size()); }

void Group::addNewStudent(Student* student) 
{
	if (student->getGroupStatus() == true) 
	{
		std::cout << "This student already been in other group";
		return;
	}
	else 
	{
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

void Group::saveGroupInfor(std::fstream& outfile)
{
	outfile.write(reinterpret_cast<char*>(this), sizeof(Group));
}

//Group Group::loadGroupInfor(std::fstream& infile){
//	infile.write(reinterpret_cast<char*>(this), sizeof(Group));
//}

 
