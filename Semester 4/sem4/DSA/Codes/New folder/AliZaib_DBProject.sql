drop database attendance;
create database attendance;
use attendance;


CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(50) NOT NULL
);


CREATE TABLE Emp_Position (
    PositionID INT PRIMARY KEY,
    PositionName VARCHAR(50) NOT NULL
);


CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(100) NOT NULL,
    DepartmentID INT,
    PositionID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID),
    FOREIGN KEY (PositionID) REFERENCES Emp_Position(PositionID)
);


CREATE TABLE Shift (
    ShiftID INT PRIMARY KEY,
    ShiftName VARCHAR(50) NOT NULL,
    StartTime TIME NOT NULL,
    EndTime TIME NOT NULL
);


CREATE TABLE Holiday (
    HolidayID INT PRIMARY KEY,
    HolidayDate DATE NOT NULL,
    HolidayDescription VARCHAR(100) NOT NULL
);


CREATE TABLE Attendance (
    AttendanceID INT PRIMARY KEY,
    EmployeeID INT,
    ShiftID INT,
    AttendanceDate DATE NOT NULL,
    Status VARCHAR(20) NOT NULL CHECK (Status IN ('Present', 'Absent', 'Late')),
    FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID),
    FOREIGN KEY (ShiftID) REFERENCES Shift(ShiftID)
);


CREATE TABLE Emp_Leave (
    LeaveID INT PRIMARY KEY,
    EmployeeID INT,
    LeaveStartDate DATE NOT NULL,
    LeaveEndDate DATE NOT NULL,
    LeaveType VARCHAR(50) NOT NULL CHECK (LeaveType IN ('Vacation', 'Sick Leave', 'Maternity Leave')),
    FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID)
);


INSERT INTO Department (DepartmentID, DepartmentName) VALUES
(1, 'IT'),
(2, 'HR'),
(3, 'Finance'),
(4, 'Marketing'),
(5, 'Operations');


INSERT INTO Emp_Position (PositionID, PositionName) VALUES
(1, 'Software Developer'),
(2, 'HR Manager'),
(3, 'Accountant'),
(4, 'Marketing Specialist'),
(5, 'Operations Manager');


INSERT INTO Employee (EmployeeID, EmployeeName, DepartmentID, PositionID) VALUES
(1, 'Ali Khan', 1, 1),
(2, 'Sara Ahmed', 2, 2),
(3, 'Ahmed Hassan', 3, 3),
(4, 'Fatima Malik', 4, 4),
(5, 'Kamran Riaz', 5, 5),
(6, 'Ayesha Qureshi', 1, 1),
(7, 'Usman Ahmed', 2, 2),
(8, 'Nida Khan', 3, 3),
(9, 'Bilal Ahmed', 4, 4),
(10, 'Zainab Ali', 5, 5),
(11, 'Farhan Malik', 1, 1),
(12, 'Amna Riaz', 2, 2),
(13, 'Nabeel Ahmed', 3, 3),
(14, 'Sadia Khan', 4, 4),
(15, 'Omar Ali', 5, 5),
(16, 'Hina Ahmed', 1, 1),
(17, 'Shahbaz Khan', 2, 2),
(18, 'Saima Ahmed', 3, 3),
(19, 'Imran Malik', 4, 4),
(20, 'Aisha Riaz', 5, 5);


INSERT INTO Shift (ShiftID, ShiftName, StartTime, EndTime) VALUES
(1, 'Morning Shift', '08:00:00', '16:00:00'),
(2, 'Afternoon Shift', '12:00:00', '20:00:00'),
(3, 'Night Shift', '20:00:00', '04:00:00');


INSERT INTO Holiday (HolidayID, HolidayDate, HolidayDescription) VALUES
(1, '2024-01-01', 'New Year'),
(2, '2024-03-23', 'Pakistan Day'),
(3, '2024-05-01', 'Labor Day'),
(4, '2024-08-14', 'Independence Day'),
(5, '2024-12-25', 'Quaid-e-Azam Day');


INSERT INTO Attendance (AttendanceID, EmployeeID, ShiftID, AttendanceDate, Status) VALUES
(1, 1, 1, '2024-01-02', 'Present'),
(2, 2, 2, '2024-01-05', 'Absent'),
(3, 3, 3, '2024-01-08', 'Late'),
(4, 4, 1, '2024-01-12', 'Present'),
(5, 5, 2, '2024-01-15', 'Present'),
(6, 6, 3, '2024-01-18', 'Absent'),
(7, 7, 1, '2024-01-22', 'Present'),
(8, 8, 2, '2024-01-25', 'Absent'),
(9, 9, 3, '2024-01-28', 'Present'),
(10, 10, 1, '2024-01-31', 'Present');


INSERT INTO Emp_Leave (LeaveID, EmployeeID, LeaveStartDate, LeaveEndDate, LeaveType) VALUES
(1, 11, '2024-02-03', '2024-02-07', 'Vacation'),
(2, 12, '2024-02-10', '2024-02-12', 'Sick Leave'),
(3, 13, '2024-02-15', '2024-02-18', 'Maternity Leave'),
(4, 14, '2024-02-21', '2024-02-24', 'Vacation'),
(5, 15, '2024-02-27', '2024-03-01', 'Sick Leave'),
(6, 16, '2024-03-05', '2024-03-09', 'Vacation'),
(7, 17, '2024-03-12', '2024-03-15', 'Sick Leave'),
(8, 18, '2024-03-18', '2024-03-21', 'Maternity Leave'),
(9, 19, '2024-03-24', '2024-03-28', 'Vacation'),
(10, 20, '2024-03-31', '2024-04-02', 'Sick Leave');
