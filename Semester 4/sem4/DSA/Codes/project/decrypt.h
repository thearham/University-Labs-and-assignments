#pragma once
#include "Hill cipher.h"

class HillCipherDecryptor : public HillCipher {
public:
    HillCipherDecryptor(int key[], const LinkedList& dict) : HillCipher(key, dict) {}

    string decrypt(const string& ciphertext) {
        int blockSize = keyMatrix.rows;
        string decryptedText;

        Matrix keyInverse = keyMatrix.inverse();

        for (int i = 0; i < ciphertext.length(); i += blockSize) {
            string block = ciphertext.substr(i, blockSize);
            Matrix ciphertextMatrix(1, blockSize);

            
            for (int j = 0; j < blockSize; ++j) {
                ciphertextMatrix.data[0][j] = getValue(block[j]);
            }

            
            Matrix decryptedMatrix = ciphertextMatrix.multiply(keyInverse);
            decryptedMatrix = decryptedMatrix % 26;  

            
            for (int j = 0; j < blockSize; ++j) {
                decryptedText += dictionary.getValue(decryptedMatrix.data[0][j]);
            }
        }

        return decryptedText;
    }
};