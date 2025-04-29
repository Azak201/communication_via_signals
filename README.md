📡 Minitalk – Interprocess Communication with Unix Signals in C

Built a lightweight client-server communication system in C, using Unix signals (SIGUSR1 and SIGUSR2) to transmit data bit by bit between processes. This project demonstrates low-level interprocess communication without using sockets or pipes.

🔧 Project Highlights:
• Implemented a server that receives characters encoded in binary via signals
• Developed a client that converts each character to binary and sends it to the server
• Handled signal synchronization, bit reconstruction, and message termination
• Explored signal queuing and process ID (PID) management
• Ensured stability and correctness even under rapid signal dispatch

🛠 Technologies & Skills:
• C programming
• Unix signals (SIGUSR1, SIGUSR2)
• Bitwise operations and binary data handling
• Interprocess communication (IPC)
• Signal safety and synchronization in Linux environments

This project deepened my understanding of how processes can communicate in a constrained, low-level system, and taught me how to think creatively with minimal tools.
