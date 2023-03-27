#include <string> 
#include <iostream>
using namespace std;

class MyTime
{   
    private:
        int hourTime;
        int minuteTime;
        int secondTime;

    public:
        MyTime() {
            
        };
        MyTime(int h, int m, int s) {
            
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

};
int main()
{
    
    MyTime T(23, 59, 50);
    
    T.PrintTime();
    T.Add5Seconds();
    T.PrintTime();
    T.Add5Seconds();
    T.PrintTime();
    T.Add5Seconds();
    T.PrintTime();
    cout << T.GetAllInSeconds();
}

