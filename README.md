# **Algoritmic Analysis Course Projects**  [![made-with-c](https://img.shields.io/badge/Made%20with-C-1f425f.svg)]()

Welcome to the repository. Here, I will be sharing the assignments I completed for my 3rd year course, Algoritmic Analysis. I took this course twice, so there will be twice the more assignments than you would usually expect for a single term course. You will also see a .clang-format file in this repository. This is a file I created for myself to override VSCode's default formatting rules. You can copy and paste that file to your workspace folder if you also hate how the formatting pushes your parantheses' to a new line. 



# Problems Solved In This Repository


- Creating a Von Neumanns Neighbourhood Matrix with a given N value
- Calculating the closest points read from a file, with divide and conquer method
- Calculating a combination of ads to earn maximum possible revenue from a given advertisement times and prices table, with dynamic programming
- Choosing flights based on a user choice of tranfer limit, duration limit and/or price limit, with the flight informations being read from a file and then turned into a graph
- ?


## Every Problem Explained

### _Von Neuman (Completed)_

Program takes an N value from the user to create and print a matrix which obeys the [Von Neumann’s Neighborhood rule](https://mathworld.wolfram.com/vonNeumannNeighborhood.html).

N = 0 would indicate that no cells are full per rule, so the program creates a 3x3 matrix. For N = 5 it would be a 5x5. Matrix must be dynamically allocated. Then program will print said matrix with full cells represented by '12 and empty celss represented by '0'.

<br />


### _Closest Points (Completed)_

sample.txt contains N random points on a cartesian plane. The program must read these points and find the closest pair following the Divide and Conquer principle. We are allowed to assume all points in the file have different coordinates.

Program executes in these steps:

1. reading the coordinates in the file “sample.txt” 
2. sort the coordinates increasing by x value
3. start the divide and conquer execution by dividing the plane into two from the median value of x coordinates
4. keep dividing until point number is 2 < n < 3, then brute force it.
5. coming back from the recursion, in both sides of the median line, compare the closest pairs from dlow and dhigh, and pick the closer one. so now **_dmin = min(dlow, dhigh)_**
6. but the closest point pair doesn't have to be on the same side of the median line. it could be on different sides. it should be enough to just check the points that are  closer in perpendicular to the median line then twice the dmin value. if a closer pair is found all values are updated.

<br />

### _Ad Revenue (Needs Debugging)_

A website has to choose between an N number of advertisements available, based on the advertisements starting times, durations and revenue they will bring as input. Based on the starting time and duration, some might ads overlap.

The program calculates the optimal combination of ads that do not overlap with airtime and bring the maximum revenue. This is done by a dynamic programming principle. 
Basically, for the j. ad: 

- we will either choose to add the ad plus those that aired before and that do not overlap with it,
- or we will choose not to add it and then the max revenue for that step would be the one on (j-1). step.

Once j reaches the final step, we will have the maximum revenue we need.

<br />

### _Flight Graph Problem (Incomplete)_

A company that sells plane tickets wants to develop an efficient algorithm to show their users available paths between the cities they wish to fly between. This company gives available flights information, in the shape of a txt file that contains source city, destination city, duration as hour, duraiton as minute, and price of the flight, in that order.
Users that wish to see flights available must:
- Select two cities to fly between
- Select the maximum amount of transfers they'd allow, or if they want to allow at all (which must be kept in control since user should not be able to enter less than 0 transfers or more than the amount of cities)
- Select if they want to add any additional constraints such as maximum duration, or price, and enter these if yes
The program aims to show the user all available paths. 

<br />

This is how the program executes:
- First the program read the file and loads all the info to a structure array in the type of a struct flights_table
- It finds every single city and puts it into a strings array (a char matrix) and uses row numbers as index to represent cities in the adjacency matrix that will be constructed. These indexes are written to the flights_table also
- Because it makes sense for cities to represent nodes of the graph and flight to represent vertexes, adjacency matrix is formed and filled with the info from the struct array and the city matrix.
- After user enters preferences, DFS is performed according to these preferences. It should be noted that the program adds an hour to the total path duration every time a transfer occurs in a path.
- After the initial prep is done, program enters an endless loop for the user to quit only when they wish to. 

<br />

### _Hashing Program (Incomplete)_

Finishing Project for this course will be a fully functional hashing program. It uses open adressing double hash, and takes key in the form of a string typed id.



<br />

**_More will be added soon._**

<br />


---
#### **If you have any further questions →**

[![Twitter][twitter-shield]][twitter-url]
<br />

[![LinkedIn][linkedin-shield]][linkedin-url]


[linkedin-shield]: https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white
[linkedin-url]:https://www.linkedin.com/in/ya%C4%9Fmur-duran-645510182/

[twitter-shield]: https://img.shields.io/badge/twitter-%231DA1F2.svg?style=for-the-badge&logo=Twitter&logoColor=white
[twitter-url]:https://twitter.com/elifyagmurduran
