#include <string> 
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



class MyTime
{   
    private:
        int hourTime;
        int minuteTime;
        int secondTime;

    public:
        class IncorrectTimeException {
        };
        MyTime() {};
        MyTime(int h, int m, int s) {
            if (s < 0 || s > 59 || m < 0 || m > 59 || h < 0 || h > 23) {
                throw IncorrectTimeException();
            }
            hourTime = h;
            minuteTime = m;
            secondTime = s;
        }
        
        int GetAllInSeconds(){
            return hourTime * 60 * 60 + minuteTime * 60 + secondTime;
        }
        void Add5Seconds() {
            secondTime += 5;
            if (secondTime >= 60) {
                minuteTime += 1;
                secondTime -= 60;
                if (minuteTime >= 60) {
                    hourTime += 1;
                    minuteTime -= 60;
                    if (hourTime >=24)
                    {
                        hourTime = 0;

                    }
                }
            }
        }
        void SetHours(int hours) {
            hourTime = hours;
        }
        void SetMinutes(int minutes) {
            minuteTime = minutes;
        }
        void SetSeconds(int Seconds) {
            secondTime = Seconds;
        }

        int GetHours() const {
            return hourTime;
        }

        int GetMinutes() const {
            return minuteTime;
        }

        int GetSeconds() const {
            return secondTime;
        }
        void PrintTime() {
            string h, m, s;
            if (hourTime < 10) {
                h = "0" + to_string(hourTime);
            }
            else {
                h = "" + to_string(hourTime);
            }
            if (minuteTime < 10) {
                m = "0" + to_string(minuteTime);
            }
            else {
                m = "" + to_string(minuteTime);
            }
            if (secondTime < 10) {
                s = "0" + to_string(secondTime);
            }
            else {
                s = "" + to_string(secondTime);
            }
            
            cout << h << ":" << m << ":" << s << endl;
        }
        string ReturnFormattedTime() {
            string h, m, s, formattedTime;
            if (hourTime < 10) {
                h = "0" + to_string(hourTime);
            }
            else {
                h = "" + to_string(hourTime);
            }
            if (minuteTime < 10) {
                m = "0" + to_string(minuteTime);
            }
            else {
                m = "" + to_string(minuteTime);
            }
            if (secondTime < 10) {
                s = "0" + to_string(secondTime);
            }
            else {
                s = "" + to_string(secondTime);
            }
            formattedTime = h + " " + m + " " + s;
            return formattedTime;
        }

};
vector<MyTime> diskIn() {
    vector<MyTime> arr;
    int arrPos = 0;
    ifstream fin("input.txt");
    if (!fin)
    {
        cout <<"Файл не открыт\n\n";

    }
    else
    { 
        cout <<"Все ОК! Файл открыт!\n\n";
        
        for (string line; getline(fin, line); )
        {
            string hour;
            string minute;
            string second = "";
            int spaceCounter = 0;
            if (line[0] != ' ' && line[0] != NULL) {
                for (int i = 0; i <= line.length(); i++)
				{
					if (line[i] == ' ') spaceCounter += 1;
					if (spaceCounter == 0)hour += line[i];
					if (spaceCounter > 0 && spaceCounter < 2 && line[i] != ' ')minute += line[i];
					if (spaceCounter >= 2) {
						if (line[i] != ' ') {
							second += line[i];

						}

						if (i == line.length()) {
							second += line[i];
						};

					}

				}
				MyTime T(stoi(hour), stoi(minute), stoi(second));
				arr.push_back(T);
				arrPos += 1;
            }
            

        }   
    }
    return arr;
}
void diskOut(vector<MyTime> array) {
    ofstream fout("output.txt");
    if (!fout) {
        cout << "Файл не открыт\n\n";
    }
    else {
        for (MyTime T: array)
        {
            string time = T.ReturnFormattedTime();
            fout << time << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
   /* MyTime T(22, 59, 05);
    
    T.PrintTime();
    T.Add5Seconds();
    T.PrintTime();
    T.Add5Seconds();
    T.PrintTime();
    T.Add5Seconds();
    T.PrintTime();
    cout << T.GetAllInSeconds() << " секунд";*/
    
    
    vector<MyTime> a = diskIn();
    for (MyTime T : a) {
        T.PrintTime();
    }
    diskOut(a);
    
    
    //commit test
    
    
}

