#include "func.h"

using namespace std;

/*
   _______    _______    __      ______     _______    __  ___________  ___  ___         ______    ____  ____   _______  ____  ____   _______      __   __  ___       ___         ______     _______   ________    _______   _______    _______  ________       ___      ___  _______   ______  ___________  ______     _______   
  |   __ "\  /"      \  |" \    /    " \   /"      \  |" \("     _   ")|"  \/"  |       /    " \  ("  _||_ " | /"     "|("  _||_ " | /"     "|    |"  |/  \|  "|     /"  |       /    " \   /"      \ |"      "\  /"     "| /"      \  /"     "||"      "\     |"  \    /"  |/"     "| /" _  "\("     _   ")/    " \   /"      \  
  (. |__) :)|:        | ||  |  // ____  \ |:        | ||  |)__/  \\__/  \   \  /       // ____  \ |   (  ) : |(: ______)|   (  ) : |(: ______)    |'  /    \:  |    /  //       // ____  \ |:        |(.  ___  :)(: ______)|:        |(: ______)(.  ___  :)     \   \  //  /(: ______)(: ( \___))__/  \\__/// ____  \ |:        | 
  |:  ____/ |_____/   ) |:  | /  /    ) :)|_____/   ) |:  |   \\_ /      \\  \/       /  /    )  )(:  |  | . ) \/    |  (:  |  | . ) \/    |      |: /'        |   /'  /       /  /    ) :)|_____/   )|: \   ) || \/    |  |_____/   ) \/    |  |: \   ) ||      \\  \/. ./  \/    |   \/ \        \\_ /  /  /    ) :)|_____/   ) 
  (|  /      //      /  |.  |(: (____/ //  //      /  |.  |   |.  |      /   /       (: (____/ //  \\ \__/ //  // ___)_  \\ \__/ //  // ___)_      \//  /\'    |  //  /       (: (____/ //  //      / (| (___\ || // ___)_  //      /  // ___)_ (| (___\ ||       \.    //   // ___)_  //  \ _     |.  | (: (____/ //  //      /  
 /|__/ \    |:  __   \  /\  |\\        /  |:  __   \  /\  |\  \:  |     /   /         \         \  /\\ __ //\ (:      "| /\\ __ //\ (:      "|     /   /  \\   | /  //         \        /  |:  __   \ |:       :)(:      "||:  __   \ (:      "||:       :)        \\   /   (:      "|(:   _) \    \:  |  \        /  |:  __   \  
(_______)   |__|  \___)(__\_|_)\"_____/   |__|  \___)(__\_|_)  \__|    |___/           \"____/\__\(__________) \_______)(__________) \_______)    |___/    \___||___/           \"_____/   |__|  \___)(________/  \_______)|__|  \___) \_______)(________/          \__/     \_______) \_______)    \__|   \"_____/   |__|  \___) 
                                                                                                                                                                                                                                                                                                                                  
Priority Queue w/ Sorted Vector
*/


// Linear Search
void priorityQueueSortedVector::insert(int data, int priority)     
{
    int index = 0;
    while (index < myVector.size() && priority > myVector[index].priority ) // Lower priority int first!
    {
        index++;
    }

    // Linear search O(N)

    item temp(data, priority);
    myVector.insert(myVector.begin() + index, temp);      
}


// Binary Search
void priorityQueueSortedVector::insert_but_better(int data, int priority)      // BINARY SEARCH O(logN)
{
    int left_index = 0;
    int right_index = myVector.size() - 1;

    while (left_index < right_index) {
        int mid_index = (left_index + right_index) / 2;

        if (myVector[mid_index].priority == priority)
        {
            item temp(data, priority);
            myVector.insert(myVector.begin() + mid_index, temp);
            return;
        }
        else if (myVector[mid_index].priority > priority)
        {
            right_index = mid_index - 1;
        }
        else
        {
            left_index = mid_index + 1;
        }
    }

    // special cases and final handling

    if (myVector.empty()) 
    {
        item temp(data, priority);
        myVector.insert(myVector.begin(), temp);
        return;
    }
    else if (priority < myVector[left_index].priority)
    {
        item temp(data, priority);
        myVector.insert(myVector.begin() + left_index, temp);
        return;
    }
    else 
    {
        item temp(data, priority);
        myVector.insert(myVector.begin() + left_index + 1, temp);
        return;
    }

}

