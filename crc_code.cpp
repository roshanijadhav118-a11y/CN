#include <iostream>
#include <string>
using namespace std;

string divide(string data, string key)
{
    int n = key.length();

    for (int i = 0; i <= data.length() - n; i++)
    {
        if (data[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                data[i + j] = (data[i + j] == key[j]) ? '0' : '1';
            }
        }
    }

    return data.substr(data.length() - n + 1);
}

int main()
{
    string data, key;

    cout << "Input dataframe: ";
    cin >> data;

    cout << "Input generator: ";
    cin >> key;

    int zeros = key.length() - 1;

    string appendedData = data + string(zeros, '0');

    string crc = divide(appendedData, key);

    string transmittedData = data + crc;

    cout << "\n Extra 0 bits have to add: " << zeros << endl;
    cout << "Data after adding Extra bits: " << appendedData << endl;
    cout << "CRC bits/Remainder: " << crc << endl;
    cout << "Transmitted data: " << transmittedData << endl;

    return 0;
}

// OUTPUT :--
// Input dataframe: 1110011100
// Input generator: 110011

//  Extra 0 bits have to add: 5
// Data after adding Extra bits: 111001110000000
// CRC bits/Remainder: 01100
// Transmitted data: 111001110001100