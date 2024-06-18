#include <bits/stdc++.h>
using namespace std;

struct Course {
    string name;
    string time;
    
    Course() : name(""), time("") {}
    Course(string n, string t) : name(n), time(t) {}
};

class Schedule {
private:
    vector<vector<Course>> week;
    
public:
    Schedule() {
        week.resize(6); // 6 days, from Saturday to Thursday
        for (int i = 0; i < 6; ++i) {
            week[i].resize(24); // 24 hours a day
        }
    }
    
    void addCourse(int day, int hour, const Course& course) {
        if (day < 0 || day >= 6 || hour < 0 || hour >= 24) {
            cout << "Invalid day or time!" << endl;
            return;
        }
        week[day][hour] = course;
    }
    
    void displaySchedule() const {
        const string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        for (int i = 0; i < 6; ++i) {
            cout << days[i] << ":" << endl;
            for (int j = 0; j < 24; ++j) {
                if (!week[i][j].name.empty()) {
                    cout << "  " << j << ":00 - " << week[i][j].name << " at " << week[i][j].time << endl;
                }
            }
        }
    }
};

int main() {
    Schedule schedule;
    string choice;
    int day, hour;
    string name, time;
    
    while (true) {
        cout << "Enter 'add' to add a course, 'show' to display the full schedule, or 'exit' to quit: ";
        cin >> choice;
        
        if (choice == "add") {
            cout << "Enter day (0 for Saturday, 1 for Sunday, ..., 5 for Thursday): ";
            cin >> day;
            cout << "Enter hour (0-23): ";
            cin >> hour;
            cout << "Enter course name: ";
            cin.ignore(); // to clear the newline character from the buffer
            getline(cin, name);
            cout << "Enter course time: ";
            getline(cin, time);
            schedule.addCourse(day, hour, Course(name, time));
        } else if (choice == "show") {
            schedule.displaySchedule();
        } else if (choice == "exit") {
            break;
        } else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
    
    return 0;
}
