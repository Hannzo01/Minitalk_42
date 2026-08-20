# 🗣️ minitalk

> A data communication program in C passing strings between a client and a server using UNIX signals.

## 💡 About the Project

This project is part of the 1337 / 42 Network curriculum. The objective is to code a small data exchange program using a client-server architecture. 

The catch? The client and server can only communicate using two UNIX signals: `SIGUSR1` and `SIGUSR2`. To send a string of text, every single character must be broken down into its binary representation (0s and 1s) and transmitted bit by bit across processes.

## 🧠 Concepts Mastered

This project is a deep dive into how operating systems manage processes and how data is structured at the lowest levels.

*   **UNIX Signals:** Mastered the use of `signal()` and `sigaction()` to intercept and handle system signals gracefully without crashing the program.
*   **Bitwise Operations:** Learned how to use bit shifting (`>>`, `<<`) and bit masking (`&`, `|`) to convert characters (like 'A') into an 8-bit binary sequence (01000001) for transmission, and then rebuild them on the receiving end.
*   **Process IDs (PID):** Understood how to fetch and utilize PIDs to ensure signals are sent to the exact correct running process.
*   **Global Variables (Strict Usage):** Learned how to safely use a single global variable to track signal states during asynchronous interruptions, strictly following the 42 Norm.

## 📚 Resources I Used

If you are a fellow student working on this project, here are the resources that helped me understand bitwise operations and signal handling:

*   [Linux Programmer's Manual: sigaction(2)](https://man7.org/linux/man-pages/man2/sigaction.2.html)
*   [YouTube: Bitwise Operators in C (Jacob Sorber)](https://www.youtube.com/watch?v=jlQmeyce65Q)
*   [YouTube: Handling Signals in C (Jacob Sorber)](https://www.youtube.com/watch?v=83M5-NPDeWs)
*   [GeeksforGeeks: Bitwise Operators in C/C++](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
*   [GeeksforGeeks: Signals in C Language](https://www.geeksforgeeks.org/signals-c-language/)
