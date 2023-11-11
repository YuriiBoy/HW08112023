#include "Header.h"
#include "Queue.h"

int main()
{
    Queue<int> queue(8);
    for (int i = 0; i < 5; i++) {
        queue.push((i + 1) * 100);
    }
    queue.display();

    int firstO = queue.firstOut();
    std::cout << "\n  " << firstO << " has been deleted\n";
    queue.display();
}
