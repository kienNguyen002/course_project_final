#include<iostream>
#include<iomanip>
#include "Submission.h"
#include <fstream>

Submission::Submission(int projectID, int groupID, Time submitDate, bool status) {
	this->projectID = projectID;
	this->groupID = groupID;
	this->submitDate = submitDate;
	this->status = status;
}

std::vector<Submission> Submission::getStatisticList()
{
	return submissionlist;
}

Submission::Submission() = default;

int Submission::getProjectID() const { return projectID; }


void Submission::setProjectID(int projectID) { this->projectID = projectID; }


int Submission::getGroupID() const { return groupID; }


void Submission::setGroupID(int groupID) { this->groupID = groupID; }


bool Submission::getStatus() const { return status; }


void Submission::setStatus(bool status) { this->status = status; }

Time Submission::getSubmitDate() const { return submitDate; }

void Submission::setSubmitDate(Time submitDate) 
{ this->submitDate = submitDate; }
std::string Submission::submissionInfor() 
{
	std::string status_sub;
	std::string infor;
	if (getStatus()) {
		status_sub = "On time";
	}
	else {
		status_sub = "late";
	}
	infor = "Project no" + std::to_string(getProjectID()) + " Group " + std::to_string(getGroupID()) + "  Status: "+ status_sub + " Submitted date: " + submitDate.toString();
	return infor;
}

void Submission::saveSubmissionInfor(std::string fileName)
{
	std::fstream statisticContent;
	std::string name = fileName + ".dat";
	statisticContent.open("group.dat", std::ios::out | std::ios::binary);
	statisticContent.write(reinterpret_cast<char*>(this), sizeof(Submission));
	statisticContent.close();
}

void Submission::loadSubmissionInfor(std::string fileName)
{
	std::string name = fileName + ".dat";
	std::fstream statisticList;
	statisticList.open(name.c_str(), std::ios::in | std::ios::binary);
	if (!statisticList.is_open())
	{
		std::cout << "file not found!";
		return;
	}

	Submission submission;
	statisticList.read(reinterpret_cast<char*>(&submission), sizeof(submission));
	this->groupID = submission.getGroupID();
	for (Submission& sm : submission.getStatisticList())
	{
		this->submissionlist.push_back(sm);
	}
	statisticList.close();
}


