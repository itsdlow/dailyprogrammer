#include <iostream>

using namespace std;

//[2019-02-11] Challenge #375 [Easy] Print a new number by adding one to each of its digit (https://www.reddit.com/r/dailyprogrammer/comments/aphavc/20190211_challenge_375_easy_print_a_new_number_by/)
int challenge(int n){
	int num = n;
	//if n is less than ten, add 1 to single deigit --  return
	if (num<10){
		return num+1;
	}
	//else aadd 1 to each digit of n
		int d = (n % 10);
		//n minus the last-place digit 
		int digits = challenge((n-d)/10);
		d = d + 1;
		digits = digits * 10;
		//handles exception case where last-place digit is 9 --> 10
		return (d==10) ? ((digits+1)*10) : (d+digits);

}



int main(){
	int num;
	cin >> num;
	/*check num for proper input (num is an int that can be pos
		or neg, if neg take abs (multiply by -1) 
		)*/
	int res = challenge(num);
	cout << num << " + 1 (to each digit) = " << res << endl;
}