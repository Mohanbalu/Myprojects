# Mobile Phone Memory Management System

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Getting Started](#getting-started)
   1. [Clone the Repository](#1-clone-the-repository)
   2. [Compile and Run](#2-compile-and-run)
   3. [Interact with the System](#3-interact-with-the-system)
4. [Usage](#usage)
   1. [Allocating System Memory](#1-allocating-system-memory)
   2. [Installing Apps](#2-installing-apps)
   3. [Viewing Memory Usage](#3-viewing-memory-usage)
   4. [Displaying Unique Data](#4-displaying-unique-data)
5. [Classes](#classes)
   1. [`Phone`](#1-phone)
   2. [`Oppo`, `Samsung`, `Apple`](#2-oppo-samsung-apple)
6. [Example Usage](#example-usage)
7. [Contributing](#contributing)
   1. [Getting Started](#getting-started-1)
   2. [Making Changes](#making-changes)
   3. [Submitting a Pull Request](#submitting-a-pull-request)
   4. [Code Style Guidelines](#code-style-guidelines)
   5. [Reporting Issues](#reporting-issues)
8. [License](#license)

## Introduction

Welcome to the Mobile Phone Memory Management System! This C++ project aims to provide a comprehensive solution for simulating and managing memory allocation on different mobile phone models. In the fast-evolving world of smartphones, efficient memory management is crucial for optimal performance and user experience. This system allows users to dynamically allocate and manage RAM and ROM, install applications with specified memory requirements, and monitor overall memory usage.

## Features

- **Dynamic Memory Allocation:** Allocate and manage RAM and ROM dynamically for each smartphone model.
- **Company-Specific Models:** Utilize derived classes to encapsulate company-specific details and behaviors for phones from different manufacturers.
- **App Installation and Memory Consumption:** Install apps with specified memory requirements, ensuring proper validation to maintain optimal performance.
- **Memory Usage Statistics:** Obtain detailed statistics on total, used, and free RAM and ROM, enabling users to monitor resource utilization effectively.
- **User Input Validation:** Ensure accurate and valid user inputs for memory allocation and app installation, preventing issues related to insufficient memory.

## Getting Started
To get started with the Mobile Phone Memory Management System, follow these simple steps to set up and run the project on your local machine.

### 1. Clone the Repository
First, clone this repository to your local machine using the following command in your terminal or command prompt:
```
git clone https://github.com/your-username/mobile-phone-memory.git
```
### 2. Compile and Run
Navigate to the project directory and compile the C++ code using a C++ compiler (e.g., g++):
```
cd mobile-phone-memoryg++ mobile_phone_memory.cpp -o mobile_phone_memory
```
Run the compiled executable:
```
./mobile_phone_memory
```
### 3. Interact with the System
Follow the on-screen instructions to allocate system memory, install apps, view memory usage, and display unique data for each phone model. The program will guide you through the steps, and you can explore various features of the Mobile Phone Memory Management System.

## Usage
Explore the functionalities of the Mobile Phone Memory Management System by following the steps outlined below.

### 1. Allocating System Memory
Upon running the program, choose the option to allocate system memory. Enter the specified RAM and ROM values for the chosen phone model. This step initializes the memory for the selected mobile phone.

### 2. Installing Apps
To simulate app installations, choose the option to install apps. Provide the app details, including the app name, RAM percentage, and ROM percentage. The system will check for available memory before installing the app. Explore the app installation process by adding multiple apps.

### 3. Viewing Memory Usage
Check the detailed memory usage statistics by selecting the option to view memory usage. This will display information such as total, used, and free RAM and ROM for the chosen phone model. Monitor how the memory changes as you install apps.

### 4. Displaying Unique Data
Each phone model has unique data associated with it. Explore this feature by selecting the option to display unique data. This will showcase specific information related to the manufacturer and model of the mobile phone.
## Classes
The Mobile Phone Memory Management System utilizes a set of classes to model different aspects of mobile phones, their memory management, and specific details for each manufacturer. Here are the key classes involved:

### 1. Phone
The Phone class serves as the base class representing a generic smartphone. It provides essential functionalities for allocating system memory, installing apps, displaying memory usage, and more.

### 2. Oppo, Samsung, Apple
Derived classes, namely Oppo, Samsung, and Apple, represent smartphones from specific manufacturers. Each of these classes extends the base Phone class and encapsulates unique data and behaviors specific to the corresponding manufacturer. These classes override the displayUniqueData function to showcase manufacturer-specific details.

Feel free to explore the class implementations within the code (mobile_phone_memory.cpp) for a more detailed understanding of their attributes and methods. You can also extend these classes or add new ones to model smartphones from additional manufacturers.

## Example Usage

### Oppo Phone Model

```cpp
#include <iostream>

int main() {
    // Example usage for an Oppo phone
    Oppo oppoModel(8, 128, "Model X", "Unique data for Model X");
    oppoModel.allocateSystemMemory(2, 20);
    oppoModel.installApp("Instagram", 10, 5);
    oppoModel.installApp("WhatsApp", 15, 7);

    std::cout << "Oppo Model X:" << std::endl;
    oppoModel.displayMemoryUsage();
    oppoModel.displayAppConsumption();
    oppoModel.displayUniqueData();

    return 0;
}
```
## Contributing
Thank you for considering contributing to the Mobile Phone Memory Management System! Contributions play a significant role in enhancing and expanding the capabilities of the project. Before contributing, please take a moment to review the guidelines below.

### Getting Started
1. Fork the Repository: Click on the "Fork" button at the top right of this repository's page to create your copy.
2. Clone your Fork: Clone the forked repository to your local machine:
```
git clone https://github.com/your-username/mobile-phone-memory.git
cd mobile-phone-memory
```
### Making Changes
Create a Branch: Create a new branch for your feature or bug fix:
```
git checkout -b feature/new-feature
```
### Implement Changes: Make the necessary changes to the code. Ensure your modifications adhere to the project's coding standards.

### Test Your Changes: Verify that your changes work as intended. Include appropriate tests if applicable.
### Submitting a Pull Request
1. Navigate to the "Pull Requests" tab on the original repository.
2. Click on "New Pull Request."
3. Select the Branch: Choose the branch containing your changes.
4. Provide Details: Give your pull request a descriptive title and summary. Include relevant information about the changes you made.
5. Submit the Pull Request.

### Code Style Guidelines
Follow the code style guidelines outlined in the project. Consistent coding styles enhance code readability and maintainability.

### Reporting Issues
If you encounter any issues or have suggestions, please open an issue on the GitHub repository. Provide detailed information about the problem, steps to reproduce it, and any relevant context.

Your contributions are highly valued, and your effort makes the Mobile Phone Memory Management System better for everyone. Thank you for your support!

## License
The Mobile Phone Memory Management System is licensed under the MIT License.

The MIT License is a permissive open-source license that allows for the free use, modification, and distribution of the software.

Feel free to customize this section based on your project's specific licensing needs. If you have questions or concerns regarding the license, please reach out for clarification.
