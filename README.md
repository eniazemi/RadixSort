# RadixSort

RadixSort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements into buckets according to their radix. For elements with more than one significant digit, this bucketing process is repeated for each digit, while preserving the ordering of the prior step, until all digits have been considered. For this reason, radix sort has also been called bucket sort and digital sort.
This form of RadixSort is implemented to start at least significant digit (LSD).

The RadixSort function works by taking an array of elements (in this case integers) and sorting it based on its digits from LSD (least significant digit) to MSD (most significant digit).

Once the maximum number in the array is found, the CountSort function is executed, so the collection is done in 10 communities (int numbers are decimal, so there is a possibility of 10 unique digits), counting the elements in the community and returning them to new (sorted) positions.
When this code ends we will get the array sorted from the smallest number to the largest number.

#EA
