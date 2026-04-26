Vectors are simple and easy to implement. However, searching for a course requires scanning the entire list, which results in O(n) time. Additionally, sorting is required before printing, adding extra overhead.
Analysis
•	Load Data in O(n)
•	Slow search O(n)
•	Print sorted in O(n log n)
•	Requires sorting before printing
Pseudocode
DEFINE STRUCTURE Course
    STRING courseNumber
    STRING courseTitle
    LIST prerequisites
END STRUCTURE
FUNCTION LoadData(fileName)
    CREATE empty list courses
    OPEN file
    IF file cannot be opened
        PRINT "Error: File not found"
        RETURN courses
    FOR EACH line in file
        SPLIT line by comma into tokens
        TRIM whitespace from tokens
        IF number of tokens < 2
            PRINT "Invalid format"
            CONTINUE

        CREATE Course object
        SET courseNumber = tokens[0]
        SET courseTitle = tokens[1]
        FOR i from 2 to end of tokens
            ADD tokens[i] to prerequisites
        ADD Course to courses
    CLOSE file
    RETURN courses
END FUNCTION
FUNCTION PrintAllCourses(courses)
    SORT courses by courseNumber
    FOR EACH course in courses
        PRINT course.courseNumber, course.courseTitle
END FUNCTION
FUNCTION PrintCourse(courses, courseNumber)
    FOR EACH course in courses
        IF course.courseNumber == courseNumber
            PRINT course.courseTitle
            PRINT prerequisites
            RETURN
    PRINT "Course not found"
END FUNCTION
MAIN PROGRAM

DECLARE courses list

WHILE user does not exit
    DISPLAY menu:
        1. Load Data
        2. Print Course List
        3. Print Course
        9. Exit
    GET choice
    IF choice == 1
        courses = LoadData(fileName)
    ELSE IF choice == 2
        CALL PrintAllCourses(courses)
    ELSE IF choice == 3
        GET courseNumber
        CALL PrintCourse(courses, courseNumber)
    ELSE IF choice == 9
        EXIT
END WHILE

Evaluation of Data Structures
Vectors are simple and easy to implement. However, searching for a course requires scanning the entire list, which results in O(n) time. Additionally, sorting is required before printing, adding extra overhead.
