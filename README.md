# PERSONAL STUDY MANAGER

## 1. Requirement
* Track student's learning subjects (time, weekdays, study period from beginning to end date, Class code, Teacher's info, Attendee's tracking progress, credits, semester)
* Calculate scores (tests, total, average, GPA, scoring letters, etc)
* Adjust list of studying subjects in that semester 
* Display list of asigned subjects in semesters

## 2. Project scope
* Track student's learning subjects:
    - Time: hour and minutes
    - Weekday: Monday, Tuesday , ... Sunday
    - Study period from beginning to end date
        - Course's beginning date (dd/mm/yyyy)
        - Course's final date (dd/mm/yyyy)
    - Class code
    - Teacher's info:
        - Name
        - Contact info:
            - Phone number
            - Email address    
    - Attendee's tracking progress
        - Numbers of days attending classes
        - Numbers of days absent from class      
        - Total percentage of days attending
    - Credits
    - Class in semester   
* Calculate scores:
    - In tests(individual test in total of 3 or 4 tests taken)
    - In total of all tests
    - In average of all tests
    - In GPA
    - In scoring letters (A/A+ to F)
* Adjust list of studying subjects in that semester:
    - Add new subjects
    - Remove subjects that will not attend(eligible 'til that subject starts)
    - Update information of subjects(in case of incorrect info)
* Display list of asigned subjects in semesters

## 3. Versions

### v0.0.3
#### 1. Requirements: RC003
- Tôi muốn theo dõi chuyên cần: nhập số buổi có mặt và số buổi vắng, và xem tỷ lệ chuyên cần của môn.

#### 2. Clarification
- Focus / Scope: Track the number of total and absent sessions for a subject and display
- Input:
    - Total Sessions (guaranteed to be integer, range [0; 30])
    - Absent Sessions (guaranteed to be integer, range [0; 30])
- Output: 
    - Percentage of Non-attendance rate (r) (real, range [0; 100], precision of 2 digits after decimal points, unit: %); display format: "Non - Attendance Rate: XX.XX%" (e.g., 90.00%).
- Business rules:
    - Total sessions >= absent sessions
    - Formula: r = (a / t )* 100.0 
- Explicit float casting is mandatory to prevent integer division precision loss. 
- Edge cases: 
    - Input: t < 0 or t - a < 0 (Total - Absent < 0) or negative numbers (e.g., t = -2). 
    - Expected Response: Display "Error: Not valid, retry." and prompt user to re-enter.
- Out of scope: Automatic exam disqualification warning (in case of absent sessions(a) is exceed the limit of maxmimum absent sessions required by the teacher)

### v0.0.2
#### 1. Requirements: RC002
- Tôi muốn ghi nhận học kỳ và lịch học của môn. Một môn có thể học nhiều buổi trong tuần, mỗi buổi có giờ bắt đầu và giờ kết thúc, và giờ kết thúc phải sau giờ bắt đầu. Lịch hiển thị rõ ràng, dễ đọc.

#### 2. Clarification
- Focus / Scope: Record semester, weekday, start time, and end time.  
- Input:
    - Semester (guaranteed to be integer, range (0; +inf))
    - Number of studying days per week ( guaranteed to be integer, range [1; 3])
    - For each study days per week include:
        -  Weekday (guaranteed to be integer, range [2; 8]) (2 = Monday, 3 = Tuesday, ..., 8 = Sunday)
        -  Start time / End time: 
            - Hour (guaranteed to be integer , range [0; 23])
            - Minute (guaranteed to be integer, range [0; 59])
- Business rules: End time > Start time. 
- Output: Display timetable in formatted 24-hour string (HH:MM). 
- Edge cases:
    - Input: End time <= Start time (e.g., Start 10:00, End 09:00). 
    - Expected Response: Display "Error: not valid, pls retry." and ask to re-enter. 
- Out of scope: Dynamic conflict checking with other subjects.

### v0.0.1

#### 1. Requirements: RPM001
- Mục tiêu: khi nhập sai kiểu (ví dụ gõ chữ thay vì số), chương trình báo lỗi và yêu cầu nhập lại, không bị kẹt hay lặp mãi.

#### 2. Clarification
- Focus / Scope: Handle non-numeric / invalid input types. 
- Constraints: Input must be a valid integer. 
- Input: Credits (guaranteed to be integer, range [0; 20])(the program will automatically handle with the character the user input)
- Business rules: Clear buffer when input stream fails(Input: String or char (e.g., "abc") )
-  Edge cases:
    - Input: String or char (e.g., "abc") 
    - Expected Response: Display "Credits only from 0 to 20, please retry" and prompt user to re-enter. 
- Out of scope: Dynamic memory allocation for input buffer.

### v0.0.0

#### 1. Requirements
- Manage only a single subject
- Manage single subject's credits
#### 2. Clarification
- No need to display any other subject's info(Focus solely on 1)
- Input: Credits (integer, range [0; 20])
- Add new credits
- Display the credits of that subject
- Out of scope:
    - No name of the subjects
    - Remove the credits
    - Update the credits
#### 3. Idea & Design
- UI: console
- UI flow: 
    - Prompt user: Insert numbers of credits
    - After insert, display numbers of credits
#### 4. Implementation
- [main.c](main.c)
#### 5. Testing 
| Scenario | Input | Output |
| :--- | :--- | :--- |
| 1 | 0 | 0 |
| 2 | 20 | 20 |
| 3 | 12 | 12 |

#### 6. Review
