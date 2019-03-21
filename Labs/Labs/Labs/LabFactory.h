#pragma once
#include <vector>
#include "Abstracts\Lab.h"
#include "Implementations\Lab1.h"
#include "Implementations\Lab2.h"

using namespace std;

// ����� ���� � ���������� ������� ������������ ������(Singleton)
// ��������� ��� ����� ������: "https://uk.wikipedia.org/wiki/������_(������_������������)"
// ��������� ������ ������� � LabFactory.cpp ����
class LabFactory
{
private:
	static LabFactory _instance;

	LabFactory() // �����������
	{
		// ��� ����� ���������� ����� ���� ���, ��� ������� 
		// ������� �������� �� ���������� ������ GetInstance() � ������� ����������� ������������ ����.
		InitLabs();
	}

	~LabFactory() // ����������
	{
		ClearLabs();
	}

	// �� �a�������� ������ ����������� � ���������� ������ _labs, �����������
	// ����� ���������� � ���������� ���������� ����� InitLabs.
	vector<Lab*> _labs;

	// ��� ����� ���������������� � ����������� ��� ����������� �����
	void InitLabs();
	// ��� ����� ���������������� � ���������� ��� ���������� ��� ��.
	void ClearLabs();

public:
	static LabFactory& GetInstance();

	// ��� �������� ��������� �����, ���� ������� ���� � 
	// ���������(�������) ����� Lab �� ���� ����������� ������.
	// ������ ��� ������� ������ ������� ���:
	//https://www.learncpp.com/cpp-tutorial/812-static-member-functions/
	Lab* GetLabByName(string labName);

	// ������� ���� ������ � ������������� ��������.
	vector<Lab*> GetLabs();
};
