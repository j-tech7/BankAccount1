#pragma warning (disable:4786)
#include<iostream>
#include<string>
#include<set>

using namespace std;

//person class
class Person
{
	private:
	string lastName;
	string firstName;
	long phoneNum;
		
	public:
	//default constructor/ no arm construtors
	Person() :lastName("blank"), firstName("blank"), phoneNum(0L)
	{}
	
	//3 -arg constructor
	Person (string f, string l, long num):
		lastName(l), firstName(f), phoneNum(num)
	{}
	
	friend bool operator<(const Person&, const Person&);
	friend bool operator==(const Person&, const Person&);	
	
	void display() const //displaying person's data
	{
		cout << endl << lastName << ", " << firstName
				<< "\t\tPhone: " << phoneNum;
	}			
};

//overload < operator  
bool operator <(const Person& p1, const Person& p2)
{
	if(p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}

//overload == operator
bool operator ==(const Person& p1, const Person& p2)
{
	return (p1.lastName == p2.lastName &&
				p1.firstName == p2.firstName) ? true : false;
}

int main()
{

	//make persons objects
	Person ptr0 ("Guardado", "Jesse", 1234567);
	Person ptr1 ("Oh", "Alyssa", 7654321);
	Person ptr2 ("Flores", "Jose", 1243765);
	Person ptr3 ("Gomez", "Kimberly", 2345617);
	Person ptr4 ("Venturi", "Taylor", 1765432);
	Person ptr5 ("Guardado", "Jesse", 1234567);
	Person ptr6 ("Ngyuen", "Phuoung", 7162534);
	Person ptr7 ("Clin", "Hillary", 5671234);
	
	multiset< Person, less<Person> > multPtrPer;
	multiset<Person, less<Person> >::iterator iter1;
	
	//creating multiset of persons
	//multiset<Person*, comparePerson> multPtrPer;
	multPtrPer.insert(ptr0);
	multPtrPer.insert(ptr1);
	multPtrPer.insert(ptr2);
	multPtrPer.insert(ptr3);
	multPtrPer.insert(ptr4);
	multPtrPer.insert(ptr5);
	multPtrPer.insert(ptr6);
	multPtrPer.insert(ptr7);
	
	
	cout << "\nNumber of entries = " << multPtrPer.size();
	
	iter1 = multPtrPer.begin();
	while(iter1 != multPtrPer.end() )
		(*iter1++).display();
	
	int i = 0;
	//for_each(multPtrPer.begin(), multPtrPer.end(), displayPerson());
	//cout << endl;
	do{
	//find person or persons with specified name(last and first)
	string searchLastName, searchFirstName;
	cout << "\n\nEnter last name of person to search for: ";
	cin >> searchLastName;
	cout <<  "Enter first name: ";
	cin >> searchFirstName;
	
	//creat a person with this name
	Person searchPerson(searchLastName, searchFirstName, 0);
	
	int cntPersons = multPtrPer.count(searchPerson);
	cout << "Number of persons with this name = " << cntPersons;
	
	//display all matches
	iter1 = multPtrPer.lower_bound(searchPerson);
	while( iter1 != multPtrPer.upper_bound(searchPerson) )
		(*iter1++).display();
	cout << endl;
	}while(i <=7);

	return 0;
}
