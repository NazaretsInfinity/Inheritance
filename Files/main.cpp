#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<ctime>
using::std::cin;
using::std::cout;
using::std::endl;

#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
#ifdef WRITE_TO_FILE1
	setlocale(LC_ALL, "Russian");
	//1) create a stream
	std::ofstream fout;
	//2) open the stream(use method 'open')
	fout.open("File.txt",std::ios_base::app); //without app(only 1st prmtr we rewrite file
	//3) write in the stream                 // with app(append) as 2nd prmtr we add in the end
	
	//fout << "Hello World" << endl;
	//fout << "Сам привет" << endl;
	
	time_t now = time(NULL);
	fout << ctime(&now) << endl;

	//4) close the stream
	fout.close();  //we opened - close is necessary!
	system("notepad File.txt");
#endif
#ifdef READ_FROM_FILE
	//1)create a stream and open it as well
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 256;
		char buffer[SIZE]{};
		while (!fin.eof())        // eof - end of file
		{
			//fin >> buffer;  // fin consider 'space' as an end of string
			fin.getline(buffer, 256);  
			cout << buffer << endl;
		}
		fin.close();
	}
	else std::cerr << "Error:file not found" << endl;

#endif
}