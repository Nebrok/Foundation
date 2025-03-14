#pragma once


class MainMenu
{
	int numMenuItems;


public:
	MainMenu();
	~MainMenu();

	void Update();
	void Render();
	void OnKeyDown();

};