#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Spec { KOMPUTERNINAUKY, INFORMATIKA, MATEMATIKAIEKONOMIKA, FIZUKAIINFORMATIKA, TRUDOVENAVCHANNA };//оголошення переліків змінних

string spec_str[] = { "Com Science", "Informatics", "Math&Econom", "Physic&Info", "Handicrafts" };

struct Student
{
	string last_name;
	int cource;
	Spec speci;
	int fizuka;
	int matematika;
	union {
		int prog;
		int chuselni_metody;
		int peda;
	};
};

int Create(Student* s, const int N, int x, int z);
void Print(Student* s, const int N);
void Sort0(Student* s, const int N);
void Sort1(Student* s, const int N);
void Sort2(Student* s, const int N);

int main() {
	int N;
	int x = 0;
	int z = 0;
	cout << "Vvedit N: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N, x, z);
	Print(s, N);
	int c;
	cout << "Select by sort:" << endl;
	cout << "0 - Physic   1 - Mathematic    2 - Average grade in physics and mathematics" << endl;
	cin >> c;
	switch (c) {
	case 0:Sort0(s, N); break;
	case 1:Sort1(s, N); break;
	case 2:Sort2(s, N); break;

	}
}
int Create(Student* s, const int N, int x, int z) {
	int speci;
	for (int i = 0; i < N; i++)
	{
		cout << "Student № " << i + 1 << ":" << endl;
		cin.get();
		cout << " Last Name: "; getline(cin, s[i].last_name);
		cout << " Cource : "; cin >> s[i].cource;
		cout << " Speciality (0 - Computer Science, 1 - Informatics, 2 - Mathematics and Economics, 3 - Physics and Informatics, 4 - Handicraft): ";
		cin >> speci;
		if (speci == 2 || speci == 3 || speci == 4) {
			x = x + 1;
		}
		if (speci == 1) {
			z++;
		}
		s[i].speci = Spec(speci);
		switch (s[i].speci) {
		case KOMPUTERNINAUKY:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Programming : "; cin >> s[i].prog;
			break;
		case INFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Numerical Methods : "; cin >> s[i].chuselni_metody;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		case FIZUKAIINFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		case TRUDOVENAVCHANNA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		}
		cout << endl;
	}
	return x, z;
}
void Print(Student* s, const int N)
{
	cout << "=============================================================================" << endl;
	cout << "| № | Last Name | Course | Speciality | Phy | Math | Prog | Num Met | Ped |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << s[i].last_name << "| " << setw(6) << right << s[i].cource << " " << "| " << setw(10) << left << spec_str[s[i].speci];
		switch (s[i].speci) {
		case KOMPUTERNINAUKY:
			cout << "| " << setw(4) << right << s[i].fizuka << "|" << " " << setw(5) << right
				<< s[i].matematika << "|" << " " << setw(5) << right << s[i].prog << "|"
				<< " " << setw(9) << right << "|" << " " << setw(5) << right << "|" << endl;
			break;
		case INFORMATIKA:
			cout << "| " << setw(4) << right << s[i].fizuka << "|" << " " << setw(5) << right
				<< s[i].matematika << "|" << setw(7) << right << "|" << setw(9) << right << s[i].chuselni_metody << "|" << " " << setw(5) << right << "|" << endl;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << "| " << setw(4) << right << s[i].fizuka << "|" << setw(6) << right
				<< s[i].matematika << "|" << setw(7) << right << "|" << setw(10) << right << "|" << setw(5) << s[i].peda << "|" << endl;
			break;
		case FIZUKAIINFORMATIKA:
			cout << "| " << setw(4) << right << s[i].fizuka << "|" << setw(6) << right
				<< s[i].matematika << "|" << setw(7) << right << "|" << setw(10) << right << "|" << setw(5) << s[i].peda << "|" << endl;
			break;
		case TRUDOVENAVCHANNA:
			cout << "| " << setw(4) << right << s[i].fizuka << "|" << setw(6) << right
				<< s[i].matematika << "|" << setw(7) << right << "|" << setw(10) << right << "|" << setw(5) << s[i].peda << "|" << endl;
			break;
		}
	}
	cout << "=============================================================================" << endl;
	cout << endl;
}
void Sort0(Student* s, const int N) {
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (s[i1].fizuka > s[i1 + 1].fizuka)
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}

	Print(s, N);
}
void Sort1(Student* s, const int N) {
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (s[i1].matematika > s[i1 + 1].matematika)
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}

	Print(s, N);
}
void Sort2(Student* s, const int N) {
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++)
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if (s[i1].matematika+s[i1].fizuka > s[i1 + 1].matematika+1)
			{
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}

	Print(s, N);
}