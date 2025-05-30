minitalk
Overview
minitalk is a simple client-server communication program developed in C. It enables the transmission of messages from a client to a server using UNIX signals (SIGUSR1 and SIGUSR2). This project is part of the 42cursus curriculum, focusing on inter-process communication and signal handling.
GitHub
+6
GitHub
+6
GitHub
+6
GitHub
+4
GitHub
+4
GitHub
+4

Features
Bidirectional communication between client and server processes.

Message encoding and decoding using UNIX signals.

Support for both standard ASCII and Unicode characters.

Acknowledgment mechanism to confirm message receipt.
GitHub
+5
GitHub
+5
GitHub
+5

Getting Started
Prerequisites
GCC compiler

Make utility

UNIX-based operating system
GitHub
+1
GitHub
+1

Installation
Clone the repository:

bash
Copy
Edit
git clone https://github.com/ALIELYOUSS/minitalk.git
cd minitalk
GitHub

Compile the server and client programs:

bash
Copy
Edit
make
GitHub
+6
GitHub
+6
GitHub
+6

This will generate two executables: server and client.

Usage
Starting the Server
In one terminal window, start the server:

bash
Copy
Edit
./server
GitHub
+3
GitHub
+3
GitHub
+3

The server will display its Process ID (PID), which you'll need to send messages from the client.
GitHub
+7
GitHub
+7
GitHub
+7

Sending a Message from the Client
In another terminal window, use the client to send a message to the server:

bash
Copy
Edit
./client [server_pid] "Your message here"
GitHub
+3
GitHub
+3
GitHub
+3

Replace [server_pid] with the PID displayed by the server.
GitHub
+5
GitHub
+5
GitHub
+5

Example
bash
Copy
Edit
./server
# Output: Server PID: 12345

./client 12345 "Hello, Server!"
The server will then display:

bash
Copy
Edit
Received message: Hello, Server!
Project Structure
client/ - Contains the client-side source code.

server/ - Contains the server-side source code.

utils/ - Utility functions used by both client and server.

minitalk.h - Header file with shared definitions and function prototypes.

Makefile - Facilitates compilation of the project.
GitHub
GitHub
+1
GitHub
+1
GitHub
+5
GitHub
+5
GitHub
+5minitalk
Overview
minitalk is a simple client-server communication program developed in C. It enables the transmission of messages from a client to a server using UNIX signals (SIGUSR1 and SIGUSR2). This project is part of the 42cursus curriculum, focusing on inter-process communication and signal handling.
GitHub
+6
GitHub
+6
GitHub
+6
GitHub
+4
GitHub
+4
GitHub
+4

Features
Bidirectional communication between client and server processes.

Message encoding and decoding using UNIX signals.

Support for both standard ASCII and Unicode characters.

Acknowledgment mechanism to confirm message receipt.
GitHub
+5
GitHub
+5
GitHub
+5

Getting Started
Prerequisites
GCC compiler

Make utility

UNIX-based operating system
GitHub
+1
GitHub
+1

Installation
Clone the repository:

bash
Copy
Edit
git clone https://github.com/ALIELYOUSS/minitalk.git
cd minitalk
GitHub

Compile the server and client programs:

bash
Copy
Edit
make
GitHub
+6
GitHub
+6
GitHub
+6

This will generate two executables: server and client.

Usage
Starting the Server
In one terminal window, start the server:

bash
Copy
Edit
./server
GitHub
+3
GitHub
+3
GitHub
+3

The server will display its Process ID (PID), which you'll need to send messages from the client.
GitHub
+7
GitHub
+7
GitHub
+7

Sending a Message from the Client
In another terminal window, use the client to send a message to the server:

bash
Copy
Edit
./client [server_pid] "Your message here"
GitHub
+3
GitHub
+3
GitHub
+3

Replace [server_pid] with the PID displayed by the server.
GitHub
+5
GitHub
+5
GitHub
+5

Example
bash
Copy
Edit
./server
# Output: Server PID: 12345

./client 12345 "Hello, Server!"
The server will then display:

bash
Copy
Edit
Received message: Hello, Server!
Project Structure
client/ - Contains the client-side source code.

server/ - Contains the server-side source code.

utils/ - Utility functions used by both client and server.

minitalk.h - Header file with shared definitions and function prototypes.

Makefile - Facilitates compilation of the project.
GitHub
GitHub
+1
GitHub
+1
GitHub
+5
GitHub
+5
GitHub
+5

Bonus Features
Support for Unicode characters in messages.

Acknowledgment signals sent from the server to the client upon successful receipt of each character.

Bonus Features
Support for Unicode characters in messages.

Acknowledgment signals sent from the server to the client upon successful receipt of each character.
