# Nightmare-Cryptor
Nightmare-Cryptor is a malicious software designed to encrypt all files on a computer. 
This code is provided for educational purposes only and should not be used for illegal activities.

## How it Works
Nightmare-Cryptor uses the XOR operation to encrypt files. When executed, it searches for all files specified as command line arguments and encrypts 
each one using the "encrypt" function. The encrypted file will have a ".enc" extension added to its original file name. 
The original file is then deleted.If no command line arguments are given, the code will create a copy of itself in the Windows startup folder,
ensuring that it will be executed every time the computer starts up. This means that the virus will run in the
background and continue to encrypt files on the computer.

# Instructions
To run the Nightmare-Cryptor virus, you can compile the code using a C++ compiler, 
such as GCC or Visual Studio. The following command can be used to compile the code:-

```g++ -o Nightmare-Cryptor.exe Nightmare-Cryptor.cpp```

Once the code is compiled, you can execute it by running the resulting "Nightmare-Cryptor.exe" file. 
If you want to encrypt specific files, you can provide them as command line arguments when running the virus. For example:

``` Nightmare-Cryptor.exe file1.txt file2.docx ```

This will encrypt "file1.txt" and "file2.docx" and delete the original files.

## Disclaimer
The Nightmare-Cryptor code is provided for educational purposes only. 
The use of this code for malicious purposes is illegal and immoral. The author of this code, 0X1975, 
takes no responsibility for any damages caused by the use of this software. Use at your own risk.
