#include<iostream>
#include <fstream>
#include "Student.h"
#include "Submission.h"
#include<vector>
#pragma once
/**
 * @class Group
 * @brief Represents a group in the course.
 */
class Group {
private:
    //ID of the group
    int groupID;  
    // List of students in the group 
    std::vector<Student> studentList; 
    std::vector<Submission> submissionlist;


public:
    /**
     * @brief Constructor for the Group class.
     * @param groupID ID of the group
     */
    Group(int groupID);
    /**
     * @brief Destructor for the Group class.
     */
    Group();
    ~Group();

    /**
     * @brief Getter method for groupID.
     * @return ID of the group
     */
    int getGroupID() const;

    /**
     * @brief Setter method for groupID.
     * @param groupID ID of the group
     */
    void setGroupID(int groupID);

    //setter, getter for student list
    void setStudentList(std::vector<Student> studentList);
    std::vector<Student> getStudentList();

    //setter, getter for statistic list
    std::vector<Submission> getStatisticList();
    void setStatisticList(std::vector<Submission> submissionlist);

    /**
     * @brief Add a new student to the group.
     * @param student Pointer to the Student object to be added to the group
     */
    void addNewStudent(Student* student);

    ///**
    // * @brief Delete a student from the group.
    // * @param student Pointer to the Student object to be deleted from the group
    // */
    //void deleteStudent(Student* student);

    int getNumberOfStudent() const;


    /**
     * @brief Save the group information to a file.
     */
    void saveGroupInfor();

    /**
     * @brief Load the group information from a file.
     */
    void loadGroupInfor();

    /**
     * @brief Display the group information.
     */
    void displayGroupInfor() const;

    //method for save and load information from file
    void saveSubmissionInfor(std::string);
    void loadSubmissionInfor(std::string);

};
#pragma once