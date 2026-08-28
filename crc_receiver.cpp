#include <iostream>
#include <string>
using namespace std;

// Function to perform Modulo-2 division
string mod2Division(string codeword, string generator)
{
    int codewordLength = codeword.length();
    int generatorLength = generator.length();

    // Perform XOR division
    for (int i = 0; i <= codewordLength - generatorLength; i++)
    {
        if (codeword[i] == '1')
        {
            for (int j = 0; j < generatorLength; j++)
            {
                codeword[i + j] =
                    (codeword[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Return remainder
    return codeword.substr(
        codewordLength - generatorLength + 1
    );
}

int main()
{
    string codeword, generator;

    cout << "========== RECEIVER SIDE ==========\n";

    // Input received codeword
    cout << "Enter Received Codeword: ";
    cin >> codeword;

    // Input CRC generator
    cout << "Enter CRC Generator: ";
    cin >> generator;

    // Perform Modulo-2 division
    string remainder = mod2Division(codeword, generator);

    // Display remainder
    cout << "\nReceived Codeword: " << codeword << endl;
    cout << "CRC Generator:    " << generator << endl;
    cout << "Remainder:        " << remainder << endl;

    // Check for error
    bool error = false;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    cout << "-----------------------------------\n";

    if (error)
    {
        cout << "Final Result: ERROR DETECTED!" << endl;
    }
    else
    {
        cout << "Final Result: NO ERROR DETECTED." << endl;
    }

    cout << "-----------------------------------\n";

    return 0;
}


// OUTPUT :--

// ========== RECEIVER SIDE ==========
// Enter Received Codeword: 1110011100110
// Enter CRC Generator: 1010

// Received Codeword: 1110011100110
// CRC Generator:    1010
// Remainder:        000
// -----------------------------------
// Final Result: NO ERROR DETECTED.
// -----------------------------------


// ========== RECEIVER SIDE ==========
// Enter Received Codeword: 111001110001100
// Enter CRC Generator: 11011

// Received Codeword: 111001110001100
// CRC Generator:    11011
// Remainder:        0101
// -----------------------------------
// Final Result: ERROR DETECTED!
// -----------------------------------