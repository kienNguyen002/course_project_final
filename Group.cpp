#include "Group.h"
#include <fstream>
#include <cstring>

Group::Group(int groupID){
	this->groupID = groupID;
}

Group::Group() = default;

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

std::vector<Submission> Group::getStatisticList()
{
	return submissionlist;
}

void  Group::setStatisticList(std::vector<Submission> submissionlist)
{
	this->submissionlist = submissionlist;
	Submission statistic;
	statistic.getProjectID();
	statistic.getGroupID();
	statistic.getStatus();
	statistic.getSubmitDate();
	submissionlist.push_back(statistic);
}
//void Group::deleteStudent(Student* student){}

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

void Group::saveGroupInfor(std::string fileName)
{
	std::string name = fileName + ".dat";
	std::fstream groupMember;
	groupMember.open(name.c_str(), std::ios::out | std::ios::binary);
	groupMember.write(reinterpret_cast<char*>(this), sizeof(Group));
	groupMember.close();
}

void Group::loadGroupInfor(std::string fileName)
{
	std::string name = fileName + ".dat";
	std::fstream groupMember;
	groupMember.open(name.c_str(), std::ios::in | std::ios::binary);
	if (!groupMember.is_open())
	{
		std::cout << "file not found!";
		return;
	}

	studentList.clear();
	Group group;
	groupMember.read(reinterpret_cast<char*>(&group), sizeof(Group));
	this->groupID = group.getGroupID();
	for(Student& st : group.getStudentList()) 
	{
		this->studentList.push_back(st);
	}
	groupMember.close();
}

void Group::saveSubmissionInfor(std::string fileName)
{
	std::fstream statisticContent;
	std::string name = fileName + ".dat";
	statisticContent.open(name.c_str(), std::ios::out | std::ios::binary);
	statisticContent.write(reinterpret_cast<char*>(this), sizeof(Group));
	statisticContent.close();
}

void Group::loadSubmissionInfor(std::string fileName)
{
	std::string name = fileName + ".dat";
	std::fstream statisticList;
	statisticList.open(name.c_str(), std::ios::in | std::ios::binary);
	if (!statisticList.is_open())
	{
		std::cout << "file not found!";
		return;
	}

	Group submission;
	statisticList.read(reinterpret_cast<char*>(&submission), sizeof(submission));
	this->groupID = submission.getGroupID();
	for (Submission& sm : submission.getStatisticList())
	{
		this->submissionlist.push_back(sm);
	}
	statisticList.close();
}



