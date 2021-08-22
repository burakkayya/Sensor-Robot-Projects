#include<iostream>
#include"RobotControl.h"
#include"MainMenu.h"
#include"Pose.h"

using namespace std;
void Menu::menu()
{

	int input, x = 0;
	bool kontrol = 0;
	Pose konum;
	Pose konum1;
	bool accessState = 0;

	if (kumanda.openAccess())
	{
		accessState = 1;
		do
		{
			cout << "               ---------Main Menu---------" << endl;
			cout << "               1. Encryption" << endl;
			cout << "               2. Motion" << endl;
			cout << "               3.Print" << endl;
			cout << "               4.Position" << endl;
			cout << "               5. Sensor" << endl;
			cout << "               6. Quit" << endl;
			cout << "Choose one :";
			cin >> input;
			if (input == 1)
			{
				do
				{
					cout << "---Encryption Menu---" << endl;
					cout << "1. Open Access" << endl;
					cout << "2. Close Access " << endl;
					cout << "3. Back to Main Menu " << endl;
					cout << "Choose one :";
					cin >> x;
					switch (x)
					{
					case 1:
						kontrol = kumanda.openAccess();
						if (kontrol == 1) {
							cout << "Password is correct access is opening.." << endl;
							accessState = 1;
						}
						else {
							cout << "Password is not correct" << endl;
							accessState = 0;
						}
						break;
					case 2:
						kontrol = kumanda.closeAccess();
						if (kontrol == 1) {
							cout << "Password is correct access is closing.." << endl;
							accessState = 0;
						}
						else
							cout << "Password is not correct" << endl;
						break;
					case 3:
						break;
					}
				} while (x != 3);
			}

			if (input == 2)
			{
				if (accessState == 1) {
					do
					{
						cout << "---Motion Menu---" << endl;
						cout << "1. Turn left" << endl;
						cout << "2. Turn Right " << endl;
						cout << "3. Forward  " << endl;
						cout << "4. Backward  " << endl;
						cout << "5. StopTurn " << endl;
						cout << "6. StopMove " << endl;
						cout << "7. Back to Main Menu " << endl;
						cout << "Choose one :";
						cin >> x;

						switch (x)
						{
						case 1:
							kumanda.turnLeft();
							cout << "<Robot turns left>" << endl;
							break;
						case 2:
							kumanda.turnRight();
							cout << "<Robot turns right>" << endl;
							break;
						case 3:
							float speed;
							cout << "enter speed" << endl;
							cin >> speed;
							kumanda.forward(speed);
							cout << "Robot is moving " << speed << " m/s." << endl;
							break;
						case 4:
							float speed1;
							cout << "enter speed" << endl;
							cin >> speed1;
							kumanda.backward(speed1);
							cout << "Robot is moving " << speed1 << " m/s." << endl;
							break;
						case 5:
							kumanda.stopTurn();
							cout << "<Robot is not turning>" << endl;
							break;
						case 6:
							kumanda.stopMove();
							cout << "<Robot stop!>" << endl;
							break;
						case 7:
							break;
						default:
							break;
						}

					} while (x != 7);
				}
				else cout << "You have no access!" << endl;
			}
			if (input == 3)
			{
				if (accessState == 1){
					do
					{
						cout << "---Print Menu---" << endl;
						cout << "1. Display Robot's position" << endl;
						cout << "2. Back to main menu" << endl;
						cout << "Choose one :";
						cin >> x;
						switch (x)
						{
						case 1:
							kumanda.print();
							break;
						case 2:
							break;
						default:
							break;
						}

					} while (x != 2);
			}
				else cout << "You have no access!" << endl;
			}
			if (input == 4)
			{
				if (accessState == 1){
					do
					{
						cout << "\n---Position Menu---" << endl;
						cout << "1. Set Pose" << endl;
						cout << "2. Get Pose" << endl;
						cout << "3. Add to Path" << endl;
						cout << "4. Clear Path " << endl;
						cout << "5. Record Path to File" << endl;
						cout << "6.Back to Main Menu" << endl;
						cout << "Choose one :";
						cin >> x;
						switch (x)
						{
						case 1:
							float x, y, th;
							cout << "Enter x,y and th" << endl;
							cin >> x >> y >> th;
							konum.setPose(x, y, th);
							kumanda.setPose(konum);
							break;
						case 2:
							konum1 = kumanda.getPose();
							cout << "x:" << konum1.getX() << " y:" << konum1.getY() << " th:" << konum1.getTh();
							break;
						case 3:
							if (kumanda.addToPath())
								cout << "Added to path" << endl;
							break;
						case 4:
							if (kumanda.clearPath())
								cout << " Empty Path " << endl;
							break;
						case 5:
							if (kumanda.recordPathtoFile())
								cout << "Path is recorded to the file" << endl;
							break;
						case 6:
							break;
						default:
							break;
						}

					} while (x != 6);
			}
				else cout << "You have no access!" << endl;
			}

			if (input == 5)
			{
				if (accessState == 1){
					do
					{
						cout << "\n---Sensor Menu---" << endl;
						cout << "1. Laser Sensor" << endl;
						cout << "2. Sonar Sensor" << endl;
						cout << "3. Back to Main Menu" << endl;
						cout << "Choose one :";
						cin >> x;
						switch (x)
						{
						case 1:
							kumanda.laserSENSOR();
							break;

						case 2:
							kumanda.sonarSENSOR();
							break;

						case 3:
							break;
						default:
							break;
						}

					} while (x != 3);
			}
				else cout << "You have no access!" << endl;
			}

		} while (input != 6);
		if (input == 6)
			exit(0);
	}
	else
	{
		cout << "Password is not correct!" << endl;
	}



}