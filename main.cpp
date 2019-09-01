//
//  main.cpp
//  Multiplication
//
//  Created by Vo Hung Son on 5/16/19.
//  Copyright © 2019 Vo Hung Son. All rights reserved.
//

#include <iostream>
using namespace std;

class Muliplication {
private:
    //string s1 = "1100101";//number 101 -> number A
    //string s2 = "1011001";//number 89 -> number B
    int s1 = 10000;
    int s2 = 10000;
    string s3 = "";
    int size = 0;
public:
    /*
     Here is the algorithm to add two binary numbers (number a & b)
     and the complexity of this algorithm is: MAX[log(a),log(b)]
     */
    string addBinary(string a, string b){//add two binary numbers
        string result = ""; // Initialize result
        int s = 0;          // Initialize digit sum
        // Travers both strings starting from last characters
        int i = int (a.size() - 1);
        int j = int (b.size() - 1);
        while (i >= 0 || j >= 0 || s == 1){
            // Comput sum of last digits and carry
            s += ((i >= 0)? a[i] - '0': 0);
            s += ((j >= 0)? b[j] - '0': 0);
            // If current digit sum is 1 or 3, add 1 to result
            result = char(s % 2 + '0') + result;
            s /= 2;// Compute carry
            i--; j--;// Move to next digits
        }
        return result;
    }//->Complexity here is MAX[log(a),log(b)]
    
    /*
     Use the algorithm that we learned in the class
     We can get the complexity is: b*log(a)
     */
    string mulBinary(string a, string b){//mul two binary numbers
        string result = "0"; // Initialize result
        string count =  "0";
        string one = "1";
        while(count != b){
            result =addBinary(result,a);//add number a with itself b times
            count = addBinary(count, one); //count b times
        }
        return result;
    }//->complexity here is: b*log(a)
    
    void algorithmInTheClass(){
        cout<<"The algorithm in the class with complexity: b*log(a)\n";
        cout<<"Number a: "<<s1<<" -> "<<gen(s1)<<"\n";
        cout<<"Number b: "<<s2<<" -> "<<gen(s2)<<"\n";
        s3 = mulBinary(gen(s1), gen(s2));
        cout<<"The result is: "<<s3<<"\n\n";
    }
    
    /*
     Here is the algorithm to add two binary numbers (number a & b)
     that I developed the algorithm of multiplication
     and the complexity of this algorithm is: log(a)*log(b)
     */
    string mulBinaryImproved(string a, string b){
        string result = "0";
        string shift = "";
        int i = int (b.size() - 1);//get the length of number b
        while (i >= 0){//this is a loop with log(b) times
            if(b[i] == '1'){
                result = addBinary(result, a + shift);//Complexity: log(a)
            }
            shift += "0";
            i--;
        }
        return result;
    }//-> The complexity of this algorithm is: log(a)*log(b)
    
    void algorithmImproved(){
        cout<<"The algorithm improved with complexity: log(b)*log(a)\n";
        cout<<"Number a: "<<s1<<" -> "<<gen(s1)<<"\n";
        cout<<"Number a: "<<s2<<" -> "<<gen(s2)<<"\n";
        s3 = mulBinaryImproved(gen(s1), gen(s2));
        cout<<"The result is: "<<s3<<"\n\n";
    }
    
    string gen(int n){
        string result = "";
        while(n!=0){
            if(n%2==0){
                result = "0" + result;
            } else {
                result = "1" + result;
            }
            n = n/2;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    clock_t start, end;
    Muliplication multiplication;
    start = clock();
    //for(int i = 0; i < 10000; i++){
        multiplication.algorithmInTheClass();
    //}
    end = clock();
    double time_taken1 = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " <<fixed<< time_taken1<<"\n";
    
    start = clock();
    //for(int i = 0; i < 10000; i++){
        multiplication.algorithmImproved();
    //}
    end = clock();
    double time_taken2 = double(end - start) / double(CLOCKS_PER_SEC);
    
    cout << "\nTime taken by program 1 is : " <<fixed<< time_taken1<<"\n";
    cout << "\nTime taken by program 2 is : " <<fixed<< time_taken2<<"\n";
    //test
    cout<<"\nTest: ";
    cout<<multiplication.gen(7);
    cout<<"\n\n ";
    return 0;
}
