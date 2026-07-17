# Transformer Load and Efficiency Calculator System

**Course:** BEE 208 — C++ Programming
**Institution:** Accra Technical University, Faculty of Engineering, Department of Electrical/Electronic Engineering
**Project:** Mid-Semester Practical Project Examination — Project Question 13

## Overview

This repository contains a C++ console application that records transformer
information, accepts details of multiple connected loads, calculates the
total connected load, estimates the transformer's loading percentage,
classifies its load status, and saves a full report to a text file.

## Problem It Solves

Electrical users often connect several loads to a transformer without
calculating the total demand this places on it, making it difficult to know
whether the transformer is underloaded, operating normally, near full
capacity, or overloaded. This application solves that problem by giving a
clear, calculated load status report.

## Features

- Accepts transformer details: name, rated capacity (kVA), primary voltage,
  secondary voltage, and power factor.
- Validates all numeric input and rejects negative values.
- Accepts multiple connected load types through a loop.
- Calculates load power per load type, total connected load, apparent load,
  and loading percentage.
- Classifies the transformer's load status (Lightly Loaded / Normal
  Operating Range / Near Full Load / Overloaded Transformer Warning).
- Displays a full report on screen and saves it to `transformer_report.txt`.

## Repository Structure

```
BEE208-Transformer-Load-and-Efficiency-Calculator
|
|-- README.md                  This file
|-- main.cpp                   Main C++ source code
|-- algorithm.md                Step-by-step algorithm
|-- pseudocode.md               Pseudocode for the system
|-- flowchart.png               Flowchart of the application logic
|-- report.md                   Full project report
|-- sample-output.png           Screenshot of a sample run (to be added)
|-- test-data.md                Test cases used to verify the programme
|-- transformer_report.txt      Example generated report
|-- group-contribution.md       Group member roles and contributions
`-- screenshots/
    |-- input-screen.png
    |-- output-screen.png
    `-- file-output.png
```

## Required C++ Concepts Used

Input/output, variables and data types, operators and expressions,
conditional statements, loops, functions, classes and objects (`Transformer`
and `LoadItem`), vectors, file handling, input validation, and comments.

## How to Compile and Run

This project requires a standard C++11 (or later) compiler such as `g++`.

```bash
g++ -std=c++11 main.cpp -o transformer_calculator
./transformer_calculator
```

On Windows (using a compiler such as MinGW):

```bash
g++ -std=c++11 main.cpp -o transformer_calculator.exe
transformer_calculator.exe
```

After running, the programme displays the transformer load report on screen
and also saves it to `transformer_report.txt` in the same folder.

## Sample Run

```
TRANSFORMER LOAD AND EFFICIENCY CALCULATOR SYSTEM

Enter transformer name: Lab Transformer 1
Enter transformer rating in kVA: 10
Enter primary voltage: 11000
Enter secondary voltage: 415
Enter power factor (0 to 1): 0.85

Enter number of load types: 3

--- Load Type 1 ---
Enter load name: Lighting Circuit
Enter power rating in watts: 60
Enter quantity: 20
Load Power: 1200.00 W

--- Load Type 2 ---
Enter load name: Socket Outlet Load
Enter power rating in watts: 500
Enter quantity: 4
Load Power: 2000.00 W

--- Load Type 3 ---
Enter load name: Motor Load
Enter power rating in watts: 1500
Enter quantity: 2
Load Power: 3000.00 W

==================================================
            TRANSFORMER LOAD REPORT
==================================================
Transformer Name        : Lab Transformer 1
Transformer Rating      : 10.00 kVA
Primary Voltage         : 11000.00 V
Secondary Voltage       : 415.00 V
Power Factor            : 0.85
--------------------------------------------------
Total Connected Load    : 6200.00 W
Estimated Apparent Load : 7.29 kVA
Loading Percentage      : 72.94 %
Load Status             : Normal Operating Range
==================================================

Report saved to transformer_report.txt
```

## Group Members

*(To be completed by the group.)*
| Student Name | Index Number | Role / Contribution |
|---|---|---|
|1.Osabutey Sampson |01240209B | Project lead |
|2.Benjamin Nii Baah Amoo |01243483B | Algorithm writer |
|3.Oteng Desmond |01243197B | Pseudocode writer |
|4.Gbeki Edem Kwame Gator |01240881B | Flowchart designer |
|5.Osabutey Sampson |01240209B | C++ programmer |
|6.Dzorgadzor Raphael |01243502B | C++ programmer |
|7.Owusu Philip Aboagye |01246180B | Testing lead |
|8.Dzikunu Nelson |01242089B | GitHub manager |
|9.Mitchel Asante |012460289B | Documentation lead |
|10.Georgina Adiamah |01244722B | Presentation lead |
## License


This project was developed for academic purposes as part of the BEE 208
course at Accra Technical University.
