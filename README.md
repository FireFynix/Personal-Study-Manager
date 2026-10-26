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
