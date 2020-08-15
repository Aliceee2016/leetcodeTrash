// leetCode-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
	int whetherInString(char a, string s) {
		int tmp = 0;
		for (int i = 0; i < s.length(); i++) {
			if (a == s[i]) {
				tmp = 1;
			}
		}
		return tmp;
	}
	int lengthOfLongestSubstring(string s) {
		int maxLen = 0;
		string tmp = "";
		//cout << "Function inside " << endl;
		for (int i = 0; i < s.length(); i++) {

			int j = i+1;
			tmp += s[i];
			for (; j < s.length(); j++) {
				//cout << tmp << " " << s[j] << endl;
				//cout << whetherInString(s[j], tmp) << endl;
				if (whetherInString(s[j], tmp) == 0) {
					tmp += s[j];
				}
				else {
					tmp = "";
					break;
				}

			}
			if ((j-i) > maxLen) {
				maxLen = j-i;
			}

		}
		//cout << "Function outside " << endl;
		return maxLen;
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double res = 0;
		int len = nums1.size() + nums2.size();
		int pos = len / 2;
		int pos1 = 0;
		int pos2 = 0;
		int temp = 0;
		int temp_1 = 0;
		//cout << "nums1.size() = " << nums1.size() << endl;
		//cout << "nums2.size() = " << nums2.size() << endl;
		if (nums1.size() == 0) {
			if (len % 2 == 0) {
				res = double(nums2[pos] + nums2[pos - 1]) / 2;
				
			}
			else {
				res = nums2[pos];
			}
			return res;
		}

		if (nums2.size() == 0) {
			if (len % 2 == 0) {
				res = double(nums1[pos] + nums1[pos - 1]) / 2;
			}
			else {
				res = nums1[pos];
			}
			return res;
		}

		vector<int> vec;
		for (int i = 0; i < pos + 1; i++) {

			temp_1 = temp;

			
			if (pos1 < nums1.size() && pos2 < nums2.size() && nums1[pos1] <= nums2[pos2]) {
				//cout << "------1-----" << endl;
				temp = nums1[pos1];
				pos1++;
			}
			else if (pos1 < nums1.size() && pos2 < nums2.size() && nums1[pos1] > nums2[pos2]) {
				//cout << "------2-----" << endl;
				temp = nums2[pos2];
				pos2++;
			}
			else {
				if (pos1 >= nums1.size() && pos2 < nums2.size()) {
					temp = nums2[pos2];
					pos2++;
				}
				if (pos1 < nums1.size() && pos2 >= nums2.size()) {
					temp = nums1[pos1];
					pos1++;
				}

			}
			vec.push_back(temp);
			//cout << i <<" "<< temp << endl;

			
		}
		if (len % 2 == 0) {
			//cout << "here" << endl;
			res = double(vec[pos - 1] + vec[pos]) / 2;

		}
		else {
			//cout << "2 here" << endl;
			res = vec[pos];
		}
		return res;
	}
	string longestPalindrome(string s) {
		
		//int length = s.size();
		//string sc = preprocessString(s, len);
		if (s == "" || s.length() < 1)
			return "";
		if (s.length() == 1)
			return s;
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++) {
			int len1 = expandRoundCentre(s, i, i); //i is the center
			int len2 = expandRoundCentre(s, i, i + 1); //centre is between i ,i+1 
			
			int len = len1 > len2 ? len1 : len2;
			//cout << " len1 len2 len: " << len1 << " " << len2 << " " << len << endl;
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
			//cout << "start end : " <<start << " " << end << endl;
		}
		string res = s.substr(start, end-start+1);
		
		return res;
	}
	int expandRoundCentre(string s, int left, int right) {
		int R = right, L = left;
		while (L >= 0 && R < s.length() && s[L] == s[R]) {
			L--;
			R++;
		}
		return R - L - 1;
	}
	string preprocessString(string s, int len) {
		char schar[2001];
		schar[0] = '#';

		for (int i = 1, j = 0; i < len && j < s.size(); i += 2, j++) {
			schar[i] = s[j];
			schar[i + 1] = '#';

		}
		schar[len] = '\0';
		string sc = schar;

		return sc;
	}
	string convert(string s, int numRows) {
		string res;
		if (numRows == 1)
			return s;
		int row = numRows;
		char cha[100][ 100];
		//string cha[100];
		int pos = 0;
		int slen = s.length();
		

		//initial cha
		int N = 100;
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < N; j++) {
				cha[i][j] = '#';
			}
		}


		int i = 0, j = 0;
		pos = 0;
		while (pos < slen) {
			
			for (; i < row && pos < slen; i++) {
				cha[i][j] = s[pos];

				pos++;
			}

			if (pos >= slen) {
				break;
			}

			i = i - 2;
			j = j + 1;
			for (; i >= 0 && pos < slen; i--, j++) {


				cha[i][j] = s[pos];
				
				pos++;
			}
			i += 2;
			j -= 1;

			if (pos >= slen) {
				break;

			}
		}
		int halfOneH = j + 1;

		for (int k = 0; k < numRows; k++) {
			for (int l = 0; l < halfOneH; l++) {
				if (cha[k][l] != '#') {					
					res.append(1, cha[k][l]);
				}
			}
			
		}
		
		return res;
	}
	int reverse(int x) {
		long res = 0;
		unsigned int num;
		int tmp = 0;
		if (x < 0) {
			num = -x;
			tmp = 1;
		}
		else {
			num = x;
		}
		int count = 10;
		while (num > 0) {
			int a_fin = num % 10;
			res = res * count + a_fin;
			num = num / 10;
			//cout << num << endl;
			//count = count * 10;
			//cout << a_fin <<" "<< res<< endl;
			
		}
		if (res > pow(2, 32))
			return 0;
		if (tmp == 1)
			res = -res;
		return res;
	}
	int myAtoi(string str) {
		//cout << "In function str = " << str << endl;
		//INT_MAX
		//INT_MIN
		long long res = 0;
		int temp = 0;
		int count = 0;
		int i = 0;
		for (i = 0; i < str.size() && str[i] == ' '; i++);
		if (i >= str.size())
			res = 0;
		else {
			if (str[i] == '-') {
				i++;

				//long num = 0;
				int cha = str[i] - '0';

				while (0 <= cha && cha <= 9 && i < str.size()) {
					//cout << "cha i str[i] res " << cha << " " << i << " " << str[i] <<" ";
					count++;
					res = res * 10 + cha;
					i++;
					cha = str[i] - '0';
					//cout << res << endl;
					if (res > INT_MAX) {
						temp = -1;
						break;
					}

				}
				res = -res;
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				int cha = str[i] - '0';

				while (0 <= cha && cha <= 9 && i < str.size()) {
					//cout << "cha i str[i] " << cha <<" " << i<<" "<< str[i]<< endl;
					count++;
					res = res * 10 + cha;
					i++;
					cha = str[i] - '0';
					if (res >= INT_MAX) {
						temp = 1;
						break;
					}
				}
			}
			else if (str[i] == '+') {
				i++;

				//long num = 0;
				int cha = str[i] - '0';
				while (0 <= cha && cha <= 9 && i < str.size()) {
					//cout << "cha i str[i] res " << cha << " " << i << " " << str[i] <<" ";
					count++;
					res = res * 10 + cha;
					i++;
					cha = str[i] - '0';
					//cout << res << endl;
					if (res >= INT_MAX) {
						temp = 1;
						break;
					}

				}


			}
			else {
				res = 0;
			}
		}
		//cout << "In function res = " << res << endl;
		if (res < INT_MIN || temp == -1) {
			res = INT_MIN;
		}
		if (res > INT_MAX || temp == 1) {
			res = INT_MAX;
		}
		return res;

	}
};

int main()
{
	Solution solu;
	string s = "bbbbb";
	//cout << solu.lengthOfLongestSubstring(s) << endl;
 //   std::cout << "Hello World!\n";
	//cout << solu.whetherInString('a',s) << endl;
	vector<int> nums1;
	vector<int> nums2;
	//nums1.push_back(1);
	//nums1.push_back(2);
	//nums2.push_back(3);
	//nums2.push_back(4);

	//nums1.push_back(1);
	//nums1.push_back(3);
	//nums2.push_back(2);
	//nums2.push_back(4);

	//nums1.push_back(1);
	//nums2.push_back(2);
	//nums2.push_back(3);
	//nums2.push_back(4);

	//cout << "Median = "<< solu.findMedianSortedArrays(nums1, nums2) << endl;
	//string str = "bb";
	string str = "PAYPALISHIRING";
	//solu.longestPalindrome(str);
	//cout << solu.longestPalindrome(str) << endl;
	//char cha[3][3] = { '#' };
	//int N = 3;
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		if (cha[i][j] == NULL) {
	//			cout << "$" << " ";
	//		}
	//		cout << cha[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	int rowNumber = 4;
	
	//string res = solu.convert(str, rowNumber);
	int x = 123;
	int resReverse = solu.reverse(x);
	//cout << resReverse << endl;

	//string temp;
	//char a = 's';
	//temp.append(1, a);
	//temp.append(1, a);
	//cout << temp << endl;
	//cout << INT_MAX << endl;
	//cout << INT_MIN << endl;
	string strAtoI= "20000000000000000000";
	cout << solu.myAtoi(strAtoI) << endl;


	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
