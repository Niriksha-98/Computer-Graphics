# Computer-Graphics (2017)

LIBRARY FILES: OpenGL files-glut32.h, glut.dll  
SOFTWARE USED: Microsoft Visual Studio 2015
 
**RSA Algorithm**

An encryption scheme has five major parts:
Plaintext - This is the text message to which an algorithm is applied.
Encryption Algorithm – It performs mathematical operations to conduct substitutions and transformations to the plaintext.
Secret Key - This is the input for the algorithm as the key dictates the encrypted outcome.
Cipher text -This is the encrypted or scrambled message produced by applying the algorithm to the plaintext message using the secret key.
Decryption Algorithm - This is the encryption algorithm in reverse. It uses the ciphertext, and the secret key to derive the plaintext message.


The Encryption Process: Sender A does the following: -
Obtains the recipient B's public key (n, e).
Represents the plaintext message as a positive integer mm with 1<m<n 
Computes the ciphertext c=me mod n.
Sends the ciphertext c to B.

                                                                     
The Decryption Process: Recipient B does the following: -
Uses his private key (n, d) to compute m=cd mod n.
Extracts the plaintext from the message representative m.

<img width="415" alt="image" src="https://user-images.githubusercontent.com/101902620/172510393-e89dbf31-b8cf-42dc-a3eb-7a56fc608283.png">

**Results**

![image](https://user-images.githubusercontent.com/101902620/172510137-016a428f-98b6-408e-a25d-63b831571d44.png)
![image](https://user-images.githubusercontent.com/101902620/172510149-3f10c582-d406-4ed9-a74e-b46b862afe4d.png)
![image](https://user-images.githubusercontent.com/101902620/172510186-9a3e0e78-b855-4208-becd-208f3f4cf4e5.png)
![image](https://user-images.githubusercontent.com/101902620/172510207-bf442572-d0c5-4da7-a61c-1e64148d9953.png)
