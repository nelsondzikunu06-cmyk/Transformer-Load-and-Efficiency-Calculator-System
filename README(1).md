*Overview*
This repository contains a C++ console application that records transformer information, accepts details of multiple connected loads, calculates the total connected load, estimates the transformer's loading percentage, classifies its load status, and saves a full report to a text file.

*Problem It Solves*
Electrical users often connect several loads to a transformer without calculating the total demand this places on it, making it difficult to know whether the transformer is underloaded, operating normally, near full capacity, or overloaded. This application solves that problem by giving a clear, calculated load status report.

*Features*
Accepts transformer details: name, rated capacity (kVA), primary voltage, secondary voltage, and power factor.
Validates all numeric input and rejects negative values.
Accepts multiple connected load types through a loop.
Calculates load power per load type, total connected load, apparent load, and loading percentage.
Classifies the transformer's load status (Lightly Loaded / Normal Operating Range / Near Full Load / Overloaded Transformer Warning).
Displays a full report on screen and saves it to transformer_report.txt.

*Required C++ Concepts Used*
Input/output, variables and data types, operators and expressions, conditional statements, loops, functions, classes and objects (Transformer and LoadItem), vectors, file handling, input validation, and comments.

*How to Compile and Run*
This project requires a standard C++11 (or later) compiler such as g++.

After running, the programme displays the transformer load report on screen and also saves it to transformer_report.txt in the same folder.

With that being said.... I'll leave the platform for Georgina Adiamah to take us through the Power Point Presentation