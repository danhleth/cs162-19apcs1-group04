#include "header.h"

// [13]
void create_years_semesters(Semester* pHead)
{
    system("cls");
    cout << ">>> Create Academic years and Semester <<<" << endl;
    string y, s, years, semester;
    int n;
    string str;
    cout << "Years: ";
    cin >> y;
    cout << "Semester: ";
    cin >> s;
    ifstream fin;
    Semester* cur;
    fin.open("data/Semester.txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Semester;
                fin >> pHead->years;
                fin >> pHead->semester;
                pHead->pNext = NULL;
                cur = pHead;
            }
            else {
                cur->pNext = new Semester;
                cur = cur->pNext;
                fin >> cur->years;
                fin >> cur->semester;
                cur->pNext = NULL;
            }
            if (cur->years == y && cur->semester == s) {
                cout << "Semester exists! Cannot add new Semester!" << endl;
                fin.close();
                system("pause");
                return;
            }
        }
        fin.close();
    }
    cur->pNext = new Semester;
    cur = cur->pNext;
    cur->years = y;
    cur->semester = s;
    cur->pNext = NULL;
    ofstream fout;
    fout.open("data/Semester.txt", ios::out);
    fout << ++n << endl;
    cur = pHead;
    while (cur) {
        if (cur->pNext) {
            fout << cur->years << endl;
            fout << cur->semester << endl << endl;
        }
        else {
            fout << cur->years << endl;
            fout << cur->semester;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "New semester is added successfully!" << endl;
    system("pause");
}

void delete_years_semesters(Semester* pHead)
{
    system("cls");
    int n;
    cout << ">>> Delete Academic Years and Semester <<<" << endl;
    Semester* cur;
    string y, s;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    fin >> n;
    for (int i = 0; i < n; i++) {
        if (!pHead) {
            pHead = new Semester;
            fin >> pHead->years;
            fin >> pHead->semester;
            pHead->pNext = NULL;
            cur = pHead;
        }
        else {
            cur->pNext = new Semester;
            cur = cur->pNext;
            fin >> cur->years;
            fin >> cur->semester;
            cur->pNext = NULL;
        }
        cout << "Years: " << cur->years << endl;
        cout << "Semester: " << cur->semester << endl;
        cout << endl;
    }
    fin.close();
    cout << "Input Academic years: ";
    cin >> y;
    cout << "Input semester: ";
    cin >> s;
    Semester* tmp = nullptr;
    if (pHead && pHead->years == y && pHead->semester == s) {
        tmp = pHead;
        pHead = pHead->pNext;
    }
    else {
        cur = pHead;
        while(cur->pNext) {
            if (cur->pNext->years == y && cur->pNext->semester == s) {
                tmp = cur->pNext;
                cur->pNext = cur->pNext->pNext;
                break;
            }
            cur = cur->pNext;
        }
    }
    if (!tmp) {
        cout << "Semester does not exist!" << endl;
        system("pause");
        return;
    }
    delete tmp;
    cur = pHead;
    ofstream fout;
    fout.open("data/Semester.txt", ios::out);
    fout << --n << endl;
    while (cur) {
        if (cur->pNext) {
            fout << cur->years << endl;
            fout << cur->semester << endl << endl;
        }
        else {
            fout << cur->years << endl;
            fout << cur->semester;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "Delete course successfully!" << endl;
    system("pause");
}

void update_years_semesters(Semester* pHead)
{
    system("cls");
    int n;
    cout << ">>> Update Academic Years and Semester <<<" << endl;
    Semester* cur;
    string y, s;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    fin >> n;
    for (int i = 0; i < n; i++) {
        if (!pHead) {
            pHead = new Semester;
            fin >> pHead->years;
            fin >> pHead->semester;
            pHead->pNext = NULL;
            cur = pHead;
        }
        else {
            cur->pNext = new Semester;
            cur = cur->pNext;
            fin >> cur->years;
            fin >> cur->semester;
            cur->pNext = NULL;
        }
        cout << "Years: " << cur->years << endl;
        cout << "Semester: " << cur->semester << endl;
        cout << endl;
    }
    fin.close();
    cout << "Input Academic years: ";
    cin >> y;
    cout << "Input semester: ";
    cin >> s;
    Semester* tmp = nullptr;
    if (pHead && pHead->years == y && pHead->semester == s) {
        tmp = pHead;
        pHead = pHead->pNext;
    }
    else {
        cur = pHead;
        while(cur->pNext) {
            if (cur->pNext->years == y && cur->pNext->semester == s) {
                tmp = cur->pNext;
                break;
            }
            cur = cur->pNext;
        }
    }
    if (!tmp) {
        cout << "Semester does not exist!" << endl;
        system("pause");
        return;
    }
    cout << endl << "Found your semester!" << endl;
    cout << "Input new Academic years: ";
    cin >> y;
    cout << "Input new semester: ";
    cin >> s;
    tmp->years = y;
    tmp->semester = s;
    cur = pHead;
    ofstream fout;
    fout.open("data/Semester.txt", ios::out);
    fout << n << endl;
    while (cur) {
        if (cur->pNext) {
            fout << cur->years << endl;
            fout << cur->semester << endl << endl;
        }
        else {
            fout << cur->years << endl;
            fout << cur->semester;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "Update course successfully!" << endl;
    system("pause");
}

void view_years_semesters()
{
    system("cls");
    cout << ">>> View all Academic Years and Semester <<<" << endl;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    int n;
    string s, y;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> y;
        fin >> s;
        cout << "Years: " << y << endl;
        cout << "Semester: " << s << endl;
    }
    system("pause");
    return;
}

void CRUD_years_semesters()
{
    CASE_13: {
        system("cls");
        Semester* pHead = NULL;
        cout << "[1]: Create." << endl;
        cout << "[2]: Update." << endl;
        cout << "[3]: Delete." << endl;
        cout << "[4]: View." << endl;
        cout << "[0]: Back." << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                create_years_semesters(pHead);
                goto CASE_13;
            }
            case 2:
            {
                update_years_semesters(pHead);
                goto CASE_13;
            }
            case 3:
            {
                delete_years_semesters(pHead);
                goto CASE_13;
            }
            case 4:
            {
                view_years_semesters();
                goto CASE_13;
            }
            case 0:
            {
                return;
            }
            default:
            {
                cout << "Wrong! Choose again!" << endl;
                system("pause");
                goto CASE_13;
            }
        }
    }
}

// [14]
string convertDate(string date) {
    stringstream ss(date);
    string token[3];
    int i = 0;
    while(getline(ss, token[i], '/')) {
        i++;
    }
    if (token[0].size() == 1) token[0] = '0' + token[0];
    if (token[1].size() == 1) token[1] = '0' + token[1];
    token[2] = "20" + token[2];
    return token[2] + " " + token[0] + " " + token[1];
}
void importCourses()
{
    cout << ">>> Import Course to Semester <<<" << endl;
    ifstream fin;
    fin.open("data/Semester.txt");
    if (!fin.is_open()) return;
    int n;
    string y, s, years, semester, c, Class, file;
    bool check = false;
    cout << "Input Academic Years: ";
    cin >> y;
    cout << "Input Semester: ";
    cin >> s;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> years;
        fin >> semester;
        if (s == semester && years == y) {
            check = true;
            break;
        }
    }
    fin.close();
    if (!check) {
        cout << "Semester does not exist!" << endl;
        system("pause");
        return;
    }
    cout << "Input class: ";
    cin >> c;
    fin.open("data/Class.txt");
    if (!fin.is_open()) return;
    check = false;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> Class;
        if (Class == c) {
            check = true;
            break;
        }
    }
    fin.close();
    if (!check) {
        cout << "Class does not exist!" << endl;
        system("pause");
        return;
    }
    cout << "Input file: ";
    cin >> file;
    fin.open("data/" + file);
    string line, header;
    if(!fin.is_open()) return;
    string id;
    getline(fin, header, '\n');
    Course* pHead = nullptr, *cur;
    while(fin.good()) {
        getline(fin, id, ',');
        if (!pHead) {
            pHead = new Course;
            getline(fin, pHead->CourseId, ',');
            getline(fin, pHead->CourseName, ',');
            getline(fin, pHead->Class, ',');
            getline(fin, pHead->LecturerUsername, ',');
            getline(fin, pHead->LecturerName, ',');
            getline(fin, pHead->LecturerDegree, ',');
            getline(fin, pHead->LecturerGender, ',');
            getline(fin, pHead->StartDate, ',');
            getline(fin, pHead->EndDate, ',');
            getline(fin, pHead->DayOfWeek, ',');
            getline(fin, pHead->StartHour, ',');
            getline(fin, pHead->StartMinutes, ',');
            getline(fin, pHead->EndHour, ',');
            getline(fin, pHead->EndMinutes, ',');
            getline(fin, pHead->room, '\n');
            pHead->pNext = NULL;
            cur = pHead;
        }
        else {
            cur->pNext = new Course;
            cur = cur->pNext;
            getline(fin, cur->CourseId, ',');
            getline(fin, cur->CourseName, ',');
            getline(fin, cur->Class, ',');
            getline(fin, cur->LecturerUsername, ',');
            getline(fin, cur->LecturerName, ',');
            getline(fin, cur->LecturerDegree, ',');
            getline(fin, cur->LecturerGender, ',');
            getline(fin, cur->StartDate, ',');
            getline(fin, cur->EndDate, ',');
            getline(fin, cur->DayOfWeek, ',');
            getline(fin, cur->StartHour, ',');
            getline(fin, cur->StartMinutes, ',');
            getline(fin, cur->EndHour, ',');
            getline(fin, cur->EndMinutes, ',');
            getline(fin, cur->room, '\n');
            cur->pNext = nullptr;
        }
    }
    fin.close();
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-Schedule-" + Class + ".txt");
    cur = pHead;
    fout << id << endl;
    while(cur) {
        fout << cur->CourseId << endl;
        fout << cur->CourseName << endl;
        fout << cur->Class << endl;
        fout << cur->LecturerUsername << endl;
        fout << cur->LecturerName << endl;
        fout << cur->LecturerDegree << endl;
        fout << (cur->LecturerGender == "Male" ? male : female) << endl;
        fout << convertDate(cur->StartDate) << endl;
        fout << convertDate(cur->EndDate) << endl;
        if (cur->DayOfWeek == "MON") fout << MON << endl;
        else if (cur->DayOfWeek == "TUE") fout << TUE << endl;
        else if (cur->DayOfWeek == "WED") fout << WED << endl;
        else if (cur->DayOfWeek == "THU") fout << THU << endl;
        else if (cur->DayOfWeek == "FRI") fout << FRI << endl;
        else fout << SAT << endl;
        fout << cur->StartHour << " " << cur->StartMinutes << endl;
        fout << cur->EndHour << " " << cur->EndMinutes << endl;
        if (cur->pNext) {
            fout << cur->room << endl << endl;
        }
        else {
            fout << cur->room;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "Import courses successfully!" << endl;
    system("pause");
}

void addCourseManually()
{
    cout << ">>> Manually add a new course. <<<" << endl;
    ifstream fin;
    int n;
    bool check = false;
    string Class, y, s, years, semester;
    CHECK_SEMESTER: {
        fin.open("data/Semester.txt");
        if (!fin.is_open()) return;
        cout << "Input Academic Years: ";
        cin >> y;
        cout << "Input Semester: ";
        cin >> s;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> years;
            fin >> semester;
            if (s == semester && years == y) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Semester does not exist!" << endl;
            system("pause");
            goto CHECK_SEMESTER;
        }
    }
    Course* pHead = nullptr, *cur, *tmp = new Course;
    cout << "Input Course ID: ";
    cin >> tmp->CourseId;
    cout << "Input Course Name: ";
    cin.ignore(1000, '\n');
    getline(cin, tmp->CourseName, '\n');
    CHECK_CLASS: {
        cout << "Input class: ";
        cin >> tmp->Class;
        fin.open("data/Class.txt");
        if (!fin.is_open()) return;
        check = false;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> Class;
            if (Class == tmp->Class) {
                check = true;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Class does not exist!" << endl;
            system("pause");
            goto CHECK_CLASS;
        }
    }
    CHECK_LECTURER: {
        cout << "Input Lecturer Username: ";
        cin >> tmp->LecturerUsername;
        fin.open("data/Lecturer.txt");
        fin >> n;
        string lecturer;
        check = false;
        for (int i = 0; i < n; i++) {
            fin >> lecturer;
            if (lecturer != tmp->LecturerUsername) {
                // Skip lecturer's info
                fin >> lecturer;
                fin.ignore(1000, '\n');
                getline(fin, lecturer, '\n');
                fin >> lecturer;
                fin >> lecturer;
            }
            else {
                check = true;
                fin >> lecturer;
                fin.ignore(1000, '\n');
                getline(fin, tmp->LecturerName, '\n');
                fin >> tmp->LecturerDegree;
                fin >> tmp->LecturerGender;
                break;
            }
        }
        fin.close();
        if (!check) {
            cout << "Lecturer does not exist!" << endl;
            system("pause");
            goto CHECK_LECTURER;
        }
    }
    cout << "Input Start Date: ";
    cin.ignore(1000, '\n');
    getline(cin, tmp->StartDate);
    cout << "Input End Date: ";
    getline(cin, tmp->EndDate);
    cout << "Input Day of Week (2-7): ";
    cin >> tmp->DayOfWeek;
    cout << "Input Start Time: ";
    cin >> tmp->StartHour >> tmp->StartMinutes;
    cout << "Input End Time: ";
    cin >> tmp->EndHour >> tmp->EndMinutes;
    cout << "Input room: ";
    cin >> tmp->room;
    tmp->pNext = nullptr;
    fin.open("data/" + y + "-" + s + "-Schedule-" + tmp->Class + ".txt");
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            if (!pHead) {
                pHead = new Course;
                fin >> pHead->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, pHead->CourseName, '\n');
                fin >> pHead->Class;
                fin >> pHead->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, pHead->LecturerName, '\n');
                fin >> pHead->LecturerDegree;
                fin >> pHead->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, pHead->StartDate, '\n');
                getline(fin, pHead->EndDate, '\n');
                fin >> pHead->DayOfWeek;
                fin >> pHead->StartHour >> pHead->StartMinutes;
                fin >> pHead->EndHour >> pHead->EndMinutes;
                fin >> pHead->room;
                pHead->pNext = nullptr;
                cur = pHead;
            }
            else {
                cur->pNext = new Course;
                cur = cur->pNext;
                fin >> cur->CourseId;
                fin.ignore(1000, '\n');
                getline(fin, cur->CourseName, '\n');
                fin >> cur->Class;
                fin >> cur->LecturerUsername;
                fin.ignore(1000, '\n');
                getline(fin, cur->LecturerName, '\n');
                fin >> cur->LecturerDegree;
                fin >> cur->LecturerGender;
                fin.ignore(1000, '\n');
                getline(fin, cur->StartDate, '\n');
                getline(fin, cur->EndDate, '\n');
                fin >> cur->DayOfWeek;
                fin >> cur->StartHour >> cur->StartMinutes;
                fin >> cur->EndHour >> cur->EndMinutes;
                fin >> cur->room;
                cur->pNext = nullptr;
            }
        }
        fin.close();
    }
    cur->pNext = new Course;
    cur->pNext = tmp;
    fin.close();
    ofstream fout;
    fout.open("data/" + y + "-" + s + "-Schedule-" + tmp->Class + ".txt");
    cur = pHead;
    fout << ++n << endl;
    while(cur) {
        fout << cur->CourseId << endl;
        fout << cur->CourseName << endl;
        fout << cur->Class << endl;
        fout << cur->LecturerUsername << endl;
        fout << cur->LecturerName << endl;
        fout << cur->LecturerDegree << endl;
        fout << cur->LecturerGender << endl;
        fout << cur->StartDate << endl;
        fout << cur->EndDate << endl;
        fout << cur->DayOfWeek << endl;
        fout << cur->StartHour << " " << cur->StartMinutes << endl;
        fout << cur->EndHour << " " << cur->EndMinutes << endl;
        if (cur->pNext) {
            fout << cur->room << endl << endl;
        }
        else {
            fout << cur->room;
        }
        cur = cur->pNext;
    }
    fout.close();
    cout << "Add new course successfully!" << endl;
    system("pause");
}
