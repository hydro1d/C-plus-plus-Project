#include <bits/stdc++.h>
using namespace std;

struct Course {
    string name;
    float start_time;
    float end_time;

    Course() : name(""), start_time(0.0), end_time(0.0) {}
    Course(string n, float start, float end) : name(n), start_time(start), end_time(end) {}
};

class Schedule {
private:
    vector<vector<Course>> week;

public:
    Schedule() {
        week.resize(6); // 6 days  from Saturday(0) to Thursday(5)
        for (int i = 0; i < 6; ++i) {
            week[i].resize(24); // 24 hours/day
        }
    }

    void addCourse(int day, float start_time, float end_time, const Course& course) {
        if (day < 0 || day >= 6 || start_time < 0.0 || start_time >= 24.0 || end_time < 0.0 || end_time >= 24.0) {
            cout << "Invalid day or time!" << endl;
            return;
        }
        int startHour = static_cast<int>(start_time);
        week[day][startHour] = course;
    }

    void displaySchedule() const {
        const string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        for (int i = 0; i < 6; ++i) {
            cout << days[i] << ":" << endl;
            for (int j = 0; j < 24; ++j) {
                if (!week[i][j].name.empty()) {
                    cout << fixed << setprecision(2)
                         << "  " << week[i][j].start_time << " - " << week[i][j].end_time
                         << " : " << week[i][j].name << endl;
                }
            }
        }
    }
};

int main() {
    Schedule schedule;
    string choice;
    int day;
    float start_time, end_time;
    string name;

    while (true) {
        cout << "Enter 'add' to add a course, 'show' to display the full schedule, or 'exit' to quit: ";
        cin >> choice;

        if (choice == "add") {
            cout << "Enter day (0 for Saturday, 1 for Sunday, ..., 5 for Thursday): ";
            cin >> day;
            cout << "Enter start time (example: 10.15 for 10:15 AM): ";
            cin >> start_time;
            cout << "Enter end time (example: 11.45 for 11:45 AM): ";
            cin >> end_time;
            cout << "Enter course name: ";
            cin.ignore(); // clear the newline character from the buffer
            getline(cin, name);
            schedule.addCourse(day, start_time, end_time, Course(name, start_time, end_time));
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
