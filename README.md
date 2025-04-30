⚖️ Crime Justice Management System (C++ with OOP & JSON)
A comprehensive criminal justice management system implemented in C++ using Object-Oriented Programming (OOP) principles and JSON for structured data storage and retrieval.

📁 Project Structure
The system models and manages key entities in a criminal justice ecosystem, including:

Civilian, Victim, Prisoner, Criminal

Police Officer, Judge, Lawyer

Court, Police Station, Forensic Laboratory

Case, Punishment, Visitor

Each entity is encapsulated with its own .cpp and .h files following OOP principles. JSON files are used to manage dynamic data such as user records, criminal data, and case files.

🚀 Features
✅ Add, view, and manage civilians, criminals, prisoners, police, and judicial staff.

📂 Case registration, evidence logging, and case resolution.

📑 Integration of visitor logs and prison records.

🧪 Forensic laboratory data handling.

🔒 Separation of concerns using classes and inheritance.

📄 Persistent storage using JSON files (e.g., criminals.json, cases.json, prisoners.json, etc.)

💡 OOP Concepts Used
Encapsulation – Class headers and implementation files separate data from functionality.

Inheritance – Shared attributes via base classes like Person.

Polymorphism – Function overloading and overriding in judicial processes.

Abstraction – Complex operations (e.g., case handling) are abstracted in well-structured classes.

🧾 JSON Integration
Uses JSON files to:

Store persistent data

Load dynamic input at runtime

Export updated entity records (e.g., prisoners, police officers, cases)

JSON examples:

criminals.json

cases.json

police_officers.json

visitor_records.json

🔧 Requirements
C++ compiler (e.g., g++, clang++)

CMake or Makefile for build automation

nlohmann/json library for JSON handling

⚙️ Build Instructions
Using make
bash
Copy
Edit
make
./main
Or manually (if Makefile not used)
bash
Copy
Edit
g++ -std=c++17 main.cpp function.cpp case.cpp ... -o crime_management
./crime_management
📦 Files and Directories

File / Directory	Description
main.cpp	Entry point of the system
case.cpp, case.h	Handles case registration and management
criminal.cpp, criminal.h	Criminal-related operations
civilian.cpp, civilian.h	Civilian and victim data handling
police_station.cpp	Handles police data
visitor.cpp	Visitor and prisoner meeting records
*.json	JSON data files for persistent recordkeeping
forensic_laboratory.*	Forensic analysis and data logging
🧠 Future Improvements
🧑‍⚖️ Role-based access (Admin, Police, Visitor)

🗃️ GUI interface using Qt or ImGui

🗃️ Encryption for sensitive JSON data

🌐 Web-based version using C++ backend with REST API

📄 License
This project is for academic purposes and free to use under the MIT License.
