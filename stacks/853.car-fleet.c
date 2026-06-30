/*
 * @lc app=leetcode id=853 lang=c
 *
 * [853] Car Fleet
 */

// @lc code=start
//stacks
//car-fleet
//Time Complexity: O(n log n) where n is the number of cars. We sort the cars based on their positions, which takes O(n log n) time. After sorting, we traverse the sorted list of cars once to calculate the number of fleets, which takes O(n) time
//Space Complexity: O(n) where n is the number of cars. We create an array of car structures to store the position and speed of each car, which requires O(n) space.
//Approach: We can create a structure to represent each car with its position and speed. We then sort the cars based on their positions in ascending order. After sorting, we traverse the sorted list of cars from the last car to the first car. For each car, we calculate the time it takes to reach the target. We maintain a variable to keep track of the largest fleet time encountered so far. If the current car's time to reach the target is greater than the largest fleet time, it means that the current car cannot catch up to the fleet in front of it, and we increment the fleet count and update the largest fleet time. If the current car's time is less than or equal to the largest fleet time, it means that the current car will join the fleet in front of it, and we do not increment the fleet count. Finally, we return the total number of fleets formed.
#include <stdlib.h> 
struct car{
    int position;
    int speed;
};

int cmp(const void* a, const void* b)
{
    struct car* x=(struct car*)a;
    struct car* y=(struct car*)b;
    return x->position-y->position;
}
int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    struct car cars[positionSize];
    for(int i=0;i<positionSize;i++)
    {
        cars[i].position=position[i];
        cars[i].speed=speed[i];
    }
    qsort(cars,positionSize,sizeof(struct car),cmp);
    int fleets=0;
    double largest_fleet_time=0.0;
    for(int i=positionSize-1;i>=0;i--)
    {
        double curr_time=(double)(target-cars[i].position)/cars[i].speed;
        if(curr_time>largest_fleet_time)
        {
            fleets++;
            largest_fleet_time=curr_time;
        }
        
    }
    return fleets;
    
    
}
// @lc code=end

