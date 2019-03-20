#include "LabFactory.h"

LabFactory LabFactory::_instance;

LabFactory& LabFactory::GetInstance()
{
	return _instance;
}

void LabFactory::InitLabs() {
	_labs.push_back(new Lab1);
	_labs.push_back(new Lab2);
}

void LabFactory::ClearLabs()
{
	for (size_t i = 0; i < _labs.size(); ++i)
	{
		delete (_labs[i]);
	}
	_labs.clear();
}

Lab* LabFactory::GetLabByName(string labName) {
	for (size_t i = 0; i < _labs.size(); ++i)
	{
		// ³��������� ��������� ���� ����� �� � ��������� ���� labName.
		// ��� ��������� ���������� ������ ������.
		if (IsEqualsIgnoreCase(_labs.at(i)->GetName(), labName)) {
			// ���� ����������� ������ ��������, �� ���������� ����������
			// ���������� �����
			return _labs.at(i);
		}
	}
	// ���� �� ����, ����� � ��������� labName, �� ����������� nullptr
	// ���������� ��� nullptr: http://archive.kalnytskyi.com/2011/09/04/introduction-to-cpp11-part-2/
	return nullptr;
}

vector<Lab*> LabFactory::GetLabs()
{
	return _labs;
}