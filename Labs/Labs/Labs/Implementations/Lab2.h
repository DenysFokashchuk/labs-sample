#pragma once
#include <iostream>
#include <sstream>
#include "../Abstracts/Lab.h"
#include "Lab2\TrainSchedule.h"
#include "Lab2\TrainScheduleManager.h"

using namespace std;

class Lab2 : public Lab
{
public:
	// ������� ����� ��
	virtual string GetName() {
		return "lab 2";
	}

	// ������� ���� ��� ��2
	virtual string GetDescription() {
		ostringstream desc;
		desc << "���������� ����, �� ������ ���������� ��� ������� ���� �����,";
		desc << "�� ������������� � �����-������������ �������:";
		desc << "����� �����, ��� �����������, ������� �����������, ��� � �����. ";
		desc << "�������������� �� ���, ������ ���������� ��� ������� ���� ����� �� ������� ���,";
		desc << "�� ������������� � 20 �� 24 ���. � ����������� � ����� ����� 15 ���.";
		return desc.str();
	}

	// ������ ��������� ��
	virtual void Execute() {

		cout << endl << "====== Lab 2 started ======" << endl;

		cout << "Please enter 'help' to see the list of available commands" << endl;
		cout << "Please enter 'exit' to close this lab" << endl;
		TrainScheduleManager manager;
		while (true) {
			cout << endl << "=> Please enter command: ";
			string cmd;
			cin >> cmd;

			if (cmd == "exit") {
				cout << endl << "====== Lab 2 finished ======" << endl;
				break;
			}
			else if (cmd == "help") {
				Help();
			}
			else if (cmd == "add") {
				manager.Add();
			}
			else if (cmd == "show") {
				manager.ShowAll();
			}
			else if (cmd == "remove") {
				cout << "Please enter TrainNo. or '*' to remove all: ";
				string trainNo;
				cin >> trainNo;
				if (trainNo == "*") {
					manager.DeleteAll();
				}
				else {
					manager.DeleteByTrainNo(trainNo);
				}
			}
			else if (cmd == "search")
			{
				manager.Search();
			}
			else {
				cout << "Command not found" << endl;
			}
		}
	}

private:
	void Help() {
		cout << "'help'     - list of commands" << endl;
		cout << "'exit'     - finish the lab" << endl;
		cout << "'add'      - add new schedule" << endl;
		cout << "'remove' - remove one or multiple schedules" << endl;
		cout << "'show' - show all train schedules" << endl;
		cout << "'search'   - search train schedules" << endl;
	}

};