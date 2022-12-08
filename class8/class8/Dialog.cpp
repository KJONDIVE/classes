#include "Dialog.h"
#include "Object.h"
#include "List.h"
#include <iostream>
using namespace std;

Dialog::Dialog(void) : Vector(0) { EndState = 0; }
Dialog::~Dialog(void) {}

void Dialog::GetEvent(TEvent& event) {
	// Строка содержит коды операций
	string OpInt = "+-?/qam";
	string s;
	string param;

	char code;
	cout << '>';
	cin >> s;
	code = s[0];
	if (OpInt.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake;
			break;
		case '+': event.command = cmAdd;
			break;
		case '-': event.command = cmDel;
			break;
		case '?': event.command = cmGet;
			break;
		case 'q': event.command = cmQuit;
			break;
		case 's': event.command = cmShow;
			break;
		}

		if (s.length() > 1) {
			// Возвращаем подстроку строки s начиная с символа с индексом 1
			param = s.substr(1, s.length() - 1);
			// Конвертируем строку в число
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else event.what = evNothing;
}

int Dialog::Execute() {
	TEvent event;
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

int Dialog::Valid() {
	int result;
	result = (EndState == 0) ? 0 : 1;
	return result;
}

void Dialog::ClearEvent(TEvent& event) { event.what = evNothing; }
void Dialog::EndExec() { EndState = 1; }

void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake:
			beg = new Object * [event.a];
			cur = 0;
			size = event.a;
			ClearEvent(event);
			break;
		case cmAdd: Add();
			ClearEvent(event);
			break;
		case cmDel: Del();
			ClearEvent(event);
			break;
		case cmShow: Show();
			ClearEvent(event);
			break;
		case cmGet: Show(event.a);
			ClearEvent(event);
			break;
		case cmQuit: EndExec();
			ClearEvent(event);
			break;
		default:
			ClearEvent(event);
		}
	}
}
