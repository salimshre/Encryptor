# 🔒 Encryptor++

🚀 **Encryptor++** is a high-performance encryption tool built in C++ that leverages the best cryptographic algorithms to secure your data. Designed for speed, security, and simplicity, this project ensures that your sensitive information remains protected.

---

## 📌 Features

✨ **Advanced encryption algorithms** (AES, RSA, etc.)\
⚡ **Fast and efficient** encryption & decryption\
💻 **User-friendly** command-line interface\
🔑 **Secure key management** system\
🌍 **Open-source & customizable**

---

## ⚙️ Algorithms Used

We employ state-of-the-art encryption techniques:

- 🔐 **AES (Advanced Encryption Standard)** - Symmetric encryption for secure data storage.
- 🔑 **RSA (Rivest-Shamir-Adleman)** - Asymmetric encryption for secure key exchange.
- 🏛️ **Caesar Cipher** - A simple encryption technique for demonstration.
- 🛡 **Custom Hashing** - Hash functions to validate data integrity.

---

# 📌How to Install GCC (MinGW) on Windows

🎥 **Video Reference:**  
[How to Install GCC](https://www.youtube.com/watch?v=GNzeSTZjziI&list=PLciC3-3T2N8b6upiQv9Js-158nqmAE3xg&index=14)

## 🛠️ Steps to Install GCC

1. **Download MinGW**  
   Visit [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/) and download the installer.

2. **Install MinGW**  
   Run the downloaded installer and follow the on-screen instructions.

3. **Install GCC Packages**  
   In the MinGW Installation Manager:
   - Select the package: `mingw32-gcc-g++` (GNU C++ compiler).
   - Go to **Installation → Apply Changes → Apply**.

4. **Set Environment Variables**  
   - Search for **Environment Variables** in the Windows search bar.
   - Click on **Edit the system environment variables**.
   - In the **System Properties** window, click **Environment Variables**.

5. **Edit System PATH**  
   - Under **System Variables**, select the `Path` variable and click **Edit**.
   - Click **New** and add this path:
     ```
     C:\MinGW\bin
     ```
   - Click **OK** to save changes.

6. **Verify GCC Installation**  
   Open Command Prompt and run:
   gcc -v



---


# 📌Setting Up Visual Studio Code for C and C++ Programming

This guide will walk you through setting up your environment for C and C++ development using Visual Studio Code.

---

## 📺 Video Tutorial

Watch the full tutorial on YouTube:  
[![Setup Guide](https://img.shields.io/badge/Watch%20Video-%F0%9F%93%BA-red)](https://www.youtube.com/watch?v=1PBD5qFWdq8)

---

## 🧰 Prerequisites

You need to install **MSYS2** to get the required C/C++ compilers.

### 🔽 Steps to Install MSYS2

1. Visit [https://www.msys2.org](https://www.msys2.org).
2. From the *Installation* section, click on `msys2-x86_64.exe` to download the installer.
3. Run the installer and complete the installation.
4. A black MSYS2 terminal will pop up — **do not close it**.
5. In the terminal, run the following command:

   ```bash
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
   ```

6. Press **Enter** to select defaults.
7. Type **y** to confirm installation and let the tools download and install.

---

## 🔧 Set Environment Variables

1. Search for **"Environment Variables"** in the Windows search bar.
2. Click **Edit the system environment variables**.
3. In the System Properties window, click **Environment Variables**.
4. Under **System Variables**, select the `Path` variable and click **Edit**.
5. Click **New**, then paste this path:

   ```
   C:\msys64\ucrt64\bin
   ```

6. Click **OK** to save and close all dialogs.

---

## ✅ Verify GCC Installation

To verify that everything is installed correctly:

1. Open **Command Prompt**.
2. Run the following command:

   ```bash
   gcc --version
   ```

You should see the GCC version info if everything is set up correctly.

---

## 📌How to setup graphics.h in VS Code | CodeWar
https://www.youtube.com/watch?app=desktop&v=J0_vt-7Ok6U&pp=ygUNI21lbnVncmFwaGljaA%3D%3D
ctr +shift+b => to select build task.
program to test
#include <graphics.h>

int main(int argc, char const *argv[]) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"hello");
    circle(320, 240, 200);
    getch();
    closegraph();
    return 0;
}

---

## 📝 command to run this algorithms
g++ main.cpp encryption.cpp -o run

---

## 📝 How It Works

1️⃣ Choose the encryption method.\
2️⃣ Input the text or file to be encrypted.\
3️⃣ Provide a secure key (if applicable).\
4️⃣ Get the encrypted output.\
5️⃣ Decrypt using the correct key.

---

## 📌 Example Usage

🔒 **Encrypt a message:**

```sh
Enter text to encrypt: Hello World
Choose algorithm (AES, RSA, Caesar): AES
Enter key: mysecurekey
Encrypted Output: Xk9sI3zB2...
```

🔓 **Decrypt a message:**

```sh
Enter encrypted text: Xk9sI3zB2...
Choose algorithm: AES
Enter key: mysecurekey
Decrypted Output: Hello World
```

---

## 🔗 Contributing

🙌 Contributions are welcome! Feel free to fork this repository, submit issues, or create pull requests to improve **Encryptor++**.

---

## 👨‍💻 Team Members
- **Aayush Kumar Mallik**
- **Sarswoti Rokaya**
- **Salim Shrestha**

---

## 📜 License

📄 This project is licensed under the **MIT License** - feel free to use and modify it as needed.

---

🌟 **Star this repo if you found it useful!** 🚀

