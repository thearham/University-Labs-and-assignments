#include "Hill cipher.h"
#include "encrypt.h"
#include "decrypt.h"
void toUpperCase(string& str) {
	for (size_t i = 0; i < str.length(); ++i) {

		if (str[i] >= 'a' && str[i] <= 'z') {

			str[i] = str[i] - ('a' - 'A');
		}
	}
}

int main() {
    LinkedList map;
    int asciiA = 65;
    for (int i = 1; i <= 26; i++) {
        map.insert(char(asciiA), i);
        asciiA++;
    }

     int key[4] = { 1, 0, 6, 1 };

    
    HillCipherEncryptor encryptor(key, map);

  
    HillCipherDecryptor decryptor(key, map);

    int choice;
    do {
        cout << "-----------* Hill 2-Cipher Program *------------\n\n";
        cout << "Press 1 to Encrypt text" << endl;
        cout << "Press 2 to Decrypt text" << endl;
        cout << "Press -1 to Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            cin.ignore();
            string input;
            cout << "Enter text: ";
            getline(cin, input);
            cout << "Encrypted text: " << encryptor.encrypt(input) << "\n";
            break;
        }

        case 2: {
            cin.ignore();
            string ciphertext;
            cout << "Enter ciphertext: ";
            getline(cin, ciphertext);
            cout << "Decrypted text: " << decryptor.decrypt(ciphertext) << "\n";
            break;
        }
        }

    } while (choice != -1);

    return 0;
}