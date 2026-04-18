#include <stdio.h>

void toh(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    toh(n - 1, source, auxiliary, destination);

    // Move nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination
    toh(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nThe sequence of moves:\n");

    toh(n, 'S', 'D', 'A');  // S = Source, D = Destination, A = Auxiliary

    return 0;
}