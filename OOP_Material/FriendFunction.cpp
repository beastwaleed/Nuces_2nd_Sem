#include <iostream> // Include the iostream library
using namespace std; // Include the entire std namespace

class Distance{
private:
    int meter;
public:
    Distance(int m):meter(m){} // Initialize the meter variable with m
    friend int add(Distance d); // Declare the add function as a friend function
};

int add(Distance d){
    d.meter += 5; // Increment the meter variable by 5
    return d.meter; //Return the updated meter variable
}

int main()
{
    Distance d(10); // Create a Distance object with a meter value of 10
    cout << "After Increment by 5 = " << add(d) << " meters" << endl; // Print the updated meter value
    return 0;
}