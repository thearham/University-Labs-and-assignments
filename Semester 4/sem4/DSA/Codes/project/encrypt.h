#pragma once
#include "Hill cipher.h"



class HillCipherEncryptor : public HillCipher {
public:
    HillCipherEncryptor(int key[], const LinkedList& dict) : HillCipher(key, dict) {}

    string encrypt(const string& plaintext) {
        int blockSize = keyMatrix.rows;
        int padding = blockSize - (plaintext.length() % blockSize);

        
        string paddedText = plaintext;
        for (int i = 0; i < padding; ++i) {
            paddedText += 'X';
        }

        string ciphertext;
        for (int i = 0; i < paddedText.length(); i += blockSize) {
            string block = paddedText.substr(i, blockSize);
            Matrix plaintextMatrix(1, blockSize);

            
            for (int j = 0; j < blockSize; ++j) {
                plaintextMatrix.data[0][j] = getValue(block[j]);
            }
            /*for (int j = 0; j < blockSize; ++j) {
                int value = getValue(block[j]);
                if (value == -1) {
                    throw std::runtime_error("Invalid character in plaintext: " + std::string(1, block[j]));
                }
                plaintextMatrix.data[0][j] = value;
            }
            */
            Matrix encryptedMatrix = plaintextMatrix.multiply(keyMatrix);
            encryptedMatrix = encryptedMatrix % 26;  

            
            /*for (int j = 0; j < blockSize; ++j) {
                ciphertext += dictionary.getValue(encryptedMatrix.data[0][j]);
            }*/
            for (int j = 0; j < blockSize; ++j) {
                if (encryptedMatrix.data[0][j] < 0 || encryptedMatrix.data[0][j] >= dictionary.size()) {
                    throw std::runtime_error("Invalid value in encrypted matrix: " + std::to_string(encryptedMatrix.data[0][j]));
                }
                ciphertext += dictionary.getValue(encryptedMatrix.data[0][j]);
            }
        }

        return ciphertext;
    }
};
