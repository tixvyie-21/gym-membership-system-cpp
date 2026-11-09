
# Gym Management System

A console-based Gym Management System developed using C++ and File Handling.

## About the Project

This project helps gym administrators manage member registrations,
membership plans, payments and gym records through a simple
console-based interface.

Member information and payment records are stored in text files,
so the data remains available even after the application closes.

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- STL Vector
- Searching and Data Management

## Features

1. Register new gym members.
2. View all registered members.
3. Search members by ID, name or phone.
4. Update member information.
5. Delete member records.
6. Manage membership plans.
7. Record membership payments.
8. View individual payment history.
9. Generate gym reports.
10. Store records permanently using text files.

## Membership Plans

| Plan | Fee |
|---|---:|
| Monthly | Rs. 1,000 |
| Quarterly | Rs. 2,700 |
| Half Yearly | Rs. 5,000 |
| Yearly | Rs. 9,000 |

## Project Structure

```text
Gym-Management-System/
│
├── main.cpp
├── README.md
├── .gitignore
└── data/
    ├── members.txt
    └── payments.txt
```

The data files are generated automatically when
the application starts.

## Requirements

- C++ compiler supporting C++17
- GCC / MinGW or another compatible compiler
- Windows, Linux or macOS

## How to Run

### Step 1: Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
```

### Step 2: Open the Project Folder

```bash
cd Gym-Management-System
```

### Step 3: Compile

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o gym
```

### Step 4: Run

Windows:

```bash
gym.exe
```

Linux / macOS:

```bash
./gym
```

## Data Storage

The project uses two text files:

- members.txt: Stores member details and payment totals.
- payments.txt: Stores individual payment transactions.

Records are separated using the pipe (|) character.

## Concepts Demonstrated

- Classes and Objects
- Encapsulation
- Vectors
- Functions
- File Input and Output
- Searching
- Updating and Deleting Records
- Input Validation

## Future Improvements

- Membership expiry date tracking.
- Trainer management.
- Attendance tracking.
- Monthly revenue reports.
- Admin login system.
- Database integration.

## Author

CSE Student

## License

This project is available for educational and learning purposes.
