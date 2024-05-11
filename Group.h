#include<iostream>
#include "Student.h"
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

public:
    /**
     * @brief Constructor for the Group class.
     * @param groupID ID of the group
     */
    Group(int groupID);

    Group();

    /**
     * @brief Destructor for the Group class.
     */
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
    void setStudentList(std::vector<Student> statistic);
    std::vector<Student> getStudentList();

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
};
#pragma once