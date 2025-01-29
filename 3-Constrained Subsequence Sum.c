int constrainedSubsetSum(int* nums, int numsSize, int k) {
    struct Node {
        int value;
        int index;
    };
    
    struct Node* heap = (struct Node*)malloc(numsSize * sizeof(struct Node));
    int heapSize = 0;
    
    int ans = nums[0];
    
    for (int i = 0; i < numsSize; i++) {
        while (i - heap[0].index > k) {
            // Remove elements from the heap that are out of range.
            if (heapSize > 0) {
                heap[0] = heap[heapSize - 1];
                heapSize--;
                int currIndex = 0;
                while (true) {
                    int leftChild = currIndex * 2 + 1;
                    int rightChild = currIndex * 2 + 2;
                    int nextIndex = currIndex;
                    if (leftChild < heapSize && heap[leftChild].value > heap[nextIndex].value) {
                        nextIndex = leftChild;
                    }
                    if (rightChild < heapSize && heap[rightChild].value > heap[nextIndex].value) {
                        nextIndex = rightChild;
                    }
                    if (nextIndex == currIndex) {
                        break;
                    }
                    struct Node temp = heap[currIndex];
                    heap[currIndex] = heap[nextIndex];
                    heap[nextIndex] = temp;
                    currIndex = nextIndex;
                }
            } else {
                break;
            }
        }
        
        int curr = (heapSize > 0) ? (heap[0].value + nums[i]) : nums[i];
        
        ans = (curr > ans) ? curr : ans;
        
        struct Node newNode;
        newNode.value = (curr > 0) ? curr : 0;
        newNode.index = i;
        heap[heapSize] = newNode;
        
        int currIndex = heapSize;
        while (currIndex > 0) {
            int parentIndex = (currIndex - 1) / 2;
            if (heap[currIndex].value > heap[parentIndex].value) {
                struct Node temp = heap[currIndex];
                heap[currIndex] = heap[parentIndex];
                heap[parentIndex] = temp;
                currIndex = parentIndex;
            } else {
                break;
            }
        }
        
        heapSize++;
    }
    
    free(heap);
    
    return ans;
}
