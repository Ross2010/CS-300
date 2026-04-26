Hash tables provide very fast search performance with average O(1) lookup time. However, they do not maintain order, so sorting is required before printing, which increases complexity.
•	Fast search O(1)
•	Load data O(n)
•	Print sorted O(n log n)
•	No inherent order 
•	Requires sorting for output
Hash Table Pseudocode

FUNCTION LoadData(fileName, hashTable)
    OPEN file
    IF file cannot be opened
        PRINT "Error: File not found"
        RETURN
    FOR EACH line in file
        SPLIT line into tokens
        TRIM whitespace
        IF tokens < 2
            PRINT "Invalid format"
            CONTINUE
        CREATE Course object
        INSERT course into hashTable
    CLOSE file
END FUNCTION
FUNCTION PrintAllCourses(hashTable)
    CREATE empty list tempList
    FOR EACH bucket in hashTable
        FOR EACH node in bucket
            ADD node.course to tempList
    SORT tempList by courseNumber
    FOR EACH course in tempList
        PRINT course.courseNumber, course.courseTitle
END FUNCTION

FUNCTION PrintCourse(hashTable, courseNumber)
    course = hashTable.Search(courseNumber)
    IF course exists
        PRINT course.courseTitle
        PRINT prerequisites
    ELSE
        PRINT "Course not found"
END FUNCTION

MAIN PROGRAM
DECLARE hashTable
WHILE user does not exit
    DISPLAY menu
    GET choice
    IF choice == 1
        CALL LoadData(fileName, hashTable)
    ELSE IF choice == 2
        CALL PrintAllCourses(hashTable)
    ELSE IF choice == 3
        GET courseNumber
        CALL PrintCourse(hashTable, courseNumber)
    ELSE IF choice == 9
        EXIT
END WHILE

Evaluation of Data Structures
Hash tables provide very fast search performance with average O(1) lookup time. However, they do not maintain order, so sorting is required before printing, which increases complexity.
