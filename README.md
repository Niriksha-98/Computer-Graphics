# Computer-Graphics (2017)
Implemented a simulation of the RSA algorithm as part of my undergraduate coursework.

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


