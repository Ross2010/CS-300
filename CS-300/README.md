Reflection Journal 

What was the problem you were solving in the projects for this course?
The goal of the project was to build an efficient advising tool for the Computer Science department at ABCU. The system needed to manage a large set of course data, read it from a CSV file, and allow advisors to view a complete, alphabetically sorted list of courses as well as search for specific courses. It also needed to correctly display prerequisite chains for each course, which added another layer of complexity.

How did you approach the problem? Consider why data structures are important to understand.
For Project Two, I decided to use a Binary Search Tree (BST). Understanding data structures is important because they directly affect how efficient and scalable a program is. A poor choice can slow everything down, while the right one can make the system much more effective.

The BST worked well for this project because it provides efficient average-case search performance of O(log n) and automatically keeps the data sorted. This made it easy to display the course catalog in order using an in-order traversal, without needing an extra sorting step. That helped keep the program both efficient and clean.

How did you overcome any roadblocks you encountered while going through the activities or project?
I ran into a couple of issues during the project. One problem was handling file names with spaces, like “CS 300 Input.csv,” which caused errors when using standard input methods. I fixed this by using getline() instead of cin, and clearing the input buffer with cin.ignore().

How has your work on this project expanded your approach to designing software and developing programs?
This project changed the way I think about programming. Instead of just focusing on making the code work, I started thinking more about efficiency and scalability. By analyzing the time and space complexity of the BST, I became more aware of how important early design decisions are, especially when working with larger data sets.

How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
My coding style has become more structured and intentional. I now focus more on writing modular functions, using consistent naming, and adding clear comments to make the code easier to follow. I also used a struct to represent courses, which makes the program easier to extend if new fields need to be added later. Overall, I’m now more focused on writing code that not only works, but is also easier to maintain and build on in the future.