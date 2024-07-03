#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#define delimeter "\n===================================\n"
#define human_take_parameters const std::string& last_name, const std::string& first_name, unsigned int age
#define human_give_parameters  last_name,  first_name, age
class Human
{
	static const int HUMAN_TYPE_WIDTH = 10;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	// INCAPSULATION
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(std::string lstn)
	{
		last_name = lstn;
	}
	void set_first_name(std::string frst)
	{
		first_name = frst;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//CONSTRUCTORS
	Human(human_take_parameters)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HUMA_Destructor:\t" << this << endl;
	}
	//METHODS
	virtual std::ostream& info(std::ostream& os)const
	{
		os << endl;
		return  os <<last_name << " " << first_name << " " << age << " y/o ";
	}
	virtual std::ofstream& write(std::ofstream& ofs)const
	{
		//ofs << strchr(typeid(*this).name(), ' ') + 1 << ": " << last_name << " " << first_name << " " << age;
		ofs.width(HUMAN_TYPE_WIDTH);
		ofs << left << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";
		ofs.width(LAST_NAME_WIDTH);ofs<< left << last_name;
		ofs.width(FIRST_NAME_WIDTH);ofs<< left << first_name;
		ofs.width(AGE_WIDTH); ofs << left << age;
		return ofs;
	}
	virtual std::ifstream& read(std::ifstream& ifs)
	{
			ifs >> last_name >> first_name >> age;
			return ifs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& pers)
{
	return pers.info(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	obj.write(ofs);
	ofs << endl;
	return ofs;
}
std::ifstream& operator>>(std::ifstream& is, Human& obj)
{
	return obj.read(is);
}

#define student_take_parameters const std::string& speciality, const std::string& group, double rating,double attendance
#define student_give_parameters speciality, group, rating, attendance

class Student : public Human
{
	static const int SPECIALITY_WIDTH=25;
	static const int GROUP_WIDTH=8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	Student(human_take_parameters, student_take_parameters) : Human(human_give_parameters)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "STUD_Destructor:\t" << this << endl;
	}
	//METHODS
	std::ostream& info(std::ostream& os)const override
	{
		return Human::info(os) << speciality << " " << group << " " << rating << " " << attendance;
	}

	std::ofstream& write(std::ofstream& ofs)const override
	{
		Human::write(ofs);
		ofs.width(SPECIALITY_WIDTH);ofs << speciality;
		ofs.width(GROUP_WIDTH);ofs << group;
		ofs.width(RATING_WIDTH); ofs << rating;
		ofs.width(ATTENDANCE_WIDTH); ofs << attendance;
		return ofs;
	}
	std::ifstream& read(std::ifstream& ifs)override
	{
		Human::read(ifs);
		char buffer[SPECIALITY_WIDTH];
		ifs.read(buffer, SPECIALITY_WIDTH);
		for (int i = SPECIALITY_WIDTH - 1; buffer[i] == ' '; i--)buffer[i] = 0;

		while (buffer[0] == ' ')
			for (int i = 0; buffer[i]; i++)buffer[i] = buffer[i + 1];
		this->speciality = buffer;
		ifs >> group >> rating >> attendance;
		return ifs;
	}
};
class Teacher : public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 5;
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()
	{
		return speciality;
	}
	const unsigned int get_experience()
	{
		return experience;
	}
	void set_speciality(const std::string speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//Constructors
	Teacher(human_take_parameters, std::string speciality, unsigned int experience) : Human(human_give_parameters)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "Constructor:\t" << this << endl;
	}
	//Destructor
	~Teacher()
	{
		cout << "TEAC_Destructor:\t" << this << endl;
	}
	//Methods
	std::ostream& info(std::ostream& os)const override
	{
		return Human::info(os) << speciality << " " << experience << "-years";
	}
	std::ofstream& write(std::ofstream& ofs)const override
	{
		Human::write(ofs);
		ofs.width(SPECIALITY_WIDTH); ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH); ofs << experience;
		return ofs;
	}
	std::ifstream& read(std::ifstream& ifs)override
	{
		Human::read(ifs);
	    /*std::string sam;
		ifs >> speciality >> sam;
		while (atoi(sam.c_str()) == 0)
		{
			speciality += " " + sam;
			ifs >> sam;
		}
		experience = atoi(sam.c_str());*/

		const int size = SPECIALITY_WIDTH;
		char buffer[size]{};
		ifs.read(buffer, size);
		int pos  = strrchr(buffer, ' ') - buffer;
		buffer[pos] = 0;
		for (int i = size - 2; buffer[i] == ' '; i--)buffer[i] = 0;
		while (buffer[0] == ' ')
		{
			for (int i = 0; buffer[i]; i++)
				buffer[i] = buffer[i + 1];
		}
		this ->speciality = buffer;
		ifs >> experience;
		return ifs;
	}	
};
class Graduate : public Student
{
	static const int WORKTOPIC_WIDTH = 32;

	std::string worktopic;
	unsigned int workgrade;
public:
	// incaps
	const std::string get_topic()const
	{
		return worktopic;
	}
	const unsigned int get_grade()const
	{
		return workgrade;
	}
	void set_topic(std::string worktopic)
	{
		this->worktopic = worktopic;
	}
	void set_grade(unsigned int workgrade)
	{
		this->workgrade = workgrade;
	}
	//Constructor
	Graduate(human_take_parameters, student_take_parameters, std::string worktopic, unsigned int workgrade)
		: Student(human_give_parameters, student_give_parameters)
	{
		set_topic(worktopic);
		set_grade(workgrade);
		cout << "GConstructor:\t" << this << endl;
	}
	//Destructor
	~Graduate()
	{
		cout << "GRAD_Destructor:\t" << this << endl;
	}
	//Methods
	std::ostream& info(std::ostream& os)const override
	{
		return Student::info(os) << " " << worktopic << " got: " << workgrade;
	}
	std::ofstream& write(std::ofstream& ofs)const override
	{
		Student::write(ofs);
		ofs.width(WORKTOPIC_WIDTH);	ofs << worktopic;
		return ofs;
	}
	std::ifstream& read(std::ifstream& ofs)override
	{
		Student::read(ofs);
		std::getline(ofs,worktopic); //'cause it has extra whitespaces
		return ofs;
	}
};
void save(Human* group[], const int n, const std::string filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i];
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str()); // c_str - return data of object std string as  C-string(null terminated file)
}
Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human:")human = new Human("", "", 0);
	if (type == "Student:")human = new Student("", "", 0, "", "", 0, 0);
	if (type == "Graduate:")human = new Graduate("", "", 0, "", "", 0, 0,"",0);
	if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
	return human;
}
Human** load(const std::string filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//1) count amount of strings in file(people)
		n = 0;
		while (!fin.eof())
		{
			std::string buffer;
			std::getline(fin, buffer);
			if (buffer.size() < 16)continue;
			n++;
		}
		//2) allocate memory 
		group = new Human*[n];
		//3) Get back to the start of file
		fin.clear();
		fin.seekg(0);
		//4) reading objects
		for (int i = 0; i < n; i++)
		{
			std::string type;
			fin >> type;
			group[i] = HumanFactory(type);
			if (group[i])fin >> *group[i];
			else continue;
		}
		fin.close();
	}
	else std::cerr << "Error:file not found" << endl;
	return group;
}
void print( Human* group[],  const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << delimeter;
	}
}
void clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++) 
	{
		delete group[i];
	}
}
#define InheritanceCheck
#define Polymorphism
void main()
{
#ifdef InheritanceCheck1
	setlocale(LC_ALL, "");
	Human human("Vercetty", "Tommy", 30);
	human.info();
	Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97);
	student.info();
	Teacher teacher("White", "Walter", 50, "Chemisty", 25);
	teacher.info();
#endif  
#ifdef Polymorphism1
	Human* group[] =
	{
	   new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
	   new Teacher("White", "Walter", 50, "Chemisty", 25),
	   new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 88,90, "How to catch Heisenberg", 5),
	   new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
	   new Teacher("Diaz","Ricardo", 50, "Weapons distribution", 20)
	};
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	print(group, sizeof(group) / sizeof(group[0]));
	clear(group, sizeof(group) / sizeof(group[0]));
#endif 
	int n = 0;
	Human** group = load("group.txt",n);
	print(group, n);
	clear(group, n);
}