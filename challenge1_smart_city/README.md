# CHALLENGE 01 : SMART CITY TEMPERATURE ALERTS<br>

## PROBLEM OVERVIEW<br>
A smart city monitors daily temperatures to generate early alerts when a significant temperature change occurs.<br>
For each day, the system checks future days to detect whether the temperature becomes at least K degrees warmer or colder.<br>
This helps authorities prepare for heatwaves or cold spells.<br>

## PROBLEM STATEMENT<br>
You are given temperature data for N consecutive days in an array temp[0…N-1].<br>
For each day i, find the earliest future day j (j > i) such that:<br>
- temp[j] ≥ temp[i] + K (at least K degrees warmer) OR<br>
- temp[j] ≤ temp[i] - K (at least K degrees colder)<br>
If such a day exists, it is called the alert day for day i.<br>
If no such day exists, the alert value for that day is 0.<br>
After precomputing alert days for all indices, you must answer queries.<br>

##  QUERY REQUIREMENTS<br>
The system supports two types of queries:<br>

NEXT X<br>
Return the index of the alert day for day X.<br>
If no alert exists, output No Alert.<br>

COUNT L R<br>
Return the number of days i in range [L, R] that have a non-zero alert day.<br>

All indices are 0-based.<br>

## INPUT FORMAT<br>
First line contains N K Q.<br>
Second line contains N integers representing temperatures.<br>
Next Q lines contain queries of type NEXT X or COUNT L R.<br>

## OUTPUT FORMAT<br>
For NEXT X, output the alert day index or No Alert.<br>
For COUNT L R, output the count of valid alert days in the given range.<br>

## APPROACH 1 – BRUTE FORCE<br>
IDEA<br>
For each day i, check all future days j > i and find the first day where temperature difference is at least K.<br>
<br>
STEPS<br>
For each index i, loop from i+1 to N-1.<br>
Check if temperature is at least K warmer or colder.<br>
Stop at the first valid day.<br>
<br>
TIME COMPLEXITY<br>
O(N^2)<br>
<br>
SPACE COMPLEXITY<br>
O(1)<br>
<br>
DRAWBACK<br>
Very slow for large N and causes time limit exceeded.<br>
<br>
## APPROACH 2 – OPTIMIZED APPROACH (MONOTONIC STACK + PREFIX SUM)<br>
IDEA<br>
This problem is similar to the Next Greater Element problem.<br>
We separately compute the next K-warmer day and the next K-colder day using stacks, then choose the earlier one.<br>

STEPS<br>
- First, compute the next K-warmer day for each index using a monotonic decreasing stack.<br>
- Second, compute the next K-colder day using a monotonic increasing stack.<br>
- For each index, select the minimum valid index among warmer and colder days.<br>
- If neither exists, alert value is 0.

Build a prefix sum array pref where pref[i] is the count of days from 0 to i having a valid alert day.<br>
For COUNT queries:<br>
COUNT L R = pref[R] − (L > 0 ? pref[L-1] : 0)<br>
<br>
TIME COMPLEXITY<br>
O(N + Q)<br>
<br>
SPACE COMPLEXITY<br>
O(N)<br>

## CONCLUSION<br>
The Smart City Temperature Alerts problem efficiently uses monotonic stacks and prefix sums to handle large inputs.<br>
Brute force is simple but inefficient, while the optimized approach is fast and suitable for real-world and competitive programming scenarios.<br>
