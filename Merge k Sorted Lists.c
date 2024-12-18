/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int findmin(int arr[], int listsSize) {
    int min = 99999;
    int place = -1;
    for(int i = 0; i < listsSize; i++) {
        if(arr[i] < min) {
            min = arr[i];
            place = i;
        }
    }
    return place;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0) return NULL;
    int arr[listsSize];
    int min = 99999, place = 0;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *current = head;
    for(int i = 0; i < listsSize; i++) {
        if(lists[i] == NULL) {
            arr[i] = 99999;
            continue;
        }
        int temp = lists[i] -> val;
        arr[i] = temp;
        if(temp < min) {
            place = i;
            min = temp;
        }
    }
    if(min == 99999) return NULL;

    while(place != -1) {
        current -> next = lists[place];
        current = lists[place];
        lists[place] = lists[place] -> next;
        if(lists[place] == NULL) arr[place] = 99999;
        else
            arr[place] = lists[place] -> val;
        place = findmin(arr, listsSize);
    
    }
    return head -> next;
}
