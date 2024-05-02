CREATE DATABASE BANK;
USE BANK;

-- Table for Bank Branch
CREATE TABLE BankBranch (
    BranchID INT PRIMARY KEY,
    BranchName VARCHAR(255),
    BranchCity VARCHAR(255),
    BranchCountry VARCHAR(255),
    BranchPhone VARCHAR(20),
    ManagerID INT
);

-- Table for Employees
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(255),
    EmployeeAddress VARCHAR(255),
    EmployeePhone VARCHAR(20),
    EmployeeEmail VARCHAR(255),
    BranchID INT,
    DepartmentID INT,
    FOREIGN KEY (BranchID) REFERENCES BankBranch(BranchID)
);

-- Table for Department
CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(255),
    HeadOfDepartment INT,
    Designation VARCHAR(255)
);

-- Table for Customers
CREATE TABLE Customer (
    CustomerID INT PRIMARY KEY,
    CustomerName VARCHAR(255),
    CustomerAddress VARCHAR(255),
    CustomerPhone VARCHAR(20),
    CustomerEmail VARCHAR(255),
    BranchID INT,
    AccountNumber INT,
    FOREIGN KEY (BranchID) REFERENCES BankBranch(BranchID)
);

-- Table for Accounts
CREATE TABLE Account (
    AccountNumber INT PRIMARY KEY,
    BranchID INT,
    CustomerID INT,
    AccountType VARCHAR(50),
    Balance DECIMAL(15, 2),
    InterestRate DECIMAL(5, 2),
    AccountStatus VARCHAR(20),
    FOREIGN KEY (BranchID) REFERENCES BankBranch(BranchID),
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID)
);

-- Table for Loans
CREATE TABLE Loan (
    LoanID INT PRIMARY KEY,
    AccountNumber INT,
    InterestRate DECIMAL(5, 2),
    Duration INT,
    StartDate DATE,
    DueAmount DECIMAL(15, 2),
    FOREIGN KEY (AccountNumber) REFERENCES Account(AccountNumber)
);

-- Table for Transactions
CREATE TABLE Transaction (
    TransactionID INT PRIMARY KEY,
    AccountNumber INT,
    DateTime TIMESTAMP,
    EmployeeID INT,
    CreditDeposit DECIMAL(15, 2),
    LoanID INT,
    TransactionType VARCHAR(50),
    FOREIGN KEY (AccountNumber) REFERENCES Account(AccountNumber),
    FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID),
    FOREIGN KEY (LoanID) REFERENCES Loan(LoanID)
);

-- Inserting data into BankBranch table
INSERT INTO BankBranch (BranchID, BranchName, BranchCity, BranchCountry, BranchPhone, ManagerID)
VALUES (1, 'Main Branch', 'New York', 'USA', '123-456-7890', 101),
       (2, 'Downtown Branch', 'Los Angeles', 'USA', '987-654-3210', 102),
       (3, 'Uptown Branch', 'Chicago', 'USA', '333-333-3333', 103),
       (4, 'Suburb Branch', 'Houston', 'USA', '444-444-4444', 104);
-- Inserting data into Department table
INSERT INTO Department (DepartmentID, DepartmentName, HeadOfDepartment, Designation)
VALUES (201, 'Finance', 101, 'Manager'),
       (202, 'Customer Service', 102, 'Manager'),
       (203, 'Marketing', NULL, NULL);

-- Inserting data into Employee table
INSERT INTO Employee (EmployeeID, EmployeeName, EmployeeAddress, EmployeePhone, EmployeeEmail, BranchID, DepartmentID)
VALUES (101, 'John Doe', '123 Main St, New York', '555-1234', 'john.doe@example.com', 1, 201),
       (102, 'Jane Smith', '456 Elm St, Los Angeles', '555-5678', 'jane.smith@example.com', 2, 202),
       (103, 'David Johnson', '789 Oak St, Chicago', '555-9012', 'david.johnson@example.com', 3, 201),
       (104, 'Emily Brown', '321 Pine St, Houston', '555-3456', 'emily.brown@example.com', 4, 202);

-- Inserting data into Customer table
INSERT INTO Customer (CustomerID, CustomerName, CustomerAddress, CustomerPhone, CustomerEmail, BranchID, AccountNumber)
VALUES (1001, 'Alice Johnson', '789 Oak St, New York', '555-1111', 'alice.johnson@example.com', 1, 10001),
       (1002, 'Bob Williams', '321 Pine St, Los Angeles', '555-2222', 'bob.williams@example.com', 2, 10002),
       (1003, 'Eva Martinez', '555 Maple St, Chicago', '555-3333', 'eva.martinez@example.com', 3, 10003),
       (1004, 'Michael Brown', '777 Cedar St, Houston', '555-4444', 'michael.brown@example.com', 4, 10004);

-- Inserting data into Account table
INSERT INTO Account (AccountNumber, BranchID, CustomerID, AccountType, Balance, InterestRate, AccountStatus)
VALUES (10001, 1, 1001, 'Savings', 5000.00, 0.5, 'Active'),
       (10002, 2, 1002, 'Checking', 2500.00, 0.2, 'Active'),
       (10003, 3, 1003, 'Savings', 8000.00, 0.6, 'Active'),
       (10004, 4, 1004, 'Checking', 4000.00, 0.3, 'Active');

-- Inserting data into Loan table
INSERT INTO Loan (LoanID, AccountNumber, InterestRate, Duration, StartDate, DueAmount)
VALUES (1, 10001, 0.8, 12, '2023-01-15', 12000.00),
       (2, 10002, 1.2, 6, '2023-03-20', 6000.00);

-- Inserting data into Transactions table
INSERT INTO Transaction (TransactionID, AccountNumber, DateTime, EmployeeID, CreditDeposit, LoanID, TransactionType)
VALUES (1, 10001, '2024-04-28 10:30:00', 101, 500.00, NULL, 'Deposit'),
       (2, 10003, '2024-04-28 11:45:00', 102, -200.00, NULL, 'Withdrawal');

CREATE VIEW AccountDetailsview AS
SELECT a.AccountNumber, a.AccountType, a.Balance, a.AccountStatus,
       c.CustomerName, c.CustomerAddress, c.CustomerPhone, c.CustomerEmail,
       b.BranchName, b.BranchCity, b.BranchCountry
FROM Account a
JOIN Customer c ON a.CustomerID = c.CustomerID
JOIN BankBranch b ON a.BranchID = b.BranchID;

CREATE VIEW EmployeeDetailsview AS
SELECT e.EmployeeID, e.EmployeeName, e.EmployeeAddress, e.EmployeePhone, e.EmployeeEmail,
       b.BranchName, b.BranchCity, b.BranchCountry
FROM Employee e
JOIN BankBranch b ON e.BranchID = b.BranchID;

CREATE VIEW TransactionDetailsview AS
SELECT t.TransactionID, t.DateTime, c.CustomerName, c.CustomerAddress, c.CustomerPhone, c.CustomerEmail,
       t.CreditDeposit, t.TransactionType
FROM Transaction t
JOIN Customer c ON t.AccountNumber = c.AccountNumber;

select * from TransactionDetailsview;+
