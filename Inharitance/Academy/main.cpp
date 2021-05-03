#include <iostream>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;

public:
	const string& get_last_name()const
	{
		return last_name;
	}
	
	const string& get_first_name()const
	{
		return first_name;
	}
	
	unsigned int get_age()const
	{
		return age;
	}

	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}

	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}

	void set_age(unsigned int age)
	{
		if (age >= 15 && age <= 100)
			this->age = age;
		else
			this->age = 0;
	}

	//const

	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConst:\t" << this << endl;
	}

	~Human()
	{
		cout << "HDestruc:\t" << this << endl;
	}


	//methods

	void info()const
	{
		cout << last_name << " " << first_name << ", " << age << " years old" << endl;
	}
};


class Student :public Human
{
	string speciality;
	double rating;
	unsigned int semester;

public:
	const string& get_speciality()const
	{

	}

	double get_rating()const
	{
		return rating;
	}

	unsigned int get_semester()const
	{
		return semester;
	}

	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	
	void set_rating(double rating)
	{
		if (rating > 0 && rating <= 5)
			this->rating = rating;
		else
			this->rating = 0;
	}

	void set_semester(unsigned int semester)
	{
		if (semester <= 5)
			this->semester = semester;
		else
			this->semester = 0;
	}

	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double rating, unsigned int semester
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_rating(rating);
		set_semester(semester);
		cout << "SConst:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestruc:\t" << this << endl;
	}


	//methods

	void info()const
	{
		cout << "Speciality: " << speciality << ", Rating:\t" << rating << ", Semester:\t" << semester << endl;
	}

};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}

	unsigned int get_experience()const
	{
		return experience;
	}

	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}

	void set_experience(unsigned int experience)
	{
		this->experience;
	}

	//const

	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) : Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConst:\t" << this << endl;
	}

	~Teacher()
	{
		cout << "TDestruc:\t" << this << endl;
	}

	//methods

	void info()const
	{
		Human::info();
		cout << speciality << ", teaching exp " << experience << " years." << endl;
	}
};

class Graduate :public Student
{
	string topic;
public:
	const string& get_topic() const
	{
		return topic;
	}

	void set_topic(const string& topic)
	{
		this->topic = topic;
	}

	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, double rating, unsigned int semester,
		const string& topic
	) :Student(
		last_name, first_name, age, speciality, rating, semester)
	{
		set_topic(topic);
		cout << "GConst:\t" << this << endl;
	}

	~Graduate()
	{
		cout << "GDestruc:\t" << this << endl;
	}

	void info()const
	{
		Student::info();
		cout << "Topic: " << topic << endl;
	}
};


void main()
{
	/*Human vasiliy("Tupenko", "Vasiliy", 18);
	vasiliy.info();*/ 
}