#include <iostream>
#include <Windows.h>
#include "main.h"

using namespace std;

void pressUp()
{
	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_UP;
	ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	SendInput(1, &ip, sizeof(INPUT));
	ZeroMemory(&ip, sizeof(INPUT));
	Sleep(5);
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_UP;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	cout << "Up pressed!" << endl;
}
void pressDown()
{
	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_DOWN;
	ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	SendInput(1, &ip, sizeof(INPUT));
	ZeroMemory(&ip, sizeof(INPUT));
	Sleep(5);
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_DOWN;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	cout << "Down pressed!" << endl;
}
void pressLeft()
{
	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_LEFT;
	ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	SendInput(1, &ip, sizeof(INPUT));
	ZeroMemory(&ip, sizeof(INPUT));
	Sleep(5);
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_LEFT;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	cout << "Left pressed!" << endl;
}
void pressRight()
{
	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_RIGHT;
	ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	SendInput(1, &ip, sizeof(INPUT));
	ZeroMemory(&ip, sizeof(INPUT));
	Sleep(5);
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VK_RIGHT;
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	cout << "Right pressed!" << endl;
}

void pressKey(CHAR string)
{
	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = VkKeyScanA(string);
	SendInput(1, &ip, sizeof(INPUT));
	ZeroMemory(&ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
	
}

int main()
{
	cout << "Helldivers 2 quick stratagems" << endl;
	cout << "Press V to activate the QuickStratagem" << endl;
	cout << "Press INS to exit" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;

	while (true)
	{
		Sleep(10);
		// Press INS to exit
		if (GetAsyncKeyState(VK_INSERT))
		{
			cout << "Exiting..." << endl;
			Sleep(1000);
			return 0;
		}
		// Press keyBind to activate the stratagem
		if (GetAsyncKeyState(0x56)) // V
		{
			pressUp();
			Sleep(100);
			pressDown();
			Sleep(100);
			pressRight();
			Sleep(100);
			pressLeft();
			Sleep(100);
			pressUp();
			cout << "Stratagem activated!" << endl;
			Sleep(2000);

		}

		//Press L to activate the string
		if (GetAsyncKeyState(0x4C)) // L
		{
			INPUT ip = { 0 };
			ip.type = INPUT_KEYBOARD;
			ip.ki.wVk = VkKeyScanA('Hello!');
			SendInput(1, &ip, sizeof(INPUT));
			ZeroMemory(&ip, sizeof(INPUT));
			ip.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT));
		}
		
	}
}