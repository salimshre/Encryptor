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

## 🛠️ Installation & Usage

### 🔽 Clone the Repository

```sh
 git clone https://github.com/yourusername/Encryptor-CPP.git
 cd Encryptor-CPP
```

### 🏗️ Compile the Program

```sh
g++ encryptor.cpp -o encryptor
```

### ▶️ Run the Program

```sh
./encryptor
```
### ▶️ Run the Program from command prompt
install gcc from this websites


# How to Install GCC (MinGW) on Windows

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
- **Sarswoti**
- **Salim Shrestha**

---

## 📜 License

📄 This project is licensed under the **MIT License** - feel free to use and modify it as needed.

---

🌟 **Star this repo if you found it useful!** 🚀

