# get_next_line – Read Your Files Line by Line in C

Welcome to my implementation of `get_next_line`, a common 42 project that focuses on reading text files line by line. This project gave me hands-on experience with file descriptors, dynamic memory management, and buffer handling in C.

## 🚀 Project Overview

The goal of this project was to create a function that reads one line at a time from a file descriptor, returning it as a string each time the function is called. Key features include:

- Reading files efficiently using a buffer of size `BUFFER_SIZE`.
- Returning lines including the newline character (`\n`).
- Handling multiple file descriptors at once (bonus part).
- Managing memory dynamically to prevent leaks and errors.

> **Note:** The bonus part supports simultaneous reading from multiple file descriptors without mixing data.

---

## 🧠 What I Learned

- How to use static variables to preserve buffer state between function calls  
- Careful dynamic memory allocation and string manipulation in C  
- Managing edge cases such as end-of-file and empty lines  
- The importance of clean, readable, and reusable code  
- Error handling and defensive programming in low-level file I/O  

---

## 📁 Project Structure
```
get_next_line/
├── get_next_line.c                # Main function logic
├── get_next_line_utils.c          # Helper functions for strings and memory
├── get_next_line_bonus.c          # Bonus version supporting multiple FDs
├── get_next_line_bonus_utils.c    # Bonus helpers
├── get_next_line.h                # Header file with prototypes and macros
├── Makefile                       # Build rules
```

---

## 🛠️ Functions Implemented

### ✅ Core Function

- **get_next_line(int fd)**: Reads the next line from the given file descriptor and returns it as a malloc’ed string, or NULL when EOF or error occurs.

### ✅ Utility Functions (in get_next_line_utils.c)

- **ft_strchr**: Finds a character in a string.  
- **ft_strdup**: Duplicates a string with dynamic memory.  
- **ft_strjoin**: Joins two strings into a new malloc’ed string.  
- **ft_substr**: Extracts a substring from a given string.  
- **ft_strlen**: Calculates string length.

### ✅ Bonus Features

- Supports multiple file descriptors by keeping a separate buffer for each FD.

---

## 🧪 How to Use

### 1. Clone the repository:
```bash
git clone https://github.com/your-username/get_next_line.git
cd get_next_line
```

### 2. Build the project:
```
make
```

### 3.use in your C project:
```
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

## 🧪 Test Your Implementation

You can test this implementation using [Francinette](https://github.com/xicodomingues/francinette), a popular automated testing tool designed for 42 libft projects.

## 🧾 License

This project is part of the 42 School curriculum. You’re welcome to use and learn from it, but do not copy it directly for your own submission.

---

## 👤 Author

**Hossein Khoshnevis**  
🧠 Software Developer | 📍 Based in the Netherlands  
[LinkedIn](https://www.linkedin.com/in/hossein-khoshnevis)  
[Portfolio](https://hosseinkhoshnevis.vercel.app/)  
[GitHub](https://github.com/hosseinkhoshnevis94)
