/*
思路1：set
能通过题解，不过因为使用了额外的空间set，不符合题意的。
*/
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> si;
        int res = -1;
        for(int i = 0; i < nums.size(); i++){
            if( si.find(nums[i]) == si.end() ) si.insert(nums[i]);
            else{
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
*/

/*
思路2：排序
能通过题解，不过因为改变了原数组，不符合题意的。
*/
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = -1;
        for(auto it = nums.begin(); it != nums.end() - 1; it++){
            if(*it == *(it+1)){
                res = *it;
                break;
            }
        }
        return res;
    }
};
*/

/*
思路3：快慢指针，符合题意。
把数组的值看成 next 指针，数组的下标看成节点的索引。因为数组中至少有两个值一样，也说明有两个节点指向同一个位置，所以一定会出现环。
举个例子，3 1 3 4 2。
nums[0] = 3
nums[3] = 4
nums[4] = 2
nums[2] = 3
即0->3->4->2->3->....
3就是循环入口节点，故3就是重复的数字。
我们需要快慢指针，同时从起点出发，慢指针一次走一步，快指针一次走两步，然后记录快慢指针相遇的点。
之后再用两个指针，一个指针从起点出发，一个指针从相遇点出发，此时两个指针都走一步，当他们再次相遇的时候就是入口点了。
*/
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        //快慢指针相遇，值一样
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        //这个时候慢指针从头出发，快指针从相遇节点出发，再次相遇时，就是环的入口节点。
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
*/

/*
思路4：二分查找，不符合题意的。
我们知道二分查找要求有序，但是给定的数组不是有序的，那么怎么用二分查找呢？
原数组不是有序，但是我们知道重复的那个数字肯定是 1 到 n 中的某一个，而 1,2...,n 就是一个有序序列。因此我们可以对 1,2...,n 进行二分查找。
mid = (1 + n) / 2，接下来判断最终答案是在 [1, mid] 中还是在 [mid + 1, n] 中。
我们只需要统计原数组中小于等于 mid 的个数，记为 count。
如果 count > mid ，在 [1,mid] 范围内的数字个数超过了 mid ，所以一定有一个重复数字。
否则的话，既然不在 [1,mid] ，那么最终答案一定在 [mid + 1, n] 中。
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int low = 0;
        int high = len - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int count = 0;
            for(int i = 0; i < len; i++){
                if(nums[i] <= mid) count++;
            }
            if(count > mid) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

