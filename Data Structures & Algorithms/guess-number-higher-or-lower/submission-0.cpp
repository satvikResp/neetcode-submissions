/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;

            int val =guess(mid+1);
            if(val==0){
                return mid+1;
            }
            else if(val==-1){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};