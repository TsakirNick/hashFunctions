#include <iostream>

//Function to sum the probe values
int sumProbes(int table[50][2])
{
	int sum = 0;
	for (int i = 0; i < 50; i++)
	{
		sum += table[i][1];
	}

	return sum;
}

//Hash function 1: Division method with linear probing
void HF1(int(&table)[50][2], int tableSize, int* keyValues)
{
	int hashValue = 0;
	int probeValue = 0;
	for (int i = 0; i < tableSize; i++)
	{
		hashValue = keyValues[i] % tableSize;
		probeValue = 0;
		while (table[hashValue][0] != 0)
		{
			hashValue++;
			probeValue++;
			if (hashValue >= 50)
			{
				hashValue = 0;
			}
		}

		//Assigning the key and probe values to the table
		table[hashValue][0] = keyValues[i];
		table[hashValue][1] = probeValue;
	}
}


//Hash Function 2: Division method with quadratic probing for collision resolution
void HF2(int(&table)[50][2], int tableSize, int* keyValues)
{
	int hashValue = 0;
	int probeValue = 0;
	for (int i = 0; i < tableSize; i++)
	{
		hashValue = keyValues[i] % tableSize;
		probeValue = 0;

		//Implementing the quadratic hash 
		for (int quadratic = 0; quadratic < tableSize; quadratic++)
		{
			int quadHash = (hashValue + quadratic * quadratic) % tableSize;
			if (table[quadHash][0] == 0)
			{
				table[quadHash][0] = keyValues[i];
				table[quadHash][1] = probeValue;
				break;
			}
			++probeValue;
		}
	}
}

//Hash Function 3: Division method with double hashing for collision resolution
void HF3(int(&table)[50][2], int tableSize, int* keyValues)
{
	int hashValue = 0;
	int hashValue2 = 0;

	for (int i = 0; i < tableSize; i++)
	{
		hashValue = keyValues[i] % tableSize;
		hashValue2 = 30 - keyValues[i] % 25;
		int probeValue = 0;

		if (table[hashValue][0] == 0)
		{
			table[hashValue][0] = keyValues[i];
		}

		else
		{
			for (int j = 1; j < 50; j++)
			{
				int doubleHash = (hashValue + j * hashValue2) % tableSize;
				probeValue++;

				if (table[doubleHash][0] == 0)
				{
					table[doubleHash][0] = keyValues[i];
					table[doubleHash][1] = probeValue;
					break;
				}

			}
		}
	}
}

//Function to print the table consisting of index, key, and probes
void displayTable(int table[50][2])
{
	std::cout << "Index Key Probes" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		std::cout << i << " " << table[i][0] << " " << table[i][1] << std::endl;
	}
}

int main()
{
	//Initializing the key array
	int keys[] = { 1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299,
	 5078, 8239, 1208, 5098, 5195, 5329, 4543, 3344, 7698, 5412,
	 5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589,
	 5439, 8907, 4097, 3096, 4310, 5298, 9156, 3895, 6673, 7871,
	 5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523 };

	int userInput = 0;

	do
	{
		int table[50][2] = {};
		//Displaying the menu to the user
		std::cout << "-----MAIN MENU-----" << std::endl;
		std::cout << "1. Run HF1(Division method with Linear Probing)" << std::endl;
		std::cout << "2. Run HF2(Division method with Quadratic Probing)" << std::endl;
		std::cout << "3. Run HF3(Division method with Double Hashing)" << std::endl;
		std::cout << "4. Exit Program" << std::endl;
		std::cout << "\nEnter option number: " << std::endl;


		//Taking user input to select the menu option
		std::cin >> userInput;

		//Switch statement with cases for each menu option
		switch (userInput)
		{

		//Case for hash function 1 with linear probing
		case 1:
		{
			HF1(table, 50, keys);
			std::cout << "Hash table result from HF1:" << std::endl;
			displayTable(table);
			std::cout << "Sum of probe values = " << sumProbes(table) << " probes" << std::endl;
			break;
		}

		//Case for hash function 2 with quadratic probing
		case 2:
		{
			HF2(table, 50, keys);
			std::cout << "Hash table result from HF2:" << std::endl;
			displayTable(table);
			std::cout << "Sum of probe values = " << sumProbes(table) << " probes" << std::endl;
			break;
		}

		//Case for hash function 3 with double hashing
		case 3:
		{
			HF3(table, 50, keys);
			std::cout << "Hash table result from HF3:" << std::endl;
			displayTable(table);
			std::cout << "Sum of probe values = " << sumProbes(table) << " probes" << std::endl;
			break;
		}

		}

	} while (userInput > 0 && userInput < 4);
}