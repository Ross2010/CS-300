Binary Search Tree
Binary Search Trees maintain data in sorted order, allowing efficient traversal and searching. Printing courses in order requires only an in-order traversal, which is O(n). However, performance may degrade if the tree becomes unbalanced. Maintains sorted order .
Analysis
•	Search in O(log n)
•	Load data in O(n log n)
•	Print sorted in O(n)
•	Can degrade if unbalanced

Pseudocode
FUNCTION LoadData(fileName, bst)
    OPEN file
    IF file cannot be opened
        PRINT "Error: File not found"
        RETURN
    FOR EACH line in file
        SPLIT line into tokens
        TRIM whitespace
        IF number of tokens < 2
            PRINT "Invalid format"
            CONTINUE
        CREATE Course object
        INSERT course into BST
    CLOSE file
END FUNCTION
FUNCTION PrintAllCourses(bst)
    CALL InOrderTraversal(bst.root)
FUNCTION InOrderTraversal(node)
    IF node is NULL
        RETURN
    InOrderTraversal(node.left)
    PRINT node.course.courseNumber, node.course.courseTitle
    InOrderTraversal(node.right)
END FUNCTION
FUNCTION PrintCourse(bst, courseNumber)
    node = bst.Search(courseNumber)
    IF node exists
        PRINT node.course.courseTitle
        PRINT prerequisites
    ELSE
        PRINT "Course not found"
END FUNCTION

MAIN PROGRAM
DECLARE bst
WHILE user does not exit
    DISPLAY menu:
        1. Load Data
        2. Print Course List
        3. Print Course
        9. Exit
    GET choice
    IF choice == 1
        CALL LoadData(fileName, bst)
    ELSE IF choice == 2
        CALL PrintAllCourses(bst)
    ELSE IF choice == 3
        GET courseNumber
        CALL PrintCourse(bst, courseNumber)
    ELSE IF choice == 9
        EXIT
END WHILE

Evaluation of Data Structures
Binary Search Trees maintain data in sorted order, allowing efficient traversal and searching. Printing courses in order requires only an in-order traversal, which is O(n). However, performance may degrade if the tree becomes unbalanced.
