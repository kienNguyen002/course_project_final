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

int Submission::getProjectID() const { return projectID; }


void Submission::setProjectID(int projectID) { this->projectID = projectID; }


int Submission::getGroupID() const { return groupID; }


void Submission::setGroupID(int groupID) { this->groupID = groupID; }


bool Submission::getStatus() const { return status; }


void Submission::setStatus(bool status) { this->status = status; }

Time Submission::getSubmitDate() const { return submitDate; }

void Submission::setSubmitDate(Time submitDate) { this->submitDate = submitDate; }
std::string Submission::submissionInfor() {
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

void Submission::saveSubmissionInfor()
{
	std::fstream statisticContent;
	statisticContent.open("group.dat", std::ios::out | std::ios::binary);

	for (Submission statistic : statisticList)
	{
		statisticContent.write(reinterpret_cast<char*>(&statistic.projectID), sizeof(statistic.projectID));
		statisticContent.write(reinterpret_cast<char*>(&statistic.groupID), sizeof(statistic.groupID));
		statisticContent.write(reinterpret_cast<char*>(&statistic.submitDate), sizeof(statistic.submitDate));
		statisticContent.write(reinterpret_cast<char*>(&statistic.status), sizeof(statistic.status));
	}

	statisticContent.close();
}

void Submission::loadSubmissionInfor()
{
	std::fstream statisticContent;
	statisticContent.open("Overall statistic.dat", std::ios::in | std::ios::binary);
	if (!statisticContent)
	{
		std::cout << "file not found!";
		return;
	}
	for (Submission statistic : statisticList)
	{
		statisticContent.read(reinterpret_cast<char*>(&statistic.projectID), sizeof(statistic.projectID));
		statisticContent.read(reinterpret_cast<char*>(&statistic.groupID), sizeof(statistic.groupID));
		statisticContent.read(reinterpret_cast<char*>(&statistic.submitDate), sizeof(statistic.submitDate));
		statisticContent.read(reinterpret_cast<char*>(&statistic.status), sizeof(statistic.status));
		
		statisticList.push_back(statistic);
	}
	statisticContent.close();
}

void Submission::setStatisticList(std::vector<Submission> )
{
	this->statisticList = statisticList;
}

std::vector<Submission> Submission::getStatisticList()
{
	return statisticList;
}