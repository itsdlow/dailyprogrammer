#include <iostream>

using namespace std;

int sum_digits(int n);

//[2019-01-28] Challenge #374 [Easy] Additive Persistence (https://www.reddit.com/r/dailyprogrammer/comments/akv6z4/20190128_challenge_374_easy_additive_persistence/)
int additive_persistence(int n, int &add_per){
	//returns the additive persistence of the given int
	//int add_per=0;

	if (n<10) {
		return add_per;
	}
	else {
		//sum digits of n
		int sum = sum_digits(n);
		//cout << "Sum" << add_per << ": " << sum <<endl;
		add_per = add_per + 1;
		additive_persistence(sum,add_per);
	}
	//while n is greater than 1 digit in length return sum of digits

	return add_per;
}

int sum_digits(int n){
	//sum the digits of an integer larger than 9
	int result = 0;
	int tmp = n;
	while (tmp>9){
		//get the last digit of result
		result += tmp % 10;
		tmp = tmp / 10;

	}
	result = result + tmp;
	return result;
}

int main() {
	int num;
	cin >> num;
	/*check num for proper input (num is an int that can be pos
		or neg, if neg take abs (multiply by -1) 
		)*/
	int ap = 0;
	additive_persistence(num, ap);
	cout << num << "'s Additive Persistence: " << ap << endl;


}