#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //This line will get the name from the user and store it in an string variable
    string name = get_string("Enter your name: ");
    //This line will print the name input from the user
    printf("hello, %s\n", name);
}