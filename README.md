# **Algoritmic Analysis Course Projects** [![made-with-c](https://img.shields.io/badge/Made%20with-C-1f425f.svg)]()

Welcome to the repository. Here, I will be sharing the assignments I completed for my 2nd and 3rd year courses, Data Structures & Algorithms and Algorithmic Analysis. These are small problem solving exercises to better understand the concepts and they are done in C language. You will also see a .clang-format file in this repository. This is a file I created for myself to override VSCode's default formatting rules. You can copy and paste that file to your workspace folder if you also hate how the formatting pushes your parentheses to a new line.

# Problems Solved In This Repository

- Cache Buffer System
- Implementing the Boyer-Moore Horspool Algorithm
- Creating a Huffman Tree
- Run Length Encoding
- Creating a Von Neumanns Neighbourhood Matrix with a given N value
- Calculating the closest points read from a file, with divide and conquer method
- Calculating a combination of ads to earn maximum possible revenue from a given advertisement times and prices table, with dynamic programming
- Choosing flights based on a user choice of transfer limit, duration limit and/or price limit, with the flight informations being read from a file and then turned into a graph
- Implementing a hash table with open addressing double hashing, taking string-typed IDs as keys

# Every Problem Explained

## _Closest Points (Completed)_

sample.txt contains N random points on a cartesian plane. The program mmet read these points and find the closest pair following the Divide and Conquer principle. We are allowed to assume all points in the file have different coordinates.

Program executes in these steps:

1. reading the coordinates in the file “sample.txt”
2. sort the coordinates increasing by x value
3. start the divide and conquer execution by dividing the plane into two from the median value of x coordinates
4. keep dividing until point number is 2 < n < 3, then brute force it.
5. coming back from the recursion, in both sides of the median line, compare the closest pairs from dlow and dhigh, and pick the closer one. so now **_dmin = min(dlow, dhigh)_**
6. but the closest point pair doesn't have to be on the same side of the median line. it could be on different sides. it should be enough to jmet check the points that are closer in perpendicular to the median line then twice the dmin value. if a closer pair is found all values are updated.

## _Von Neuman (Completed)_

Program takes an N value from the user to create and print a matrix which obeys the [Von Neumann's Neighborhood rule](https://mathworld.wolfram.com/vonNeumannNeighborhood.html).

N = 0 would indicate that no cells are full per rule, so the program creates a 3x3 matrix. For N = 5 it would be a 5x5. Matrix must be dynamically allocated. Then program will print said matrix with full cells represented by '1' and empty cells represented by '0'.

## _Ad Revenue (Completed)_

A website has to choose between an N number of advertisements available, based on the advertisements starting times, durations and revenue they will bring as input. Based on the starting time and duration, some might ads overlap.

The program calculates the optimal combination of ads that do not overlap with airtime and bring the maximum revenue. This is done by a dynamic programming principle.
Basically, for the j. ad:

- we will either choose to add the ad plus those that aired before and that do not overlap with it,
- or we will choose not to add it and then the max revenue for that step would be the one on (j-1). step.

Once j reaches the final step, we will have the maximum revenue we need.

## _Flight Graph Problem (In Progress)_

A company that sells plane tickets wants to develop an efficient algorithm to show their users available paths between the cities they wish to fly between. This company gives available flights information, in the shape of a txt file that contains source city, destination city, duration as hour, duration as minute, and price of the flight, in that order.
Users that wish to see flights available must:

- Select two cities to fly between
- Select the maximum amount of transfers they'd allow, or if they want to allow at all (which must be kept in control since user should not be able to enter less than 0 transfers or more than the amount of cities)
- Select if they want to add any additional constraints such as maximum duration, or price, and enter these if yes
  The program aims to show the user all available paths.

This is how the program executes:

- First the program reads the file and loads all the info to a structure array in the type of a struct flights_table
- It finds every single city and puts it into a strings array (a char matrix) and uses row numbers as index to represent cities in the adjacency matrix that will be constructed. These indexes are written to the flights_table also
- Because it makes sense for cities to represent nodes of the graph and flights to represent edges, adjacency matrix is formed and filled with the info from the struct array and the city matrix.
- After user enters preferences, DFS is performed according to these preferences. It should be noted that the program adds an hour to the total path duration every time a transfer occurs in a path.
- After the initial prep is done, program enters an endless loop for the user to quit only when they wish to.

## _Hashing Program (Completed)_

A fully functional hashing program that uses open addressing with double hashing. It takes keys in the form of string-typed IDs (e.g., "12345") and stores person records containing name, surname, birth year, and city.

This is how the program executes:

- The program reads person records from "test.txt", each line containing an ID, name, surname, year, and city
- Each ID string is converted to a numeric key using Horner's method
- Two hash functions h1 and h2 are used: h1(key) = key mod 97 and h2(key) = 1 + (key mod 96)
- Double hashing is applied: hash(key, i) = (h1(key) + i * h2(key)) mod 97
- On collision, the probe sequence increments i until an empty slot is found
- The program supports insert, find, and delete (lazy deletion with a `deleted` flag) operations
- After loading all records, the hash table contents are printed

## _Cache Buffer System (In Progress)_

A cache buffer system implemented using a doubly linked list. The program simulates a cache that stores strings with a limited capacity and a threshold for access frequency.

This is how the program executes:

- The user chooses to either read data from a file or enter strings manually
- Each incoming string is searched for in the linked list
- If found, its access counter is incremented. If the counter exceeds the threshold, the node is evicted from the cache
- If not found, the string is inserted at the front of the list. If inserting causes the list to exceed capacity, the least recently used (last) node is removed
- The program prints the final state of the cache buffer

## _Implementing the Boyer-Moore Horspool Algorithm (Completed)_

An implementation of the Boyer-Moore-Horspool string matching algorithm for searching and replacing patterns in text read from a file.

This is how the program executes:

- The program reads a text string from a user-specified file
- The user enters a pattern to search for and a replacement string
- The user selects whether the search should be case sensitive or not
- A bad match table is constructed from the pattern, mapping each character to its shift value
- The algorithm scans from right to left within a window aligned to the text, shifting by the bad match value on mismatch
- All occurrences of the pattern are found and their positions recorded
- The pattern occurrences are then replaced with the replacement string in the text
- The modified text and the number of replacements are printed

## _Creating a Huffman Tree (Completed)_

A program that builds a Huffman Tree from a user-entered string, demonstrating the greedy algorithm approach to optimal prefix-free encoding.

This is how the program executes:

- The user enters a text string
- The program counts the frequency of each unique character using a linked list
- The linked list is sorted by frequency using insertion sort
- The two nodes with the lowest frequencies are repeatedly extracted from the list, combined into a new parent node whose frequency is their sum, and then reinserted into the sorted list
- This process continues until a single tree root remains — the Huffman Tree
- The resulting tree is printed sideways in the console, showing the hierarchical structure with frequency and character labels

## _Run Length Encoding (Not Started)_

Run Length Encoding is a simple lossless data compression algorithm. The idea is to replace consecutive repeated characters with the character followed by its count.

---

# License

This project is licensed under the Apache License - see the LICENSE file for details.