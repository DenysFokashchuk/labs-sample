#include <iostream>
#include <iomanip>
#include <locale>;
#include "windows.h";
#include "Labs\LabFactory.h"

using namespace std;

// �������� ������ ��������� ��
// ����������� �������� iomanip (left, right, setw) ��� ������������
// https://cpppatterns.com/patterns/write-data-in-columns.html
void help() {
	auto labs = LabFactory::GetInstance().GetLabs();
	string nameLabel = "Lab Name";
	string descLabel = "Description";
	int maxAllowedLength = 60;
	int maxNameLen = nameLabel.length();
	int maxDescLen = descLabel.length();
	for (size_t i = 0; i < labs.size(); i++)
	{
		int nameLen = labs[i]->GetName().length();
		if (maxNameLen < nameLen && nameLen < maxAllowedLength) {
			maxNameLen = nameLen;
		}

		int descLen = labs[i]->GetDescription().length();
		if (maxDescLen < descLen && descLen < maxAllowedLength) {
			maxDescLen = descLen;
		}
	}

	cout << right << setw(maxNameLen) << nameLabel << "\t" << left << setw(maxDescLen) << descLabel << endl;
	for (size_t i = 0; i < labs.size(); i++)
	{
		cout << right << setw(maxNameLen) << labs[i]->GetName() << "\t" << left << setw(maxDescLen) << labs[i]->GetDescription() << endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Enter 'help' to see a list of available labs" << endl;
	while (true)
	{
		cout << "=> Please enter LR name: ";
		string command;

		// ��� ��������������� ����� getline ������ �������� 'cin >>'
		// ������� ������� ����� ���� ������ � ������ �� ������� ������,
		// ����� ����, ��� ������ ���� �����.
		// ���������: http://www.cplusplus.com/forum/beginner/213159/
		getline(std::cin, command);
		
		if (IsEqualsIgnoreCase(command, "help")) {
			help();
			continue;
		}

		Lab* selectedLab = LabFactory::GetInstance().GetLabByName(command); // ��������� ��
		
		// ���������� �� �������� ��
		if (selectedLab == nullptr) {
			cout << "LR not found!" << endl;
		}
		else {
			// ���� �������� - ���� �� ���������
			selectedLab->Execute(); 
		}
	}
}