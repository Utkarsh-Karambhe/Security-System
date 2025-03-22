
# 🔒 Security System - C++ File-Based Authentication  

## 📌 Project Overview  
This **Security System** is a **C++ console-based authentication system** that allows users to:  
✅ **Register** with a username, password, and age.  
✅ **Login** using stored credentials.  
✅ **Change password** securely.  
✅ **Exit the program** when needed.  

All user credentials are stored securely in a **file (`file.txt`)**, making it persistent across sessions.  

---

## 🚀 Features  
- **User Registration:** Stores credentials in a file.  
- **User Login:** Validates username & password.  
- **Secure Password Change:** Ensures correct old password before updating.  
- **File Handling:** Uses `fstream` for reading/writing data.  
- **Error Handling:** Prevents incorrect logins and mismatched passwords.  

---

## 🛠️ Technologies Used  
- **C++ (Core Logic)**  
- **File Handling (`fstream`)** for data storage  
- **String Processing (`sstream`, `string`)** for handling user input  

---

## 📸 Program Flow  
```text
1️⃣ User selects an option: Register, Login, Change Password, or Exit.  
2️⃣ If registering, credentials are stored in `file.txt`.  
3️⃣ If logging in, credentials are validated against stored data.  
4️⃣ If changing the password, the system ensures authentication before updating.  
