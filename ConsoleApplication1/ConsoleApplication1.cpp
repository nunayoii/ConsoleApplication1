﻿#include <string>
#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Record.h"
#include "Utility.h"
#include "ConsoleApplication1.h"

using namespace std;
vector<Student> students;
vector<Teacher> teachers;
vector<Course> courses;
vector<Record> records;

int main()
{
	initializeData();
	displayMenu();
}

void initializeData()
{

	courses.push_back(Course("C001", "C++ Programming", "這門課程教授C++程式語言"));
	courses.push_back(Course("C002", "Java Programming", "這門課程教授Java程式語言"));
	courses.push_back(Course("C003", "Python Programming", "這門課程教授Python程式語言"));
	courses.push_back(Course("C004", "C# Programming", "這門課程教授C#程式語言"));
	courses.push_back(Course("C005", "Visual Basic Programming", "這門課程教授Visual Basic程式語言"));

	students.push_back(Student("I001", "陳", "小明", "男", "1999-01-01", "S001", Department::ComputerSciece, ClassName::_1A));
	students.push_back(Student("I002", "林", "小華", "男", "1999-02-02", "S002", Department::ElectricalEngineering, ClassName::_1A));
	students.push_back(Student("I003", "黃", "小美", "女", "1999-03-03", "S003", Department::InformationManagement, ClassName::_1B));
	students.push_back(Student("I004", "張", "小強", "男", "1999-04-04", "S004", Department::ComputerSciece, ClassName::_2A));
	students.push_back(Student("I005", "李", "小花", "女", "1999-05-05", "S005", Department::ElectronicEngineering, ClassName::_2B));

	vector<Course> teacher1_courses = { courses[0], courses[1], courses[2] };
	teachers.push_back(Teacher("I101", "王", "大富", "男", "1980-7-1", "T001", Department::ComputerSciece, ClassName::_1A, teacher1_courses));
	vector<Course> teacher2_courses = { courses[3], courses[4] };
	teachers.push_back(Teacher("I102", "李", "大貴", "男", "1985-5-5", "T002", Department::InformationManagement, ClassName::_1B, teacher2_courses));

	records.push_back(Record("S001", "C001"));
	records.push_back(Record("S001", "C002"));
	records.push_back(Record("S002", "C001"));
	records.push_back(Record("S002", "C003"));
	records.push_back(Record("S003", "C002"));
	records.push_back(Record("S003", "C003"));
	records.push_back(Record("S004", "C003"));
	records.push_back(Record("S004", "C004"));
	records.push_back(Record("S005", "C004"));
	records.push_back(Record("S005", "C005"));
}

void displayMenu() {
	int choice;
	do {
		system("cls");
		cout << "=========================" << endl;
		cout << "1. 列出學生資料" << endl;
		cout << "2. 列出課程資料" << endl;
		cout << "3. 列出教師資料" << endl;
		cout << "4. 列出選課紀錄" << endl;
		cout << "5  查詢學生資料" << endl;
		cout << "6. 查詢課程資料" << endl;
		cout << "7. 查詢教師資料" << endl;
		cout << "8. 查詢選課紀錄" << endl;
		cout << "9. 新增學生資料" << endl;
		cout << "10. 新增課程資料" << endl;
		cout << "11. 新增教師資料" << endl;
		cout << "12. 新增選課紀錄" << endl;
		cout << "13. 刪除學生資料" << endl;
		cout << "14. 刪除課程資料" << endl;
		cout << "15. 刪除教師資料" << endl;
		cout << "16. 刪除選課紀錄" << endl;
		cout << "17. 修改學生資料" << endl;
		cout << "18. 修改課程資料" << endl;
		cout << "19. 修改教師資料" << endl;
		cout << "=========================" << endl;
		cout << "0. 退出" << endl;
		cout << "請選擇操作: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "列出學生資料" << endl;
			listStudents();
			system("pause");
			break;
		case 2:
			cout << "列出課程資料" << endl;
			listCourses();
			system("pause");
			break;
		case 3:
			cout << "列出教師資料" << endl;
			listTeachers();
			system("pause");
			break;
		case 4:
			cout << "列出選課紀錄" << endl;
			listRecords();
			system("pause");
			break;
		case 5:
			cout << "查詢學生資料" << endl;
			queryStudent();
			break;
		case 6:
			cout << "查詢課程資料" << endl;
			queryCourse();
			system("pause");
			break;
		case 7:
			cout << "查詢教師資料" << endl;
			queryTeacher();
			system("pause");
			break;
		case 8:
			cout << "查詢選課紀錄" << endl;
			queryRecord();
			system("pause");
			break;
		case 9:
			cout << "新增學生資料" << endl;
			addStudent();
			system("pause");
			break;
		case 10:
			cout << "新增課程資料" << endl;
			system("pause");
			break;
		case 11:
			cout << "新增教師資料" << endl;
			system("pause");
			break;
		case 12:
			cout << "新增選課紀錄" << endl;
			system("pause");
			break;
		case 13:
			cout << "刪除學生資料" << endl;
			deleteStudent();
			system("pause");
			break;
		case 14:
			cout << "刪除課程資料" << endl;
			system("pause");
			break;
		case 15:
			cout << "刪除教師資料" << endl;
			system("pause");
			break;
		case 16:
			cout << "刪除選課紀錄" << endl;
			system("pause");
			break;
		case 17:
			cout << "修改學生資料" << endl;
			updateStudent();
			system("pause");
			break;
		case 18:
			cout << "修改課程資料" << endl;
			system("pause");
			break;
		case 19:
			cout << "修改教師資料" << endl;
			system("pause");
			break;
		case 0:
			cout << "退出" << endl;
			break;
		default:
			cout << "無效選擇" << endl;
			break;
		}
	} while (choice != 0);
}

void listStudents()
{
	cout << "學生資料總共有" << students.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto student : students) {
		student.display();
		cout << endl;
	}
	cout << endl;
}

void listCourses()
{
	cout << "課程資料總共有" << courses.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto course : courses) {
		course.display();
		cout << endl;
	}
	cout << endl;
}

void listTeachers()
{
	cout << "教師資料總共有" << teachers.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto teacher : teachers) {
		teacher.display();
		cout << endl;
	}
	cout << endl;
}

void listRecords()
{
	cout << "選課紀錄總共有" << records.size() << "筆" << endl;
	cout << "----------------" << endl;
	for (auto record : records) {
		record.display();
		cout << endl;
	}
	cout << endl;
}

void queryStudent()
{
	string studentId;
	cout << "請輸入學號: ";
	cin >> studentId;

	bool found = false;
	for (auto student : students) {
		if (student.getStudentId() == studentId) {
			student.display();
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "找不到學號為" << studentId << "的學生" << endl;
	}
}

void queryCourse()
{
	string courseId;
	cout << "請輸入課程編號: ";
	cin >> courseId;
	bool found = false;
	for (auto course : courses) {
		if (course.getCourseId() == courseId) {
			course.display();
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "找不到課程編號為" << courseId << "的課程" << endl;
	}
}

void queryTeacher()
{
	string teacherId;
	cout << "請輸入教師編號: ";
	cin >> teacherId;
	bool found = false;
	for (auto teacher : teachers) {
		if (teacher.getTeacherId() == teacherId) {
			teacher.display();
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "找不到教師編號為" << teacherId << "的教師" << endl;
	}
}

void queryRecord()
{
	int recordId;
	cout << "請輸入選課紀錄編號: ";
	cin >> recordId;
	bool found = false;
	for (auto record : records) {
		if (record.getRecordId() == recordId) {
			record.display();
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "找不到選課紀錄編號為:" << recordId << "的選課紀錄" << endl;
	}
}

void addStudent()
{
	string id, lastName, firstName, birthDate, gender, studentId;
	int departmentChoice, classNameChoice;

	cout << "身分證字號: ";
	cin >> id;
	cout << "姓: ";
	cin >> lastName;
	cout << "名: ";
	cin >> firstName;
	cout << "性別： ";
	cin >> gender;
	cout << "生日: ";
	cin >> birthDate;
	cout << "學號: ";
	cin >> studentId;

	cout << "科系: " << endl;
	for (int i = 0; i < static_cast<int>(Department::Last); i++) {
		cout << i << ". " << Utility::toString(static_cast<Department>(i)) << endl;
	}
	cout << "請選擇科系: ";
	cin >> departmentChoice;
	Department department = static_cast<Department>(departmentChoice);

	cout << "班級: " << endl;
	for (int i = 0; i < static_cast<int>(ClassName::Last); i++) {
		cout << i << ". " << Utility::toString(static_cast<ClassName>(i)) << endl;
	}
	cout << "請選擇班級: ";
	cin >> classNameChoice;
	ClassName className = static_cast<ClassName>(classNameChoice);

	students.push_back(Student(id, lastName, firstName, gender, birthDate, studentId, department, className));
}

void deleteStudent()
{
	string studentId;
	cout << "請輸入學號: ";
	cin >> studentId;
	bool found = false;
	for (auto it = students.begin(); it != students.end(); it++) {
		if (it->getStudentId() == studentId) {
			students.erase(it);
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "找不到學號為" << studentId << "的學生" << endl;
	}
}

void updateStudent()
{
	string studentId;
	cout << "請輸入學號: ";
	cin >> studentId;
	bool found = false;

	for (auto& student : students) {
		if (student.getStudentId() == studentId) {
			found = true;
			int departmentChoice, classNameChoice;

			cout << "科系: " << endl;
			for (int i = 0; i < static_cast<int>(Department::Last); i++) {
				cout << i << ". " << Utility::toString(static_cast<Department>(i)) << endl;
			}
			cout << "請選擇科系: ";
			cin >> departmentChoice;
			Department department = static_cast<Department>(departmentChoice);
			student.setDepartment(department);

			cout << "班級: " << endl;
			for (int i = 0; i < static_cast<int>(ClassName::Last); i++) {
				cout << i << ". " << Utility::toString(static_cast<ClassName>(i)) << endl;
			}
			cout << "請選擇班級: ";
			cin >> classNameChoice;
			ClassName className = static_cast<ClassName>(classNameChoice);
			student.setClassName(className);
		}
	}
	if (!found) {
		cout << "找不到學號為" << studentId << "的學生" << endl;
	}
}