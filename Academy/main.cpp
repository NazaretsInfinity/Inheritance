#include<iostream>
#include<string>
using namespace std;
#define delimeter "\n===================================\n"
#define human_take_parameters const std::string& last_name, const std::string& first_name, unsigned int age
#define human_give_parameters  last_name,  first_name, age
class Human
{
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
virtual void info()const
{
	cout << delimeter;
	cout << last_name << " " << first_name << " " << age << " y/o" << endl;
}
};
#define student_take_parameters const std::string& speciality, const std::string& group, double rating,double attendance
#define student_give_parameters speciality, group, rating, attendance
class Student : public Human
{
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
	void info()const override
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};
class Teacher : public Human
{
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
	void info()const override
	{
		Human::info();
		cout << speciality << " " << experience << "-years" << endl;
	}
};
class Graduate : public Student
{
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
void info()const override
{
	Student::info();
	cout << worktopic << " got: " << workgrade << endl;
}
};
#define InheritanceCheck
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
#ifdef InheritanceCheck
	Human* group[] =
	{
	   new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
	   new Teacher("White", "Walter", 50, "Chemisty", 25),
	   new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
	};
	for (int i = 0; i < sizeof(group) / sizeof(group[i]); i++)
	{
		group[i]->info();
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[i]); i++) //CALL OF DISTRCTR
	{
		delete group[i];
	}
#endif 
}
